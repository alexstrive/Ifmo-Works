#include <vector>
#include <fstream>

using namespace std;

template<class T>
class Stack {
protected:
    vector<T> values;
public:

    void push(T value) {
        values.push_back(value);
    }

    T pop() {
        T value = values.back();
        values.pop_back();

        return value;
    }

};

int main() {
    ifstream input("stack.in");
    ofstream output("stack.out");

    Stack<int> stack;
    int commandNumber;

    input >> commandNumber;

    for (int i = 0; i < commandNumber; i++) {
        string command;

        input >> command;

        // Добавление элемента в стек
        if (command == "+") {
            int value;
            input >> value;
            stack.push(value);
        }

        // Удаление из стека и вывод значения
        if (command == "-") {
            int value = stack.pop();
            output << value << endl;
        }
    }

    return 0;
}