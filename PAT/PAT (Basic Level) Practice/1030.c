#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100100

long compare( const void *a, const void *b );
long left( long num[], long n, long target);

long main(void)
{
    long N, p,user_n;
    long num[MAXN], Max[MAXN];

    scanf("%d%d", &N, &p);
    for ( long i = 0; i < N; i++ )
        scanf("%d", num + i);
    qsort(num, N, sizeof(long), compare);

    user_n = 0;
    do {
        Max[user_n] = left(num, N, p * num[user_n]) - user_n + 1;
    } while ( p * num[user_n++] < num[N - 1]);
    qsort(Max, user_n, sizeof(long), compare);

    printf("%d\n", Max[user_n - 1]);
    return 0;
}

long compare( const void *a, const void *b ) {
    return *(const long *)a - *(const long*)b;
}

long left( long num[], long n, long target) {
    long left = 0, right = n;

    while ( left < right ) {
        long mid = ( left + right ) >> 1;
        if ( target < num[mid] )
            right = mid;
        else
            left = mid + 1;
    }

    return left - 1;
}
