#include <stdio.h>
#include <stdlib.h>

#define MAXN 100100

typedef struct _person {
    char name[8];
    int year;
    int month;
    int day;
} person;

int compare( const void *a, const void *b );

int main(void)
{
    int count = 0, N;
    person Person[MAXN];
    scanf("%d\n", &N);
    for ( int i = 0; i < N; i++ ) {
        scanf("%s %d/%d/%d\n", Person[count].name, &Person[count].year, &Person[count].month, &Person[count].day);
        if ( Person[count].year > 2014 || (Person[count].year == 2014 && Person[count].month > 9) 
                || (Person[count].year == 2014 && Person[count].month == 9 && Person[count].day > 6) ||
             Person[count].year < 1814 || (Person[count].year == 1814 && Person[count].month < 9)
                || (Person[count].year == 1814 && Person[count].month == 9 && Person[count].day < 6) )
            ;
        else
            count++;
    }

    qsort(Person, count, sizeof(person), compare);
    if ( count == 0)
        printf("0\n");
    else
        printf("%d %s %s\n", count, Person[count - 1].name, Person[0].name);
    return 0;
}

int compare( const void *a, const void *b ) {
    int k;
    if ( ((const person*)a)->year < ((const person*)b)->year )
        k = 1;
    else if ( ((const person*)a) -> year > ((const person*)b) ->year )
        k = -1;
    else {
        if ( ((const person*)a) -> month < ((const person*)b) -> month )
            k = 1;
        else if ( ((const person*)a) -> month > ((const person*)b) -> month )
            k = -1;
        else {
            if ( ((const person*)a) -> day < ((const person*)b) -> day )
                k = 1;
            else
                k = -1;
        }
    }
    return k;
}
