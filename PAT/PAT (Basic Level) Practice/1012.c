#include <stdio.h>
#include <stdbool.h>

#define MAXN 5

int A2 = 1, A4 = 0;

int main(void)
{
    int N, A[MAXN], num;
    bool flag[MAXN];

    for (int i = 0; i < MAXN; i++ ) {
        A[i] = 0;
        flag[i] = false;
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &num);
        switch(num%5) {
        case 0:
            if (num % 2 == 0) {
                flag[0] = true;
                A[0] += num;
            }
            break;
        case 1: flag[1] = true; A[1] += A2 * num; A2 *= -1; break;
        case 2: flag[2] = true; A[2] ++; break;
        case 3: flag[3] = true; A[3] += num; A4++; break;
        case 4: flag[4] = true; A[4] = A[4] < num ? num : A[4]; break;
        }
    }

    for ( int i = 0; i < MAXN; i++ ) {
        if ( flag[i] ) {
            if ( i != 3 )
                printf("%d", A[i]);
            else
                printf("%.1f", A[i] * 1.0 / A4);
        }
        else
            printf("N");
        printf("%c", i == MAXN - 1 ? '\n' : ' ');
    }
    return 0;
}
