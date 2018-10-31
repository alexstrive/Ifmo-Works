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
        // Увеличиваем количество связей прямо и обратно
        adjencyMatrix[startVertex - 1][endVertex - 1] += 1;
        adjencyMatrix[endVertex - 1][startVertex - 1] += 1;
    }

    // Проверяем наличие параллельных ребер
    bool haveParallelEdges = false;

    for (int i = 0; i < numberVertices; i++) {
        for (int j = 0; j < numberVertices; j++) {
            if (adjencyMatrix[i][j] > 1) {
                haveParallelEdges = true;
            }
        }
    }

    ofstream output("output.txt");
    output << (haveParallelEdges ? "YES" : "NO");

    return 0;
}