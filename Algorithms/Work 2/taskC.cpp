#include <iostream>
#include <fstream>

using namespace std;

unsigned long merge(int array[], int start, int middle, int last) {
    int left_index, right_index, current_index;
    int left_size = middle - start + 1;
    int right_size = last - middle;

    unsigned long inversions = 0;

    // Копируем элементы в соответствующие части

    int left_part[left_size], right_part[right_size];

    // Копируем элементы в левую часть
    for (left_index = 0; left_index < left_size; left_index++) {
        left_part[left_index] = array[start + left_index];
    }

    // Копируем элементы в правую часть
    for (right_index = 0; right_index < right_size; right_index++) {
        right_part[right_index] = array[middle + 1 + right_index];
    }

    left_index = 0;
    right_index = 0;
    current_index = start;

    // Сортируем элементы по возрастанию
    while (left_index < left_size && right_index < right_size) {

        if (left_part[left_index] <= right_part[right_index]) {
            array[current_index] = left_part[left_index];
            left_index++;
        }
        else {
            array[current_index] = right_part[right_index];
            right_index++;

            inversions += middle - left_index + 1;
        }

        current_index++;
    }

    // Копируем оставшиеся элементы из левой части
    while (left_index < left_size) {
        array[current_index] = left_part[left_index];
        left_index++;
        current_index++;
    }

    // Копируем оставшиеся элементы из правой части
    while (right_index < right_size) {
        array[current_index] = right_part[right_index];
        right_index++;
        current_index++;
    }

    return inversions;
}

unsigned long merge_sort(int *arr, int first, int last) {
    unsigned long inversions = 0;

    if (first < last) {
        int middle = first + (last - first) / 2;

        inversions = merge_sort(arr, first, middle);
        inversions += merge_sort(arr, middle + 1, last);

        inversions += merge(arr, first, middle, last);
    }

    return inversions;
}

int main() {
    int number_values;

    ifstream input_file;
    input_file.open("./inversions.in");

    input_file >> number_values;
    auto *values = new int[number_values];

    for (int i = 0; i < number_values; i++) {
        input_file >> values[i];
    }

    auto inversions = merge_sort(values, 0, number_values);

    ofstream output_file;
    output_file.open("./inversions.out");

    output_file << inversions;

    return EXIT_SUCCESS;
}