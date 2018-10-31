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

    size_t size() {
        return values.size();
    }

};

int main() {
    ifstream input("postfix.in");
    ofstream output("postfix.out");

    string data;
    Stack<int> values;

    string a, b;

    input >> a >> b;

    values.push(stoi(a));
    values.push(stoi(b));

    while (input >> data) {
        int firstValue, secondValue;
        switch (data[0]) {
            case '+':
                secondValue = values.pop();
                firstValue = values.pop();
                values.push(firstValue + secondValue);
                break;
            case '-':
                secondValue = values.pop();
                firstValue = values.pop();
                values.push(firstValue - secondValue);
                break;
            case '*':
                secondValue = values.pop();
                firstValue = values.pop();
                values.push(firstValue * secondValue);
                break;
            case '/':
                secondValue = values.pop();
                firstValue = values.pop();
                values.push(firstValue / secondValue);
                break;
            default:
                values.push(stoi(data));
        }
    }

    output << values.pop();

    return 0;
}