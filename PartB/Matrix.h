#ifndef EX3_MATRIX_H
#define EX3_MATRIX_H
#include "Auxiliaries.h"


// use to check and simplify implementation
typedef int T;

namespace mtm {
    template<class T>
    class Matrix {
        Dimensions dimensions;
        T* matrix;

    public:
        /**
         * Constructor
         * TODO
         * assumptions of T class:
         *
         * @param dims
         * @param init_value
         * Exceptions:
         */
        Matrix(const Dimensions& dims, const T& init_value = T())  {}  // Aviram.

        /**
         * Copy c`tor
         *  TODO
         * assumptions of T class:
         *
         * @param other
         *
         */
        Matrix<T>(const Matrix<T>& other) {} // Aviram
        /**
         * Assignment operator
         * TODO
         * assumptions of T class:
         *
         * @param other
         */
        Matrix<T>&  operator=(const Matrix<T>& other) {} // Aviram
        /**
         * D`or
         * TODO
         * assumptions of T class:
         *
        */
        ~Matrix<T>() {}         // Aviram

        /**
         * creates the transposed Matrix
         * TODO
         * assumptions of T class:
         *
         * Exceptions:
         */
        Matrix<T> transpose() const {} // Aviram

        /**
         * adding two Matrix`s
         * TODO
         * assumptions of T class:
         *
         * Exceptions:
         */
        Matrix<T> operator+(const Matrix<T>& other) const {} // Aviram

        /**
         * unary operator -
         * TODO
         * assumptions of T class:
         *
         * Exceptions:
         */
        Matrix<T> operator-() const {} // Aviram

        /**
         * Binary operator -
         * TODO
         * assumptions of T class:
         *
         * Exceptions:
         */
        Matrix<T> operator-(const Matrix<T>& other) const {} // Aviram

        /**
         * Sum of a Matrix with an Object (Matrix at left side)
         * TODO
         * assumptions of T class:
         *
         * Exceptions:
         */
        Matrix<T> operator+(const T& t) const {} // Aviram

        /**
         * Sum of a Matrix with a T Object (Matrix at right side)
         * TODO
         * assumptions of T class:
         *
         * Exceptions:
         */
        friend Matrix<T> operator+(T& t, const Matrix<T>& mat) {}// Aviram

        /**
         *  Sum to current Matrix with a T object
         * TODO
         * assumptions of T class:
         *
         * Exceptions:
         */
        Matrix<T>& operator+=(const T& t) {} // Aviram

        /**
         * defines logical expression <
         * TODO
         * assumptions of T class:
         *
         * Exceptions:
         */
        Matrix<bool> operator<(const T& t) const {} // Aviram

        /**
         * defines logical expression <=
         * TODO
         * assumptions of T class:
         *
         * Exceptions:
         */
        Matrix<bool> operator<=(const T& t) const {} // Aviram

        /**
         * defines logical expression >
         * TODO
         * assumptions of T class:
         *
         * Exceptions:
         */
        Matrix<bool> operator>(const T& t) const {} // Aviram

        /**
         * defines logical expression >=
         * TODO
         * assumptions of T class:
         *
         * Exceptions:
         */
        Matrix<bool> operator>=(const T& t) const {} // Aviram

        /**
         * return a new Matrix with values after application of a functor
         * TODO
         * assumptions of T class:
         *
         * Exceptions:
         */
        template<class Application>
        Matrix<T> apply(Application c) const {} // Aviram



        /* ******************** iterator Class ******************** */
        class iterator {
            int row;
            int col;
            Matrix<T>* mat;
            /** private c`tor used by begin/end functions.
            * TODO
            * assumptions of T class:
            *
            * Exceptions:
            *
            */
            explicit iterator(Matrix<T>* mat, int row = 0, int col = 0) {} // Aviram
            friend class Matrix<T>;

        public:
            iterator(const iterator& it) = default; // TODO is it?
            iterator& operator=(const iterator&) = default; // TODO is it?
            ~iterator() = default;  // TODO is it?

            /**
             * boolean equals operator between iterators
             * @param it1 iterator to compare
             * @return true - if it1 points to the same cell in the same matrix as this
             *         false - otherwise.
             */
            bool operator==(const iterator& it1) const;    // Aviram
            /**
            * boolean not equals operator between iterators
            * @param it1 iterator to compare
            * @return false - if it1 points to the same cell in the same matrix as this
            *         true - otherwise.
            */
            bool operator!=(const iterator& it1) const;    // Aviram

            /**
             * defining operator * - Read & Write access to cell pointed by iterator
             * @return T& to cell
             * TODO
             * assumptions of T class:
             *
             * Exceptions:
             *
             */
            T& operator*() const {}  // Noam
            /**
             * Increment Postfix operator
             * TODO
             * assumptions of T class:
             *
             * Exceptions:
             *
             */
            iterator operator++(int) {} // Noam
            /**
             * Increment Prefix operator
             * TODO
             * assumptions of T class:
             *
             * Exceptions:
             *
            */
            iterator operator++() {} // Noam
        };

        /* ******************** const_iterator Class ******************** */

        class const_iterator {
            int row;
            int col;
            Matrix<T>* mat;
            /** private c`tor used by begin/end functions.
            * TODO
            * assumptions of T class:
            *
            * Exceptions:
            *
            */
            explicit const_iterator(Matrix<T>* mat, int row = 0, int col = 0) {} // Aviram
            friend class Matrix<T>;

