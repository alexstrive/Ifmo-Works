//
// Created by Alexey Novopashin on 19/03/2018.
//

#ifndef PROGLABWORK1_POSITIVEMATRIX_H
#define PROGLABWORK1_POSITIVEMATRIX_H

#include "Matrix.h"

template <class T>
class PositiveMatrix : public Matrix<T> {
public:
    PositiveMatrix(int row, int col) : Matrix<T>(row, col) {}

    void setValue(int row, int col, T value) override {
        if (value < 0) {
            exit(0);
        }

        this->values[row][col] = value;
    }
};

#endif //PROGLABWORK1_POSITIVEMATRIX_H
