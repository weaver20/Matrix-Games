
#ifndef EX3_INTMATRIX_H
#define EX3_INTMATRIX_H
#include "Auxiliaries.h"

namespace mtm {

    /**
     * This class represents a Matrix of int numbers.
     */
    class IntMatrix {
        Dimensions dimensions;
        int *matrix;
        void markEquals(IntMatrix &to_mark, int num, int mark_value) const;

    public:

        /**
         *  C`tor - create an IntMatrix in the size of dims and sets all cells to value (default=0)
         * @param dims - size of the matrix
         * @param value - cell values
         */
        explicit IntMatrix(const Dimensions& dims, int  value = 0);
        /**
         * Copy C`tor
         */
        IntMatrix(const IntMatrix&);
        /**
         * Assignment operator
         * @return a reference to the assigned Matrix.
         */
        IntMatrix& operator=(const IntMatrix&);
        // iterators to the matrix
        class iterator;
        class const_iterator;
        /**
         * const IntMatrix begin function
         * @return a const_iterator that points to the first cell (0,0)
         */
        const_iterator begin() const;
        /**
         * IntMatrix begin function
         * @return an iterator that points to the first cell (0,0)
         */
        iterator begin() ;
        /**
         * const IntMatrix end function
         * @return a const_iterator that points to the last cell in the matrix
         */
        const_iterator end() const;
        /**
         * IntMatrix end function
         * @return an iterator that points to the last cell in the matrix
         */
        iterator end() ;
        /**
         * Destructor
         */
        ~IntMatrix();
        /**
         * a static function that creates an Identity matrix of the size of NxN
         * @return an Identity Matrix
         */
        static IntMatrix Identity(unsigned int);
        /**
         *
         * @return number of lines in matrix
         */
        int height() const;
        /**
         *
         * @return number of columns in matrix
         */
        int width() const;
        /**
         *
         * @return number of cells in matrix
         */
        int size() const;
        /**
         * create a new IntMatrix that is the transposed of the matrix that is using this function.
         * @return the transposed matrix
         */
        IntMatrix transpose() const;
        /**
         * defining sum of matrix`s
         * @return the sum of two matrix`s
         */
        IntMatrix operator+(const IntMatrix&) const;
        /**
         * unary operator in matrix
         * @return the "negative" Matrix
         */
        IntMatrix operator-() const;
        /**
         *  defining substraction between to matrix`s
         * @return the difference.
         */
        IntMatrix operator-(const IntMatrix&) const;
        /**
         * defining += operator for matrix`s
         * @return
         */
        IntMatrix& operator+=(int);
        /**
         * define a sum of an int with an IntMatrix - IntMatrix as first parameter
         * @return the sum of the two
         */
        IntMatrix operator+(int) const;
        /**
         * defining output operator for matrix
         * @param os
         * @return
         */
        friend std::ostream& operator<<(std::ostream& os, const IntMatrix& to_print);
        /**
         * defining () operator for Matrix - Read & Write
         * @return reference to cell (i,j)
         */
        int& operator()(int, int);
        /**
         * defining () operator for Matrix - Read Only
         * @return reference to cell (i,j)
         */
        const int& operator()(int, int) const;
        /*
         * Defining logical operators
         */
        IntMatrix operator<(int) const;
        IntMatrix operator<=(int) const;
        IntMatrix operator>(int) const;
        IntMatrix operator>=(int) const;
        IntMatrix operator==(int) const;
        IntMatrix operator!=(int) const;

     

    };
    /**
    * define a sum of an int with an IntMatrix - int as first parameter
    * @return the sum of the two
    */
    IntMatrix operator+(int, const IntMatrix&);
    /**
     *
     * @return
     *          true - there`s no zeroes in the matrix
     *          false - otherwise
     */
    bool all(const IntMatrix&);
    /**
     *
     * @return
     *          false - if there`s no zero`s in the matrix
     *          true - otherwise.
     */
    bool any(const IntMatrix&);



    /* ******************** iterator Class ******************** */


    class IntMatrix::iterator{
        int row;
        int col;
        IntMatrix* mat;
        /*
         * Private C`or used only by IntMatrix class (begin, end functions)
         */
        explicit iterator(IntMatrix* mat, int row = 0, int col = 0);
        friend class IntMatrix;
        bool isInMainDiagonal() const;

    public:
        iterator(const iterator&) = default;
        iterator& operator=(const iterator&) = default;
        ~iterator() = default;
        /**
         * defining operator * - Read & Write access to cell pointed by iterator
         * @return int& to cell
         */
        int& operator*() const;
        /**
         * Increment Postfix operator
         */
        iterator operator++(int);
        /**
         * Increment Prefix operator
         */
        iterator operator++();
        /**
         * boolean equals operator between iterators
         * @param it1 iterator to compare
         * @return true - if it1 points to the same cell in the same matrix as this
         *         false - otherwise.
         */
        bool operator==(const IntMatrix::iterator& it1) const;
        /**
         * boolean not equals operator between iterators
         * @param it1 iterator to compare
         * @return false - if it1 points to the same cell in the same matrix as this
         *         true - otherwise.
         */
        bool operator!=(const IntMatrix::iterator& it1) const; //Done
    };



    /* ******************** const_iterator Class ******************** */

    class IntMatrix::const_iterator{
        int row;
        int col;
        const IntMatrix* mat;

        explicit const_iterator(const IntMatrix*  mat, int row = 0, int col = 0);

        friend class IntMatrix;


    public:

        const_iterator(const const_iterator&) = default;
        const_iterator& operator=(const const_iterator&) = default;
        ~const_iterator() = default;
        /**
         * defining operator * - Read  Only access to cell pointed by const_iterator
         * @return value of cell
         */
        int operator*() const;
        /**
         * Increment Postfix operator
         */
        const_iterator operator++(int);
        /**
        * Increment Prefix operator
        */
        const_iterator operator++();
        /**
         * boolean equals operator between const_iterators
         * @param it1 const_iterator to compare
         * @return true - if it1 points to the same cell in the same matrix as this
         *         false - otherwise.
         */
        bool operator==(const IntMatrix::const_iterator& it1);
        /**
       * boolean not equals operator between const_iterators
       * @param it1 const_iterator to compare
       * @return false - if it1 points to the same cell in the same matrix as this
       *         true - otherwise.
       */
        bool operator!=(const IntMatrix::const_iterator& it1);

    };


std::ostream& operator<<(std::ostream& os, const IntMatrix& to_print);



}



#endif //EX3_INTMATRIX_H
