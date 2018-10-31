#include <iostream>
#include "Vector.h"

using namespace std;

int main() {
    // Можем указать изначальное значение буффера
    // Например
//  Vector<int> vector(5);
    Vector<int> vector;

    vector.push(3);
    vector.push(1);
    vector.push(5);
    vector.push(33);
    vector.push(4);
    vector.push(57);
    vector.pop();
    vector.pop();
    vector.push(31);
    vector.push(65);
    vector.shift();
    vector.push(48);
    vector.push(10);
    vector.push(42);
    vector.push(9);
    vector.unshift(99);
    vector.push(32);
    vector.push(81);
    vector.shift();
    vector.shift();
    vector.shift();
    vector.unshift(142);

    // Проходимся по всем элементам через итераторы
    for (auto &it : vector) {
        cout << it << endl;
    }

    return 0;
}