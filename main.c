#include <stdio.h>
#include <time.h>
#include "matrix.h"

// #include <stdio.h>
// #include <stdlib.h>


int main(void)
{

	time_t t1 = time(NULL);

    matrix * A = gen_matrix(3,3);
	matrix * B = gen_matrix(3,1);
	populate(A);
	populate(B);

	matrix* C = solve_system(A, B);

	display(C);

    return 0;
}
