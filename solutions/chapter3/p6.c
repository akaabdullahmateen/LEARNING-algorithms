#include <stdlib.h>
#include <stdio.h>
struct Node;
typedef struct Node* List;
typedef struct Node* Position;
struct Node
{
    int Number;
    Position Next;
};
void Insert( int X , Position P )
{
    Position TmpCell;
    TmpCell = (struct Node*) malloc(sizeof(struct Node));
    TmpCell->Number = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}
void DeleteNext( Position P )
{
    Position TmpCell;
    TmpCell = P->Next;
    P->Next = TmpCell->Next;
    free(TmpCell);
}
int Josephus( int N , int M )
{
    List L;
    Position LastCell;
    int i, count=0;
    // Create a circularly linked list with N nodes
    L = (struct Node*) malloc(sizeof(struct Node));
    L->Number = 1;
    LastCell = L->Next = L;
    for ( i = 2 ; i <= N ; i++ ) {
        Insert( i , LastCell );
        LastCell = LastCell->Next;
    }
    // Perform the elimination process
    while ( L != L->Next ) {
        if ( ++count == M ) {
            DeleteNext(L);
            count = 0;
        }
        L = L->Next;
    }
    return L->Number;
}
int main()
{
    int N,M;
    scanf("%d %d" , &N , &M );
    printf("The winner is %d\n" , Josephus( N , M ));
    return 0;
}