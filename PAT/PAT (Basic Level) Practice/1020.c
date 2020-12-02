#include <stdio.h>
#include <stdlib.h>

typedef struct _goods {
    double price;
    double weight;
    double Total_Price;
} goods;

int compare( const void *a, const void *b );

int main(void)
{
    int N, D;
    double Total_Weight = 0, sum = 0;
    goods Goods[1024];

    scanf("%d%d", &N, &D);
    for ( int i = 0; i < N; i++ )
        scanf("%lf", &Goods[i].weight);
    for ( int i = 0; i < N; i++ )
        scanf("%lf", &Goods[i].Total_Price);
    for ( int i = 0; i < N; i++ )
        Goods[i].price = Goods[i].Total_Price / Goods[i].weight;

    qsort(Goods, N, sizeof(goods), compare);

    for ( int i = 0; Total_Weight < D; i++ ) {
        if ( D - Total_Weight >= Goods[i].weight ) {
            sum = sum + Goods[i].Total_Price;
            Total_Weight = Total_Weight + Goods[i].weight;
        }
        else {
            sum = sum + ( D - Total_Weight ) * Goods[i].price;
            Total_Weight = Total_Weight + ( D - Total_Weight);
        }
    }
    printf("%.2f\n", sum);
    return 0;
}

int compare( const void *a, const void *b) {
    if ( ((const goods*)a)->price < ((const goods*)b)->price )
        return 1;
    else
        return -1;
}
