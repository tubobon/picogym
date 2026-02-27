# DISKO3
## 解法
fileコマンド、fsstatコマンドでファイルシステムがあることを確認。ちなみにFAT32\
mmlsコマンドを実行しても反応がないことから、パーティションテーブルが存在しない = 一つのかたまりと推定\
offsetはわからないが、offsetが0の場合の可能性が高いため、\
`sudo mount -o loop disk.img /mnt`\
と試しにmountすると普通にできた。\
中身を見ると、`flag.gz`といういかにも怪しげなファイルがあったため、`gzip -d flag.gz`で解凍、flagを得た
