#ifndef EX3_MATRIX_H
#define EX3_MATRIX_H
#include "Auxiliaries.h"
#include <cstring>
#include "Exceptions.h"

// use to check and simplify implementation
//typedef int T;

namespace mtm {

    /**
     * Matrix Class
     * @tparam T - type of data
     *  basic assumptions of T class:
     *      no parameters C`tor
     *      D`tor
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
         *      IllegalArgument() - if one of the dimensions are not a positive number
         *      std::bad_alloc() - if there`s an allocation problem
         */
        explicit Matrix<T>(const Dimensions& dims, const T& init_value = T());

        /**
         * Copy c`tor
         * assumptions of T class:
         *      basic assumptions
         * @param other - copy this matrix
         *      std::bad_alloc() - if there`s an allocation problem
         */
        Matrix<T>(const Matrix<T>& other);
        /**
         * Assignment operator
         *
         * assumptions of T class:
         *      basic assumptions
         * @param other
         * Exceptions:
         *      std::bad_alloc() - if there`s an allocation problem
         */
        Matrix<T>&  operator=(const Matrix<T>& other);
        /**
         * D`or
         *
         * assumptions of T class:
         *      basic assumptions
         * Exceptions:
         *      none.
        */
        ~Matrix<T>();

        /**
         * creates the transposed Matrix
         *
         * assumptions of T class:
         *          basic assumptions
         * Exceptions:
         *      std::bad_alloc() - if there`s an allocation problem
         */
        Matrix<T> transpose() const;

        /**
         * adding two Matrix`s
         * assumptions of T class:
         *      basic assumptions
         *      += operator
         * Exceptions:
         *      DimensionMismatch - if the 2 Matrix`s arent at the same size.
         *      std::bad_alloc() - if there`s an allocation problem
         */
        Matrix<T> operator+(const Matrix<T>& other) const;

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
        Matrix<T> operator-() const;

        /**
         * Binary operator (-)
         *
         * assumptions of T class:
         *      basic assumptions
         *      unary operator -
         *      += operator
         * Exceptions:
         *      std::bad_alloc() - if there`s an allocation problem
         */
        Matrix<T> operator-(const Matrix<T>& other) const;

        /**
         * Sum of a Matrix with an Object (Matrix at left side)
         *
         * assumptions of T class:
         *      basic assumptions
         *      operator +=
         * Exceptions:
         *      std::bad_alloc() - if there`s an allocation problem
         */
        Matrix<T> operator+(const T& t) const;

        /**
         *  Sum to current Matrix with a T object
         *
         * assumptions of T class:
         *      basic assumptions
         *      operator +=
         * Exceptions:
         */
        Matrix<T>& operator+=(const T& t);



        /**
         * defines logical expression <
         *
         * assumptions of T class:
         *      basic assumptions
         *      operator <
         * Exceptions:
         *      std::bad_alloc() - if there`s an allocation problem
         */
        Matrix<bool> operator<(const T& t) const;
        /**
         * defines logical expression <=
         *
         * assumptions of T class:
         *      basic assumptions
         *      operator <
         *      operator ==
         *
         * Exceptions:
         *      std::bad_alloc() - if there`s an allocation problem
         */
        Matrix<bool> operator<=(const T& t) const;

        /**
         * defines logical expression >
         *
         * assumptions of T class:
         *      basic assumptions
         *      operator ==
         *      operator <
         * Exceptions:
         *      std::bad_alloc() - if there`s an allocation problem
         */
        Matrix<bool> operator>(const T& t) const;
        /**
         * defines logical expression >=
         *
         * assumptions of T class:
         *      basic assumptions
         *      operator ==
         *      operator <
         * Exceptions:
         *      std::bad_alloc() - if there`s an allocation problem
         */
        Matrix<bool> operator>=(const T& t) const;
        /**
         * return a new Matrix with values after application of a functor
         *
         * assumptions of T class:
         *      basic assumptions
         *      Copy C`tor
         *      assume apply_func accepts T objects and implemented operator ().
         * Exceptions:
         *      std::bad_alloc() - if there`s an allocation problem
         */
        template<class Application>
        Matrix<T> apply(Application apply_func) const ;



