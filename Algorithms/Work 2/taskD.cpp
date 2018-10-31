#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int target_number;

    ifstream input_file;
    input_file.open("./antiqs.in");

    input_file >> target_number;

    auto *values = new int[target_number];

    // Заполняем массив элементами от 1 до n
    for (int i = 0; i < target_number; i++) {
        values[i] = i + 1;
    }

    for (int i = 0; i < target_number; i++) {
        swap(values[i], values[i / 2]);
    }

    ofstream output_file;
    output_file.open("./antiqs.out");

    for (int i = 0; i < target_number; i++) {
        output_file << values[i] << " ";
    }

    return EXIT_SUCCESS;
}