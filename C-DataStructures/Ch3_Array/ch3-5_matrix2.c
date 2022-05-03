#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100
typedef struct {
    int row;
    int column;
    int value;
}element;

typedef struct SparseMatrix {
    element data[MAX_TERMS];
    int rows;
    int cols;
    int terms;
} SparseMatrix;

Spa