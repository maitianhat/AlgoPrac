#include <stdio.h>
#include <string.h>

char number[10][8] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main(int argc, char const *argv[]) {
    char ch;
    int sum = 0;
    while ( scanf("%c", &ch)  && ch != '\n' )
        sum = sum + ch - '0';
    
    char s_num[10];
    sprintf(s_num, "%d", sum);
    for (int i = 0; i < strlen(s_num); i++) {
        printf("%s", number[s_num[i] - '0']);
        if ( i != strlen(s_num) - 1)
            putchar(' ');
    }
    putchar('\n');
    return 0;
}