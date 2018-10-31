#include <iostream>
#include "Matrix.h"
#include "PositiveMatrix.h"

using namespace std;

int main() {
    Matrix<int> matrix(3, 3);
    matrix.setValue(1, 2, 10);

    cout << matrix;

    matrix.transpose();

    cout << matrix;

    Matrix<int> tmpMatrix(3, 3);
    tmpMatrix.setValue(0, 0, 10);

    cout << tmpMatrix + matrix + 5;
    cout << matrix - 5;
    cout << -matrix;

    PositiveMatrix<float> positiveMatrix(4, 2);

    cout << positiveMatrix;

    positiveMatrix.setValue(0, 0, 5.3);
//    positiveMatrix.setValue(0, 1, -2); // Exit
    positiveMatrix.setValue(1, 0, 10.3);

    positiveMatrix.save("matrix.txt");

    cout << positiveMatrix;

    return 0;
}