#include "matrix.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void free_matrix(matrix * A)
{

    // NULL Check
    if (A == NULL)
    {
        printf("\nCannot free NULL Matrix");
        return;
    }

    // Frees elements in the matrix
    free(A->els);

    // Frees the matrix itself
    free(A);

}


void refit_matrix(matrix * A)
{

    // NULL Check
    if (A == NULL)
    {
        printf("\nCannot refit NULL Matrix");
        return;
    }

    // Calculates the number of new bytes needed to realloc
    size_t bytes = A->rows * A->columns * sizeof(double);

    // Reallocs memory for the elements
    A->els = realloc(A->els, bytes);

}

void display(const matrix * A)
{

    // NULL Check
    if (A == NULL)
    {
        printf("\nCannot Display NULL Matrix");
        return;
    }

    // Displays elements in a grid
    printf("\n");
    for (int i = 0 ; i < A->rows ; i++)
    {

        printf("\n");

        for (int j = 0 ; j < A->columns ; j++)
        {
            printf("%lf \t", A->els[i*A->columns+j]);
        }

    }

}


matrix* gen_matrix(int m, int n)
{

    // Allocates memory for the matrix
    matrix * A = malloc(sizeof(matrix));

    // Sets the number of rows
    A->rows = m;

    // Sets the number of columns
    A->columns = n;

    // Allocates memory for the elements of the matrix
    // by the data type size * m * n
    A->els = calloc(A->columns * A->rows, sizeof(double));

    return A;

}


matrix* identity(int m)
{

    // Generates matrix which will be later returned
    matrix* A = gen_matrix(m,m);

    // Sets leading diagonal to 1s
    for (int i = 0 ; i < m ; i++)
    {
        A->els[i*m+i] = 1;
    }

    // Returns the identity matrix
    return A;

}


matrix* copy(const matrix* A)
{

    // NULL Check
    if (A == NULL)
    {
        printf("\nCannot copy NULL Matrix");
        return NULL;
    }

    // Generates a matrix with the same sizes
    matrix*B = gen_matrix(A->rows, A->columns);

    // Calculates memory size to copy and copies elements to new matrix
    size_t memsize = sizeof(double) * B->rows * B->columns;
    memcpy(B->els, A->els, memsize);

    // Returns copied matrix
    return B;

}


