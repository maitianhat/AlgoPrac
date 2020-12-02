#include <stdio.h>

int main(void)
{
    int count;
    long a, b, c;

    scanf("%d", &count);
    for ( int i = 1; i <= count; i++ ) {
        scanf("%ld%ld%ld", &a, &b, &c);
        if ( a + b > c )
            printf("Case #%d: true\n", i);
        else
            printf("Case #%d: false\n", i);
    }
    return 0;
}
