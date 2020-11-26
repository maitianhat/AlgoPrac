#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char const *argv[]) {
    char str[128];
    bool flag = true;

    gets(str + 1);
    str[0] = ' ';

    for ( int i = strlen(str); i >= 0; i-- ) {
        if ( str[i] == ' ' ) {
            if ( flag )
                flag = false;
            else
                putchar(' ');
            printf("%s", str + i + 1);
            str[i] = '\0';
        }
    }
    return 0;
}