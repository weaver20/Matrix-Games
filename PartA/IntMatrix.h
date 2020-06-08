
#ifndef EX3_INTMATRIX_H
#define EX3_INTMATRIX_H
#include "Auxiliaries.h"

namespace mtm {

    class IntMatrix {
        Dimensions dimensions;
        int *matrix;

    public:

        explicit IntMatrix(const Dimensions& dims, int  value = 0); // Done
        IntMatrix(const IntMatrix&);     // Done
        IntMatrix& operator=(const IntMatrix&);     //Done
        class iterator;
        class const_iterator;
        const_iterator begin() const;                           // TODO : Me
        iterator begin() ;                                      // TODO : Me
        const_iterator end() const;                             // TODO : Me
        iterator end() ;                                        // TODO : Me
        ~IntMatrix();                               // Done
        static IntMatrix Identity(unsigned int);                                          // Done

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
        IntMatrix operator==(int) const;                                             // TODO : Me
        IntMatrix operator!=(int) const;                                             // TODO : Me

    };

    IntMatrix operator+(const IntMatrix&, int);                                  // Done
    IntMatrix operator+(int, const IntMatrix&);                                  // Done
    bool all(const IntMatrix&);                                                       // TODO : Me
    bool any(const IntMatrix&);                                                       // TODO : Me

    /* ******************** iterator Class ******************** */


    class IntMatrix::iterator{
        int row;
        int col;
        const IntMatrix* mat;
        explicit iterator(const IntMatrix* mat, int row = 0, int col = 0);  // Done
        friend class IntMatrix;
        bool isInMainDiagonal();                                                    // Done

    public:
        iterator(const iterator&) = default;    // Copy c`tor
        int& operator*() const;                                                       // Done
        iterator operator++(int); // Postfix                                          // Done
        iterator operator++();    // Prefix                                           // Done
        ~iterator() = default;                                                           // Done
        iterator& operator=(const iterator&) = default;                // maybe default?         // TODO : Me
        bool operator==(const IntMatrix::iterator& it1) const; //Done
        bool operator!=(const IntMatrix::iterator& it1) const; //Done
    };

    /* ******************** const_iterator Class ******************** */

    class IntMatrix::const_iterator{
        int row;
        int col;
        const IntMatrix* mat;
        explicit const_iterator(const IntMatrix* mat, int row = 0, int col = 0);  // Done
        friend class IntMatrix;


    public:
        const_iterator(const const_iterator&) = default; // Copy c`tor
        const int& operator*() const;                                               // TODO : Me
        iterator operator++(int);                                                   // TODO : Me
        iterator operator++();                                                      // TODO : Me
        ~const_iterator() = default;                                                     // Done
        const_iterator& operator=(const const_iterator&) = default;       // maybe default?         // TODO : Me
        bool operator==(const IntMatrix::const_iterator& it1);
        bool operator!=(const IntMatrix::const_iterator& it1);
    };

}



#endif //EX3_INTMATRIX_H
