//
// Created by Alexey Novopashin on 20/03/2018.
//

#ifndef WORK_3_CHECKBOX_H
#define WORK_3_CHECKBOX_H

#include "iostream"

using namespace std;

class Checkbox {
protected:
    string text;
    bool isSelected = false;
public:
    virtual void select() {
        this->isSelected = !this->isSelected;
    }

    virtual void setText(string text) {
        this->text = text;
    }
};

#endif //WORK_3_CHECKBOX_H
