# speeds and feeds
`nc mercury.picoctf.net 16524`に接続すると、


```G17 G21 G40 G90 G64 P0.003 F50
G0Z0.1
G0Z0.1
G0X0.8276Y3.8621
G1Z0.1
G1X0.8276Y-1.9310
G0Z0.1
G0X1.1034Y3.8621
G1Z0.1
G1X1.1034Y-1.9310
G0Z0.1
G0X1.1034Y3.0345
G1Z0.1

のような長いコードが与えられるが、これはGコードといって図面を作成するときに使われるコードである。

オンラインビューアーにコードを張り付けるとflagの図面を得ることができた。

https://ncviewer.com/


`picoCTF{num3r1cal_c0ntr0l_1395ffad}`
