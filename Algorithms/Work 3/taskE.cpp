#include <vector>
#include <fstream>

using namespace std;

bool isHeap(vector<int> &values, int index) {
    return values[index] >= values[index / 2];
}

int main() {
    ifstream input("isheap.in");
    ofstream output("isheap.out");

    int length;
    input >> length;
    vector<int> values(length + 1);

    for (int i = 1; i < length + 1; i++) {
        input >> values[i];
    }

    for (int i = 2; i < length; i++) {

        if (!isHeap(values, i)) {
            output << "NO";
            return EXIT_SUCCESS;
        }

    }

    output << "YES";


    return EXIT_SUCCESS;
}