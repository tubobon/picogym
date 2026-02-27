# Operation Orchid
## 解法バイナリを書き換えた
fileコマンドでdataと出たからxxdでバイナリ確認するとマジックナンバーが壊れていた\
IHDRとかあったため、PNGと推定、`dd`コマンドでバイナリを書き換えた\
復元したPNGを見ると、真っ赤な画像が出てきた。\
`exiftool`,`pngcheck`,`zsteg`,`binwalk`,`foremost`,`strings`に加えStegsolveでLSBを見てみるなどあらゆる策を講じたが全敗。\
おとなしくWriteupを見ると、どうやら一部の色調が異なり文字が現れているらしい。\
ApperiSolveで確認すると、確かにflagを見つけることができた。\
結論としては、Apperisolve最強やん（エラー返さない限りは）。あとついでにこいつクソ問やんと思った。