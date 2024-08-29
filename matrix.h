#ifndef MATRIX_H
#define MATRIX_H

typedef struct {
    int rows;
    int columns;
    double* els;
} matrix;

// Matrix Create Functions

matrix* copy(matrix* A);
matrix* gen_matrix(int m, int n);
matrix* identity(int m);
matrix* product(matrix * A, matrix * B);

// Matrix Self Functions

void transpose(matrix * A);
void mirror(matrix * A);
void flip(matrix * A);
void rotate(matrix * A);
void reverse(matrix* A);

void remove_row(matrix* A, int row);
void remove_col(matrix* A, int column);

// External Functions

void list(matrix * A);
void display(matrix * A);
void free_matrix(matrix * A);

// Valued Functions

int determinant(matrix* A);
int gen_cofactor(matrix* A, int pos);

#endif //MATRIX_H
