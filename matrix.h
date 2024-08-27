#ifndef MATRIX_H
#define MATRIX_H

typedef struct {
    int rows;
    int columns;
    double* els;
} matrix;

// Matrix Functions

matrix* GenMatrix(int m, int n);
matrix* Identity(int m);
matrix* Product(matrix * A, matrix * B);
matrix* Transpose(matrix * A);
matrix* Mirror(matrix * A);
matrix* Flip(matrix * A);
matrix* Rotate(matrix * A);
matrix* Reverse(matrix* A);


// External Functions

void list(matrix * A);
void display(matrix * A);
void FreeMatrix(matrix * A);

#endif //MATRIX_H
