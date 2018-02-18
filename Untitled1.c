#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


struct Seperate;
typedef struct Seperate *Pos;

typedef struct Seperate {
    int n;
    Pos next;
    int br;
}_sep;

Pos Node();
void Put(int x, Pos P);
void Generator(int min, int max, Pos A, Pos B, int size);
void Choice(int x, Pos A, Pos B, int size);
void Place (int x, Pos P);
void PrintSc(Pos P);
void Range_Size(int* x, int* y, int* z);
bool MemoryCheck(Pos P);

int main(int argc, char* argv[])
{
    srand(time(NULL));

    int min=0, max=0, size=0;
    Pos Even=NULL, Odd=NULL;

    Even=Node();
    Odd=Node();
    if(MemoryCheck(Even) || MemoryCheck(Odd));

    else
    {
        Range_Size(&min, &max, &size);
        printf("Generated numbers:\n");

        Generator(min, max, Even, Odd, size);

        printf("\nSorted lists:\n");

        printf("\nEven: ");

        PrintSc(Even);

        printf("\nOdd: ");

        PrintSc(Odd);

        printf("\nEnd of lists!\n");
    }
    return 0;
}


Pos Node()
{
    Pos q = NULL;
    q =(Pos) malloc (sizeof(_sep));
    if(MemoryCheck(q));
    else
    {
        q->n=0;
        q->next=NULL;
        q->br=0;
    }
    return q;
}

void Put(int x, Pos P)
{
    Pos q=Node();
    if(MemoryCheck(q));
    else
    {
        q->n=x;
        q->next=P->next;
        P->next=q;
    }
}

void Generator(int min, int max, Pos A, Pos B, int size)
{
    int x;
    while(A->br<size || B->br<size)
    {
        x=min + (rand()%(max-min+1));
        printf("%d\n", x);
        Choice(x, A, B, size);
    }
}

void Choice(int x, Pos A, Pos B, int size)
{
    if(x%2==0 && A->br<size)
    {
        A->br++;
        Place(x, A);
    }
    else if(x%2!=0 && B->br<size)
    {
        B->br++;
        Place(x, B);
    }
}

void Place (int x, Pos P)
{
    Pos q=P;
    if(MemoryCheck(q));
    else
    {
        while(q->next!=NULL && x<q->next->n)
            q=q->next;
        if(q->next==NULL || x!=q->next->n)
            Put(x, q);
       else if(x==q->next->n)
            P->br--;
    }
}

void PrintSc(Pos P)
{
    while(P->next!=NULL)
    {
        P=P->next;
        printf("%d ", P->n);
    }
}

void Range_Size(int* x, int* y, int* z)
{
    int i=0;
    while(i==0)
    {
        printf("Set the range of randomly generated numbers:\n");
        scanf(" %d %d", &(*x), &(*y));
        printf("Set the list size:\n");
        scanf(" %d", &(*z));
        if((2*(*z)-1)<=(*y-*x))
            i++;
        else
            printf("\nRange not big enough for chosen list size!\n\n");
    }
    printf("Range set to %d - %d!\n", *x, *y);
    printf("List sizes set to %d!\n", *z);
}

bool MemoryCheck(Pos P)
{
    if(P==NULL)
    {
        printf("\n***** Allocated memory not found! *****\n");
        return 1;
    }
    else
        return 0;
}
