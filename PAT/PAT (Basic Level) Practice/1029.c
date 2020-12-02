#include <stdio.h>
#include <string.h>

void fun(int len, char str[], int num[]);

int main(void)
{
    int n_before[64], n_after[64], len;
    char before[128], after[128];
    scanf("%s%s", before, after);

    memset(n_before, 0, sizeof(int) * 64);
    memset(n_after, 0, sizeof(int) * 64);

    fun( strlen(before), before, n_before );
    fun( strlen(after), after, n_after );

    len = strlen(before);
    for ( int i = 0; i < len; i++ ) {
        char c = before[i];
        if ( c >= '0' && c <= '9' ) {
            if ( 0 == n_after[c - '0'] && n_before[c - '0'] != 0 ) {
                n_before[c - '0'] = 0;
                printf("%c", c);
            }
        }

        if ( c >= 'A' && c <= 'Z' ) {
            if ( 0 == n_after[c - 'A' + 10] && n_before[c - 'A' + 10] != 0 ) {
                n_before[c - 'A' + 10] = 0;
                printf("%c", c);
            }
        }

        if ( c >= 'a' && c <= 'z' ) {
            // printf("%c", c);
            if ( 0 == n_after[c - 'a' + 10] && n_before[c - 'a' + 10] != 0 ) {
                n_before[c - 'a' + 10] = 0;
                printf("%c", c - 'a' + 'A');
            }
        }

        if ( c == '_' ) {
            if ( 0 == n_after[26 + 10] && n_before[26 + 10] != 0 ) {
                n_before[26 + 10] = 0;
                printf("%c", c);
            }
        }
    }
    printf("\n");
    return 0;
}

void fun( int len, char before[], int n_before[]) {
    for ( int i = 0; i < len; i++ ) {
        if ( before[i] >= '0' && before[i] <= '9' )
            n_before[before[i] - '0'] ++;
        else if ( before[i] >= 'A' && before[i] <= 'Z')
            n_before[before[i] - 'A' + 10] ++;
        else if ( before[i] >= 'a' && before[i] <= 'z')
            n_before[before[i] - 'a' + 10] ++;
        else if ( before[i] == '_' )
            n_before[10 + 26]++;
    }
}