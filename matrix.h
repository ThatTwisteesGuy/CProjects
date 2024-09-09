#ifndef MATRIX_H
#define MATRIX_H

#include <stdbool.h>


typedef struct {
    int rows;
    int columns;
    double* els;

} matrix;

// Matrix Create Functions

matrix* gen_matrix(int m, int n);
matrix* identity(int m);
matrix* copy(matrix* A);
matrix* product(matrix * A, matrix * B);
matrix* cofactor_matrix(matrix* A);
matrix* inverse(matrix* A);
matrix* solve_system(matrix* A, matrix* v);

// Matrix Self Functions

void multiply(matrix* A, double s);
void divide(matrix* A, double s);

void transpose(matrix * A);
void mirror(matrix * A);
void flip(matrix * A);
void rotate(matrix * A);
void reverse(matrix* A);

void swap_rows(matrix* A, int r1, int r2);
void remove_row(matrix* A, int row);
void remove_col(matrix* A, int column);

// External Functions

void display(matrix * A);
void free_matrix(matrix * A);
void populate(matrix* A);

// Valued Functions

double determinant(matrix* A);
double cofactor(matrix* A, int pos);
double dot_product(matrix* v1, matrix* v2);
double modulus(matrix* v1);

// Matrix Property Check Functions

bool is_square(matrix* A);
bool is_vector(matrix* A);
bool is_equal(matrix* A, matrix* B);
bool is_orthogonal(matrix* A);
bool is_symmetric(matrix* A);
bool is_skew_symmetric(matrix* A);


#endif //MATRIX_H
