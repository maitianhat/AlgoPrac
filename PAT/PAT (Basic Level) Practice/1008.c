#include <stdio.h>
#include <stdbool.h>

bool flag = true;

void Output ( int num );

int main(int argc, char const *argv[]) {
    int N, M;
    int pNum[128];

    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%d", pNum + i);
    
    M = M % N;
    for (int i = N - M; i < N; i++)
        Output(pNum[i]);
    for (int i = 0; i < N - M; i++)
        Output(pNum[i]);
    putchar('\n');

    return 0;
}

void Output ( int num ) {
    if ( flag )
        flag = false;
    else
        putchar(' ');
    printf("%d", num);
}
