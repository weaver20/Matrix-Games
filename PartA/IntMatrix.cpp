
#include "IntMatrix.h"
#include <assert.h>

using namespace mtm;

IntMatrix::iterator IntMatrix::begin() {
    return IntMatrix::iterator(this);
}
IntMatrix::const_iterator IntMatrix::begin() const {
    return IntMatrix::const_iterator(this);
}
IntMatrix::iterator IntMatrix::end() {
    return IntMatrix::iterator(this, this->height(), 0);
}

IntMatrix::const_iterator IntMatrix::end() const {
    return IntMatrix::const_iterator(this, this->height(), 0);
}


IntMatrix IntMatrix::Identity(unsigned int size) {
    IntMatrix identity_mat = IntMatrix(Dimensions(size,size));
    if (size == 1){
        identity_mat(0,0) = 1;
    }
    for(IntMatrix::iterator it = identity_mat.begin() ; it != identity_mat.end() ; it++ ) {
        if(it.isInMainDiagonal()) {
            *it = 1;
        }
    }
    return identity_mat;
}

inline bool IntMatrix::iterator::isInMainDiagonal() const {
    return row == col;
}

inline int IntMatrix::height() const {
    return dimensions.getRow();
}

inline int IntMatrix::width() const {
    return dimensions.getCol();
}
inline int IntMatrix::size() const {
    return dimensions.getCol()*dimensions.getRow();
}

int& IntMatrix::operator()( int row_num, int col_num)  {
    // skipping `row_num` rows and than going to 'col_num' cell in that row.
    return  *(matrix + width() * row_num + col_num);
}

const int& IntMatrix::operator()(int row_num, int col_name) const {
    return  *(matrix + width() * row_num + col_name);
}

namespace mtm {
    std::ostream &operator<<(std::ostream &os, const IntMatrix &to_print) {
        std::string matrix_in_string = printMatrix(to_print.matrix, to_print.dimensions);
        os << matrix_in_string;

        return os;
    }
}

IntMatrix IntMatrix::operator==(int num) const {
    // creating an all zeros matrix
    IntMatrix result(dimensions);
    // marking the cells that equals num  with '1's at the zeros matrix
    markEquals(result,num, 1);
    return result;
}

IntMatrix IntMatrix::operator!=(int num) const {
    //creating an all ones matrix
    IntMatrix result(dimensions,1);
    // marking the cells that equals num with '0' at the ones matrix.
    markEquals(result,num, 0);
    return result;
}

/**
 * marks a given matrix according to the value of the index in the matrix(this)
 * @param to_mark - marked matrix
 * @param num - number to compare
 * @param mark_value - use this value to mark index's.
 */
void IntMatrix::markEquals(IntMatrix &to_mark, int num, int mark_value) const {
    iterator mark_it = to_mark.begin();
    for(const_iterator c_it = begin() ; c_it != end() ; c_it++ , mark_it++) {
        if(*c_it == num) {
            *mark_it = mark_value;
        }
    }
}
namespace mtm {
    bool all(const IntMatrix &matrix) {
        for (IntMatrix::const_iterator it = matrix.begin(); it != matrix.end(); it++) {
            // one of the cells is 0
            if (*it == 0) {
                return false;
            }
            // result will stay true if no cell is 0
        }
        return true;
    }

    bool any(const IntMatrix &matrix) {
        for (IntMatrix::const_iterator it = matrix.begin(); it != matrix.end(); it++) {
            // if one of the cells is 0 - return true and end.
            if (*it != 0) {
                return true;
            }
            // if no cell is 0 -
            return false;
        }
        return true;
    }
}
/* ******************* iterator functions ******************* */

int& IntMatrix::iterator::operator*() const {
    return mat->operator()(row,col);
}

IntMatrix::iterator IntMatrix::iterator::operator++(int) {
    iterator result = *this;
    if(col == mat->width() - 1) {
        col = 0;
        row++;
    }
    else {
        col++;
    }
    // returning iterator before incrementing
    return result;
}

IntMatrix::iterator IntMatrix::iterator::operator++() {
    if(col == mat->width() - 1) {
        col = 0;
        row++;
    }
    else {
        col++;
    }
    // returning iterator before incrementing
    return *this;
}


/* ******************* const_iterator functions ******************* */

int IntMatrix::const_iterator::operator*() const {
    return mat->operator()(row,col);
}

IntMatrix::const_iterator IntMatrix::const_iterator::operator++(int) {
    const_iterator result = *this;
    if(col == mat->width() - 1) {
        col = 0;
        row++;
    }
    else {
        col++;
    }
    // returning const_iterator before incrementing
    return result;
}

IntMatrix::const_iterator IntMatrix::const_iterator::operator++() {
    if(col == mat->width() - 1) {
        col = 0;
        row++;
    }
    else {
        col++;
    }
    // returning incremented const_iterator
    return *this;
}

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
    IntMatrix mat(Dimensions(dimensions.getCol(), dimensions.getRow()));
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

    for(IntMatrix::iterator it = temp1.begin(); it != temp1.end(); ++it){
        *it = temp2(it.row, it.col) < value ? 1 : 0;
    }
    return temp1;
}

IntMatrix IntMatrix::operator<=(int value) const{
    assert(dimensions.getRow() > 0 and dimensions.getCol() > 0);
    IntMatrix temp1(dimensions), temp2(*this);

    for(IntMatrix::iterator it = temp1.begin(); it != temp1.end(); ++it){
        *it = temp2(it.row, it.col) <= value ? 1 : 0;
    }
    return temp1;
}

IntMatrix IntMatrix::operator>(int value) const{
    assert(dimensions.getRow() > 0 and dimensions.getCol() > 0);
    IntMatrix temp1(dimensions), temp2(*this);

    for(IntMatrix::iterator it = temp1.begin(); it != temp1.end(); ++it){
        *it = temp2(it.row, it.col) > value ? 1 : 0;
    }
    return temp1;
}

IntMatrix IntMatrix::operator>=(int value) const{
    assert(dimensions.getRow() > 0 and dimensions.getCol() > 0);
    IntMatrix temp1(dimensions), temp2(*this);

    for(IntMatrix::iterator it = temp1.begin(); it != temp1.end(); ++it){
        *it = temp2(it.row, it.col) >= value ? 1 : 0;
    }
    return temp1;
}

IntMatrix IntMatrix::operator+(int value) const{
    IntMatrix temp(*this);
    return temp += value;
}

namespace mtm {
    IntMatrix operator+(int value, const IntMatrix &mat) {
        return mat + value;
    }
}

bool IntMatrix::iterator::operator==(const IntMatrix::iterator& it1) const{
    return not(it1.mat != mat or row != it1.row or col != it1.col);
}

bool IntMatrix::iterator::operator!=(const IntMatrix::iterator& it1) const{
    return !(*this == it1);
}

IntMatrix::const_iterator::const_iterator(const IntMatrix* mat, int row, int col) : row(row),
col(col), mat(mat){}

bool IntMatrix::const_iterator::operator==(const IntMatrix::const_iterator& it1){
    return not(it1.mat != mat or row != it1.row or col != it1.col);
}

bool IntMatrix::const_iterator::operator!=(const IntMatrix::const_iterator& it1){
    return !(*this == it1);
}

IntMatrix::iterator::iterator(IntMatrix* mat, int row, int col) : row(row), col(col), mat(mat){}





