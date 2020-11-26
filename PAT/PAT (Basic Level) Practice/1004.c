#include <stdio.h>

struct _stu {
    char    name[16];
    char    num[16];
    int     grade;
} Max, Min, temp;

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);

    Max.grade = -1;
    Min.grade = 101;
    while ( n-- ) {
        scanf("%s %s %d\n", temp.name, temp.num, &temp.grade);
        if ( temp.grade > Max.grade )
            Max = temp;
        if ( temp.grade < Min.grade )
            Min = temp;
    }
    printf("%s %s\n%s %s\n", Max.name, Max.num, Min.name, Min.num);
    return 0;
}