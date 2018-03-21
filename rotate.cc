#include <iostream>
#include <algorithm>
using namespace std;
int A[7] = {0, 1, 2, 3, 4, 5, 6};
int main() {
    rotate(A,A+3,A+7);
    for (int i = 0; i < 7; i++)
        cout << A[i] << " ";
    cout << endl;
}
