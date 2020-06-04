
#ifndef EX3_INTMATRIX_H
#define EX3_INTMATRIX_H
#include "Auxiliaries.h"

namespace mtm {

    class IntMatrix {
        Dimensions dimensions;
        int *matrix;

    public:

        IntMatrix(const Dimensions&, int = 0);      // TODO: Noam
        IntMatrix(const IntMatrix&);                // TODO: Noam
        IntMatrix& operator=(const IntMatrix&);     // TODO: Noam
        class iterator;
        class const_iterator;
        iterator begin() const;                     // Aviram
        iterator end() const;                       // Aviram
        ~IntMatrix();                               // TODO: Noam

        IntMatrix& Identity(unsigned int);          // Aviram
        int height();                               // Aviram
        int width();                                // Aviram
        int size();                                 // Aviram
        IntMatrix& transpose();                     // TODO: Noam
        IntMatrix operator+(const IntMatrix) const; // TODO: Noam
        IntMatrix operator-() const;                // TODO: Noam
        IntMatrix operator-(const IntMatrix) const; // TODO: Noam
        IntMatrix& operator+=(int);                 // TODO: Noam
        friend std::ostream& operator<<(std::ostream& os, const IntMatrix&);    // Aviram
        int& operator()(int, int); // Read&Write                                // Aviram
        const int& operator()(int, int) const; // Read Only                     // Aviram
        IntMatrix operator<(int) const;                                         // TODO: Noam
        IntMatrix operator<=(int) const;                                        // TODO: Noam
        IntMatrix operator>(int) const;                                         // TODO: Noam
        IntMatrix operator>=(int) const;                                        // TODO: Noam
        IntMatrix operator==(int) const;                                        // Aviram
        IntMatrix operator!=(int) const;                                        // Aviram

    };

    IntMatrix operator+(const IntMatrix, int);                                  // TODO: Noam
    IntMatrix operator+(int, const IntMatrix);                                  // TODO: Noam
    bool all(const IntMatrix);                                                  // Aviram
    bool any(const IntMatrix);                                                  // Aviram


    //TODO: do we need to implement d`tor and operator =??


    class IntMatrix::iterator{
        Dimensions index;
        const IntMatrix* mat;
        iterator(const IntMatrix* mat, Dimensions dim);                         // TODO: Noam
        friend class IntMatrix;

    public:
        iterator(const iterator&) = default;    // Copy c`tor
        int& operator*() const;                                                  // Aviram
        iterator operator++(int); // Postfix                                     // Aviram
        iterator operator++();    // Prefix                                      // Aviram
        ~iterator();                                                             // TODO: Noam
        iterator& operator=(const iterator&);                                    // Aviram
    };

    bool operator==(IntMatrix::iterator it1, IntMatrix::iterator it2);          // TODO: Noam
    bool operator!=(IntMatrix::iterator it1, IntMatrix::iterator it2);          // TODO: Noam

    class IntMatrix::const_iterator{
        Dimensions index;
        const IntMatrix* mat;
        const_iterator(const IntMatrix* mat, Dimensions dim);                   // TODO: Noam
        friend class IntMatrix;

    public:
        const_iterator(const const_iterator&) = default; // Copy c`tor
        const int& operator*() const;                                          // Aviram
        iterator operator++(int);                                              // Aviram
        iterator operator++();                                                 // Aviram
        ~const_iterator();                                                     // TODO: Noam
        const_iterator& operator=(const const_iterator&);                      // Aviram
    };

    bool operator==(const IntMatrix::iterator it1, const IntMatrix::iterator it2);    // TODO: Noam
    bool operator!=(const IntMatrix::iterator it1, const IntMatrix::iterator it2);    // TODO: Noam
}



#endif //EX3_INTMATRIX_H
