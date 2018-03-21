#include <iostream>
using namespace std;
int main() {
    int A[4] = { 0, 1, 2, 3, };
    int i = 0;
    while (i < 4 && A[i] != 2) {
        cout << A[i] << endl;
        ++i;
    }
}
