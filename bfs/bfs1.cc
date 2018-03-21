#include <iostream>
#include <fstream>
#include <string>
#include <queue>
using namespace std;

int g[5][5] = {
    {0, 1, 1, 0, 0},
    {1, 0, 0, 1, 1},
    {1, 0, 0, 1, 0},
    {0, 1, 1, 0, 1},
    {0, 1, 0, 1, 0}
};
int op[5] = {0, 0, 0, 0, 0};

void search(int src) {
    queue<int> q;
    q.push(src);
    op[src] = 1;
    while (! q.empty()) {
        int s = q.front();
        q.pop();
        cerr << "visiting " << s << ' ' << op[s] << endl;
        for (int i = 0; i < 5; i++) {
            if ((g[s][i] == 1) && (op[i] == 0)) {
                q.push(i);
                op[i] = 1;
            }
        }
    }
}

int main() {
    ifstream ifs("bfs_array.txt");
    string str;

    if (ifs.fail()) {
        cerr << "File do not exist." << endl;
        exit(0);
    }

    int a = 0, b = 0, c = 0, d = 0, e = 0;
    while(getline(ifs, str)) {
        sscanf(str.data(), "%d, %d, %d, %d, %d", &a, &b, &c, &d, &e);
        cout << "a= " << a << endl;
        cout << "b= " << b << endl;
        cout << "c= " << c << endl;
        cout << "d= " << d << endl;
        cout << "e= " << e << endl;
    }
    search(0);
}
