#include <stdio.h>

int main(void)
{
    char str_A[16], str_B[16];
    int D_A, D_B;
    int P_A = 0, P_B = 0;

    scanf("%s %d %s %d", str_A, &D_A, str_B, &D_B);

    for ( int i = 0; str_A[i] != NULL; i++ )
        if (str_A[i] - '0' == D_A)
            P_A = P_A * 10 + D_A;
    
    for ( int i = 0; str_B[i] != NULL; i++ )
        if ( str_B[i] - '0' == D_B )
            P_B = P_B * 10 + D_B;

    printf("%d\n", P_A + P_B);
    return 0;
}
