
#include "IntMatrix.h"
#include <assert.h>
using namespace mtm;

IntMatrix::IntMatrix(const Dimensions &dims, int value): dimensions(dims.getRow(), dims.getCol()),
matrix(new int[dimensions.getRow() * dimensions.getCol()]) {
    for(IntMatrix::iterator it = begin(); it != end(); ++it){
        *it = value;
    }
}

IntMatrix::IntMatrix(const IntMatrix& mat): dimensions(mat.height(), mat.width()),
matrix(new int[mat.size()]) {
    for (IntMatrix::iterator it = begin(); it != end(); ++it){
        *it = mat(it.row, it.col);
    }
}

IntMatrix& IntMatrix::operator=(const IntMatrix& mat) {
    assert(dimensions == mat.dimensions);
    if (this == &mat) {
        return *this;
    }
    dimensions = Dimensions(mat.height(), mat.width());
    int col_length = dimensions.getCol();
    delete[] matrix;
    matrix = new int[mat.size()];
    for(IntMatrix::iterator it = begin(); it != end(); ++it){
        *it = mat(it.row, it.col);
    }
    return *this;
}

IntMatrix::~IntMatrix() {
    delete [] matrix;
}

IntMatrix IntMatrix::transpose() const {
    assert(dimensions.getRow() > 0 and dimensions.getCol() > 0);
    IntMatrix mat(dimensions);
    for(IntMatrix::iterator it = mat.begin(); it != mat.end(); ++it){
        *it = mat(it.col, it.row);
    }
    return mat;
}

IntMatrix IntMatrix::operator+(const IntMatrix& mat) const {
    assert(dimensions == mat.dimensions);
    IntMatrix temp1(dimensions);
    IntMatrix temp2(*this);
    for(IntMatrix::iterator it = temp1.begin(); it != temp1.end(); ++it){
        *it = mat(it.row, it.col) + temp2(it.row, it.col);
    }
    return temp1;
}

IntMatrix IntMatrix::operator-() const {
    IntMatrix temp1(dimensions);
    for(IntMatrix::iterator it = temp1.begin(); it != temp1.end(); ++it){
        *it = - temp1(it.row, it.col);
    }
    return temp1;
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
    IntMatrix temp1(dimensions), temp2(*this);

    for(IntMatrix::iterator it = temp1.begin(); it != temp1.end(); it){
        *it = temp2(it.row, it.col) < value ? 1 : 0;
    }
    return temp1;
}

IntMatrix IntMatrix::operator<=(int value) const{
    assert(dimensions.getRow() > 0 and dimensions.getCol() > 0);
    IntMatrix temp1(dimensions), temp2(*this);

    for(IntMatrix::iterator it = temp1.begin(); it != temp1.end(); it){
        *it = temp2(it.row, it.col) <= value ? 1 : 0;
    }
    return temp1;
}

IntMatrix IntMatrix::operator>(int value) const{
    assert(dimensions.getRow() > 0 and dimensions.getCol() > 0);
    IntMatrix temp1(dimensions), temp2(*this);

    for(IntMatrix::iterator it = temp1.begin(); it != temp1.end(); it){
        *it = temp2(it.row, it.col) > value ? 1 : 0;
    }
    return temp1;
}

IntMatrix IntMatrix::operator>=(int value) const{
    assert(dimensions.getRow() > 0 and dimensions.getCol() > 0);
    IntMatrix temp1(dimensions), temp2(*this);

    for(IntMatrix::iterator it = temp1.begin(); it != temp1.end(); it){
        *it = temp2(it.row, it.col) >= value ? 1 : 0;
    }
    return temp1;
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
    return not(it1.mat != mat or row != it1.row or col != it1.col);
}

bool IntMatrix::iterator::operator!=(const IntMatrix::iterator& it1) const{
    return !(*this == it1);
}

IntMatrix::const_iterator::const_iterator(const IntMatrix*  mat, int row, int col) : row(row),
col(col), mat(mat){}

bool IntMatrix::const_iterator::operator==(const IntMatrix::const_iterator& it1){
    return not(it1.mat != mat or row != it1.row or col != it1.col);
}

bool IntMatrix::const_iterator::operator!=(const IntMatrix::const_iterator& it1){
    return !(*this == it1);
}

IntMatrix::iterator::iterator(const IntMatrix* mat, int row, int col) : mat(mat), row(row),
col(col){}




