#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Итеративный двоичный поиск
int binarySearch(vector<int> &values, int targetValue, int &left, int &right) {
    int currentLeft = 0, currentRight = values.size();

    // Ищем первое вхождение элемента
    while (currentLeft < currentRight) {
        int middle = (currentLeft + currentRight) / 2;

        // Если значение элемента больше, чем значение элемента по-середине
        // То ищем его в правой части
        if (targetValue > values[middle] ) {
            currentLeft = middle + 1;
        }
        // Иначе - в левой
        else {
            currentRight = middle;
        }
    }

    left = currentLeft + 1;
    currentLeft = 0, currentRight = values.size();

    // Ищем последнее вхождение элемента
    while (currentLeft < currentRight) {
        int middle = (currentLeft + currentRight) / 2;

        // Не учитываем похожие элементы
        if (targetValue >= values[middle]) {
            currentLeft = middle + 1;
        }
        else {
            currentRight = middle;
        }
    }

    right = currentLeft;

    if (left > right) {
        left = right = -1;
    }
}


int main() {
    ifstream input("binsearch.in");

    unsigned int numberValues;
    input >> numberValues;

    vector<int> values(numberValues);
    for (int i = 0; i < numberValues; i++) {
        input >> values[i];
    }

    unsigned int numberRequests;
    input >> numberRequests;

    vector<int> requests(numberRequests);
    for (int i = 0; i < numberRequests; i++) {
        input >> requests[i];
    }

    ofstream output("binsearch.out");

    for (auto request : requests) {
        int first = -1, last = -1;
        binarySearch(values, request, first, last);

        output << first << " " << last << endl;
    }

    return EXIT_SUCCESS;
}