#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Node {
    int key, leftChild, rightChild;
};

int depth(vector<Node> &tree, int root) {
    // Выходим из поиска, если вершины не существует
    if (root == -1) {
        return 0;
    }

    // Рекурсивно разделяем поиск слева и справа
    // Добавление единицы позволяет учитывать нынешнюю вершину
    return max(
            depth(tree, tree[root].leftChild),
            depth(tree, tree[root].rightChild)) + 1;
}

int main() {
    ifstream input("height.in");
    int numberOfNodes;

    input >> numberOfNodes;

    vector<Node> tree;

    // Заполняем дерево вершинами
    for (int i = 0; i < numberOfNodes; i++) {
        int data, leftChild, rightChild;
        input >> data >> leftChild >> rightChild;

        // Отнимаем по единице, чтобы использовать данные значения, в качестве индексов
        leftChild -= 1;
        rightChild -= 1;

        tree.push_back(Node {data, leftChild, rightChild});
    }

    ofstream output("height.out");

    output << (numberOfNodes == 0 ? 0 : depth(tree, 0));

    return 0;
}