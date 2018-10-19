//
// Created by Alexey Novopashin on 20/03/2018.
//

#ifndef WORK_3_WINDOWSCHECKBOX_H
#define WORK_3_WINDOWSCHECKBOX_H

#include "Checkbox.h"

class WindowsCheckbox : public Checkbox {
public:
    void select() override {
        Checkbox::select();
        cout << "Windows Checkbox selected!" << endl;
    }
};

#endif //WORK_3_WINDOWSCHECKBOX_H
