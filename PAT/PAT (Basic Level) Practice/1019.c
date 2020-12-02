#include <stdio.h>
#include <string.h>

#define Kaprekar 6174

void GetNum(int num, int A[]);
int  getMin(int A[]);
int  getMax(int A[]);

int main(void)
{
    int ans, Min, Max;
    int num[10];
    scanf("%d", &ans);
    do {
        GetNum(ans, num);
        Min = getMin(num);
        Max = getMax(num);
        ans = Max - Min;
        printf("%04d - %04d = %04d\n", Max, Min, ans); 
    } while ( ans != 0 && ans != Kaprekar );
    return 0;
}

void GetNum(int num, int A[]) {
    memset(A, 0, sizeof(int) * 10);
    for ( int i = 0; i < 4; i++ ) {
        A[num % 10] ++;
        num /= 10;
    }
}

int  getMin(int A[]) {
    int res = 0;
    for ( int i = 0; i < 10; i++ ) {
        for ( int j = 0; j < A[i]; j++ )
            res = res * 10 + i;
    }
    
    return res;
}

int  getMax(int A[]) {
    int res = 0;
    for ( int i = 9; i >= 0; i-- ) {
        for ( int j = 0; j < A[i]; j++ )
            res =  res * 10 + i;
    }

    return res;
}
