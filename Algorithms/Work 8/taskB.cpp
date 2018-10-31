#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Генерация префиксов
// Возрат их в формате массива элементов
int *generatePrefixes(string source) {
    auto prefix = new int[source.size()];

    prefix[0] = 0;
    for (int i = 1; i < source.size(); ++i) {
        int k = prefix[i - 1];

        while (k > 0 && source[i] != source[k]) {
            k = prefix[k - 1];
        }

        if (source[i] == source[k]) {
            k++;
        }

        prefix[i] = k;
    }

    return prefix;
}

// Быстрый поиск по алгоритму
// Кнута-Морриса-Пратта
// Возвращаются позиции, в которых встречается подстрока
vector<int> search(string &source, string &pattern) {
    vector<int> positions;
    int *prefixes = generatePrefixes(pattern + "#" + source);

    for (int i = 0; i < source.length(); ++i) {
        if (prefixes[pattern.length() + i + 1] == pattern.size()) {
            positions.push_back(i - pattern.size() + 2);
        }
    }

    return positions;
}

int main() {
    ifstream input("search2.in");
    string pattern, source;
    input >> pattern >> source;

    ofstream output("search2.out");

    vector<int> positions = search(source, pattern);

    output << positions.size() << endl;
    for (auto position: positions) {
        output << position << " ";
    }

    return 0;
}