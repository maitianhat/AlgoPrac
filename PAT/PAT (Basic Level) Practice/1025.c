#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100100

typedef struct _node {
    int data;
    int next;
} Node;

int reverList( Node *list, int rev_num, int head, int N );
void printList( Node *list, int head );

int main(void)
{
    int Head, N, rev_num;
    int add_front, add_next, number;
    int next, num = 1;
    Node list[MAXSIZE];
    scanf("%d%d%d", &Head, &N, &rev_num);

    for ( int i = 0; i < N; i++ ) {
        scanf("%d%d%d", &add_front, &number, &add_next);
        list[add_front].data = number;
        list[add_front].next = add_next;
    }

    next = Head;
    while ( list[next].next != -1 ) {
        next = list[next].next;
        num++;
    }

    if ( rev_num > 1 )
        Head = reverList(list, rev_num, Head, num);
    
    printList(list, Head);

    return 0;
}

int reverList( Node *list, int rev_num, int head, int N ) {
    int i, flag = 1;
    int last_head;

    int rev_head = head;
    int mid_head = head;
    int mid_next;

    while ( N - rev_num >= 0 ) {
        N -= rev_num;

        for ( i = 0; i < rev_num - 1; i++ ) {
            mid_next = list[rev_head].next;
            list[rev_head].next = list[mid_next].next;
            list[mid_next].next = mid_head;
            mid_head = mid_next;
        }

        if ( flag == 0 ) {
            list[last_head].next = mid_head;
        }

        if ( flag ) {
            head = mid_head;
            flag = 0;
        }

        last_head = rev_head;
        rev_head = list[rev_head].next;
        mid_head = rev_head;
    }

    return head;
}

void printList( Node *list, int head ) {
    while ( list[head].next != -1 ) {
        printf("%05d %d %05d\n", head, list[head].data, list[head].next);
        head = list[head].next;
    }

    printf("%05d %d -1\n", head, list[head].data);
}
