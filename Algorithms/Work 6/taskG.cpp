#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

enum class Color {
    White,
    Gray,
    Black
};

bool hasLoops = false;

class Vertex {
private:
    Color color = Color::White;
public:
    vector<int> neighbours;

    void visit(vector<Vertex> &graph) {
        if (getColor() == Color::Black) {
            return;
        }

        if (getColor() == Color::Gray) {
            hasLoops = true;
        }

        if (hasLoops) {
            return;
        }

        // Помечаем вершину, как рабочую
        setColor(Color::Gray);

        // Проходим всех соседей вершины
        // Перекрашиваем их в соответсвующий цвет
        for (auto neighbour : neighbours) {
            graph[neighbour].visit(graph);
        }

        // Помечаем вершину, как пройденную
        setColor(Color::Black);
    }

    Color getColor() const {
        return color;
    }

    void setColor(Color color) {
        Vertex::color = color;
    }
};

void DFS(vector<Vertex> &graph) {
    for (auto &vertex : graph) {
        if (vertex.getColor() == Color::White) {
            vertex.visit(graph);
        }
    }
}

void addEdge(vector<Vertex> &graph, int startVertex, int endVertex) {
    graph[startVertex - 1].neighbours.push_back(endVertex - 1);
    graph[endVertex - 1].neighbours.push_back(startVertex - 1);
}

void topologicalSort(vector<Vertex> &source, vector<Vertex> &target) {

}

int main() {
    ifstream input("topsort.in");

    unsigned int numberVertices, numberEdges;
    input >> numberVertices >> numberEdges;

    vector<Vertex> graph(numberVertices);

    // Формируем граф
    for (int i = 0; i < numberEdges; i++) {
        int startVertex, endVertex;
        input >> startVertex >> endVertex;

        addEdge(graph, startVertex, endVertex);
    }

    vector<Vertex> sortedGraph(numberVertices);

    topologicalSort(graph, sortedGraph);

    ofstream output("topsort.out");

    for (auto vertex: sortedGraph) {
    }

    return EXIT_SUCCESS;
}