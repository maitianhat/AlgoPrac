#include <math.h>
#include <stdio.h>
#include <stdbool.h>

bool IsPrime ( int num );

int main(int argc, char const *argv[]) {
    int n, count = 0;
    scanf("%d", &n);
    if ( n < 5 )
        putchar('0');
    else {
        for ( int i = 3; i + 2 <= n; i += 2 ) {
            if (IsPrime(i) && IsPrime(i + 2)) {
                count ++;
            }
        }
        printf("%d", count);
    }
    return 0;
}

bool IsPrime ( int num ) {
    int m = floor(sqrt(num) + 0.5);
    for ( int i = 3; i <= m; i ++ )
        if (num % i == 0)
            return false;
    return true;
}