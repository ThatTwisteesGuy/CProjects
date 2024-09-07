#include <stdio.h>
#include "matrix.h"

// #include <stdio.h>
// #include <stdlib.h>


int main(void)
{

    matrix* A = gen_matrix(2,2);;

    populate(A);

    if (is_orthogonal(A))
    {
        printf("\nYes");
    }
    else
    {
        printf("\nNo");
    }

    return 0;
}
