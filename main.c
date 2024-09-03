#include <stdio.h>

#include "matrix.h"

// #include <stdio.h>
// #include <stdlib.h>


int main(void)
{

    matrix * A = gen_matrix(3,3);

    for (int i = 0; i < A->rows*A->columns; i++)
    {
         A->els[i] = ((i+1)*5)%11;
    }

	int det = 0;

	for (int i = 0; i < 10000; i++)
	{
		swap_rows(A, 0, 1);
		det = determinant(A);
		printf("\n%d", det);
	}


    return 0;
}
