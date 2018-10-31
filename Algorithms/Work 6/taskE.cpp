#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

enum class Color {
    White,
    Gray,
    Black
};

template<class T>
class Queue {
protected:
    vector<T> values;
public:

    void push(T value) {
        values.push_back(value);
    }

    T pop() {
        T value = values.front();
        values.erase(values.begin());

        return value;
    }

    bool isEmpty() {
        return values.empty();
    }

};

class Vertex {
private:
    Color color = Color::White;
    int distance = 0;
public:
    vector<int> neighbours;

    Color getColor() const {
        return color;
    }

    int getDistance() const {
        return distance;
    }

    void setDistance(int distance) {
        Vertex::distance = distance;
    }

    void setColor(Color color) {
        Vertex::color = color;
    }
};

void BFS(vector<Vertex> &graph, int start = 0) {
    graph[start].setColor(Color::Gray);

    Queue<int> queue;
    queue.push(start);

    while (!queue.isEmpty()) {
        auto currentVertexNumber = queue.pop();
        auto &currentVertex = graph[currentVertexNumber];

        // Проходим по соседям
        for (auto &neighbourNumber : currentVertex.neighbours) {
            auto &neighbour = graph[neighbourNumber];

            if (neighbour.getColor() == Color::White) {

                // Помечаем соседа, как рабочую вершину
                neighbour.setColor(Color::Gray);
                // Увеличиваем значение дистанции на единицу от существующей до предыдущей вершины
                int currentDistance = currentVertex.getDistance();
                neighbour.setDistance(currentDistance + 1);

                // Добавляем номер соседа в очередь на проход
                queue.push(neighbourNumber);
            }
        }

        // Завершаем работу на данной вершине
        currentVertex.setColor(Color::Black);
    }

}

void addUndirectedEdge(vector<Vertex> &graph, int startVertex, int endVertex) {
    graph[startVertex - 1].neighbours.push_back(endVertex - 1);
    graph[endVertex - 1].neighbours.push_back(startVertex - 1);
}

int main() {
    ifstream input("pathbge1.in");

    unsigned int numberVertices, numberEdges;
    input >> numberVertices >> numberEdges;

    vector<Vertex> graph(numberVertices);

    // Формируем граф
    for (int i = 0; i < numberEdges; i++) {
        int startVertex, endVertex;
        input >> startVertex >> endVertex;

        addUndirectedEdge(graph, startVertex, endVertex);
    }

    ofstream output("pathbge1.out");
    BFS(graph);

    for (auto &vertex : graph) {
        output << vertex.getDistance() << " ";
    }

    return EXIT_SUCCESS;
}