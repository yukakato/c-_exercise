#include <iostream>
#include <algorithm>
using namespace std;
int A[5] = {3, 5, 1, 2, 4};
int main() {
    sort(A, A+5);
    reverse(A, A+5);
    for (int i = 0; i < 5; i++)
        cout << A[i] << " ";
    cout << endl;
}
