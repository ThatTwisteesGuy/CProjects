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


void refit_matrix(matrix * A)
{

    // Reallocates the memory if the size of the matrix changed
    realloc(A->els, A->rows*A->columns*sizeof(double));

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

    // Calculates memory size to copy and copies elements to new matrix
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

    // Copies matrix
    matrix* B = copy(A);

    // Iterates all entries
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

    // Frees intermediate matrix
    free_matrix(B);

}


void flip(matrix * A)
{

    // When reversing the order of the entries and then mirroring a matrix
    // This results in a flip of the matrix

    reverse(A);
    mirror(A);

}


void rotate(matrix * A)
{

    // When a transpose and a flip are performed consecutively on a matrix
    // This results in a 90 degree clockwise rotation of the matrix

    transpose(A);
    flip(A);

}


void remove_row(matrix* A, int row)
{

    // Checks if input row is valid
    if (row >= A->rows)
    {
        printf("Invalid Row");
        return;
    }

    // Checks if the matrix is not on its last row
    if (A->rows <= 1)
    {
        printf("Cannot Remove Last Row");
        return;
    }

    // Gets the index of the start of the row
    int rowstart_index = row*A->columns;
    // Gets the index of the end of the row
    int rowend_index = row*A->columns+A->columns;
    // Gets the index of the final element in the matrix
    int final_index = (A->columns*A->rows)-1;

    // Calculates the total size to be moved
    int bytes = sizeof(double)*(final_index-rowend_index+1);

    // Moves all consequent elements to the position of the row
    memmove(&A->els[rowstart_index], &A->els[rowend_index], bytes);

    // Removes the row and refits the matrix memory
    A->rows--;
    refit_matrix(A);

}


void remove_col(matrix* A, int column)
{

    // Checks if input column is valid
    if (column >= A->columns)
    {
        printf("Invalid Column");
        return;
    }

    // Checks if the matrix is on its last column
    if (A->columns <= 1)
    {
        printf("Cannot Remove Last Column");
        return;
    }

    // Transposes the matrix so that the column becomes a row
    transpose(A);

    // Removes the row which was a column
    remove_row(A, column);

    // Transposes back
    transpose(A);

}


int determinant(matrix* A)
{

    // Sets determinant 0
    int det = 0;

    // Checks if the matrix is square
    if (A->rows != A->columns)
    {
        printf("Not a Square Matrix!");
        return det;
    }

    // n = 0 Base Case
    if (A->rows == 0)
    {
        return det;
    }

    // n = 1 Base Case
    if (A->rows == 1)
    {
        return A->els[0];
    }

    // n = 2 Base Case
    if (A->rows == 2)
    {
        return A->els[0]*A->els[3]-A->els[1]*A->els[2];
    }

    // Recursive Case
    {

        for (int i = 0 ; i < A->rows ; i++)
        {

            // Adds the cofactors of the entries multiplied with the entries of the top row
            det += A->els[i] * gen_cofactor(A, i);

        }

    }

    // Returns the determinant
    return det;

}


int gen_cofactor(matrix* A, int pos)
{

    // Get row and column to remove
    int m = pos/A->columns;
    int n = pos%A->columns;

    // Makes a copy of the original matrix
    matrix * B = copy(A);

    // Removes the row and column of the position
    remove_row(B, m);
    remove_col(B, n);

    // Gets the sign of the position on the sign matrix
    int sign = 1+(-2*((m+n)%2));

    // Gets the cofactor of the position on the cofactor matrix
    int CF = determinant(B)*sign;

    // Frees intermediate matrix used
    free_matrix(B);

    // Returns cofactor
    return CF;

}


void populate(matrix* A)
{

    for (int i = 0; i < A->rows*A->columns; i++)
    {

        printf("Element %d:", i);
        scanf("%lf", &A->els[i]);

    }

}


void multiply(matrix* A, double s)
{

    for (int i = 0; i < A->rows*A->columns; i++)
    {

        A->els[i] *= s;

    }
}


void divide(matrix* A, double s)
{

    for (int i = 0; i < A->rows*A->columns; i++)
    {

        A->els[i] /= s;

    }
}