#include <stdio.h>

int main(void)
{
    char day[7][5] = {
        "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"
    };
    int DAY = -1, HH = -1, MM = -1;
    char str[4][64];
    for ( int i = 0; i < 4; i++ )
        scanf("%s", str[i]);
    
    for ( int i = 0; str[0][i] != NULL && str[1][i] != NULL; i++ ) {
        if ( str[0][i] == str[1][i] ) {

            if ( DAY == -1 && str[0][i] >= 'A' && str[0][i] <= 'G')
                DAY = str[0][i] - 'A';

            else if ( DAY != -1 && HH == -1 ) {
                if ( str[0][i] >= '0' && str[0][i] <= '9')
                    HH = str[0][i] - '0';
                else if ( str[0][i] >= 'A' && str[0][i] <= 'N')
                    HH = str[0][i] - 'A' + 10;
                // printf("%c\n", str[0][i]);
            }

        }
    }

    for ( int i = 0; MM == -1 && str[2][i] != NULL && str[3][i] != NULL; i++ ) {
        if ( str[2][i] == str[3][i] && ((str[2][i] >= 'A' && str[2][i] <= 'Z') || (str[2][i] >= 'a' && str[2][i] <= 'z')) )
            MM = i;
    }

    printf("%s %02d:%02d\n", day[DAY], HH, MM);
    return 0;
}
