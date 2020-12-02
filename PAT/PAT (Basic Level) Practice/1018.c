#include <stdio.h>

int main(void)
{
    int N;
    int num[2][6];
    char a, b;
    for ( int i = 0; i < 2; i++ )
        for ( int j = 0; j < 6; j++ )
            num[i][j] = 0;

    scanf("%d\n", &N);
    for ( int i = 0; i < N; i++ ) {
        scanf("%c %c\n", &a, &b);
        if ( (a == 'B' && b == 'C') || (a == 'C' && b == 'J') || (a == 'J' && b == 'B') ) {
            num[0][0] ++;
            num[1][2] ++;
            if ( a == 'B' )
                num[0][3] ++;
            else if ( a == 'C' )
                num[0][4] ++;
            else if ( a == 'J' )
                num[0][5] ++;
        }
        else if ( a == b ) {
            num[0][1] ++;
            num[1][1] ++;
        }
        else {
            num[0][2] ++;
            num[1][0] ++;
            if ( b == 'B' )
                num[1][3] ++;
            else if ( b == 'C' )
                num[1][4] ++;
            else if ( b == 'J' )
                num[1][5] ++;
        }
    }

    printf("%d %d %d\n", num[0][0], num[0][1], num[0][2]);
    printf("%d %d %d\n", num[1][0], num[1][1], num[1][2]);

    if ( num[0][3] >= num[0][4] && num[0][3] >= num[0][5] )
        printf("B ");
    else if ( num[0][4] >= num[0][5] )
        printf("C ");
    else
        printf("J ");
    
    if ( num[1][3] >= num[1][4] && num[1][3] >= num[1][5] )
        printf("B\n");
    else if ( num[1][4] >= num[1][5] )
        printf("C\n");
    else
        printf("J\n");
    return 0;
}
