
#ifndef EX3_INTMATRIX_H
#define EX3_INTMATRIX_H
#include "Auxiliaries.h"

namespace mtm {

    class IntMatrix {
        Dimensions dimensions;
        int *matrix;
        void markEquals(IntMatrix &to_mark, int num, int mark_value) const;

    public:

        explicit IntMatrix(const Dimensions& dims, int  value = 0); // Done
        IntMatrix(const IntMatrix&);     // Done
        IntMatrix& operator=(const IntMatrix&);     // Done
        class iterator;
        class const_iterator;
        const_iterator begin() const;                           // Done
        iterator begin() ;                                      // Done
        const_iterator end() const;                             // Done
        iterator end() ;                                        // Done
        ~IntMatrix();                               // Done
        static IntMatrix Identity(unsigned int);                                         // Done

        int height() const;                                                              // Done
        int width() const;                                                               // Done
        int size() const;                                                                // Done
        IntMatrix transpose() const;                // Done
        IntMatrix operator+(const IntMatrix&) const;//Done
        IntMatrix operator-() const;                //Done
        IntMatrix operator-(const IntMatrix&) const; //Done
        IntMatrix& operator+=(int);                 // Done
        friend std::ostream& operator<<(std::ostream& os, const IntMatrix&);        // Done
        int& operator()(int, int); // Read&Write                                    // Done
        const int& operator()(int, int) const; // Read Only                         // Done
        IntMatrix operator<(int) const;                                         // Done
        IntMatrix operator<=(int) const;                                        // Done
        IntMatrix operator>(int) const;                                         // Done
        IntMatrix operator>=(int) const;                                        // Done
        IntMatrix operator==(int) const;                                             // Done
        IntMatrix operator!=(int) const;                                             // Done

    };

    IntMatrix operator+(const IntMatrix, int);                                  // Noam
    IntMatrix operator+(int, const IntMatrix);                                  // Noam
    bool all(const IntMatrix&);                                                       // Done
    bool any(const IntMatrix&);                                                       // Done

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
        ~iterator() = default;                                                             // Noam
        int& operator*() const;                                                       // Done
        iterator operator++(int); // Postfix                                          // Done
        iterator operator++();    // Prefix                                           // Done
        bool operator==(const IntMatrix::iterator& it1) const; //Done
        bool operator!=(const IntMatrix::iterator& it1) const; //Done
    };


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
        ~const_iterator() = default;                                                     // Noam
        int operator*() const;                                               // Done
        const_iterator operator++(int);                                      // Done
        const_iterator operator++();                                         // Done
        bool operator==(const IntMatrix::const_iterator& it1);
        bool operator!=(const IntMatrix::const_iterator& it1);

    };


}



#endif //EX3_INTMATRIX_H
