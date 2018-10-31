#include <iostream>
#include <fstream>
 
size_t * prefixFunction(const std::string& line) {
    auto prefix = new size_t[line.size()];
    prefix[0] = 0;
    for (int i = 1; i < line.size(); ++i) {
        size_t k = prefix[i - 1];
        while(k > 0 && line[i] != line[k])
            k = prefix[k - 1];
        if(line[i] == line[k])
            k++;
        prefix[i] = k;
    }
    return prefix;
}
 
int main() {
    std::string line; // Строка и подстрока
 
    std::ifstream input("prefix.in");
    input >> line; // Считывание с файла
    input.close();
 
    std::ofstream output("prefix.out");
 
    size_t * prefix = prefixFunction(line);
    for (int i = 0; i < line.size(); ++i) {
        output << prefix[i] << " ";
    }
    output.close();
    return 0;
}