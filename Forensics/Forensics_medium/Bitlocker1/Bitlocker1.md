# Bitlocker1
## 解法
Bitlockerはディスク全体を暗号化したものである。\
このファイルを復号してディスクイメージを得るには、dislockerコマンドを行う\
その際、パスワードもしくは48桁の回復コードが必要になるのだが、今回はパスワードがそんなに難しいものでないらしい。\
そのため、hash crackを行う\
最初にBitlocker2jhonを使い、暗号化されたファイルのハッシュ値を読み取った\
ハッシュ値は複数あるが、今回はパスワードのハッシュ値に当たる`Bitlocker$0`を用いる\
`$bitlocker$0$16$cb4809fe9628471a411f8380e0f668db$1048576$12$d04d9c58eed6da010a000000$60$68156e51e53f0a01c076a32ba2b2999afffce8530fbe5d84b4c19ac71f6c79375b87d40c2d871ed2b7b5559d71ba31b6779c6f41412fd6869442d66d`\
これを`hash cat`を使い`rockyou.txt`をベースに辞書攻撃するとパスワード`jacqueline`が見つかった\
続いて`sudo dislocker -V bitlocker-1.dd -u jacqueline -- /bitlock`とすると復号ができ、ディスクイメージを得ることができる。\
今回の場合、ファイルシステムも存在し、`mount`から進めるのが定石になるのだが、原因不明のWSLの権限バグで`mount`ができなかったため、`fls+icat`コマンドでディスクイメージ内のファイルを読み取った。\
よってflagを得た