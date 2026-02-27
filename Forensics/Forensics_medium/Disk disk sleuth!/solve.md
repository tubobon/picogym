# Disk, disk, sleuth!
imgファイルなので`mount`するのがセオリー\
`mmls`コマンドでパーティションがどうなってるか確認

### mountのやり方
- mkdir でディレクトリを作る
- `sudo mount loop,offset=パーティションの長さ XXX.img ファイルパス`

今回は`mmls`で本体が2048バイトから始まっていることが分かるため、パーティションは2048*512 = 1048576バイトとなり、\
`sudo mount loop,offset=1048576 dd.img /mnt/img`とマウントをした。

rootディレクトリなどを探したがflagが見つからなかったため、imgディレクトリに`grep`をかけた。

`grep -r "picoCTF{*" /mnt/img`

この操作によりflagを得ることができた。

`picoCTF{f0r3ns1c4t0r_n30phyt3_dcbf5942}`
