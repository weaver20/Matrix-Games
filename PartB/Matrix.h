#ifndef EX3_MATRIX_H
#define EX3_MATRIX_H
#include "Auxiliaries.h"


// use to check and simplify implementation
typedef int T;

namespace mtm {
    /**
     * Matrix Class
     * @tparam T - type of data
     *  basic assumptions of T class:
     *      no parameters C`tor
     *      Assignment operator
     *      T Assignment operator and C`tor throw only std::bad_alloc exceptions.
     *
     */
    template<class T>
    class Matrix {
        Dimensions dimensions;
        T* matrix;

    public:
        /**
         * Constructor
         * assumptions of T class:
         *      basic assumptions.
         * @param dims - dimensions of the matrix
         * @param init_value - initialize all the matrix to this value
         * Exceptions:
         *      IllegalInitialization() - if one of the dimensions are not a positive number
         *      std::bad_alloc() - if there`s an allocation problem
         */
        explicit Matrix(const Dimensions& dims, const T& init_value = T())     // Aviram.
                : dimensions(dims.getRow(), dims.getCol())
        {
            if(dimensions.getRow() <=0 or dimensions.getCol() <=0) {
                throw IllegalInitialization();
            }

            matrix = new T[size()];
            try {
                for (iterator it = begin() ; it != end() ; it++) {
                    *it = init_value;
                }
            }
            catch (std::bad_alloc&) {
                delete[] matrix;
                throw;
            }

        }

        /**
         * Copy c`tor
         * assumptions of T class:
         *      basic assumptions
         * @param other - copy this matrix
         *      std::bad_alloc() - if there`s an allocation problem
         */
        Matrix<T>(const Matrix<T>& other) :                 // Aviram
                dimensions(other.height(), other.width()) {

            matrix = new T[other.size()];
            const_iterator other_it = other.begin();
            try {
                for (iterator it = begin() ; it != end() ; it++) {
                    *it = *(other_it++);
                }
            }
            catch (std::bad_alloc&) {
                delete[] matrix;
                throw;
            }

        }
        /**
         * Assignment operator
         *
         * assumptions of T class:
         *      basic assumptions
         * @param other
         * Exceptions:
         *      std::bad_alloc() - if there`s an allocation problem
         */
        Matrix<T>&  operator=(const Matrix<T>& other) {     // Aviram
            if(this == &other) {
                return *this;
            }
            T* temp_matrix = new T[other.size()];
            Dimensions temp_dims(other.height(), other.width());
            const_iterator other_it = other.begin();
            try {
                for (iterator it = begin() ; it != end() ; it++) {
                    *it = *(other_it++);
                }
            }
            catch (std::bad_alloc&) {
                delete[] temp_matrix;
                throw;
            }
            delete[] matrix;
            matrix = temp_matrix;
            dimensions = temp_dims;

            return *this;

        }
        /**
         * D`or
         *
         * assumptions of T class:
         *      basic assumptions
         *      D`or
         * Exceptions:
         *      none.
        */
        ~Matrix<T>() {       // Aviram
            delete[] matrix;
        }

        /**
         * creates the transposed Matrix
         * TODO
         * assumptions of T class:
         *          basic assumptions
         *          iterator assignment operator
         *          iterator * operator
         * Exceptions:
         *      std::bad_alloc() - if there`s an allocation problem
         */
        Matrix<T> transpose() const {       // Aviram
            Matrix<T> transposed_mat(Dimensions(width(),height()));
            // transposed_mat and this Matrix has the same size!

            for (iterator it = transposed_mat.begin();
                 it != transposed_mat.end();
                 it++) {
                *it = *this(it.col, it.row);
            }
            return transposed_mat;

        }

        /**
         * adding two Matrix`s
         * assumptions of T class:
         *      basic assumptions
         *      += operator
         * Exceptions:
         *      DimensionMismatch - if the 2 Matrix`s arent at the same size.
         *      std::bad_alloc() - if there`s an allocation problem
         */
        Matrix<T> operator+(const Matrix<T>& other) const { // Aviram
            // validate same size
            if(dimensions != other.dimensions) {
                throw DimensionMismatch();
            }
            // copy current matrix
            Matrix<T> sum_mat(*this);
            const_iterator other_it = other.begin();
            // sums the second mat to the copy of the first.
            for(iterator sum_it = sum_mat.begin() ; sum_it != sum_mat.end() ; sum_it++, other_it++) {
                *sum_it += *other_it;
            }

            return sum_mat;

        }