        /* ******************** iterator Class ******************** */
        class iterator {
            int row;
            int col;
            Matrix<T>* mat;
            inline bool isInMainDiagonal() const;

            /** private c`tor used by begin/end functions.
            *
            * assumptions of T class:
            *       basic assumptions
            * Exceptions:
            *       none.
            */
            explicit iterator(Matrix<T>* mat, int row = 0, int col = 0);
            friend class Matrix<T>;

        public:
            /** Copy C`tor
            *
            * assumptions of T class:
            *       basic assumptions
            * Exceptions:
            *       none.
            */
            iterator(const iterator& it) = default;

            /** Assignment Operator
            *
            * assumptions of T class:
            *       basic assumptions
            * Exceptions:
            *       none.
            */
            iterator& operator=(const iterator&) = default;

            /** D`or
            *
            * assumptions of T class:
            *       basic assumptions
            * Exceptions:
            *       none.
            */
            ~iterator() = default;

            /**
             * boolean equals operator between iterators
             * @param it1 iterator to compare
             * @return true - if it1 points to the same cell in the same matrix as this
             *         false - otherwise.
             * Exceptions:
             *       none.
             */
            bool operator==(const iterator& it1) const;
            /**
            * boolean not equals operator between iterators
            * @param it1 iterator to compare
            * @return false - if it1 points to the same cell in the same matrix as this
            *         true - otherwise.
            * Exceptions:
            *       none.
            */
            bool operator!=(const iterator& it1) const;

            /**
           * defining operator * - Read & Write access to cell pointed by iterator
           * @return T& to cell
           *
           * assumptions of T class:
           *        basic assumptions
           * Exceptions:
           *         AccessIllegalElement - if iterator points to a cell that is not in the matrix.
           */
            T& operator*() const;
            /**
             * Increment Postfix operator
             *
             * assumptions of T class:
             *      basic assumptions
             * Exceptions:
             *      None.
             */
            const iterator operator++(int);
            /**
             * Increment Prefix operator
             *
             * assumptions of T class:
             *      basic assumptions
             * Exceptions:
             *      None.
            */
            iterator operator++();

            /**
             * returns GridPoint of the position of the iterator.
             * @return
             */
            GridPoint getGridPoint();
        };

        /* ******************** const_iterator Class ******************** */

        class const_iterator {
            int row;
            int col;
            const Matrix<T>* mat;

            /** private c`tor used by begin/end functions.
            *
            * assumptions of T class:
            *       basic assumptions
            * Exceptions:
            *       none.
            */
            explicit const_iterator(const Matrix<T>* mat, int row = 0, int col = 0);

            friend class Matrix<T>;

        public:

            /** Copy C`tor
            *
            * assumptions of T class:
            *       basic assumptions
            * Exceptions:
            *       none.
            */
            const_iterator(const const_iterator& it) = default;

            /** Assignment Operator
            *
            * assumptions of T class:
            *       basic assumptions
            * Exceptions:
            *       none.
            */
            const_iterator& operator=(const const_iterator&) = default;

            /** D`or
            *
            * assumptions of T class:
            *       basic assumptions
            * Exceptions:
            *       none.
            */
            ~const_iterator() = default;

            /**
             * boolean equals operator between iterators
             * @param it1 iterator to compare
             * @return true - if it1 points to the same cell in the same matrix as this
             *         false - otherwise.
             * Exceptions:
             *       none.
             */
            bool operator==(const const_iterator& it1) const;
            /**
            * boolean not equals operator between iterators
            * @param it1 iterator to compare
            * @return false - if it1 points to the same cell in the same matrix as this
            *         true - otherwise.
            * Exceptions:
            *       none.
            */
            bool operator!=(const const_iterator& it1) const;

            /**
              * defining operator * - Read & Write access to cell pointed by iterator
              * @return T& to cell
              */
            const T& operator*() const;
            /**
             * Increment Postfix operator
             */
            const const_iterator operator++(int);
            /**
            * Increment Prefix operator
            */
            const_iterator operator++();
        };


