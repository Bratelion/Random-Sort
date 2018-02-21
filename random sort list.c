#include "sort functions.h"


int main(int argc, char* argv[])
{
    Pos Even=NULL, Odd=NULL;
    Even=Node();
    Odd=Node();
    if(MemoryPos(Even) || MemoryPos(Odd));

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
