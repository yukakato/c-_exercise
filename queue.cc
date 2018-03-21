#include <iostream>
#include <queue>
using namespace std;
int main() {
    queue<int> q;
    q.push(3);
    q.push(4);
    q.push(1);
    while (! q.empty()) {
        int n = q.front();
        q.pop();
        cout << n << endl;
    }
}
