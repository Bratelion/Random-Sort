#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


struct Seperate;
typedef struct Seperate *Pos;

typedef struct Seperate {
    int n;
    Pos next;
    int cnt;
}_sep;

Pos Node();
void Put(int x, Pos P);
void Generator(Pos A, Pos B);
void Choice(int x, Pos A, Pos B, int size, int ch);
void Place (int x, Pos P, int ch);
void PrintSc(Pos P);
void Range_Size(int* min, int* max, int* size, int* ch);
bool MemoryCheck(Pos P);

int main(int argc, char* argv[])
{
    Pos Even=NULL, Odd=NULL;
    Even=Node();
    Odd=Node();
    if(MemoryCheck(Even) || MemoryCheck(Odd));

    else
    {
        Generator(Even, Odd);

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
        q->cnt=0;
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

void Generator(Pos A, Pos B)
{
    srand(time(NULL));
    int x;
    int min=0, max=0, size=0, ch=5;
    Range_Size(&min, &max, &size, &ch);
    printf("Generated numbers:\n");
    while(A->cnt<size || B->cnt<size)
    {
        x=min + (rand()%(max-min+1));
        printf("%d\n", x);
        Choice(x, A, B, size, ch);
    }
}

void Choice(int x, Pos A, Pos B, int size, int ch)
{
    if(x%2==0 && A->cnt<size)
    {
        A->cnt++;
        Place(x, A, ch);
    }
    else if(x%2!=0 && B->cnt<size)
    {
        B->cnt++;
        Place(x, B, ch);
    }
}

void Place (int x, Pos P, int ch)
{
    Pos q=P;
    if(MemoryCheck(q));
    else
    {
        switch (ch)
        {
            case 0: while(q->next!=NULL && x>q->next->n)
                        q=q->next;
                    break;
            case 1: while(q->next!=NULL && x<q->next->n)
                        q=q->next;
                    break;
            case 2: while(q->next!=NULL && x!=q->next->n)
                        q=q->next;
                    break;
        }
        if(q->next==NULL || x!=q->next->n)
            Put(x, q);
        else if(x==q->next->n)
            P->cnt--;
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

void Range_Size(int* min, int* max, int* size, int* ch)
{
    int i=0;
    while(i==0)
    {
        printf("Set the range of randomly generated numbers:\n");
        scanf(" %d %d", &(*min), &(*max));
        printf("Set the list size:\n");
        scanf(" %d", &(*size));
        if((2*(*size)-1)<=(*max-*min))
            i++;
        else
            printf("\nRange not big enough for chosen list size!\n\n");
    }
    while(*ch<=-1 || *ch>=3)
    {
        printf("Choose: 0) Ascending order\n");
        printf("        1) Descending order\n");
        printf("        2) As the generator makes\n\n");
        scanf(" %d", &(*ch));
    }
    printf("Range set to %d - %d!\n", *min, *max);
    printf("List sizes set to %d!\n", *size);
    if(*ch==0)
        printf("Numbers are listed in ASCENDING ORDER!\n");
    if(*ch==1)
        printf("Numbers are listed in DESCENDING ORDER!\n");
    if(*ch==2)
        printf("Numbers are listed in GENERATED ORDER!\n");
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
