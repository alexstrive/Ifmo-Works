#include <iostream>
#include <fstream>

using namespace std;

// Генерация префиксов
// Возрат их в качестве массива
int *generatePrefixes(string &source) {
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

int main() {
    ifstream input("prefix.in");
    string source;
    input >> source;

    ofstream output("prefix.out");
    auto *prefixies = generatePrefixes(source);
    for (int i = 0; i < source.size(); ++i) {
        output << prefixies[i] << " ";
    }

    return 0;
}