#ifndef MATRIX_H
#define MATRIX_H

typedef struct {
    int rows;
    int columns;
    double* els;
} matrix;

// Matrix Functions

matrix* gen_matrix(int m, int n);
matrix* identity(int m);
matrix* product(matrix * A, matrix * B);
matrix* transpose(matrix * A);
matrix* mirror(matrix * A);
matrix* flip(matrix * A);
matrix* rotate(matrix * A);
matrix* reverse(matrix* A);


// External Functions

void list(matrix * A);
void display(matrix * A);
void free_matrix(matrix * A);

#endif //MATRIX_H
