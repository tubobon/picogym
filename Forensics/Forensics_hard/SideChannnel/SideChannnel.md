# SideChannnel
## 解法
8桁のpinの正誤判定をするプログラムが与えられた。\
問題文にもある通り、サイドチャンネル攻撃は、プログラム自体の脆弱性ではなく、それを実行する際の実行時間の違いなどの**副産物**を利用して、情報漏洩を図る攻撃である。\
今回はその中のタイミング攻撃について解説する。\
タイミング攻撃は、異なる入力によるプログラム実行時間の違いを観測し、情報漏洩を図る攻撃のことである。\
8桁のpinをプログラムで判断する際、C言語だとイメージしやすいが、配列の0番地の文字から判断するのが定石である。（そこから1,2,3番地に続く）\
ここでもしも、X番地の文字が入力と正しければ、次の文字を判定する処理に進むし、そうでなければ、プログラムを終了する処理にするとどうだろうか。\
文字が正しければ実行時間は長くなるし、違うと判断されれば、実行時間は短くなるだろう。\
今回は1桁目のpinから順番に0~9の数字を試し、一番実行時間が長い数字を見つけていくことにした。
```
tubo@TUBO:/mnt/c/Users/yuki_/Downloads$ time ./pin_checker <<< 00000000
Please enter your 8-digit PIN code:
8
Checking PIN...
Access denied.

real    0m0.253s
user    0m0.129s
sys     0m0.012s


（省略）


tubo@TUBO:/mnt/c/Users/yuki_/Downloads$ time ./pin_checker <<< 48390519
Please enter your 8-digit PIN code:
8
Checking PIN...
Access denied.

real    0m1.174s
user    0m1.069s
sys     0m0.020s
tubo@TUBO:/mnt/c/Users/yuki_/Downloads$ time ./pin_checker <<< 48390513
Please enter your 8-digit PIN code:
8
Checking PIN...
Access granted. You may use your PIN to log into the master server.

real    0m1.271s
user    0m1.181s
sys     0m0.008s
```
よって,pinは`48390513`だと判明し、flagを得た。`picoCTF{t1m1ng_4tt4ck_914c5ec3}`


