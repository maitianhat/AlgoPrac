#include <stdio.h>

int main(void)
{
    char str[1024];
    int B;
    int Q;
    scanf("%s %d", str, &B);
    
    Q = str[0] - '0';
    if ( str[1] == NULL) {
        printf("%d %d\n", Q/B, Q%B);
        return 0;
    }

    for (int i = 1; str[i]; i++ ) {
        Q = Q * 10 + str[i] - '0';
        printf("%d", Q/B);
        Q = Q%B;
    }
    printf(" %d", Q);
    return 0;
}
