#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct Seperate;
typedef struct Seperate *Pos;

typedef struct Seperate {
    int n;
    Pos next;
    int br;
}_sep;

Pos Node();
void Put(int x, Pos P);
void Generator();
void Choice (int a, Pos A, Pos B);
void Place (int x, Pos P);
void PrintSc(Pos P);


int main(int argc, char* argv[])
{
    srand(time(NULL));
    Pos Even, Odd;
    Even=Node();
    Even->br=0;
    Odd=Node();
    Odd->br=0;
    printf("Generated numbers:\n");

    Generator(Even, Odd);

    printf("\nSorted lists:\n");
    printf("\nEven: ");

    PrintSc(Even);

    printf("\nOdd: ");

    PrintSc(Odd);

    printf("\nEnd of lists!\n");
    return 0;
}




Pos Node()
{
    Pos q = NULL;
    q =(Pos) malloc (sizeof(_sep));
    if(q==NULL) return -1;
    q->n=NULL;
    q->next=NULL;
    q->br=NULL;
    return q;
}

void Put(int x, Pos P)
{
    Pos q=Node();
    if(q==NULL) printf("\n***** Put:: No memory! *****\n");
    q->n=x;
    q->next=P->next;
    P->next=q;
}

void Generator(Pos A, Pos B)
{
    int x;
    x=50 + (rand()%31);
    printf("%d\n", x);
    while(A->br<1 || B->br<1)
        Choice(x, A, B);
}

void Choice(int x, Pos A, Pos B)
{
    if(x%2==0 && A->br<10)
    {
        A->br++;
        Place(x, A);
    }
    else if(x%2!=0 && B->br<10)
    {
        B->br++;
        Place(x, B);
    }
}

void Place (int x, Pos P)
{
    Pos q=P;
    if(q==NULL) printf("\n***** Place:: Sent Nonexistent List!! *****\n");
    while(q->next!=NULL && x<q->next->n)
        q=q->next;
    if(x==q->next->n)
        printf("\nElement exists in list!\n");
    else
        Put(x, q);
}

void PrintSc(Pos P)
{
    while(P->next!=NULL)
    {
        P=P->next;
        printf("%d ", P->n);
    }
}
