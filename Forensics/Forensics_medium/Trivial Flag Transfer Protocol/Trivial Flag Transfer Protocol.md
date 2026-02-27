# Trivial Flag Transfer Protocol
## 解法
パケットキャプチャの問題。\
TFTPプロトコルは、単純ファイル転送のプロトコルで、暗号化を特にせずにただ転送するプロトコル。\
そのため作問者はflagの転送に一工夫いれたという。TFTPの転送ファイルはオブジェクトのエクスポートで保存することができ、今回はいくつかのasciiファイルとbmpファイルを入手した。
`instructions.txt`と`plan`にはそれぞれROT13暗号化が入ったテキストが用意されていて復号すると、
```
TFTPDOESNTENCRYPTOURTRAFFICSOWEMUSTDISGUISEOURFLAGTRANSFER.FIGUREOUTAWAYTOHIDETHEFLAGANDIWILLCHECKBACKFORTHEPLAN
(TFTPは通信を暗号化しないため、フラグの転送を隠装する必要があります。フラグを隠す方法を考えておいてください。後で計画を確認しに来ます。)
IUSEDTHEPROGRAMANDHIDITWITH-DUEDILIGENCE.CHECKOUTTHEPHOTOS
(そのプログラムを使い、「デューデリジェンス」をもってそれを隠しました。写真を確認してください。)
```
よって3つのbmpに対し、`steghide extract -sf picture.bmp -p DUEDILIGENCE`をかけると`picture3.bmp`で`flag.txt`を発見。\
flagを得た。`picoCTF{h1dd3n_1n_pLa1n_51GHT_18375919}`
