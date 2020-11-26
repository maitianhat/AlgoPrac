#include <stdio.h>

int main() {
    int n;
    int num[3];
    scanf("%d", &n);
    for (int i = 0; i < 3; i++ ) {
        num[i] = n % 10;
        n /= 10;
    }
    for (int i = 2; i >= 0; i-- ) {
        for (int j = 1; j <= num[i]; j++) {
            switch(i) {
                case 2: putchar('B');   break;
                case 1: putchar('S');   break;
                case 0: putchar(j + '0');   break;
            }
        }
    }
    return 0;
}