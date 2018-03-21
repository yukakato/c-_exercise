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
- bfs.cc: 幅優先探索（木は隣接行列で表現）
- ops1.cc: 最適探索
- ops2.cc: 最適探索（異なる木構造のとき）
- heu1.cc: 最良探索
- heu2.cc: 最良探索（異なる木構造のとき）
