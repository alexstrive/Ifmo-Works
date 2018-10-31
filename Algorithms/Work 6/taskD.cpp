#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

enum class Color {
    White,
    Gray,
    Black
};

class Vertex {
private:
    Color color = Color::White;
    int component = 0;
public:
    vector<int> neighbours;

    void visit(vector<Vertex> &graph, int componentNumber) {
        // Помечаем вершину, как рабочую
        setColor(Color::Gray);

        // Проходим всех соседей вершины
        // Перекрашиваем их в соответсвующий цвет
        for (auto neightbour : neighbours) {
            if (graph[neightbour].getColor() == Color::White) {
                graph[neightbour].visit(graph, componentNumber);
            }
        }

        // Помечаем вершину, как пройденную
        setColor(Color::Black);
        // Устанавливаем номер компоненты
        setComponent(componentNumber);
    }

    Color getColor() const {
        return color;
    }

    int getComponent() const {
        return component;
    }

    void setComponent(int component) {
        Vertex::component = component;
    }

    void setColor(Color color) {
        Vertex::color = color;
    }
};

int DFS(vector<Vertex> &graph) {
    // Общий счетчик компонент связности
    int component = 0;

    for (auto &vertex : graph) {
        if (vertex.getColor() == Color::White) {
            component += 1;
            vertex.visit(graph, component);
        }
    }

    return component;
}

int main() {
    ifstream input("components.in");

    int numberVertices, numberEdges;
    input >> numberVertices >> numberEdges;

    vector<Vertex> graph(numberVertices);

    // Формируем граф
    for (int i = 0; i < numberEdges; i++) {
        int startVertex, endVertex;
        input >> startVertex >> endVertex;

        graph[startVertex - 1].neighbours.push_back(endVertex - 1);
        graph[endVertex - 1].neighbours.push_back(startVertex - 1);
    }

    ofstream output("components.out");
    output << DFS(graph) << endl;

    for (auto &vertex : graph) {
        output << vertex.getComponent() << " ";
    }

    return EXIT_SUCCESS;
}