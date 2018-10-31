//
// Created by Alexey Novopashin on 20/03/2018.
//

#ifndef WORK_3_MACBUTTON_H
#define WORK_3_MACBUTTON_H


#include "Button.h"

class MacButton : public Button {
public:
    void click() override {
        cout << "Mac Button clicked" << endl;
    }
};


#endif //WORK_3_MACBUTTON_H
