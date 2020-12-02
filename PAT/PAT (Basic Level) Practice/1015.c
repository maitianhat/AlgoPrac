#include <stdio.h>
#include <stdlib.h>

#define MAXN 100100
typedef struct _stu {
    int name;
    int score_a;
    int score_b;
    int sum;
    int flag;
} stu;

int compare( const void *a, const void *b );

int main(void)
{
    stu num[MAXN];
    int a, b, c, d;
    int N, L, H;

    scanf("%d%d%d", &N, &L, &H);
    a = b = c = d = 0;

    for ( int i = 0; i < N; i++ ) {
        scanf("%d%d%d", &num[i].name, &num[i].score_a, &num[i].score_b);
        num[i].sum = num[i].score_a + num[i].score_b;
        if ( num[i].score_a >= H ) {
            if ( num[i].score_b >= H ) {
                num[i].flag = 1;
                a ++;
            }
            else if ( num[i].score_b >= L ) {
                num[i].flag = 2;
                b ++;
            }
        }
        else if ( num[i].score_a >= L  && num[i].score_b >= L ) {
            if ( num[i].score_a >= num[i].score_b ) {
                num[i].flag = 3;
                c ++;
            }
            else {
                num[i].flag = 4;
                d ++;
            }
        }
    }

    printf("%d\n", a + b + c +d);
    qsort(num, N, sizeof(stu), compare);

    for( int i = 1; i <= 4; i++ ) {
        for ( int j = 0; j < N; j++ ) {
            if ( num[j].flag == i )
                printf("%d %d %d\n", num[j].name, num[j].score_a, num[j].score_b);
        }
    }

    return 0;
}

int compare( const void *a, const void *b ) {
    int k;
    if ( ((const struct _stu*)a)->sum < ((const struct _stu*)b)->sum )
        k = 1;
    else if ( ((const struct _stu*)a) -> sum > ((const struct _stu*)b)->sum )
        k = -1;
    else {
        if ( ((const struct _stu*)a)->score_a < ((const struct _stu*)b) -> score_a )
            k = 1;
        else if ( ((const struct _stu*)a)->score_a > ((const struct _stu*)b) -> score_a )
            k = -1;
        else {
            if ( ((const struct _stu*)a) -> name > ((const struct _stu*)b) -> name)
                k = 1;
            else
                k = -1;
        }
    }
    return k;
}
