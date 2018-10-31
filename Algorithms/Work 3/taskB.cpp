#include <vector>
#include <fstream>

using namespace std;

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

};

int main() {
    ifstream input("queue.in");
    ofstream output("queue.out");

    Queue<int> queue;
    int commandNumber;

    input >> commandNumber;

    for (int i = 0; i < commandNumber; i++) {
        string command;

        input >> command;

        // Добавление элемента в очередь
        if (command == "+") {
            int value;
            input >> value;
            queue.push(value);
        }

        // Удаление из очереди и вывод значения
        if (command == "-") {
            int value = queue.pop();
            output << value << endl;
        }
    }

    return EXIT_SUCCESS;
}