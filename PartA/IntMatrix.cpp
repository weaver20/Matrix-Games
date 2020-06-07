#include "IntMatrix.h"

namespace mtm {

    inline int IntMatrix::height() const {
        return dimensions.getRow();
    }

    inline int IntMatrix::width() const {
        return dimensions.getCol();
    }
    inline int IntMatrix::size() const {
        return dimensions.getCol()*dimensions.getRow();
    }

    IntMatrix IntMatrix::Identity(unsigned int size) {
        IntMatrix identity_mat = IntMatrix(Dimensions(size,size));
        for(IntMatrix::iterator it = identity_mat.begin() ; it != identity_mat.end() ; it++ ) {
            if(it.isInMainDiagonal()) {
                *it = 1;
            }
        }
        return identity_mat;
    }

    int& IntMatrix::operator()( int row_num, int cul_num)  {
        return  *(matrix + dimensions.getCol() * row_num + cul_num);
    }

    const int& IntMatrix::operator()(int row_num, int cul_num) const {
        return  *(matrix + dimensions.getCol() * row_num + cul_num);
    }

    inline bool IntMatrix::iterator::isInMainDiagonal() {
        return row == col;
    }

    std::ostream& operator<<(std::ostream& os, const IntMatrix& to_print) {
        std::string matrix_in_string = printMatrix(to_print.matrix, to_print.dimensions);
        os << matrix_in_string;

        return os;
    }



    /* ******************* iterator functions ******************* */

    int& IntMatrix::iterator::operator*() const {
        return mat->operator()(row,col);
    }

    IntMatrix::iterator IntMatrix::iterator::operator++(int) {
        iterator result = *this;
        if(col == mat->width()) {
            col = 0;
            row++;
        }
        else {
            col++;
        }
        return result;
    }

    IntMatrix::iterator IntMatrix::iterator::operator++() {
        if(col == mat->width()) {
            col = 0;
            row++;
        }
        else {
            col++;
        }
        return *this;
    }


    /* ******************* const_iterator functions ******************* */

    const int& IntMatrix::const_iterator::operator*() const {
        return mat->operator()(row,col);
    }



}