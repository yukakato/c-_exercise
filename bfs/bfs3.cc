#include <iostream>
#include <string>
#include <queue>
#include <cstdlib>
#include <math.h>
using namespace std;

void search(int src, int n, vector<string> v) {
    // vector型から2次元配列に変換
    int g[n][n], op[n], k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g[i][j] = atoi(v[k].c_str());
            k++;
        }
        op[i] = 0;
    }

    // 初期状態をオープンリストに入れる
    queue<int> q;
    q.push(src);
    op[src] = 1;

    // オープンリストが空でない限り以下を実行
    while (! q.empty()) {
        // オープンリストから先頭の要素sを取り出す
        int s = q.front();
        q.pop();
        // クローズドリストの書き出し
        cerr << "visiting " << s << endl;
        // sからの接続状態を調べる
        for (int i = 0; i < n; i++) {
            // sと接続している && まだ探査していない
            if ((g[s][i] == 1) && (op[i] == 0)) {
                // オープンリストに入れる
                q.push(i);
                // 探査済みのフラグを立てる
                op[i] = 1;
            }
        }
    }
}

int main() {
    // 標準入力から接続行列のデータを読み込む
    vector<string> v;
    string word;
    while (getline(cin, word, ',')) v.push_back(word);
    int n = static_cast<int>(sqrt(v.size()));
    // 検索処理
    search(0, n, v);
}
