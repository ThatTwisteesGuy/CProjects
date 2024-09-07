#include <stdio.h>
#include "matrix.h"

// #include <stdio.h>
// #include <stdlib.h>


int main(void)
{

	matrix* A = identity(3);
	matrix* v = gen_matrix(3,1);

	matrix* c = solve_system(A, v);
	display(c);

    return 0;
}
