#include <stdio.h>
#include <time.h>
#include "matrix.h"

// #include <stdio.h>
// #include <stdlib.h>


int main(void)
{

	time_t t1 = time(NULL);

    matrix * A = gen_matrix(3,3);

    for (int i = 0; i < A->rows*A->columns; i++)
    {
         A->els[i] = ((i+1)*5)%11;
    }

	printf("\ndeterminant: %lf", determinant(A));

	display(A);

	matrix* B = cofactor_matrix(A);

	display(B);

    return 0;
}
