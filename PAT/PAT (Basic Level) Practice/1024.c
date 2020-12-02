#include <stdio.h>
#include <string.h>

#define MAXN 10010

int main(void)
{
    char str[MAXN];
    int count = 0, i, sum = 0, len;
    char flag1, a, b[MAXN], flag2, c[MAXN];
    scanf("%s", str);

    flag1 = str[count++];       // "[+-]"
    a = str[count++];           // "[1-9]"
    count++;                    // "."
    for ( i = 0; str[count] != 'E'; count++, i++)   // "[0-9]+"
        b[i] = str[count];
    b[i] = '\0';
    count++;                    // "E"
    flag2 = str[count++];       // "[+-]"
    for ( i = 0; str[count]; count++, i++)          // "[0-9]+"
        c[i] = str[count];
    c[i] = '\0';

    for ( i = 0; c[i]; i++ )
        sum = sum * 10 + c[i] - '0';

    if ( flag1 == '-')
        printf("-");
    if ( sum == 0 ) {
        printf("%c.%s", a, b);
    }
    else {
        if ( flag2 == '-' ) {
            printf("0.");
            for ( i = 0; i < sum - 1; i++ )
                printf("0");
            printf("%c%s", a, b);
        }
        else {
            printf("%c", a);
            len = strlen(b);
            if ( len <= sum ) {
                printf("%s", b);
                for ( i = 0; i < sum - len; i++ )
                    printf("0");
            }
            else {
                for ( i = 0; i < sum; i++ )
                    printf("%c", b[i]);
                printf(".%s", b + i);
            }
        }
    }
    printf("\n");
    return 0;
}
