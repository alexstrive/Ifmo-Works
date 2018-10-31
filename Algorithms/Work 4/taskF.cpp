#include <fstream>
#include <stack>

using namespace std;

template<class T>
class StackMin {
private:
    // Реализуем стек с минимальным элементом через стек с парами
    // При каждом добавлении элемента в стек
    // Ищем минимальный из добавлемого элементов и предыдущего минимального
    // Таким образом на второй позиции будет находится минимальный элемент
    // Из всего стека
    stack<pair<T, T>> stack;
public:
    void push(int value) {
        int minValue = isEmpty()
                       ? value
                       : min(value, stack.top().second);

        stack.push(pair<T, T>(value, minValue));
    }

    T pop() {
        int value = stack.top().first;
        stack.pop();
        return value;
    }

    T getMinValue() {
        return stack.top().second;
    }

    size_t size() {
        return stack.size();
    }

    bool isEmpty() {
        return stack.empty();
    }

};

template<class T>
class QueueMin {
private:
    // Реализуем очередь через два стека с минимальным элементом
    // Получаем принцип FIFO
    StackMin<T> enqueueStack, dequeueStack;
public:
    void enqueue(int value) {
        enqueueStack.push(value);
    }

    T dequeue() {
        // Перекидываем все элементы из стека, находящихся в очереди
        // В стек, ждущих покидания очереди
        if (dequeueStack.isEmpty()) {
            while (!enqueueStack.isEmpty()) {
                dequeueStack.push(enqueueStack.pop());
            }
        }

        return dequeueStack.pop();
    }

    int getMinValue() {
        if (enqueueStack.isEmpty() || dequeueStack.isEmpty()) {
            return enqueueStack.isEmpty()
                   ? dequeueStack.getMinValue()
                   : enqueueStack.getMinValue();
        }
        else {
            return min(enqueueStack.getMinValue(), dequeueStack.getMinValue());
        }
    }
};

int main() {

    ifstream input("queuemin.in");
    ofstream output("queuemin.out");

    QueueMin<int> queueMin;
    int numberCommands;

    input >> numberCommands;

    for (int i = 0; i < numberCommands; i++) {
        char command;
        int argument;
        input >> command;

        switch (command) {
            case '+':
                input >> argument;
                queueMin.enqueue(argument);
                break;
            case '-':
                queueMin.dequeue();
                break;
            case '?':
                output << queueMin.getMinValue() << endl;
                break;
            default:
                break;
        }
    }

    return EXIT_SUCCESS;
}