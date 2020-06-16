#ifndef EX3_MATRIX_H
#define EX3_MATRIX_H
#include "../PartA/Auxiliaries.h"


// use to check and simplify implementation
typedef int T;

namespace mtm {
    template<class T>
    class Matrix {
        Dimensions dimensions;
        T* data;

    public:
        /**
         * TODO
         * assumptions of T class:
         *
         * @param dims
         * @param init_value
         * Exceptions:
         */
        Matrix(Dimensions& dims, T& init_value = T()) {}        // Aviram.



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
}

#endif //EX3_MATRIX_H
