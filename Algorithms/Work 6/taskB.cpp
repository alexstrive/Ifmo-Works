#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream input("input.txt");

    int numberVertices;
    input >> numberVertices;

    // Создаем матрицу смежности
    auto **adjencyMatrix = new int*[numberVertices];
    for (int i = 0; i < numberVertices; i++) {
        adjencyMatrix[i] = new int[numberVertices];
    }

    // Обнуляем значения матрицы смежности
    for (int i = 0; i < numberVertices; i++) {
        for (int j = 0; j < numberVertices; j++) {
            adjencyMatrix[i][j] = 0;
        }
    }

    // Вводим значения матрицы смежности
    for (int i = 0; i < numberVertices; i++) {
        for (int j = 0; j < numberVertices; j++) {
            input >> adjencyMatrix[i][j];
        }
    }

    // Проверяем валидность
    bool isValid = true;

    for (int i = 0; i < numberVertices; i++) {
        for (int j = 0; j < numberVertices; j++) {
            bool doesBackConnect = adjencyMatrix[i][j] == adjencyMatrix[j][i];
            bool doesSelfConnect = (i == j) && (adjencyMatrix[i][j] == 1);

            if (!doesBackConnect || doesSelfConnect) {
                isValid = false;
            }
        }
    }

    ofstream output("output.txt");
    output << (isValid ? "YES" : "NO");

    return 0;
}