        /**
         * unary operator -
         *
         * assumptions of T class:
         *      basic assumptions
         *      unary operator -
         *
         * Exceptions:
         *      std::bad_alloc() - if there`s an allocation problem
         */
        Matrix<T> operator-() const {           // Aviram
            Matrix<T> neg_mat(*this);

            for (iterator it = neg_mat.begin() ; it != neg_mat.end() ; it++) {
                *it = -*it;
            }

            return neg_mat;
        }

        /**
         * Binary operator (-)
         *
         * assumptions of T class:
         *      basic assumptions
         *      unary operator -
         *      binary operator +
         * Exceptions:
         *      std::bad_alloc() - if there`s an allocation problem
         */
        Matrix<T> operator-(const Matrix<T>& other) const {  // Aviram
            return *this + (-other);
        }

        /**
         *  Sum to current Matrix with a T object
         * TODO
         * assumptions of T class:
         *      basic assumptions
         *      operator +=
         * Exceptions:
         */
        Matrix<T>& operator+=(const T& t) {     // Aviram

            for(iterator it = begin(); it != end() ; it++) {
                *it += t;
            }
            return *this;
        }

        /**
         * Sum of a Matrix with an Object (Matrix at left side)
         * TODO
         * assumptions of T class:
         *      basic assumptions
         *      operator +=
         * Exceptions:
         *      std::bad_alloc() - if there`s an allocation problem
         */
        Matrix<T> operator+(const T& t) const {     // Aviram
            Matrix<T> temp(*this);
            return temp += t;
        }


        // TODO : Fix code Multiplication??
        /**
         * defines logical expression <
         *
         * assumptions of T class:
         *      basic assumptions
         *      operator <
         * Exceptions:
         *      std::bad_alloc() - if there`s an allocation problem
         */
        Matrix<bool> operator<(const T& t) const {      // Aviram
            Matrix<bool> bool_mat(dimensions, false);
            const_iterator c_it = begin();

            for(iterator bool_it = bool_mat.begin() ;
                bool_it != bool_mat.end() ;
                bool_it++, c_it++) {

                if(*c_it < t) {
                    *bool_it = true;
                }
            }

        }
        /**
         * defines logical expression <=
         *
         * assumptions of T class:
         *      basic assumptions
         *      TODO update this!
         * Exceptions:
         *      std::bad_alloc() - if there`s an allocation problem
         */
        Matrix<bool> operator<=(const T& t) const {             // Aviram
            return operator==(t) + operator<(t);
        }

        /**
         * defines logical expression >
         *
         * assumptions of T class:
         *      basic assumptions
         *      TODO: UPDATE THIS
         * Exceptions:
         *      std::bad_alloc() - if there`s an allocation problem
         */
        Matrix<bool> operator>(const T& t) const {          // Aviram
            // creating the "reverse" matrix.
            Matrix<bool> small_equals = operator<=(t);
            // "reversing" the matrix. (all true will be false and all false will be true)
            return small_equals.operator!=(true);
        }
        // TODO: Continue here!!!!!!! *********************************************
        // TODO: Continue here!!!!!!! *********************************************
        // TODO: Continue here!!!!!!! *********************************************
        /**
         * defines logical expression >=
         *
         * assumptions of T class:
         *      basic assumptions
         *      operator >=
         * Exceptions:
         *      std::bad_alloc() - if there`s an allocation problem
         */
        Matrix<bool> operator>=(const T& t) const {         // Aviram
            Matrix<bool> bool_mat(dimensions, false);
            const_iterator c_it = begin();

            for(iterator bool_it = bool_mat.begin() ;
                bool_it != bool_mat.end() ;
                bool_it++, c_it++) {

                if(*c_it >= t) {
                    *bool_it = true;
                }
            }


        }
        /**
         * return a new Matrix with values after application of a functor
         * TODO
         * assumptions of T class:
         *
         * Exceptions:
         */
        template<class Operation>
        Matrix<T> apply(Operation& operate) const { // Aviram









        }



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
       * Sum of a Matrix with a T Object (Matrix at right side)
       *
       * assumptions of T class:
       *      basic assumptions
       *      operator +
       * Exceptions:
       *      std::bad_alloc() - if there`s an allocation problem
       */
    Matrix<T> operator+(const T& t, const Matrix<T>& mat) {    // Aviram
        return mat + t;
    }
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
