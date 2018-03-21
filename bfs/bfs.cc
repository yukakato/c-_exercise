#include <iostream>
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
    search(0);
}
