
#include "IntMatrix.h"
using namespace mtm;

IntMatrix::IntMatrix(const Dimensions &dims, int value): dimensions(Dimensions(dims.getRow(), dims.getCol())),
matrix(new int[dimensions.getRow() * dimensions.getCol()]) {
    int col_length = dims.getCol();
    for (int i = 0; i < dims.getRow(); i++) {
        for (int j = 0; j < col_length; j++) {
            *(matrix + col_length * i + j) = value;
        }
    }
}

IntMatrix::IntMatrix(const IntMatrix& mat): dimensions(mat.height(), mat.width()),
matrix(new int[dimensions.getCol() * dimensions.getRow()]) {
    int col_length = dimensions.getCol();
    for (int i = 0; i < dimensions.getRow(); i++) {
        for (int j = 0; j < col_length; j++) {
            matrix[col_length * i + j] = mat(i, j);
        }
    }
}

IntMatrix& IntMatrix::operator=(const IntMatrix& mat){
    if(this == &mat){
        return *this;
    }

    dimensions = Dimensions(mat.height(), mat.width());
    int col_length = dimensions.getCol();
    delete[] matrix;
    matrix = new int[col_length * dimensions.getRow()];
    for(int i = 0; i < col_length; i++){
        for(int j = 0; j < dimensions.getRow(); j++){
            matrix[col_length * i + j] = mat(i, j);
        }
    }
    return *this;
}





