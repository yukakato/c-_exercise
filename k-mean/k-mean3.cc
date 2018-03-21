#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

void classify(int n, int m) {
    srand((unsigned int)time(NULL));
    double o[n][2];      // 各データの座標
    double c[m][2];      // 各クラスタの重心
    int z[n], z_pre[n];  // 各データのクラスタラベル

    // 乱数で値を初期化
    for (int i = 0; i < n; ++i) {
        o[i][0] = rand() % 100;
        o[i][1] = rand() % 100;
        z[i] = rand() % m;
    }
    for (int i = 0; i < m; i++) {
        c[i][0] = rand() % 100;
        c[i][1] = rand() % 100;
    }

    // zの値が変化しなくなる（z == z_pre）まで繰り返す
    while (memcmp(z, z_pre, n) != 0) {
        // zを最も近いクラスタ代表点の値に変更
        for (int i = 0; i < n; ++i) {
            z_pre[i] = z[i];
            // oとcの距離を求める
            double d[m], tmp = 100000000;
            for (int j = 0; j < m; ++j) { 
                d[j] = pow((o[i][0] - c[j][0]),2) + pow((o[i][1] - c[j][1]),2);
                if (d[j] < tmp) {
                    tmp = d[j];
                    z[i] = j;
                }
            }
        }

        // 各クラスタの重心値を更新
        int x[m], y[m], num[m];
        for (int i = 0; i < m; ++i) {
            num[i] = 0;
            x[i] = 0;
            y[i] = 0;
            for (int j = 0; j < n; ++j) {
                if (z[j] == i) {
                    num[i]++;
                    x[i] += o[j][0];
                    y[i] += o[j][1];
                }
            }
            c[i][0] = x[i] / num[i];
            c[i][1] = y[i] / num[i];
        }

        // 各クラスタの重心値を出力
        for (int i = 0; i < m; ++i)
            cout << "(" << (int)c[i][0] << ", " << (int)c[i][1] << ") ";
        cout << endl;
    }
}

// main関数
int main() {
    classify(100, 5);  // データ数を引数に与える
}
