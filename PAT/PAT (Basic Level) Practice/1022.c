#include <stdio.h>

int main(void)
{
    int a, b, D;
    int sum, num[128], i = 0;
    scanf("%d%d%d", &a, &b, &D);
    
    sum = a + b;

    do {
        num[i] = sum % D;
        sum /= D;
        i ++;
    } while ( sum );

    for ( i--; i >= 0; i-- )
        printf("%d", num[i]);
    printf("\n");
    return 0;
}
