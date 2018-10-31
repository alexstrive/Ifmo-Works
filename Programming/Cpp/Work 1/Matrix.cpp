//
// Created by Alexey Novopashin on 20/02/2018.
//

#include <iostream>
#include "Matrix.h"

Matrix::Matrix(int row, int col) : row(row), col(col) {
    this->allocateMemory();
    this->initValues(0);
}

Matrix::~Matrix() {
    for (int i = 0; i < this->row; i++) {
        delete[] values[i];
    }

    delete[] values;
}

void Matrix::transpose() {
    auto **transposedValues = new int *[this->row];

    for (int i = 0; i < this->row; i++) {
        transposedValues[i] = new int[this->col];
    }

    for (int i = 0; i < this->col; i++) {
        for (int j = 0; j < this->row; j++) {
            transposedValues[i][j] = this->values[j][i];
        }
    }

    this->values = transposedValues;
}

void Matrix::setValue(int row, int col, int value) {
    values[row][col] = value;
}

std::ostream &operator<<(std::ostream &os, const Matrix &matrix) {
    os << "values: " << matrix.values << " row: " << matrix.row << " col: " << matrix.col << std::endl;
    os << "{" << std::endl;
    for (int i = 0; i < matrix.row; i++) {
        os << "\t" << "{ ";
        for (int j = 0; j < matrix.col; j++) {
            os << matrix.values[i][j] << " ";
        }
        os << "}" << std::endl;
    }
    os << "}" << std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, const Matrix &matrix) {

    for (int i = 0; i < matrix.row; i++) {
        for (int j = 0; j < matrix.col; j++) {
            is >> matrix.values[i][j];
        }
    }

    return is;
}

void Matrix::allocateMemory() {
    values = new int *[this->row];

    for (int i = 0; i < this->row; i++) {
        this->values[i] = new int[this->col];
    }
}

void Matrix::initValues(int value) {
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->col; j++) {
            this->setValue(i, j, value);
        }
    }
}

Matrix Matrix::operator-() {
    Matrix newMatrix = Matrix(this->row, this->col);

    for (int i = 0; i < this->row; i++) {
        for(int j = 0; j < this->col; j++) {
            newMatrix.setValue(i, j, -this->values[i][j]);
        }
    }

    return newMatrix;
}

void Matrix::setValues(int **values) {
    this->values = values;
}

Matrix operator+(const Matrix &left, const Matrix &right) {
    Matrix newMatrix = Matrix(left.row, left.col);

    for (int i = 0; i < left.row; i++) {
        for(int j = 0; j < left.col; j++) {
            newMatrix.setValue(i, j, left.values[i][j] + right.values[i][j]);
        }
    }

    return newMatrix;
}

Matrix operator+(const int scalar, const Matrix &right) {
    Matrix newMatrix = Matrix(right.row, right.col);

    for (int i = 0; i < right.row; i++) {
        for(int j = 0; j < right.col; j++) {
            newMatrix.setValue(i, j, right.values[i][j] + scalar);
        }
    }

    return newMatrix;
}

Matrix operator+(const Matrix &left, const int scalar) {
    Matrix newMatrix = Matrix(left.row, left.col);

    for (int i = 0; i < left.row; i++) {
        for(int j = 0; j < left.col; j++) {
            newMatrix.setValue(i, j, left.values[i][j] + scalar);
        }
    }

    return newMatrix;
}

Matrix operator-(const Matrix &left, const Matrix &right) {
    Matrix newMatrix = Matrix(left.row, left.col);

    for (int i = 0; i < left.row; i++) {
        for(int j = 0; j < left.col; j++) {
            newMatrix.setValue(i, j, left.values[i][j] - right.values[i][j]);
        }
    }

    return newMatrix;
}

Matrix operator-(const int scalar, const Matrix &right) {
    Matrix newMatrix = Matrix(right.row, right.col);

    for (int i = 0; i < right.row; i++) {
        for(int j = 0; j < right.col; j++) {
            newMatrix.setValue(i, j, right.values[i][j] - scalar);
        }
    }

    return newMatrix;
}

Matrix operator-(const Matrix &left, const int scalar) {
    Matrix newMatrix = Matrix(left.row, left.col);

    for (int i = 0; i < left.row; i++) {
        for(int j = 0; j < left.col; j++) {
            newMatrix.setValue(i, j, left.values[i][j] - scalar);
        }
    }

    return newMatrix;
}