matrix* product(const matrix * A, const matrix * B)
{

    // NULL Check
    if (A == NULL || B == NULL)
    {
        printf("\nCannot Perform Product on NULL Matrices");
        return NULL;
    }

    // Checks that input Matrices are valid
    if (A->columns != B->rows)
    {
        // Returns NULL to prevent error
        printf("\nCannot Perform Product on Incompatible Matrices");
        return NULL;
    }

    // Generates matrix which will later be returned
    // It is important to first check that the inputs are valid to not
    // generate a matrix for nothing
    matrix * C = gen_matrix(A->rows, B->columns);

    // Matrix multiplication algorithm
    for (int i = 0 ; i < A->rows ; i++)
    {
        for (int j = 0 ; j < B->columns ; j++)
        {
            for (int k = 0 ; k < A->columns ; k++)
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

    // NULL Check
    if (A == NULL)
    {
        printf("\nCannot perform operation on NULL Matrix");
        return;
    }

    // Transposes dimensions
    int temp = A->rows;
    A->rows = A->columns;
    A->columns = temp;

    // Makes a copy of the input matrix
    matrix* B = copy(A);

    // Transposes elements
    for (int i = 0 ; i < A->columns ; i++)
    {
        for (int j = 0 ; j < A->rows ; j++)
        {
            A->els[j*A->columns+i] = B->els[i*A->rows+j];
        }
    }

    // Frees intermediate matrix
    free_matrix(B);

}


void mirror(const matrix * A)
{

    // NULL Check
    if (A == NULL)
    {
        printf("\nCannot perform operation on NULL Matrix");
        return;
    }

    // Copies matrix
    matrix* B = copy(A);

    // Iterates all entries
    for (int i = 0 ; i < B->rows*B->columns ; i++)
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


void reverse(const matrix* A)
{

    // NULL Check
    if (A == NULL)
    {
        printf("\nCannot perform operation on NULL Matrix");
        return;
    }

    // Generates matrix to be later returned
    matrix* B = copy(A);

    // m*n
    int mn = B->rows*B->columns;

    // Reverses the order of all entries in the matrix
    for (int i = 0 ; i < B->rows*B->columns ; i++)
    {
        A->els[i] = B->els[mn-1-i];
    }

    // Frees intermediate matrix
    free_matrix(B);

}


void flip(const matrix * A)
{

    // NULL Check
    if (A == NULL)
    {
        printf("\nCannot perform operation on NULL Matrix");
        return;
    }

    // When reversing the order of the entries and then mirroring a matrix
    // This results in a flip of the matrix
    reverse(A);
    mirror(A);

}


void rotate(matrix * A)
{

    // NULL Check
    if (A == NULL)
    {
        printf("\nCannot perform operation on NULL Matrix");
        return;
    }

    // When a transpose and a flip are performed consecutively on a matrix
    // This results in a 90 degree clockwise rotation of the matrix
    transpose(A);
    flip(A);

}


void remove_row(matrix* A, int row)
{

    // NULL Check
    if (A == NULL)
    {
        printf("\nCannot perform operation on NULL Matrix");
        return;
    }

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
    size_t bytes = sizeof(double)*(final_index-rowend_index+1);


    // Moves all consequent elements to the position of the row
    memmove(&A->els[rowstart_index], &A->els[rowend_index], bytes);


    // Removes the row and refits the matrix memory
    A->rows--;

    // Refits the matrix memory for the new dimensions
    refit_matrix(A);

}


void remove_col(matrix* A, int column)
{

    // NULL Check
    if (A == NULL)
    {
        printf("\nCannot perform operation on NULL Matrix");
        return;
    }

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


double determinant(const matrix* A)
{

    // NULL Check
    if (A == NULL)
    {
        return 0;
    }

    // Checks if the matrix is square
    if (is_square(A) != true)
    {
        printf("Matrix Is Not Square");
        return 0;
    }

    // n = 0 Base Case
    if (A->rows == 0)
    {
        return 0;
    }

    // n = 1 Base Case
    if (A->rows == 1)
    {
        return A->els[0];
    }

    // Recursive Case
    double det = 0;

    for (int i = 0 ; i < A->rows ; i++)
    {

        // Adds the cofactors of the entries multiplied with the entries of the top row
        double cof = cofactor(A, i);
        det += A->els[i] * cof;

    }

    // Returns determinant
    return det;

}


double cofactor(const matrix* A, int pos)
{

    if (A == NULL)
    {
        return 0;
    }

    if (is_square(A) != true)
    {
        printf("Matrix Is Not Square");
        return 0;
    }

    if (A->rows <= 0)
    {
        printf("Matrix has dimension 0");
        return 0;
    }

    if (pos >= A->rows*A->columns)
    {
        printf("Position Is Invalid");
        return 0;
    }

    if (A->rows == 1)
    {
        return A->els[0];
    }

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


void populate(const matrix* A)
{

    // NULL Check
    if (A == NULL)
    {
        printf("\nCannot populate NULL Matrix");
        return;
    }

    // Iterates and prompts user to populate each entry
    for (int i = 0 ; i < A->rows*A->columns ; i++)
    {

        printf("\nElement %d:", i);
        scanf("%lf", &A->els[i]);

    }

}


void multiply(const matrix* A, double s)
{

    // NULL Check
    if (A == NULL)
    {

        printf("\nCannot perform operation on NULL Matrix");
        return;

    }

    // Iterates each element and multiplies by scale factor
    for (int i = 0 ; i < A->rows*A->columns ; i++)
    {
        A->els[i] *= s;
    }

}


void divide(const matrix* A, double s)
{

    // NULL Check
    if (A == NULL)
    {

        printf("\nCannot perform operation on NULL Matrix");
        return;

    }

    // Iterates each element and divides by scale factor
    for (int i = 0 ; i < A->rows*A->columns ; i++)
    {
        A->els[i] /= s;
    }

}


void swap_rows(const matrix* A, int r1, int r2)
{

    // NULL Check
    if (A == NULL)
    {
        printf("\nCannot perform operation on NULL Matrix");
        return;
    }

    // Checks if given rows are valid
    if (r1 >= A->rows || r2 >= A->rows)
    {

        printf("\nInvalid Rows");
        return;

    }

    // Creates temporary array to hold row of elements
    double temp[A->columns];

    // Calculates the size needed to copy over
    size_t bytes = A->columns * sizeof(double);

    // Copies from r1 to temp
    memcpy(temp, &A->els[r1*A->columns], bytes);

    // Overwrites r1 with r2
    memcpy(&A->els[r1*A->columns], &A->els[r2*A->columns], bytes);

    // Copies temp onto r2
    memcpy(&A->els[r2*A->columns], temp, bytes);

}


matrix* cofactor_matrix(const matrix* A)
{

    // NULL Check
    if (A == NULL)
    {
        printf("\nCannot perform operation on NULL Matrix");
        return NULL;
    }

    // Generates new matrix with the same dimensions as the input matrix
    matrix* B = gen_matrix(A->rows, A->columns);

    // Iterates each element and populates it with the cofactor of the
    // corresponding entry in the input matrix
    for (int i= 0 ; i < A->rows*A->columns ; i++)
    {
        B->els[i] = cofactor(A, i);
    }

    // Returns the cofactor matrix
    return B;

}


matrix* inverse(const matrix* A)
{

    // NULL Check
    if (A == NULL)
    {
        printf("\nCannot perform operation on NULL Matrix");
        return NULL;
    }

    // Gets determinant and checks if the matrix is singular
    double det = determinant(A);
    if (det == 0)
    {
        printf("Input Matrix Is Singular");
        return NULL;
    }

    // Inverse matrix algorithm
    matrix* B = cofactor_matrix(A);
    transpose(B);
    divide(B, det);

    // Return inverse matrix
    return B;

}


matrix* solve_system(const matrix* A, const matrix* v1)
{

    // NULL Check
    if (A == NULL || v1 == NULL)
    {
        printf("\nCannot perform operation on NULL Matrices");
        return NULL;
    }

    // Checks if input vector is valid
    if (is_vector(v1) == false)
    {
        printf("\nInput vector is not a vector");
        return NULL;
    }

    // Checks if system has infinite solutions
    matrix* Ainv = inverse(A);
    if (Ainv == NULL)
    {
        printf("\nSystem Has Infinite Solutions");
        return NULL;
    }

    // Attempts to generate the result, if the result is null
    // the system was not compatible, otherwise returns the answer

    matrix* v2 = product(Ainv, v1);
    if (v2 == NULL)
    {
        printf("\nSystem Is Incompatible");
        free_matrix(Ainv);
        return NULL;
    }

    // Frees intermediate matrix
    free_matrix(Ainv);

    // Returns vector result of the solves system
    return v2;

}


double modulus(const matrix* v1)
{

    // NULL Check
    if (v1 == NULL)
    {
        printf("\nCannot Perform Operation On NULL Matrix");
        return 0;
    }

    // Checks if input vector is valid
    if (is_vector(v1) == false)
    {
        printf("\nMatrix Provided Is Not A Vector");
        return 0;
    }

    // Modulus algorithm
    double mod = 0;
    for (int i = 0 ; i < v1->rows ; i++)
    {
        mod += v1->els[i] * v1->els[i];
    }
    mod = sqrt(mod);

    // Returns modulus of the vector
    return mod;

}


double dot_product(const matrix* v1, const matrix* v2)
{

    // NULL Check
    if (v1 == NULL || v2 == NULL)
    {
        printf("\nCannot Perform Operation On NULL Matrices");
        return 0;
    }

    // Checks if vectors are valid
    if (is_vector(v1) == false || is_vector(v2) == false)
    {
        printf("\nMatrices Provided Are Not Vectors");
        return 0;
    }

    // Checks if vectors are of the same dimensions
    if (v1->rows != v2->rows)
    {
        printf("\nVectors Are Mismatched");
        return 0;
    }

    // Dot product algorithm
    double dp = 0;
    for (int i = 0 ; i < v1->rows ; i++)
    {
        dp += v1->els[i] * v2->els[i];
    }

    // Returns dot product of the 2 vectors
    return dp;

}


bool is_vector(const matrix* A)
{

    // NULL Check
    if (A == NULL)
    {
        printf("\nCannot perform operation on NULL Matrix");
        return false;
    }

    // Checks if matrix is a vector by checking if it's nx1
    if (A->columns == 1)
    {
        return true;
    }

    return false;

}


bool is_equal(const matrix* A, const matrix* B)
{

    // NULL Check
    if (A == NULL || B == NULL)
    {
        printf("\nCannot perform operation on NULL Matrix");
        return false;
    }

    // Checks if dimensions are unequal
    if (A->rows != B->rows || A->columns != B->columns)
    {
        return false;
    }

    // Compares each entry of both matrices
    bool eq = true;
    for (int i = 0 ; i < A->rows * A->columns ; i++)
    {

        if (A->els[i] != B->els[i])
        {
            eq = false;
        }

    }

    return eq;

}


bool is_orthogonal(const matrix* A)
{

    // NULL Check
    if (A == NULL)
    {
        printf("\nCannot perform operation on NULL Matrix");
        return false;
    }

    // Checks if inverse exists
    matrix* Ainv = inverse(A);
    if (Ainv == NULL)
    {
        return false;
    }

    bool orth = false;

    // Makes a copy of the matrix and transposes it
    matrix* B = copy(A);
    transpose(B);

    // Checks if tranpose and inverse of the matrix are the same
    if (is_equal(Ainv, B) == true)
    {
        orth = true;
    }

    // Frees intermediate matrices
    free_matrix(Ainv);
    free_matrix(B);

    return orth;

}


bool is_symmetric(const matrix* A)
{

    // NULL Check
    if (A == NULL)
    {
        printf("\nCannot perform operation on NULL Matrix");
        return false;
    }

    // Copies original matrix and transposes
    matrix* B = copy(A);
    transpose(B);

    // Checks if tranpose is equal to the original
    bool eq = is_equal(A, B);

    // Frees intermediate matrix
    free_matrix(B);

    return eq;

}


bool is_skew_symmetric(const matrix* A)
{

    // NULL Check
    if (A == NULL)
    {
        printf("\nCannot perform operation on NULL Matrix");
        return false;
    }

    // Copies input matrix and transposes it
    matrix* B = copy(A);
    transpose(B);

    // Copies original matrix and multiplies it by -1
    matrix* C = copy(A);
    multiply(C, -1);

    // Checks if negates matrix is equal to the transposed matrix
    bool eq = is_equal(C, B);

    // Frees intermediate matrices
    free_matrix(B);
    free_matrix(C);

    return eq;

}


bool is_square(const matrix* A)
{

    // NULL Check
    if (A == NULL)
    {
        printf("\nCannot perform operation on NULL Matrix");
        return false;
    }

    // Checks if dimensions are square
    if (A->rows == A->columns)
    {
        return true;
    }
        return false;

}