//
// Created by avira on 03/06/2020.
//

#ifndef EX3_INTMATRIX_H
#define EX3_INTMATRIX_H
#include "Auxiliaries.h"
using mtm::Dimensions;

class IntMatrix {
    Dimensions dimensions;
    int* matrix;
    void initialize(int initial_value);

public:
    IntMatrix(const Dimensions& dims) : dimensions(dims) {
        matrix = new[dims.getCol()*dims.getRow()];
        this->initialize(0);
        }
    }
    IntMatrix(const Dimensions& dims, int initial_value);

};


#endif //EX3_INTMATRIX_H
