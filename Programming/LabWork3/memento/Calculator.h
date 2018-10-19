//
// Created by Alexey Novopashin on 03/04/2018.
//

#ifndef WORK_3_CALCULATOR_H
#define WORK_3_CALCULATOR_H


#include "CalculatorOriginator.h"
#include "CalculatorCaretaker.h"

class Calculator {
private:
    CalculatorOriginator currentState;
    CalculatorCaretaker history;


    void updateState(int value) {
        this->currentState.setValue(value);
        this->saveState();
    }

    void saveState() {
        Memento *snapshot = this->currentState.save();
        history.add(snapshot);
    }

public:

    explicit Calculator(int initValue) {
        this->updateState(initValue);
    }

    void add(int number) {
        int value = currentState.getValue() + number;
        this->updateState(value);
    }

    void subtract(int number) {
        int value = currentState.getValue() - number;
        this->updateState(value);
    }

    void multiply(int number) {
        int value = currentState.getValue() * number;
        this->updateState(value);
    }

    void divide(int number) {
        int value = currentState.getValue() / number;
        this->updateState(value);
    }

    void undo() {
        this->currentState.restore(history.previous());
    }

    void redo() {
        this->currentState.restore(history.next());
    }

    int getCurrentValue() {
        return this->currentState.getValue();
    }
};


#endif //WORK_3_CALCULATOR_H
