//
// Created by Alexey Novopashin on 20/03/2018.
//

#include "iostream";
#include "../../Color.h"

#ifndef WORK_3_BUTTON_H
#define WORK_3_BUTTON_H

using namespace std;

class Button {
protected:
    string text;
    Color color;
public:
    virtual void click() = 0;

    virtual void setColor(Color color) {
        this->color = color;
    }

    virtual void setText(string text) {
        this->text = text;
    }
};


#endif //WORK_3_BUTTON_H
