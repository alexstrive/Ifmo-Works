//
// Created by Alexey Novopashin on 20/03/2018.
//

#ifndef WORK_3_WINDOWSBUTTON_H
#define WORK_3_WINDOWSBUTTON_H


#include "Button.h"

class WindowsButton : public Button {
public:
    void click() override {
        cout << "Windows Button clicked" << endl;
    }
};


#endif //WORK_3_WINDOWSBUTTON_H
