#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Node {
    int key;
    Node *left, *right;
};

class BST {
private:
    Node *root = nullptr;

    Node *search(int key) {
        Node *currentNode = root;

        if (currentNode != nullptr && currentNode->key == key) {
            if (currentNode->key > key) {
                currentNode = currentNode->left;
            }
            else {
                currentNode = currentNode->right;
            }
        }

        return currentNode;
    }
public:

    bool exists(int key) {
        return search(key) != nullptr;
    }

    void insert(int key) {
        if (exists(key)) {
            return;
        }
    }

};

int main() {
    ifstream input("bstsimple.in");
    ofstream output("bstsimple.out");

    string command;
    int argument;
    BST tree;

    while (input >> command >> argument) {

        if (command == "insert") {

        }

        if (command == "delete") {

        }

        if (command == "exists") {
            output << (tree.exists(argument) ? "true" : "false") << endl;
        }

        if (command == "next") {

        }

        if (command == "prev") {

        }

    }

    return EXIT_SUCCESS;
}