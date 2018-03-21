#include <iostream>
#include <stack>
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
    stack<int> st;
    st.push(src);
    op[src] = 1;
    while (! st.empty()) {
        int s = st.top();
        st.pop();
        cerr << "visiting " << s << ' ' << op[s] << endl;
        for (int i = 0; i < 5; i++) {
            if ((g[s][i] == 1) && (op[i] == 0)) {
                st.push(i);
                op[i] = 1;
            }
        }
    }
}

int main() {
    search(0);
}
