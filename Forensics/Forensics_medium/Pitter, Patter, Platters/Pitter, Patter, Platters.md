# Pitter, Patter, Platters
## 解法
`file`コマンド`fsstat`コマンドでファイルシステムの存在を確認後、`fls+icat`で中身を見ると怪しげなファイルを見つけた。（ここでファイルシステムが出たから`mmls`ではパーティションテーブルは出なかった）
```
++ r/r 4040:    bzip2-lib.tcz
++ r/r 4041:    pcre.tcz.md5.txt
++ r/r 4042:    pcre.tcz
++ r/r 4043:    nginx.tcz.md5.txt
++ r/r 4044:    nginx.tcz
++ r/r 4045:    fuse.tcz.md5.txt
++ r/r 4046:    fuse.tcz
++ r/r 4047:    libdnet.tcz
++ r/r 4048:    open-vm-tools.tcz
++ r/r 4049:    open-vm-tools-modules-3.8.13-tinycore.tcz
++ r/r 4050:    libtirpc.tcz.md5.txt
++ r/r 4051:    libtirpc.tcz
++ r/r 4052:    glib2.tcz.dep
++ r/r 4053:    libffi.tcz.md5.txt
++ r/r 4054:    libffi.tcz
++ r/r 4055:    glib2.tcz.md5.txt
++ r/r 4056:    glib2.tcz
+ d/d 4020:     ondemand
+ r/r 4021:     onboot.lst
r/r 12: suspicious-file.txt
V/V 8033:       $OrphanFiles
```
`icat ディスク名 12`で中身を見ると、`Nothing to see here! But you may want to look here -->`とでてきた。\
ヒントでスラックスペースに隠されているとほのめかされていたため、スラックスペースについて調べると、ディスクは基本ブロック単位で読み書きをするのだが、ファイルの大きさがそのブロックよりも小さいとき、スラックスペースなるものが、出てくるらしい。つまりは余りのスペース。`blkls`での未使用領域とは異なる。\
`blkcat`コマンドはブロックを指定するとそのブロック全体を表示する = ファイル全体に加えて、スラックスペースも表示するコマンドのため、これを使ってみると、
`blkcat suspicious.dd.sda1 2049`\
`Nothing to see here! But you may want to look here -->}3986312f_3<_|Lm_111t5_3b{FTCocip`とflagがリトルエンディアン方式で格納されていたため、flagを得た。\
ちなみに`blkcat`には対象ファイルのブロックを指定する必要があるのだが、それは`istat`コマンドで確認できる。
```
Tubo@TUBO-PC:~/CTF$ istat suspicious.dd.sda1 12
inode: 12
Allocated
Group: 0
Generation Id: 3646402035
uid / gid: 0 / 0
mode: rrw-r--r--
size: 55
num of links: 1

Inode Times:
Accessed:       2020-09-30 22:15:59 (JST)
File Modified:  2020-09-30 14:17:23 (JST)
Inode Modified: 2020-09-30 22:15:54 (JST)

Direct Blocks:
2049
```