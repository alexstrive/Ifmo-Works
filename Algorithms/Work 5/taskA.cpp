#include <fstream>
#include <vector>

using namespace std;

class LinkedList {
private:

    class Node {
    public:
        int value;
        Node *next;

        explicit Node(int data, Node *next = nullptr) : value(data), next(next) {};
    };

    Node *head = nullptr;

public:

    void insert(const int value) {
        Node *wrappedNode = new Node(value, head);
        head = wrappedNode;
    }

    void remove(const int targetValue) {
        if (head && head->value == targetValue) {
            head = nullptr;
            return;
        }

        auto currentNode = head;

        while (currentNode && currentNode->next != nullptr) {

            if (currentNode->next->value == targetValue) {
                currentNode->next = currentNode->next->next;
                delete currentNode->next;
                return;
            }

            currentNode = currentNode->next;
        }
    }

    bool doesExist(int targetValue) {
        Node *currentNode = this->head;

        if (currentNode && currentNode->value == targetValue) {
            return true;
        }

        while (currentNode && currentNode->next != nullptr) {

            if (currentNode->next->value == targetValue) {
                return true;
            }

            currentNode = currentNode->next;
        }

        return false;
    }
};

class HashTable {
private:
    vector<LinkedList> list;
    const int MAX_SIZE = 100000;

    // TODO: another hash function?
    int hashify(int value) {
        return value % MAX_SIZE;
    }

public:
    HashTable() {
        list.resize(MAX_SIZE);
    }

    void insert(const int value) {
        if (!doesExist(value)) {
            int hash = hashify(value);
            list[hash].insert(value);
        }
    }

    void remove(const int value) {
        int hash = hashify(value);
        list[hash].remove(value);
    }

    bool doesExist(const int value) {
        int hash = hashify(value);
        return list[hash].doesExist(value);
    }
};

int main() {
    string command;
    ifstream input("set.in");
    ofstream output("set.out");

    HashTable hashTable;

    while (input >> command) {
        int value;
        input >> value;

        if (command == "insert") {
            hashTable.insert(value);
        }

        if (command == "delete") {
            hashTable.remove(value);
        }

        if (command == "exists") {
            output << (hashTable.doesExist(value) ? "true" : "false") << endl;
        }

    }

    return 0;
}
