#include "sort functions.h"

struct Tree;
typedef struct Tree *Side;

typedef struct Tree {
    int n;
    Side left;
    Side right;
    int lvl;
}_tree;

Side Leaf();
bool MemoryTree(Side T);
Side Insert(int x, Side T);
void PrintTree_L2H(Side T, Pos A);
Side ListToTree(Pos L, Side T);
void LeveledTreeList(int x, int lvl, Pos A);

Side Leaf()
{
    Side q = NULL;
    q =(Side) malloc (sizeof(_tree));
    if(MemoryTree(q));
    else
    {
        q->n=0;
        q->left=NULL;
        q->right=NULL;
        q->lvl=1;
    }
    return q;
}

bool MemoryTree(Side T)
{
    if(T==NULL)
    {
        printf("\n***** Allocated memory not found! *****\n");
        return 1;
    }
    else
        return 0;
}

Side Insert(int x, Side T)
{
    Side q=NULL;
    if(T==NULL)
    {
        q=Leaf();
        if(MemoryTree(q));
        else
        {
            q->n=x;
            T=q;
        }
    }
    else if(x<T->n)
    {
        T->left=Insert(x, T->left);
        if(T->left->lvl==1)
            T->left->lvl=T->lvl +1;
    }
    else if(x>T->n)
    {
        T->right=Insert(x, T->right);
        if(T->right->lvl==1)
            T->right->lvl=T->lvl +1;
    }
    else T->n=x;

    return T;
}

void PrintTree_L2H(Side T, Pos A)
{
    if(T->left!=NULL)
        PrintTree_L2H(T->left, A);
    printf("lvl %d. %d\n", T->lvl, T->n);
    LeveledTreeList(T->n, T->lvl, A);
    if(T->right!=NULL)
        PrintTree_L2H(T->right, A);
}

Side ListToTree(Pos L, Side T)
{
    if(MemoryList(L));
    else
    {
        while(L->next!=NULL)
        {
            L=L->next;
            T=Insert(L->n, T);
        }
    }
    return T;
}

void LeveledTreeList(int x, int lvl, Pos A)
{
    Pos q=A;
    if(MemoryList(q));
    else
    {
        while(q->next!=NULL && lvl>=q->next->cnt)
            q=q->next;
        Put(x, q, lvl);
    }
}
