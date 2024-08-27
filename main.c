#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main(void)
{
    matrix * A = gen_matrix(3,3);
    for (int i = 0 ; i < 9 ; i++)
    {
        A->els[i] = i+1;
    }
    matrix * B = rotate(A);
    matrix * C = B;
    for (int i = 0; i < 100000000; i++)
    {
        C = transpose(B);
        free_matrix(B);
        B = C;
    }

    display(B);

    free_matrix(A);
    free_matrix(B);
    free_matrix(C);

    return 0;
}
