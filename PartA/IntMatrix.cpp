#include "IntMatrix.h"

namespace mtm {

    IntMatrix::iterator IntMatrix::begin() {
        return IntMatrix::iterator(this,0,0);
    }
    IntMatrix::const_iterator IntMatrix::begin() const {
        return IntMatrix::const_iterator(this,0,0);
    }
    IntMatrix::iterator IntMatrix::end() {
        return IntMatrix::iterator(this, this->height()-1, this->width()-1);
    }

    IntMatrix::const_iterator IntMatrix::end() const {
        return IntMatrix::const_iterator(this, this->height()-1, this->width()-1);
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

    int& IntMatrix::operator()( int row_num, int cul_num)  {
        return  *(matrix + dimensions.getCol() * row_num + cul_num);
    }

    const int& IntMatrix::operator()(int row_num, int cul_num) const {
        return  *(matrix + dimensions.getCol() * row_num + cul_num);
    }



    std::ostream& operator<<(std::ostream& os, const IntMatrix& to_print) {
        std::string matrix_in_string = printMatrix(to_print.matrix, to_print.dimensions);
        os << matrix_in_string;

        return os;
    }

    IntMatrix IntMatrix::operator==(int num) const {
        IntMatrix result(dimensions);
        markEquals(result,num, 1);
        return result;
    }

    IntMatrix IntMatrix::operator!=(int num) const {
        IntMatrix result(dimensions,1);
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

     int IntMatrix::const_iterator::operator*() const {
        return mat->operator()(row,col);
    }

    IntMatrix::const_iterator IntMatrix::const_iterator::operator++(int) {
        const_iterator result = *this;
        if(col == mat->width()) {
            col = 0;
            row++;
        }
        else {
            col++;
        }
        return result;
    }

    IntMatrix::const_iterator IntMatrix::const_iterator::operator++() {
        if(col == mat->width()) {
            col = 0;
            row++;
        }
        else {
            col++;
        }
        return *this;
    }
}