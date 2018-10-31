#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream input("input.txt");

    int numberVertices, numberEdges;

    input >> numberVertices >> numberEdges;

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

    // Формируем матрицу смежности
    for (int i = 0; i < numberEdges; i++) {
        int startVertex, endVertex;
        input >> startVertex >> endVertex;

        // Вычитаем по единице, чтобы использовать в качестве индекса
        adjencyMatrix[startVertex - 1][endVertex - 1] = 1;
    }

    ofstream output("output.txt");

    // Выводим матрицу смежности
    for (int i = 0; i < numberVertices; i++) {

        for (int j = 0; j < numberVertices; j++) {
            output << adjencyMatrix[i][j] << " ";
        }

        output << endl;
    }

    return 0;
}