#include <stdio.h>
int main() {
    int year;
    while (~scanf("%d", &year)) {
        if (year % 4 == 0)
            printf("%d\n", 366);
        else
            printf("%d\n", 365);
    }
}
