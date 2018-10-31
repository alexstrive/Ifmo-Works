//
// Created by Alexey Novopashin on 20/02/2018.
//

#ifndef PROGLABWORK1_MATRIX_H
#define PROGLABWORK1_MATRIX_H


#include <ostream>
#include <fstream>

template<class T>
class Matrix {
private:
    int row, col;

    void allocateMemory() {
        values = new T *[this->row];

        for (int i = 0; i < this->row; i++) {
            this->values[i] = new T[this->col];
        }
    }

    void initValues(int value = 0) {
        for (int i = 0; i < this->row; i++) {
            for (int j = 0; j < this->col; j++) {
                this->setValue(i, j, value);
            }
        }
    }

protected:
    T **values;
public:
    Matrix(int row = 3, int col = 3) : row(row), col(col) {
        this->allocateMemory();
        this->initValues(0);
    }

    void transpose() {

        int row = this->row;
        int col = this->col;

        auto **transposedValues = new T *[col];

        for (int i = 0; i < this->row; i++) {
            transposedValues[i] = new T[row];
        }

        for (int i = 0; i < col; i++) {
            for (int j = 0; j < row; j++) {
                transposedValues[i][j] = this->values[j][i];
            }
        }

        this->row = col;
        this->col = row;
        this->values = transposedValues;
    }

    void save(std::string filename) {
        std::ofstream outputFile;
        outputFile.open(filename);

        outputFile << "{" << std::endl;
        for (int i = 0; i < this->row; i++) {
            outputFile << "\t" << "{ ";
            for (int j = 0; j < this->col; j++) {
                outputFile << this->values[i][j] << " ";
            }
            outputFile << "}" << std::endl;
        }
        outputFile << "}" << std::endl;
    }

    ~Matrix() {
        for (int i = 0; i < this->row; i++) {
            delete[] values[i];
        }

        delete[] values;
    }

    virtual void setValue(int row, int col, T value) {
        values[row][col] = value;
    }

    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix) {
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

    friend std::istream &operator>>(std::istream &is, const Matrix &matrix) {

        for (int i = 0; i < matrix.row; i++) {
            for (int j = 0; j < matrix.col; j++) {
                is >> matrix.values[i][j];
            }
        }

        return is;
    }

    friend Matrix<T> operator+(const Matrix<T> &left, const int scalar) {
        Matrix<T> newMatrix(left.row, left.col);

        for (int i = 0; i < left.row; i++) {
            for (int j = 0; j < left.col; j++) {
                newMatrix.setValue(i, j, left.values[i][j] + scalar);
            }
        }

        return newMatrix;
    }

    friend Matrix<T> operator+(const Matrix<T> &left, const Matrix<T> &right) {
        Matrix<T> newMatrix(left.row, left.col);

        for (int i = 0; i < left.row; i++) {
            for (int j = 0; j < left.col; j++) {
                newMatrix.setValue(i, j, left.values[i][j] + right.values[i][j]);
            }
        }

        return newMatrix;
    }

    friend Matrix<T> operator+(const int scalar, const Matrix<T> &right) {
        Matrix<T> newMatrix(right.row, right.col);

        for (int i = 0; i < right.row; i++) {
            for (int j = 0; j < right.col; j++) {
                newMatrix.setValue(i, j, right.values[i][j] + scalar);
            }
        }

        return newMatrix;
    }

    friend Matrix<T> operator-(const Matrix<T> &left, const Matrix<T> &right) {
        Matrix<T> newMatrix(left.row, left.col);

        for (int i = 0; i < left.row; i++) {
            for (int j = 0; j < left.col; j++) {
                newMatrix.setValue(i, j, left.values[i][j] - right.values[i][j]);
            }
        }

        return newMatrix;
    }

    friend Matrix<T> operator-(const int scalar, const Matrix<T> &right) {
        Matrix<T> newMatrix(right.row, right.col);

        for (int i = 0; i < right.row; i++) {
            for (int j = 0; j < right.col; j++) {
                newMatrix.setValue(i, j, right.values[i][j] - scalar);
            }
        }

        return newMatrix;
    }

    friend Matrix<T> operator-(const Matrix<T> &left, const int scalar) {
        Matrix<T> newMatrix(left.row, left.col);

        for (int i = 0; i < left.row; i++) {
            for (int j = 0; j < left.col; j++) {
                newMatrix.setValue(i, j, left.values[i][j] - scalar);
            }
        }

        return newMatrix;
    }

    Matrix<T> operator-() {
        Matrix<T> newMatrix(this->row, this->col);

        for (int i = 0; i < this->row; i++) {
            for (int j = 0; j < this->col; j++) {
                newMatrix.setValue(i, j, -this->values[i][j]);
            }
        }

        return newMatrix;
    }

};


#endif //PROGLABWORK1_MATRIX_H
