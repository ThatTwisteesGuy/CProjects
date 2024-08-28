#include "matrix.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void free_matrix(matrix * A)
{

    // Frees elements in the matrix
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


matrix* gen_matrix(int m, int n)
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


matrix* identity(int m)
{

    // Generates matrix which will be later returned
    matrix* A = gen_matrix(m,m);

    // Sets leading diagonal to 1s
    for(int i = 0; i < m; i++)
    {
        A->els[i*m+i] = 1;
    }

    // Returns the identity matrix
    return A;

}


matrix* copy(matrix* A)
{

    // Generates a matrix with the same sizes
    matrix*B = gen_matrix(A->rows, A->columns);

    // Calculate memory size to copy and copies elements to new matrix
    size_t memsize = sizeof(double) * B->rows * B->columns;
    memcpy(B->els, A->els, memsize);

    // Returns copied matrix
    return B;

}


matrix* product(matrix * A, matrix * B)
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
    matrix * C = gen_matrix(A->rows, B->columns);

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


void transpose(matrix * A)
{
    // Transposes dimensions
    int temp = A->rows;
    A->rows = A->columns;
    A->columns = temp;

    // Makes a copy of the input matrix
    matrix* B = copy(A);

    // Transposes elements
    for (int i = 0; i < A->columns; i++)
    {
        for (int j = 0; j < A->rows; j++)
        {
            A->els[j*A->columns+i] = B->els[i*A->rows+j];
        }
    }

    // Frees intermediate matrix
    free_matrix(B);

}


void mirror(matrix * A)
{

    matrix* B = copy(A);

    for (int i = 0; i < B->rows*B->columns; i++)
    {
        // Gets the row index of the mirrored position
        // this would be the same as the input matrix's
        int rowIndex = (i/A->columns)*A->columns;

        // Calculates the mirrored offset using modulo
        int columnOffset = A->columns-1-i%A->columns;

        // Sets element to the mirrored element
        A->els[i] = B->els[rowIndex + columnOffset];
    }

    // Frees intermediate matrix
    free_matrix(B);

}


void reverse(matrix* A)
{

    // Generates matrix to be later returned
    matrix* B = copy(A);

    // m*n
    int mn = B->rows*B->columns;

    // Reverses the order of all entries in the matrix
    for (int i = 0; i < B->rows*B->columns; i++)
    {
        A->els[i] = B->els[mn-1-i];
    }

    free_matrix(B);

}


void flip(matrix * A)
{

    // When reversing the order of the entries and then mirroring a matrix
    // this results in a flip of the matrix

    reverse(A);
    mirror(A);

}


void rotate(matrix * A)
{

    // When a transpose and a flip are performed consecutively on a matrix
    // this results in a 90 degree clockwise rotation of the matrix

    transpose(A);
    flip(A);

}