#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {
    Matrix matrix = Matrix();
    matrix.setValue(1, 2, 10);

    cout << matrix;

    matrix.transpose();

    cout << matrix;

//    cin >> matrix;

    Matrix tmpMatrix = Matrix();
    tmpMatrix.setValue(2, 1, 10);

    cout << matrix + tmpMatrix;
    cout << matrix - 5;

    cout << -matrix;

    return 0;
}