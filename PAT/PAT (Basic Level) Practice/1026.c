#include <stdio.h>

#define PARAM 100
int main(void)
{
    int c1, c2;
    int time;
    int hh, mm, ss;
    scanf("%d%d", &c1, &c2);

    time = c2 - c1;
    if ( time % 100 >= 50 )
        time = time / 100 + 1;
    else
        time = time / 100;
    
    ss = time % 60;
    time = time / 60;

    mm = time % 60;
    hh = time / 60;

    printf("%02d:%02d:%02d\n", hh, mm, ss);
    return 0;
}
