
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
        class iterator;
        class const_iterator;
        iterator begin() const;
        iterator end() const;
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

    class IntMatrix::iterator{
        Dimensions index;
        const IntMatrix* mat;
      //  iterator(const IntMatrix* mat, Dimensions dim); // Should be public and should be a copy c`tor - (See page 9, last comment)
        friend class IntMatrix;

    public:
        iterator(const IntMatrix* mat);    // Copy c`tor
        int& operator*() const;
        iterator operator++(int); // Postfix
        iterator operator++();    // Prefix
    };

    bool operator==(IntMatrix::iterator it1, IntMatrix::iterator it2);
    bool operator!=(IntMatrix::iterator it1, IntMatrix::iterator it2);

    class IntMatrix::const_iterator{
        Dimensions index;
        const IntMatrix* mat;
    //    const_iterator(const IntMatrix* mat, Dimensions dim); // see comment at line 52
        friend class IntMatrix;

    public:
        const_iterator(const IntMatrix* mat); // Copy c`tor
        const int& operator*() const;
        iterator operator++(int);
        iterator operator++();
    };

    bool operator==(const IntMatrix::iterator it1, const IntMatrix::iterator it2);
    bool operator!=(const IntMatrix::iterator it1, const IntMatrix::iterator it2);
}



#endif //EX3_INTMATRIX_H
