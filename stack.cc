#include <iostream>
#include <stack>
using namespace std;
int main() {
    stack<int> s;
    s.push(3);
    s.push(4);
    s.push(1);
    while (! s.empty()) {
        int n = s.top();
        s.pop();
        cout << n << endl;
    }
}
