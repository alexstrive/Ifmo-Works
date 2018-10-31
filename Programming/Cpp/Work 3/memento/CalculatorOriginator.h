//
// Created by Alexey Novopashin on 03/04/2018.
//

#ifndef WORK_3_CALCULATORORIGINATOR_H
#define WORK_3_CALCULATORORIGINATOR_H

#include "Memento.h"

// Originator
class CalculatorOriginator {
private:
    int value;
public:
    Memento *save() {
        return new Memento(this->value);
    }

    void restore(Memento *memento) {
        this->value = memento->getState();
    }

    void setValue(int value) {
        this->value = value;
    }

    int getValue() const {
        return value;
    }
};


#endif //WORK_3_CALCULATORORIGINATOR_H
