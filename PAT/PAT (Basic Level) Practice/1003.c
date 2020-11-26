#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool judge( );

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d\n", &n);
    for ( int i = 0; i < n; i++ )
        if ( judge( ) )
            printf("YES\n");
        else
            printf("NO\n");
    return 0;
}

bool judge( ) {
    bool res = true;
    char str[128];
    int Count_P = 0, Count_T = 0;
    size_t local_P, local_T, len;
    int num_before, num_middle, num_last;

    scanf("%s\n", str);
    len = strlen(str);
    for (size_t i = 0; i < len; i++) {
        if ( str[i] == 'P' && Count_P++ == 0 )
            local_P = i;
        else if ( str[i] == 'T' && Count_T++ == 0 )
            local_T = i;
        else if ( str[i] == 'A' )
            ;
        else
            res = false;
    }

    if ( Count_P > 1 || Count_T > 1 )
        res = false;

    num_before = local_P;
    num_middle = local_T - local_P - 1;
    num_last   = len - local_T - 1;

    if ( num_middle != 0 && num_last == num_before * num_middle )
        ;
    else
        res = false;
    
    return res;
}
