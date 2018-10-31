#include <fstream>
#include <vector>

using namespace std;

struct Node {
    int key, left, right;
};

// Особый порядок прохода дерева
// В результате получаем условно остортировнаный по неубыванию массив ключей
void inorderTreeWalk(vector<Node> &tree, vector<int> &keys, int root) {

    // Выход, если узла не существует
    if (root == -1) {
        return;
    }

    // Спуск влево
    inorderTreeWalk(tree, keys, tree[root].left);

    keys.push_back(tree[root].key);

    // Спуск вправо
    inorderTreeWalk(tree, keys, tree[root].right);
}

// Проверка массива на отсортированность по неубыванию
bool isSorted(vector<int> &keys) {

    for (int i = 0; i < keys.size() - 1; i++) {
        if (keys[i] >= keys[i + 1]) {
            return false;
        }
    }

    return true;
}

// Является ли массив двоичным деревом поиска
bool isBST(vector<Node> &tree) {
    vector<int> keys;
    inorderTreeWalk(tree, keys, 0);
    return isSorted(keys);
}

int main() {
    ifstream input("check.in");

    int numberNodes;
    vector<Node> tree;

    input >> numberNodes;

    for (int i = 0; i < numberNodes; i++) {
        int key, left, right;
        input >> key >> left >> right;

        // Уменьшаем на единицу индексы левого и правого дочернего узла
        // Чтобы использовать их в дальнейшем
        tree.push_back({key, left - 1, right - 1});
    }


    ofstream output("check.out");
    output << (numberNodes == 0 || isBST(tree) ? "YES" : "NO");

    return EXIT_SUCCESS;
}