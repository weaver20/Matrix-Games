
#include "IntMatrix.h"
#include <assert.h>
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

IntMatrix& IntMatrix::operator=(const IntMatrix& mat) {
    if (this == &mat) {
        return *this;
    }

    dimensions = Dimensions(mat.height(), mat.width());
    int col_length = dimensions.getCol();
    delete[] matrix;
    matrix = new int[col_length * dimensions.getRow()];
    for (int i = 0; i < col_length; i++) {
        for (int j = 0; j < dimensions.getRow(); j++) {
            matrix[col_length * i + j] = mat(i, j);
        }
    }
    return *this;
}

IntMatrix::~IntMatrix() {
    delete [] matrix;
}

IntMatrix IntMatrix::transpose() const {
    assert(dimensions.getRow() > 0 and dimensions.getCol() > 0);
    IntMatrix mat(dimensions);
    for(int i = 0; i < dimensions.getCol(); i++){
        for(int j = 0; j < dimensions.getRow(); j++){
            mat(i, j) = matrix[i + j * dimensions.getRow()];
        }
    }
    return mat;
}

IntMatrix IntMatrix::operator+(const IntMatrix& mat) const {
    assert(dimensions == mat.dimensions);
    IntMatrix temp(dimensions);
    int col_length = dimensions.getCol();
    for (int i = 0; i < dimensions.getRow(); i++) {
        for (int j = 0; j < col_length; j++) {
            temp(i,j) = matrix[col_length * i + j] + mat(i, j);
        }
    }
    return temp;
}

IntMatrix IntMatrix::operator-() const {
    IntMatrix temp(dimensions);
    int col_length = dimensions.getCol();
    for (int i = 0; i < dimensions.getRow(); i++) {
        for (int j = 0; j < col_length; j++) {
            temp(i,j) = -temp(i,j);
        }
    }
    return temp;
}

IntMatrix IntMatrix::operator-(const IntMatrix& mat) const {
    return *this + (-mat);
}

IntMatrix& IntMatrix::operator+=(int value) {
    for(IntMatrix::iterator it = begin(); it != end(); ++it){
        *it += value;
    }
    return *this;
}

IntMatrix IntMatrix::operator<(int value) const{
    assert(dimensions.getRow() > 0 and dimensions.getCol() > 0);
    IntMatrix temp(dimensions);
    int col_length = dimensions.getCol();
    for (int i = 0; i < dimensions.getRow(); i++) {
        for (int j = 0; j < col_length; j++) {
            if(matrix[col_length * i + j] < value){
                temp(i,j) = 1;
            }
        }
    }
    return temp;
}

IntMatrix IntMatrix::operator<=(int value) const{
    assert(dimensions.getRow() > 0 and dimensions.getCol() > 0);
    IntMatrix temp(dimensions);
    int col_length = dimensions.getCol();
    for (int i = 0; i < dimensions.getRow(); i++) {
        for (int j = 0; j < col_length; j++) {
            if(matrix[col_length * i + j] <= value){
                temp(i,j) = 1;
            }
        }
    }
    return temp;
}

IntMatrix IntMatrix::operator>(int value) const{
    assert(dimensions.getRow() > 0 and dimensions.getCol() > 0);
    IntMatrix temp(dimensions);
    int col_length = dimensions.getCol();
    for (int i = 0; i < dimensions.getRow(); i++) {
        for (int j = 0; j < col_length; j++) {
            if(matrix[col_length * i + j] > value){
                temp(i,j) = 1;
            }
        }
    }
    return temp;
}

IntMatrix IntMatrix::operator>=(int value) const{
    assert(dimensions.getRow() > 0 and dimensions.getCol() > 0);
    IntMatrix temp(dimensions);
    int col_length = dimensions.getCol();
    for (int i = 0; i < dimensions.getRow(); i++) {
        for (int j = 0; j < col_length; j++) {
            if(matrix[col_length * i + j] >= value){
                temp(i,j) = 1;
            }
        }
    }
    return temp;
}

IntMatrix operator+(const IntMatrix& mat, int value){
    IntMatrix temp(mat);
    return temp += value;
}

IntMatrix operator+(int value, IntMatrix& mat){
    IntMatrix temp(mat);
    return temp += value;
}

bool IntMatrix::iterator::operator==(const IntMatrix::iterator& it1) const{
    assert(it1.mat == mat);
    return *(*this) == *it1;
}

bool IntMatrix::iterator::operator!=(const IntMatrix::iterator& it1) const{
    return !(*this == it1);
}

IntMatrix::const_iterator::const_iterator(const IntMatrix*  mat, int row, int col) : row(row),
col(col), mat(mat){}

bool IntMatrix::const_iterator::operator==(const IntMatrix::const_iterator& it1){
    assert(it1.mat == mat);
    return *(*this) == *it1;
}

bool IntMatrix::const_iterator::operator!=(const IntMatrix::const_iterator& it1){
    return !(*this == it1);
}

IntMatrix::iterator::iterator(const IntMatrix* mat, int row, int col) : mat(mat), row(row),
col(col){}




