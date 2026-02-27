# ReadMyCert
CSRファイルの解析には`openssl`コマンドを用いる

`openssl req -in ReadMyCert.csr -noout -text` とすることでCSRファイルの情報をtext形式で得ることができた。\
フラグは内部にあった。`picoCTF{read_mycert_41d1c74c}`
