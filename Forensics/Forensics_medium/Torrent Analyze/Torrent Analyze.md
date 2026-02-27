# Torrent Analyze
## 解法
典型的なwireSharkの問題。ファイル名を探す問題で末尾が`.iso`のファイルであるため、とりあえず怪しそうな`BT-DHT`（ユーザ同士でファイル共有するプロトコル）を探すとInfo-hashというものがある。\
このhashは共有ファイルのメタ情報をハッシュ化したもので、`https://btdig.com/e2467cbf021192c241367b892230dc1e05c0580e`のようなトレント検索エンジンで検索可能。\
hashを何個か試してみると末尾が`iso`のファイルを発見。ハッシュ値は`e2467cbf021192c241367b892230dc1e05c0580e`\
よってflagを得た。`picoCTF{ubuntu-19.10-desktop-amd64.iso}`