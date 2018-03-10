#include "binary tree functions.h"


int main(int argc, char* argv[])
{
    Pos Even=NULL, Odd=NULL, S_even=NULL, S_odd=NULL;
    Side T_odd=NULL, T_even=NULL;
    Even=Node();
    Odd=Node();
    S_even=Node();
    S_odd=Node();
    if(MemoryList(Even) || MemoryList(Odd) || MemoryList(S_even) || MemoryList(S_odd));
    else
    {
        Generator(Even, Odd);
        T_even=ListToTree(Even, T_even);
        T_odd=ListToTree(Odd, T_odd);

        printf("\nSorted lists:\n");

        printf("\nEven: ");
        PrintList(Even);

        printf("\nOdd: ");
        PrintList(Odd);

        printf("\nEnd of lists!\n");

        if(MemoryTree(T_even) || MemoryTree(T_odd));
        else
        {
            printf("\nEven tree:\n");
            PrintTree_L2H(T_even, S_even);
            printf("\nSorted by levels: ");
            PrintList(S_even);

            printf("\n\nOdd tree:\n");
            PrintTree_L2H(T_odd, S_odd);
            printf("\nSorted by levels: ");
            PrintList(S_odd);

            printf("\nEnd of trees!\n");
        }
    }
    return 0;
}
