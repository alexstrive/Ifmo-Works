//
// Created by Alexey Novopashin on 03/04/2018.
//

#ifndef WORK_3_CALCULATORCARETAKER_H
#define WORK_3_CALCULATORCARETAKER_H


#include <vector>
#include "Memento.h"

// Caretaker
class CalculatorCaretaker {
private:
    std::vector<Memento*> snapshots;
    int currentSnapshotNumber = 0;

public:
    void add(Memento *snapshot) {
        this->snapshots.push_back(snapshot);
        currentSnapshotNumber = static_cast<int>(this->snapshots.size() - 1);
    }

    Memento *previous() {
        if (currentSnapshotNumber - 1 < 0) {
            return this->snapshots[currentSnapshotNumber];
        }

        return this->snapshots[--currentSnapshotNumber];
    }

    Memento *next() {
        if (currentSnapshotNumber + 1 >= snapshots.size()) {
            return this->snapshots[currentSnapshotNumber];
        }

        return this->snapshots[++currentSnapshotNumber];
    }
};


#endif //WORK_3_CALCULATORCARETAKER_H
