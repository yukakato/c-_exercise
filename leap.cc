#include <iostream>
using namespace std;
int main() {
    int year;
    while (cin >> year) {
        if (year % 4 == 0)
            cout << 366 << endl;
        else
            cout << 365 << endl;
    }
}
