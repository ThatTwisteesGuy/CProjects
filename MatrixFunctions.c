#include <math.h>

#include "matrix.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void FreeMatrix(matrix * A)
{

    // Frees elemenents in the matrix
    free(A->els);

    // Frees the matrix itself
    free(A);

}


void display(matrix * A)
{
    printf("\n");
    for (int i = 0; i < A->rows; i++)
    {
        printf("\n");
        for (int j = 0; j < A->columns; j++)
        {
            printf("%lf \t", A->els[i*A->columns+j]);
        }
    }
}


void list(matrix * A)
{
    for (int i = 0; i < A->rows*A->columns; i++)
    {
        printf("%lf, ", A->els[i]);
    }
}


matrix* GenMatrix(int m, int n)
{
    // Allocates memory for the matrix
    matrix * A = malloc(sizeof(matrix));

    // Sets the number of rows
    A -> rows = m;

    // Sets the number of columns
    A -> columns = n;

    // Allocates memory for the elements of the matrix
    // by the data type size * m * n
    A->els = calloc(A->columns * A->rows,sizeof(double));

    return A;
}


matrix* Identity(int m)
{

    // Generates matrix which will be later returned
    matrix* A = GenMatrix(m,m);

    // Sets leading diagonal to 1s
    for(int i = 0; i < m; i++)
    {
        A->els[i*m+i] = 1;
    }

    // Returns the identity matrix
    return A;

}


matrix* Product(matrix * A, matrix * B)
{

    // Checks that input Matrices are valid
    if (A->columns != B->rows)
    {
        // Returns NULL to prevent error
        return NULL;
    }

    // Generates matrix which will later be returned
    // It is important to first check that the inputs are valid to not
    // generate a matrix for nothing
    matrix * C = GenMatrix(A->rows, B->columns);

    // Matrix multiplication algorithm
    for (int i = 0; i < A->rows; i++)
    {
        for (int j = 0; j < B->columns; j++)
        {
            for (int k = 0; k < A->columns; k++)
            {
                C->els[(i*C->columns)+j] += A->els[i*A->columns+k] * B->els[k*B->columns+j];
            }
        }
    }

    // Returns product of A and B
    return C;
}


matrix* Transpose(matrix * A)
{
    matrix* B = GenMatrix(A->columns, A->rows);

    for (int i = 0; i < B->columns; i++)
    {
        for (int j = 0; j < B->rows; j++)
        {
            B->els[i*B->columns+j] = A->els[j*B->columns+i];
        }
    }

    return B;
}


matrix* Mirror(matrix * A)
{

    matrix* B = GenMatrix(A->rows, A->columns);

    for (int i = 0; i < B->rows*B->columns; i++)
    {
        // Gets the row index of the mirrored position
        // this would be the same as the input matrix's
        int rowIndex = (i/B->columns)*B->columns;

        // Calculates the mirrored offset using modulo
        int columnOffset = B->columns-1-i%B->columns;


        B->els[i] = A->els[rowIndex + columnOffset];
    }

    return B;
}


matrix* Reverse(matrix* A)
{

    // Generates matrix to be later returned
    matrix* B = GenMatrix(A->rows, A->columns);

    // m*n
    int mn = B->rows*B->columns;

    // Reverses the order of all entries in the matrix
    for (int i = 0; i < B->rows*B->columns; i++)
    {
        B->els[i] = A->els[mn-1-i];
    }

    // Returns the reversed matrix
    return B;

}

matrix* Flip(matrix * A)
{

    // When reversing the order of the entries and then mirroring a matrix
    // this results in a flip of the matrix

    matrix* C = Reverse(A);
    matrix* B = Mirror(C);

    // Frees the intermediate matrix

    FreeMatrix(C);

    // Returns the flipped matrix
    return B;

}

matrix* Rotate(matrix * A)
{

    // When a transpose and a flip are performed consecutively on a matrix
    // this results in a 90 degree clockwise rotation of the matrix

    matrix* C = Flip(A);
    matrix* B =  Transpose(C);

    // Frees the intermediate matrix

    FreeMatrix(C);

    // Returns the rotated matrix
    return B;
}