
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
        class Iterator;
        Iterator begin() const;
        Iterator end() const;
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
        int& operator()(int, int); // Read&Write
        const int& operator()(int, int) const; // Read Only
        IntMatrix operator<(int) const;
        IntMatrix operator<=(int) const;
        IntMatrix operator>(int) const;
        IntMatrix operator>=(int) const;
        IntMatrix operator==(int) const;
        IntMatrix operator!=(int) const;

    };

    IntMatrix operator+(const IntMatrix, int);
    IntMatrix operator+(int, const IntMatrix);
    bool all(const IntMatrix);
    bool any(const IntMatrix);

    class IntMatrix::Iterator{
        Dimensions index;
        const IntMatrix* mat;
        Iterator(const IntMatrix* mat, Dimensions dim);
        friend class IntMatrix;

    public:
        const int& operator*() const;
        Iterator operator++(int);
        Iterator operator++();
    };
    bool operator==(const IntMatrix::Iterator it1, const IntMatrix::Iterator it2);
    bool operator!=(const IntMatrix::Iterator it1, const IntMatrix::Iterator it2);

}



#endif //EX3_INTMATRIX_H
