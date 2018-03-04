#include "binary tree functions.h"


int main(int argc, char* argv[])
{
    Pos Even=NULL, Odd=NULL;
    Side T_odd=NULL, T_even=NULL;
    Even=Node();
    Odd=Node();
    if(MemoryList(Even) || MemoryList(Odd));
    else
    {
        Generator(Even, Odd);
        ListToTree(Even, T_even);
        ListToTree(Odd, T_odd);

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
            PrintTree_L2H(T_even);

            printf("\nOdd tree:\n");
            PrintTree_L2H(T_odd);

            printf("\nEnd of trees!\n");
        }
    }
    return 0;
}
