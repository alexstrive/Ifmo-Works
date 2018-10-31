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

bool check(string sequence) {
    Stack<char> brackets;
    int depth = 0;

    for (char currentBracket : sequence) {
        // Спускаемся на уровень ниже
        if (currentBracket == '(' || currentBracket == '[') {
            brackets.push(currentBracket);
            depth++;
        }

        // Поднимаемся на уровень выше
        if (currentBracket == ')' || currentBracket == ']') {

            // Получаем последнию добавленную скобку
            char lastBracket;
            if (brackets.size() > 0) {
                lastBracket = brackets.pop();
            }
            else {
                return false;
            }

            // Сравниваем типы скобок
            if (lastBracket == '(' && currentBracket == ')') {
                depth--;
            }
            else if (lastBracket == '[' && currentBracket == ']') {
                depth--;
            }
            else {
                return false;
            }

            if (depth < 0) {
                return false;
            }

        }
    }

    return depth == 0;
}

int main() {
    ifstream input("brackets.in");
    ofstream output("brackets.out");

    string sequence;

    while (input >> sequence) {
        string answer = check(sequence) ? "YES" : "NO";

        output << answer << endl;
    }

    return 0;
}