# C++演習用プログラム
### コンパイル方法

```
$ g++ -Wall sample.cc
$ ./a.out
```

### ファイル構成
- leap.c: 最初のプログラムC版（年を読み込んでうるう年か判定し，日数を出力）
- leap.cc: 最初のプログラムC++版
  - リダイレクションとファイルを用いたテスト

  ```
  $ cat > years.input
  2004
  1999
  1900
  2000
  ^C
  $ ./a.out < years.input > years.output
  $ cat years.output
  366
  365
  366
  366
  ```

- loop1.cc: 配列，ループ，条件分岐（その1）
- loop2.cc: 配列，ループ，条件分岐（その2）
- func.cc: 関数
- vector.cc: 配列の長さを実行時に決めるvector
- sort.cc: sort
- reverse.cc: reverse
- rotate.cc: rotate
- string.cc: 基本データ構造string
- stack.cc: 基本データ構造stack
- queue.cc: 基本データ構造queue
- priorityqueue.cc: 基本データ構造priorityqueue
- dfs.cc: 深さ優先探索（木は隣接行列で表現）
- bfs（幅優先探索，木は隣接行列で表現）
  - bfs.cc: 基本形
  - bfs1.cc: 出力結果を追加
  - bfs2.cc: ファイル読み込み版
  - bfs3.cc: コードの見直し
- ops1.cc: 最適探索
- ops2.cc: 最適探索（異なる木構造のとき）
- heu1.cc: 最良探索
- heu2.cc: 最良探索（異なる木構造のとき）
- ast1.cc: A*アルゴリズム
- ast2.cc: A*アルゴリズム（異なる木構造のとき）
- dp（動的計画法）
  - dp.cc: ひな型
  - dp1.cc: 1ステップ目まで
  - dp2.cc: コストの設定
  - dp3.cc: 14ステップ目まで
- edit（編集距離）
  - edit1.cc: 基本形
  - edit2.cc: コードの整理
  - edit3.cc: コードの整理
  - edit4.cc: 任意の文字列をキーボードから入力
- ql（強化学習）
  - ql1.cc, ql1_rand1.cc: ひな型（Q値を乱数で初期化，結果の出力なし）
  - ql2.cc, ql2_rand.cc: グリーディ法で10回遷移させる
  - ql3.cc, ql3_rand.cc: Q値の更新，2回出力させて比較，報酬なし
  - ql4.cc, ql4_rand.cc: 報酬の追加，10000回学習させる
  - ql5.cc, ql5_rand.cc: ランダム選択
  - ql6.cc, ql6_rand.cc: ε-greedy法
- k-mean法
  - k-mean1.cc: 点の分類，2クラスタ
  - k-mean2.cc: 点の分類，2クラスタ，コードの整理
  - k-mean3.cc: 点の分類，任意のクラスタ
  - k-mean.cc: 画像の減色
