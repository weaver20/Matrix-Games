
#ifndef EX3_INTMATRIX_H
#define EX3_INTMATRIX_H
#include "Auxiliaries.h"

namespace mtm {

    class IntMatrix {
        Dimensions dimensions;
        int *matrix;

    public:

        IntMatrix(const Dimensions&, int = 0);
        IntMatrix(const IntMatrix&);
        IntMatrix& operator=(const IntMatrix&);
        ~IntMatrix();

        IntMatrix& Identity(unsigned int);
        int height();
        int width();
        int size();
        IntMatrix& transpose();
        IntMatrix operator+(const IntMatrix) const;
        IntMatrix operator-() const;
        IntMatrix operator-(const IntMatrix) const;
        IntMatrix& operator+=(int);
        friend std::ostream& operator<<(std::ostream& os, const IntMatrix&);
        int& operator()(int, int);
        const int& operator()(int, int) const;
    };

    IntMatrix operator+(IntMatrix, int);
    IntMatrix operator+(int, IntMatrix);

}



#endif //EX3_INTMATRIX_H
