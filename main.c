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
    matrix * C = Transpose(A);

    display(B);
    display(C);

    return 0;
}
