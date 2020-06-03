//
// Created by avira on 03/06/2020.
//

#ifndef EX3_INTMATRIX_H
#define EX3_INTMATRIX_H
#include "Auxiliaries.h"

namespace mtm {

    class IntMatrix {
        Dimensions dimensions;
        int *matrix;
        void initialize(int initial_value);
    public:
        IntMatrix(const Dimensions &dims);
        IntMatrix(const Dimensions &dims, int initial_value);
        IntMatrix(const IntMatrix&);
        IntMatrix& operator=(const IntMatrix&);
        ~IntMatrix();

        IntMatrix& Identity(unsigned int dimension);
        int height();
        int width();
        int size();
        IntMatrix& transpose();
    };

}



#endif //EX3_INTMATRIX_H
