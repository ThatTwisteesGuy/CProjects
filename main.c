#include <stdio.h>
#include <wchar.h>

#include "matrix.h"

// #include <stdio.h>
// #include <stdlib.h>


int main(void)
{
    matrix * A = gen_matrix(3,3);

    display(A);
    int det = determinant(A);
    printf("\ndeterminant: %d", det);

    return 0;
}
