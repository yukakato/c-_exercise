#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

void classify(int n) {
    srand((unsigned int)time(NULL));
    double o[n][2];      // 各データの座標
    double c[2][2];      // 各クラスタの重心
    int z[n], z_pre[n];  // 各データのクラスタラベル

    // 乱数で値を初期化
    for (int i = 0; i < n; ++i) {
        o[i][0] = rand() % 100;
        o[i][1] = rand() % 100;
        z[i] = rand() % 2;
    }
    for (int i = 0; i < 2; i++) {
        c[i][0] = rand() % 100;
        c[i][1] = rand() % 100;
    }

    // zの値が変化しなくなる（z == z_pre）まで繰り返す
    while (memcmp(z, z_pre, n) != 0) {
        // 最も近いクラスタ代表点の値を1に変更
        for (int i = 0; i < n; ++i) {
            z_pre[i] = z[i];
            // oとcの距離を求める
            double d1 = pow((o[i][0] - c[0][0]),2) + pow((o[i][1] - c[0][1]),2);
            double d2 = pow((o[i][0] - c[1][0]),2) + pow((o[i][1] - c[1][1]),2);
            if (d1 > d2) z[i] = 1;
            else z[i] = 0;
        }

        // 各クラスタの重心値を更新
        int n0 = 0, n1 =0;
        double x0 = 0, y0 = 0, x1 = 0, y1 = 0;
        for (int i = 0; i < n; ++i) {
            if (z[i] == 0) {
                n0++;
                x0 += o[i][0];
                y0 += o[i][1];
            }
            else {
                n1++;
                x1 += o[i][0];
                y1 += o[i][1];
            }
        }
        c[0][0] = x0 / n0;
        c[0][1] = y0 / n0;
        c[1][0] = x1 / n1;
        c[1][1] = y1 / n1;

        // 各座標の値をクラスタごとに出力
        cout << "cluster1" << endl;
        for (int i = 0; i < n; ++i)
            if (z[i] == 0)
                cout << "(" << o[i][0] << ", " << o[i][1] << "), ";
        cout << endl;
        cout << "cluster2" << endl;
        for (int i = 0; i < n; ++i)
            if (z[i] == 1)
                cout << "(" << o[i][0] << ", " << o[i][1] << "), ";
        cout << endl;

        // 各クラスタの重心値を出力
        cout << "weight" << endl;
        cout << "(" << (int)c[0][0] << ", " << (int)c[0][1] << ") " << 
                "(" << (int)c[1][0] << ", " << (int)c[1][1] << ")" << endl;
        cout << endl;
    }
}

// main関数
int main() {
    classify(100);  // データ数を引数に与える
}
