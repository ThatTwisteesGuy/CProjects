#include <stdio.h>
#include <wchar.h>

#include "matrix.h"

// #include <stdio.h>
// #include <stdlib.h>


int main(void)
{
    matrix * A = gen_matrix(3,3);
    for (int i = 0 ; i < 9 ; i++)
    {
        A->els[i] = i+1;
    }


    display(A);
    remove_row(A, 0);
    display(A);


    return 0;
}
