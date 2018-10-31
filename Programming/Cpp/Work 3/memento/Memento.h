//
// Created by Alexey Novopashin on 03/04/2018.
//

#ifndef WORK_3_CALCULATORMEMENTO_H
#define WORK_3_CALCULATORMEMENTO_H

// Memento
class Memento {
private:
    int state;
public:
    explicit Memento(int state) : state(state) {}

    int getState() const {
        return state;
    }
};


#endif //WORK_3_CALCULATORMEMENTO_H