        public:
            const_iterator(const const_iterator& it) = default; // TODO is it?
            const_iterator& operator=(const const_iterator&) = default; // TODO is it?
            ~const_iterator() = default;  // TODO is it?

            /**
             * boolean equals operator between iterators
             * @param it1 iterator to compare
             * @return true - if it1 points to the same cell in the same matrix as this
             *         false - otherwise.
             */
            bool operator==(const const_iterator& it1) const {}   // Aviram
            /**
            * boolean not equals operator between iterators
            * @param it1 iterator to compare
            * @return false - if it1 points to the same cell in the same matrix as this
            *         true - otherwise.
            */
            bool operator!=(const const_iterator& it1) const {}   // Aviram

            /**
             * defining operator * - Read & Write access to cell pointed by iterator
             * @return T& to cell
             */
            const T& operator*() const {}  // Noam
            /**
             * Increment Postfix operator
             */
            const_iterator operator++(int) {} // Noam
            /**
            * Increment Prefix operator
            */
            const_iterator operator++() {} // Noam
        };












        /**
         * Matrix begin function
         * @return an iterator that points to the first cell (0,0)
         * TODO
         * assumptions of T class:
         *
         * Exceptions:
         */
        iterator begin() {} // Noam
        /**
         * const Matrix begin function
         * @return a const_iterator that points to the first cell (0,0)
         *
         * TODO
         * assumptions of T class:
         *
         * Exceptions:
         */
        const_iterator begin() const {} // Noam
        /**
         * Matrix end function
         * @return an iterator that points to the last cell in the matrix
         *
         * TODO
         * assumptions of T class:
         *
         * Exceptions:
         */
        iterator end() {} // Noam
        /**
        * const Matrix end function
        * @return a const_iterator that points to the last cell in the matrix
         *
         * TODO
         * assumptions of T class:
         *
         * Exceptions:
        */
        const_iterator end() const {} // Noam
        /**
         * a static function that creates a matrix of the size of dim x dim
         * initialize all the cells that are NOT in the main Diagonal to default value
         * and initialize main Diagonal cells to init_value.
         * @return a new Matrix accordingly
         *
         * TODO
         * assumptions of T class:
         *
         * Exceptions:
         */
        static Matrix<T> Diagonal(int dim, const T& init_value) {} // Noam

        /**
         * @return number of lines in matrix
         */
        inline int height() const {} // Noam
        /**
         * @return number of columns in matrix
         */
        inline int width() const {} // Noam
        /**
         * @return number of cells in matrix
         */
        inline int size() const {} // Noam
        /**
         * defining output operator for matrix
         * @param os
         * @return
         *
         * TODO
         * assumptions of T class:
         *
         * Exceptions:
         */
        friend std::ostream &operator<<(std::ostream &os, const Matrix<T> &to_print) {} // Noam
        /**
         * defining () operator for Matrix - Read & Write
         * @return reference to cell (i,j)
         *
         * TODO
         * assumptions of T class:
         *
         * Exceptions:
         *
         */
        T& operator()( int row_num, int col_num) {} // Noam
        /**
         * defining () operator for Matrix - Read Only
         * @return reference to cell (i,j)
         *
         * TODO
         * assumptions of T class:
         *
         * Exceptions:
         */
        const T& operator()( int row_num, int col_num) const {} // Noam

        /**
         * creates a boolean Matrix and sets cells to:
         *      true - if the object in the cell == t
         *      false - otherwise
         * @param t
         * @return the created boolean Matrix
         *
         * TODO
         * assumptions of T class:
         *
         * Exceptions:
         *
         */
        Matrix<bool> operator==(const T& t) const {} // Noam

        /**
         * creates a boolean Matrix and sets cells to:
         *      true - if the object in the cell != t
         *      false - otherwise
         * @param t
         * @return the created boolean Matrix
         *
         * TODO
         * assumptions of T class:
         *
         * Exceptions:
         *
         */
        Matrix<bool> operator!=(const T& t) const {} // Noam




        // Exception Classes
        class AccessIllegalElement : public std::exception {

        public:
            const char* what() const noexcept override  {
                return "Mtm matrix error: An attempt to access an illegal element";
            }
        };
        class IllegalInitialization : public std::exception {
        public:
            const char* what() const noexcept override  {
                return "Mtm matrix error: Illegal initialization values";
            }
        };
        class DimensionMismatch : public std::exception {
            const Dimensions first;
            const Dimensions second;
            friend class Matrix;
            DimensionMismatch(const Dimensions& first, const Dimensions& second) : first(first), second(second) {}
        public:
            const char* what() const noexcept override  {}
        };
    };

    /**
     * this function checks the boolean values of the object in the matrix
     * @param matrix
     * @return
     * true - if the boolean values of the cells are all true.
     * false - otherwise.
     *
     * TODO
     * assumptions of T class:
     *
     * Exceptions:
     *
     */
    bool all(const Matrix<T>& matrix) {} // Noam

    /**
     * this function checks the boolean values of the object in the matrix
     * @param matrix
     * @return
     * true - if at least one boolean value of one of the cells are true.
     * false - otherwise.
     *
     * TODO
     * assumptions of T class:
     *
     * Exceptions:
     *
     */
    bool any(const Matrix<T>& matrix) {} // Noam

}

#endif //EX3_MATRIX_H
