#include <stdio.h>

int main(void)
{
    int N;
    char c;
    int per_height;
    scanf("%d %c", &N, &c);

    for ( per_height = 0; 2 * per_height * per_height - 1 <= N; per_height ++ );
    per_height--;

    for ( int i = per_height; i > 0; i-- ) {
        for ( int j = 0; j < per_height - i; j++ )
            printf(" ");
        for ( int j = 0; j < 2 * i - 1; j++)
            printf("%c", c);
        printf("\n");
    }

    for ( int i = 2; i <= per_height; i++ ) {
        for ( int j = 0; j < per_height - i; j++ )
            printf(" ");
        for ( int j = 0; j < 2 * i - 1; j++ )
            printf("%c", c);
        printf("\n");
    }

    printf("%d\n", N - ( 2 * per_height * per_height - 1 ));
    return 0;
}
