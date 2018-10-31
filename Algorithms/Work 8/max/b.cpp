#include <iostream>
#include <fstream>


size_t *prefixFunction(const std::string &line) {
    auto prefix = new size_t[line.size()];
    prefix[0] = 0;
    for (int i = 1; i < line.size(); ++i) {
        size_t k = prefix[i - 1];
        while (k > 0 && line[i] != line[k])
            k = prefix[k - 1];
        if (line[i] == line[k]) {
            k++;
        }
        prefix[i] = k;
    }
    return prefix;
}

void search(std::ofstream &output, std::string &line, std::string &pattern) {
    std::string position = ""; // Хранение позиций подстроки в строке
    size_t countPattern = 0; // Колличество вхождений

    size_t *prefix = prefixFunction(pattern + "#" + line);
    for (int i = 0; i < line.size(); ++i) {
        if (prefix[pattern.size() + i + 1] == pattern.size()) {
            countPattern++;
            position += std::to_string(i - pattern.size() + 2);
            position += " ";
        }
    }
    output << countPattern << std::endl << position;
}

int main() {
    std::string line, pattern; // Строка и подстрока

    std::ifstream input("search2.in");
    input >> pattern >> line; // Считывание с файла
    input.close();

    std::ofstream output("search2.out");

    search(output, line, pattern);
    return 0;
}