        /**
         * Matrix begin function
         * @return an iterator that points to the first cell (0,0)
         *
         * assumptions of T class:
         *      basic assumptions
         * Exceptions:
         *      None.
         */
        iterator begin();
        /**
         * const Matrix begin function
         * @return a const_iterator that points to the first cell (0,0)
         *
         * assumptions of T class:
         *      basic assumptions
         * Exceptions:
         *      None.
         */
        const_iterator begin() const;
        /**
         * Matrix end function
         * @return an iterator that points to the last cell in the matrix
         *
         * assumptions of T class:
         *      basic assumptions
         * Exceptions:
         *      None.
         */
        iterator end();
        /**
        * const Matrix end function
        * @return a const_iterator that points to the last cell in the matrix
         *
         * assumptions of T class:
         *      basic assumptions
         * Exceptions:
         *      None.
        */
        const_iterator end() const;
        /**
         * a static function that creates a matrix of the size of dim x dim
         * initialize all the cells that are NOT in the main Diagonal to default value
         * and initialize main Diagonal cells to init_value.
         * @return a new Matrix accordingly
         *
         *
         * assumptions of T class:
         *      basic assumptions
         * Exceptions:
         *      IllegalInitialization - if dim is not a positive number.
         *      std::bad_alloc - in case of an allocation problem.
         */
        static Matrix<T> Diagonal(int dim, const T& init_value);

        /**
         * @return number of lines in matrix
         */
        inline int height() const;
        /**
         * @return number of columns in matrix
         */
        inline int width() const;
        /**
         * @return number of cells in matrix
         */
        inline int size() const;


        /**
         * defining () operator for Matrix - Read & Write
         * @return reference to cell (i,j)
         *
         *
         * assumptions of T class:
         *      basic assumptions
         * Exceptions:
         *      AccessIllegalElement - if cell (i,j) is not in the matrix.
         */
        T& operator()(int row_num, int col_num);
        /**
         * Added this function to simplify working with GridPoints
         * @param coordinates
         * @return
         */
        T& operator()(const GridPoint& coordinates);
        /**
         * defining () operator for Matrix - Read Only
         * @return reference to cell (i,j)
         *
         *
         * assumptions of T class:
         *      basic assumptions
         *
         * Exceptions:
         *      AccessIllegalElement - if cell (i,j) is not in the matrix.
         */
        const T& operator()( int row_num, int col_num) const;
        /**
         * Added this function to simplify working with GridPoints
         * @param coordinates
         * @return
         */
        const T& operator()( const GridPoint& coordinates) const;

        /**
         * creates a boolean Matrix and sets cells to:
         *      true - if the object in the cell == t
         *      false - otherwise
         * @param t
         * @return the created boolean Matrix
         * assumptions of T class:
         *      basic assumptions.
         *      operator ==
         * Exceptions:
         *      std::bad_alloc - in case of an allocation problem.
         *
         */
        Matrix<bool> operator==(const T& t) const;

        /**
         * creates a boolean Matrix and sets cells to:
         *      true - if the object in the cell != t
         *      false - otherwise
         * @param t
         * @return the created boolean Matrix
         *
         * assumptions of T class:
         *      basic assumptions.
         *      operator ==
         * Exceptions:
         *      std::bad_alloc - in case of an allocation problem.
         *
         */
        Matrix<bool> operator!=(const T& t) const;

        // GameException Classes
    class AccessIllegalElement : public std::exception {
        public:
            const char* what() const noexcept override;
        };

        class IllegalInitialization : public std::exception  {
        public:
            const char* what() const noexcept override;
        };

