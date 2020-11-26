#include <stdio.h>

#define MAXN 1024

struct Term {
    int para;
    int index;
} term[MAXN];

int main(int argc, char const *argv[]) {
    int cnt = 0, flag = 0;
    while (scanf("%d%d", &term[cnt].para, &term[cnt].index) == 2) {
        term[cnt].para = term[cnt].para * term[cnt].index;
        term[cnt].index -= 1;
        cnt++;
    }

    if ( cnt == 1 && term[0].para == 0 )
        printf("0 0\n");
    else {
        for (int j = 0; j < cnt; j++) {
            if ( term[j].para != 0) {
                if ( flag++ != 0)
                    putchar(' ');
                printf("%d %d", term[j].para, term[j].index);
            }
        }
        putchar('\n');
    }
    return 0;
}