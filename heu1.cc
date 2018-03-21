#include <iostream>
#include <utility>
#include <queue>
using namespace std;

int g[6][6] = {
    {0, 1, 3, 5, 0, 0},
    {1, 0, 0, 0, 1, 0},
    {3, 0, 0, 0, 2, 1},
    {5, 0, 0, 0, 0, 5},
    {0, 1, 2, 0, 0, 5},
    {0, 0, 1, 5, 5, 0}
};

int op[6] = {0, 0, 0, 0, 0, 0};
int cost[6] = {4, 3, 1, 1, 3, 0};
int pre[6] = {-1, -1, -1, -1, -1, -1};

typedef pair<int, int> P;
pair<int, int> pp;

void search(int src) {
    priority_queue<P> q;
    pp.first = 0;
    pp.second = src;
    q.push(pp);
    op[src] = 1;
    while (! q.empty()) {
        pair<int, int> n;
        n = q.top();
        q.pop();
        op[n.second] = 1;
        cerr << "visiting " << - n.first << ' ' << n.second << endl;
        if (n.second == 5) break;
        for (int i = 0; i < 6; i++) {
            if ((g[n.second][i] != 0) && (op[i] == 0)) {
                pre[i] = n.second;
                pp.first = - cost[i];
                pp.second = i;
                q.push(pp);
                cerr << "push " << - pp.first << ' ' << pp.second << endl;
            }
        }
    }
}

void print_path(void) {
    int i = 5;
    cerr << "5";
    while (i > 0) {
        cerr << "<--" << pre[i];
        i = pre[i];
    }
    cerr << endl;
}

int main() {
    search(0);
    print_path();
}

