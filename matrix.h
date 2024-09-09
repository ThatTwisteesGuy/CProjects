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
matrix* copy(const matrix* A);
matrix* product(const matrix * A, const matrix * B);
matrix* cofactor_matrix(const matrix* A);
matrix* inverse(const matrix* A);
matrix* solve_system(const matrix* A, const matrix* v);

// Matrix Self Functions

void multiply(const matrix* A, double s);
void divide(const matrix* A, double s);

void transpose(matrix * A);
void mirror(const matrix * A);
void flip(const matrix * A);
void rotate(matrix * A);
void reverse(const matrix* A);

void swap_rows(const matrix* A, int r1, int r2);
void remove_row(matrix* A, int row);
void remove_col(matrix* A, int column);

// External Functions

void display(const matrix * A);
void free_matrix(matrix * A);
void populate(const matrix* A);

// Valued Functions

double determinant(const matrix* A);
double cofactor(const matrix* A, int pos);
double dot_product(const matrix* v1, const matrix* v2);
double modulus(const matrix* v1);

// Matrix Property Check Functions

bool is_square(const matrix* A);
bool is_vector(const matrix* A);
bool is_equal(const matrix* A, const matrix* B);
bool is_orthogonal(const matrix* A);
bool is_symmetric(const matrix* A);
bool is_skew_symmetric(const matrix* A);


#endif //MATRIX_H
