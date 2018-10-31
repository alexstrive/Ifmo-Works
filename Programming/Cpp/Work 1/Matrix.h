//
// Created by Alexey Novopashin on 20/02/2018.
//

#ifndef PROGLABWORK1_MATRIX_H
#define PROGLABWORK1_MATRIX_H


#include <ostream>

class Matrix {
private:
    int **values;
    int row, col;

    void allocateMemory();
    void initValues(int value = 0);
public:
    explicit Matrix(int row = 3, int col = 3);

    void transpose();

    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix);
    friend std::istream &operator>>(std::istream &is, const Matrix &matrix);

    friend Matrix operator+(const Matrix &left, const Matrix &right);
    friend Matrix operator+(const Matrix &left, const int scalar);
    friend Matrix operator+(const int scalar, const Matrix &right);

    friend Matrix operator-(const Matrix &left, const Matrix &right);
    friend Matrix operator-(const Matrix &left, const int scalar);
    friend Matrix operator-(const int scalar, const Matrix &right);

    Matrix operator-();

    virtual ~Matrix();

    void setValue(int row, int col, int value);
    void setValues(int **values);
};


#endif //PROGLABWORK1_MATRIX_H
