#include "matrix.h"

// #include <stdio.h>
// #include <stdlib.h>


int main(void)
{
    matrix * A = gen_matrix(4,3);
    for (int i = 0 ; i < 12 ; i++)
    {
        A->els[i] = i+1;
    }

    matrix* B = copy(A);
    transpose(B);


    display(A);
    display(B);

    free_matrix(A);
    free_matrix(B);

    return 0;
}
