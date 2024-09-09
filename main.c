#include <stdio.h>
#include "matrix.h"

// #include <stdio.h>
// #include <stdlib.h>


int main(void)
{

    matrix* A = gen_matrix(3,3);;

    populate(A);

    double det = determinant(A);

    printf("\n\nDeterminant: %lf", det);

    free_matrix(A);
    return 0;
}
