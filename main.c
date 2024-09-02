#include <stdio.h>
#include <wchar.h>

#include "matrix.h"

// #include <stdio.h>
// #include <stdlib.h>


int main(void)
{

    matrix * A = gen_matrix(3,3);
    populate(A);
    multiply(A, 2);
    display(A);

    return 0;
}
