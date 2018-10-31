#include <vector>
#include <fstream>

using namespace std;

// Построение MaxHeap
void heapify(int arr[], int size, int rootIndex) {
    int maxIndex = rootIndex;
    int leftIndex = 2 * rootIndex + 1;
    int rightIndex = 2 * rootIndex + 2;

    // Сравниваем левого предка и родителя по значениям
    if (leftIndex < size && arr[leftIndex] > arr[maxIndex]) {
        maxIndex = leftIndex;
    }

    // Сравниваем правого предка и родителя по значениям
    if (rightIndex < size && arr[rightIndex] > arr[maxIndex]) {
        maxIndex = rightIndex;
    }

    // Меняем местами максимальный элемент и родителя
    if (maxIndex != rootIndex) {
        swap(arr[rootIndex], arr[maxIndex]);

        // Продолжаем строить MaxHeap
        heapify(arr, size, maxIndex);
    }
}

// Пирамидальная сортировка
void heapSort(int arr[], int size) {
    // Строим MaxHeap
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }

    for (int i = size - 1; i >= 0; i--) {
        // Меняем местами root и последний элемент
        swap(arr[0], arr[i]);

        // Строим MaxHeap из оставшихся элементов
        heapify(arr, i, 0);
    }
}


int main() {
    ifstream input("sort.in");
    ofstream output("sort.out");

    int size, *array;

    input >> size;
    array = new int[size];

    for (int i = 0; i < size; i++) {
        input >> array[i];
    }

    heapSort(array, size);

    for (int i = 0; i < size; i++) {
        output << array[i] << " ";
    }

    return EXIT_SUCCESS;
}