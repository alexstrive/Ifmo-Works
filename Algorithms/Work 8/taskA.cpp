#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream input("search1.in");
    string target, source;
    input >> target >> source;


    ofstream output("search1.out");

    if (target.length() > source.length()) {
        output << "0" << endl;
        return 0;
    }

    vector<int> inclusions;
    for (int i = 0; i < source.length() - target.length() + 1; ++i) {
        int j = 0;

        for (j = 0; j < target.length(); ++j) {
            if (target[j] != source[i + j]) {
                break;
            }
        }

        if (j == target.length()) {
            inclusions.push_back(i + 1);
        }
    }


    output << inclusions.size() << endl;
    for (auto inclusionNumber : inclusions) {
        output << inclusionNumber << " ";
    }

    return 0;
}