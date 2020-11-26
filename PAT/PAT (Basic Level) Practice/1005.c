#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAXN 128

int num[MAXN];

void Callatz( int t );

int main(int argc, char const *argv[]) {
    int n, temp;
    bool flag = true;
    scanf("%d", &n);

    memset (num, -1, sizeof(int) * MAXN);
    while ( n-- ) {
        scanf("%d", &temp);
        num[temp] = 1;
    }
    for ( int i = 0; i < MAXN; i++ ) {
        if ( num[i] == 1 )
            Callatz(i);
    }

    for ( int i = 127; i >= 2; i-- ) {
        if ( num[i] == 1 ) {
            if ( flag )
                flag = false;
            else
                putchar(' ');
            printf("%d", i);
        }
    }
    putchar('\n');
    return 0;
}

void Callatz( int t ) {
    while ( t != 1 ) {
        if ( t % 2 )
            t = 3 * t + 1;
        t /= 2;
        if ( t < 128 ) {
            if (num[t] == 0)
                return;
            else
                num[t] = 0;
        }
    }
}