    class DimensionMismatch : public std::exception  {
            const Dimensions first;
            const Dimensions second;
            std::string result;
            friend class Matrix;
            /**
             * This exception requires information about the dimensions of the Matrix`s.
             * @param first - left Matrix.
             * @param second - right Matrix.
             */
            DimensionMismatch(const Dimensions& first, const Dimensions& second);
        public:
            const char* what() const noexcept override;
        };
    };



    template<class T>
    Matrix<T>::const_iterator::const_iterator(const Matrix<T> *mat, int row, int col)
            : row(row), col(col), mat(mat) {}

    template<class T>
    bool Matrix<T>::const_iterator::operator==(const Matrix::const_iterator &it1) const {   // Aviram
        return it1.mat == mat and it1.row == row and it1.col == col;
    }

    template<class T>
    bool Matrix<T>::const_iterator::operator!=(const Matrix::const_iterator &it1) const {   // Aviram
        return not( it1 == *this);

    }

    template<class T>
    const T &Matrix<T>::const_iterator::operator*() const { // Noam

        return (*mat)(row, col);
    }

    template<class T>
    const typename Matrix<T>::const_iterator Matrix<T>::const_iterator::operator++(int) { // Noam
        const_iterator result = *this;
        if(col == mat->width() - 1) {
            col = 0;
            row++;
        }

        else {
            col++;
        }
        // returning iterator before incrementing
        return result;
    }

    template<class T>
    typename Matrix<T>::const_iterator Matrix<T>::const_iterator::operator++() { // Noam

        if(col == mat->width() - 1) {
            col = 0;
            row++;
        }
        else {
            col++;
        }

        return *this;
    }
    // Aviram

    template<class T>
    Matrix<T>::iterator::iterator(Matrix<T> *mat, int row, int col)
            : row(row), col(col), mat(mat) {}

    template<class T>
    bool Matrix<T>::iterator::operator==(const Matrix::iterator &it1) const {        // Aviram
        return it1.mat == mat and it1.row == row and it1.col == col;

    }

    template<class T>
    bool Matrix<T>::iterator::operator!=(const Matrix::iterator &it1) const {        // Aviram
        return not( it1 == *this);

    }

    template<class T>
    T &Matrix<T>::iterator::operator*() const { // Noam
        return (*mat)(row, col);
    }

    template<class T>
    const typename Matrix<T>::iterator Matrix<T>::iterator::operator++(int)  { // Noam
        iterator result = *this;
        if(col == mat->width() - 1) {
            col = 0;
            row++;
        }

        else {
            col++;
        }

        // returning iterator before incrementing
        return result;
    }

    template<class T>
    typename Matrix<T>::iterator Matrix<T>::iterator::operator++() { // Noam

        if(col == mat->width() - 1) {
            col = 0;
            row++;
        }

        else {
            col++;
        }

        return *this;
    }

    template<class T>
    bool Matrix<T>::iterator::isInMainDiagonal() const  {
        return row == col;
    }


    template<class T>
    GridPoint Matrix<T>::iterator::getGridPoint() {
        return GridPoint(row,col);
    }
    // Aviram


    /**
      * defining output operator for matrix
      * @param os
      * @return
      *
      *
      * assumptions of T class:
      *     basic assumptions
      *     operator <<
      * Exceptions:
      *     None.
      */
    template<class T>
    std::ostream &operator<<(std::ostream &os, const Matrix<T> &to_print) { // Noam
        return printMatrix(os, to_print.begin(),to_print.end(), to_print.width());


    }

    template<class T>
    Matrix<T>::Matrix(const Dimensions &dims, const T &init_value)
            : dimensions(dims.getRow(), dims.getCol())
    {
        if(dimensions.getRow() <=0 or dimensions.getCol() <=0) {
            throw IllegalArgument();
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

    template<class T>
    Matrix<T>::Matrix(const Matrix<T> &other)  :                 // Aviram
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

    template<class T>
    Matrix<T> &Matrix<T>::operator=(const Matrix<T> &other) {     // Aviram
        if(this == &other) {
            return *this;
        }
        T* temp_matrix = new T[other.size()];
        T* temp_it = temp_matrix;
        Dimensions temp_dims(other.height(), other.width());

        try {
            for(const_iterator other_it = other.begin(); other_it != other.end()  ; other_it++, temp_it++) {
                *temp_it = *(other_it);
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

    template<class T>
    Matrix<T>::~Matrix<T>() {       // Aviram
        delete[] matrix;
    }

    template<class T>
    Matrix<T> Matrix<T>::transpose() const  {       // Aviram
        Matrix<T> transposed_mat(Dimensions(width(),height()));
        // transposed_mat and this Matrix has the same size!

        for (iterator it = transposed_mat.begin();
             it != transposed_mat.end();
             it++) {
            *it = (*this)(it.col, it.row);
        }
        return transposed_mat;

    }

    template<class T>
    Matrix<T> Matrix<T>::operator+(const Matrix<T> &other) const { // Aviram
        // validate same size
        if(dimensions != other.dimensions) {
            throw DimensionMismatch(dimensions, other.dimensions);
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

    template<class T>
    Matrix<T> Matrix<T>::operator-() const {           // Aviram
        Matrix<T> neg_mat(*this);

        for (iterator it = neg_mat.begin() ; it != neg_mat.end() ; it++) {
            *it = -*it;
        }

        return neg_mat;
    }

    template<class T>
    Matrix<T> Matrix<T>::operator-(const Matrix<T> &other) const {  // Aviram
        return *this + (-other);
    }

    template<class T>
    Matrix<T> &Matrix<T>::operator+=(const T &t) {     // Aviram

        for(iterator it = begin(); it != end() ; it++) {
            *it += t;
        }
        return *this;
    }

    template<class T>
    Matrix<bool> Matrix<T>::operator<(const T &t) const {      // Aviram
        Matrix<bool> bool_mat(dimensions, false);
        const_iterator c_it = begin();

        for(Matrix<bool>::iterator bool_it = bool_mat.begin() ;
            bool_it != bool_mat.end() ;
            bool_it++, c_it++) {

            if(*c_it < t) {
                *bool_it = true;
            }
        }
        return bool_mat;
    }

    template<class T>
    Matrix<bool> Matrix<T>::operator<=(const T &t) const  {             // Aviram
        // equals boolean matrix + smaller boolean matrix
        return operator==(t) + operator<(t);
    }

    template<class T>
    Matrix<bool> Matrix<T>::operator>(const T &t) const {          // Aviram
        // creating the "reverse" matrix.
        Matrix<bool> small_equals = operator<=(t);
        // "reversing" the matrix. (all true will be false and all false will be true)
        return small_equals.operator!=(true);
    }

    template<class T>
    Matrix<bool> Matrix<T>::operator>=(const T &t) const {         // Aviram
        // equals boolean matrix + bigger boolean matrix
        return operator==(t) + operator>(t);

    }

    template<class T>
    template<class Application>
    Matrix<T> Matrix<T>::apply(Application apply_func) const { // Aviram

        Matrix<T> applied_mat(*this);
        for(iterator it = applied_mat.begin() ; it != applied_mat.end() ; it++) {
            *it = apply_func(*it);
        }
        return  applied_mat;
    }

    template<class T>
    typename Matrix<T>::iterator Matrix<T>::begin()  { // Noam
        return iterator(this);
    }

    template<class T>
    typename Matrix<T>::const_iterator Matrix<T>::begin() const { // Noam
        return const_iterator(this, 0, 0);
    }

    template<class T>
    typename Matrix<T>::iterator Matrix<T>::end() { // Noam
        return iterator(this, this->height(), 0);
    }

    template<class T>
    typename Matrix<T>::const_iterator Matrix<T>::end() const { // Noam
        return const_iterator(this, this->height(), 0);
    }

    template<class T>
    Matrix<T> Matrix<T>::Diagonal(int dim, const T &init_value) { // Noam
        if(dim <= 0){
            throw IllegalInitialization();
        }
        Matrix<T> identity_mat = Matrix<T>(Dimensions(dim, dim));
        if (dim == 1){
            identity_mat(0,0) = init_value;
        }
        for(Matrix<T>::iterator it = identity_mat.begin() ; it != identity_mat.end() ; it++ ) {
            if(it.isInMainDiagonal()) {
                *it = init_value;
            }
        }
        return identity_mat;
    }

    template<class T>
    int Matrix<T>::height() const { // Noam
        return dimensions.getRow();
    }

    template<class T>
    int Matrix<T>::width() const { // Noam
        return dimensions.getCol();
    }

    template<class T>
    int Matrix<T>::size() const { // Noam
        return dimensions.getRow() * dimensions.getCol();
    }

    template<class T>
    T &Matrix<T>::operator()(int row_num, int col_num) { // Noam
        if(row_num >= dimensions.getRow() or col_num >= dimensions.getCol() or row_num < 0 or col_num < 0){
            throw IllegalCell();
        }

        return matrix[row_num * dimensions.getCol() + col_num];
    }

    template<class T>
    const T& Matrix<T>::operator()(int row_num, int col_num) const { // Noam
        if(row_num >= dimensions.getRow() or col_num >= dimensions.getCol() or row_num < 0 or col_num < 0){
            throw IllegalCell();
        }

        return matrix[row_num * dimensions.getCol() + col_num];
    }

    template<class T>
    T& Matrix<T>::operator()(const GridPoint &coordinates) {
        return operator()(coordinates.row,coordinates.col);
    }

    template<class T>
    const T &Matrix<T>::operator()(const GridPoint &coordinates) const {
        return operator()(coordinates.row,coordinates.col);
    }


    template<class T>
    Matrix<bool> Matrix<T>::operator==(const T &t) const { // Noam
        Matrix<bool> bool_mat(dimensions);
        const_iterator c_it = begin();
        for (Matrix<bool>::iterator it = bool_mat.begin() ; it != bool_mat.end() ; it++, c_it++) {
            *it = (*c_it == t);
        }
        return bool_mat;
    }

    template<class T>
    Matrix<bool> Matrix<T>::operator!=(const T &t) const { // Noam
        Matrix<bool> equals_mat = (*this == t);
        return (equals_mat == false);
    }

    template<class T>
    Matrix<T> Matrix<T>::operator+(const T &t) const  {     // Aviram
        Matrix<T> temp(*this);
        return temp += t;
    }


    /**
       * Sum of a Matrix with a T Object (Matrix at right side)
       *
       * assumptions of T class:
       *      basic assumptions
       *      operator +
       * Exceptions:
       *      std::bad_alloc() - if there`s an allocation problem
       */
    template<class T>
    Matrix<T> operator+(const T& t, const Matrix<T>& mat) {    // Aviram
        // creating a matrix initialized with t in every cell
        Matrix<T> t_mat(Dimensions(mat.height(),mat.width()),t);
        // summing the t matrix with mat.
        return t_mat + mat;
    }
    /**
     * this function checks the boolean values of the object in the matrix
     * @param matrix
     * @return
     * true - if the boolean values of the cells are all true.
     * false - otherwise.
     *
     * assumptions of T class:
     *      basic assumptions.
     *      boolean conversion.
     * Exceptions:
     *      None.
     */
    template<class T>
    bool all(const Matrix<T>& matrix) {
        for (typename Matrix<T>::const_iterator it = matrix.begin(); it != matrix.end(); it++) {
            // one of the cells's boolean value is false
            if (!bool(*it)) {
                return false;
            }
            // result will stay true if no cell's boolean value is false.
        }
        return true;
    }

    /**
     * this function checks the boolean values of the object in the matrix
     * @param matrix
     * @return
     * true - if at least one boolean value of one of the cells are true.
     * false - otherwise.
     *
     * assumptions of T class:
     *      basic assumptions.
     *      boolean conversion.
     * Exceptions:
     *      None.
     */
    template<class T>
    bool any(const Matrix<T>& matrix) { // Noam
        for (typename Matrix<T>::const_iterator it = matrix.begin(); it != matrix.end(); it++) {
            // if one of the cells's boolean value is true.
            if (bool(*it)) {
                return true;
            }
        }
        // if all cells's boolean value is false.
        return false;
    }


    template<class T>
    const char *Matrix<T>::AccessIllegalElement::what() const noexcept   {
        return "Mtm matrix error: An attempt to access an illegal element";
    }


    template<class T>
    const char *mtm::Matrix<T>::IllegalInitialization::what() const noexcept   {
        return "Mtm matrix error: Illegal initialization values";
    }

    template<class T>
    const char *Matrix<T>::DimensionMismatch::what() const noexcept  {
        return result.c_str();
    }

    template<class T>
    Matrix<T>::DimensionMismatch::DimensionMismatch(const Dimensions &first, const Dimensions &second)  : first(first), second(second) {
        result =  "Mtm matrix error: Dimension mismatch: (" + std::to_string(first.getRow());
        result.append(",");
        result.append(std::to_string(first.getCol()));
        result.append(") (");
        result.append(std::to_string(second.getRow()));
        result.append(+ ",");
        result.append(std::to_string(second.getCol()));
        result.append(+ ")");

    }
}

#endif //EX3_MATRIX_H
