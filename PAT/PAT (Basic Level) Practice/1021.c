#include <stdio.h>

int main(void)
{
    char str[1024];
    int num[10];
    
    for ( int i = 0; i < 10; i++ )
        num[i] = 0;
    scanf("%s", str);
    
    for ( int i = 0; str[i]!=NULL; i++) {
        num[str[i] - '0'] ++;
    }
    
    for ( int i = 0; i < 10; i++ ) {
        if (num[i] != 0)
            printf("%d:%d\n", i, num[i]);
    }
    return 0;
}