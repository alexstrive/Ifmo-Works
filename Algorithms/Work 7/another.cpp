#include <iostream>
#include <fstream>


int main() {
    int n, m; // Колличество вершин и ребер
    int vertex1, vertex2, weight;

    std::ifstream input("pathsg.in");
    input >> n >> m;

    long long int data[n][n];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            data[i][j] = INT_MAX;

    for (int i = 0; i < m; ++i) {
        input >> vertex1 >> vertex2 >> weight;
        data[--vertex1][--vertex2] = weight;
    }
    input.close();

    /* Алгоритм Флойда-Уоршелла*/
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                if(i == j) {
                    data[i][j] = 0;
                    continue;
                }
                data[i][j] = data[i][k] + data[k][j] < data[i][j] ? (data[i][k] + data[k][j]) : data[i][j];
            }


    std::ofstream output("pathsg.out");

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            output << data[i][j] << " ";
        output << std::endl;
    }

    output.close();
    return 0;
}