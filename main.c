#include <stdio.h>

#include "matrix.h"

// #include <stdio.h>
// #include <stdlib.h>


int main(void)
{

    matrix * A = gen_matrix(3,3);

    for (int i = 0; i < A->rows*A->columns; i++)
    {
         A->els[i] = ((i+1)*5)%7;
    }

    int det = determinant(A);

    printf("\n%d\n", det);

    swap_rows(A, 0, 2);

    det = determinant(A);

    printf("\n%d\n", det);

    return 0;
}
