#include <fstream>
#include <vector>

using namespace std;

/*!
 *  structure that contains value and pointer to the next node
 */
struct Node {
    int Value;
    Node *Next;
};

/*!
 *  class with realization of a list containing the values ​​of elements with a single hash
 */
class hashList {
    Node *Start;
public:
    ///constructor
    hashList() {
        Start = new Node();
        Start->Value = 0;
        Start->Next = nullptr;
    }

    /*!
     * a method that adds a new element to the end of the list
     * @param x key of the element
     */
    void Insert(int x) {
        auto *NewNode = new Node;
        NewNode->Value = x;
        NewNode->Next = Start->Next;
        Start->Next = NewNode;
    }

    /*!
     * a method that finds and removes an item from the list if it exists there
     * @param x key of the element
     */
    void Delete(int x) {
        Node *node = Start;
        while (node->Next != nullptr) {
            if (node->Next->Value == x) {
                Node *toDel = node->Next;
                node->Next = node->Next->Next;
                delete toDel;
                return;
            }
            else {
                node = node->Next;
            }
        }
    }

    /*!
     * a method that finds an item from the list if it exists there
     * @param x key of the element
     */
    bool Exists(int x) {
        Node *CurNode = Start;
        while (CurNode->Next != nullptr) {
            if (CurNode->Next->Value == x) {
                return true;
            }
            else {
                CurNode = CurNode->Next;
            }
        }
        return false;
    }
};

/*!
 *  class with realization of a hash-table
 */
class hashTable {
    vector<hashList> set;

    /*!
     * a method that assigns a specific hash to this value
     * @param x key of the element
     */
    int hash(int x) {
        return abs(x) % 18000;
    }

public:
    ///constructor( in the task 100000 - max)
    hashTable() {
        set.resize(100000);
    }

    /*!
     * a method that adds a new element to the end of the table
     * @param x key of the element
     */
    void Insert(int x) {
        if (!Exists(x)) { set[hash(x)].Insert(x); }
    }

    /*!
     * a method that finds an item from the table if it exists there
     * @param x key of the element
     */
    bool Exists(int x) {
        return set[hash(x)].Exists(x);
    }

    /*!
     * a method that finds and removes an item from the table if it exists there
     * @param x key of the element
     */
    void Delete(int x) {
        set[hash(x)].Delete(x);
    }
};

int main() {
    ifstream fin("set.in");
    ofstream fout("set.out");
    ///Hash Table
    hashTable set;
    ///a variable for command
    string command;

    /*
     * scan commands and do it
     */
    while (fin >> command) {
        int number;
        fin >> number;

        if (command == "insert") {
            set.Insert(number);
        }

        else if (command == "delete") {
            set.Delete(number);
        }

        else if (command == "exists") {
            fout << (set.Exists(number) ? "true" : "false") << endl;
        }
    }

    return 0;
}