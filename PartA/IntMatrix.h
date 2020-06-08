
#ifndef EX3_INTMATRIX_H
#define EX3_INTMATRIX_H
#include "Auxiliaries.h"

namespace mtm {

    class IntMatrix {
        Dimensions dimensions;
        int *matrix;
        void markEquals(IntMatrix &to_mark, int num, int mark_value) const;

    public:

        IntMatrix(const Dimensions&, int = 0);      // Noam
        IntMatrix(const IntMatrix&);                // Noam
        IntMatrix& operator=(const IntMatrix&);     // Noam
        class iterator;
        class const_iterator;
        iterator begin() ;                                                               // Done
        const_iterator begin() const;                                                    // Done
        iterator end() ;                                                                 // Done
        const_iterator end() const;                                                      // Done
        ~IntMatrix();                               // Noam
        static IntMatrix Identity(unsigned int);                                         // Done

        int height() const;                                                              // Done
        int width() const;                                                               // Done
        int size() const;                                                                // Done
        IntMatrix transpose() const;                // Noam
        IntMatrix operator+(const IntMatrix) const; // Noam
        IntMatrix operator-() const;                // Noam
        IntMatrix operator-(const IntMatrix) const; // Noam
        IntMatrix& operator+=(int);                 // Noam
        friend std::ostream& operator<<(std::ostream& os, const IntMatrix&);        // Done
        int& operator()(int, int); // Read&Write                                    // Done
        const int& operator()(int, int) const; // Read Only                         // Done
        IntMatrix operator<(int) const;                                         // Noam
        IntMatrix operator<=(int) const;                                        // Noam
        IntMatrix operator>(int) const;                                         // Noam
        IntMatrix operator>=(int) const;                                        // Noam
        IntMatrix operator==(int) const;                                             // TODO : Me
        IntMatrix operator!=(int) const;                                             // TODO : Me

    };

    IntMatrix operator+(const IntMatrix, int);                                  // Noam
    IntMatrix operator+(int, const IntMatrix);                                  // Noam
    bool all(const IntMatrix&);                                                       // TODO : Me
    bool any(const IntMatrix&);                                                       // TODO : Me

    /* ******************** iterator Class ******************** */


    class IntMatrix::iterator{
        int row;
        int col;
        IntMatrix* const mat;
        iterator(const IntMatrix* mat, int col_index, int row_index);                            // Noam
        friend class IntMatrix;
        bool isInMainDiagonal() const;                                                    // Done

    public:
        iterator(const iterator&) = default;
        iterator& operator=(const iterator&) = default;
        int& operator*() const;                                                       // Done
        iterator operator++(int); // Postfix                                          // Done
        iterator operator++();    // Prefix                                           // Done
        ~iterator();                                                             // Noam

    };

    bool operator==(IntMatrix::iterator it1, IntMatrix::iterator it2);          // Noam
    bool operator!=(IntMatrix::iterator it1, IntMatrix::iterator it2);          // Noam

    /* ******************** const_iterator Class ******************** */

    class IntMatrix::const_iterator{
        int row;
        int col;
        const IntMatrix* mat;
        const_iterator(const IntMatrix* mat, int col_index, int row_index);                   // Noam
        friend class IntMatrix;


    public:
        const_iterator(const const_iterator&) = default;
        const_iterator& operator=(const const_iterator&) = default;
        int operator*() const;                                               // Done
        const_iterator operator++(int);                                      // Done
        const_iterator operator++();                                         // Done
        ~const_iterator();                                                     // Noam

    };

    bool operator==(const IntMatrix::const_iterator it1, const IntMatrix::const_iterator it2);    // Noam
    bool operator!=(const IntMatrix::const_iterator it1, const IntMatrix::const_iterator it2);    // Noam
}



#endif //EX3_INTMATRIX_H
