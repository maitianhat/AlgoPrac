#include <stdio.h>
#include <stdbool.h>

bool IsPrime( int n );

int main(void)
{
    int count = 0, prime = 2;
    int M, N;
    scanf("%d%d", &M, &N);

    while ( count < M - 1) {
        if ( IsPrime(prime) )
            count++;
        prime++;
    }

    for ( int i = 1; M <= N; ) {
        if ( IsPrime(prime) ) {
            printf("%d", prime);
            if ( M != N )
                printf("%c", i % 10 ? ' ' : '\n');
            i++; M++;
        }
        prime++;
    }
    return 0;
}

bool IsPrime( int n ) {
    for ( int i = 2; (long)i * i <= n; i++ ) {
        if ( n % i == 0 )
            return false;
    }
    return true;
}