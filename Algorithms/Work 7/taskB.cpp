#include <fstream>

using namespace std;

int MAX_VERTEXES = 200; // по условию
int INF = 100000; // любое другое число, больше, чем 10^4 (использую здесь 10^5)

int main() {
    ifstream input("pathsg.in");
    ofstream output("pathsg.out");

    int numberVertexes, numberEdges;
    input >> numberVertexes >> numberEdges;

    int graph[MAX_VERTEXES][MAX_VERTEXES];

    // Инициализируем массив графа плюс бесконечностью
    for (int i = 0; i < numberVertexes; i++) {
        for (int j = 0; j < numberVertexes; j++) {
            graph[i][j] = INF;
        }
    }

    // Заполняем исходными данными
    for (int i = 0; i < numberEdges; i++) {
        int start, end, weight;
        input >> start >> end >> weight;

        graph[start - 1][end - 1] = weight;
    }

    // Данным циклом проходим по каждой вершине
    for (int currentVertexIndex = 0; currentVertexIndex < numberVertexes; currentVertexIndex++) {

        // Применяем алгоритм Дейкстры
        for (int i = 0; i < numberVertexes; i++) {
            for (int j = 0; j < numberVertexes; j++) {
                if ((i != j) && (graph[i][currentVertexIndex] + graph[currentVertexIndex][j] < graph[i][j])) {
                    graph[i][j] = graph[i][currentVertexIndex] + graph[currentVertexIndex][j];
                }
            }
        }

    }

    // Вывод на экран
    for (int i = 0; i < numberVertexes; ++i) {
        for (int j = 0; j < numberVertexes; ++j) {
            output << (graph[i][j] != INF ? graph[i][j] : 0) << " ";
        }

        output << endl;
    }


    return EXIT_SUCCESS;
}

