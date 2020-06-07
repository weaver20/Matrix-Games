#include "IntMatrix.h"

namespace mtm {

    inline int IntMatrix::height() {
        return dimensions.getRow();
    }

    inline int IntMatrix::width() {
        return dimensions.getCol();
    }
    inline int IntMatrix::size() {
        return dimensions.getCol()*dimensions.getRow();
    }

    IntMatrix IntMatrix::Identity(unsigned int size) {
        IntMatrix identity_mat = IntMatrix(Dimensions(size,size));
        for(IntMatrix::iterator it = this->begin() ; it != this->end() ; it++ ) {
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
        return index.getRow() == index.getCol();
    }

    std::ostream& operator<<(std::ostream& os, const IntMatrix& to_print) {
        std::string matrix_in_string = printMatrix(to_print.matrix, to_print.dimensions);
        os << matrix_in_string;

        return os;
    }

}