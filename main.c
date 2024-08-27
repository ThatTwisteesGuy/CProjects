#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main(void)
{
    matrix * A = GenMatrix(3,3);
    for (int i = 0 ; i < 9 ; i++)
    {
        A->els[i] = i+1;
    }
    matrix * B = Rotate(A);
    matrix * C = B;
    for (int i = 0; i < 100000000; i++)
    {
        C = Transpose(B);
        FreeMatrix(B);
        B = C;
    }

    display(B);

    FreeMatrix(A);
    FreeMatrix(B);
    FreeMatrix(C);

    return 0;
}
