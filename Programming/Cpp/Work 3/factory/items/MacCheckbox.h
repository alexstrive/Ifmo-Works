//
// Created by Alexey Novopashin on 20/03/2018.
//

#ifndef WORK_3_MACCHECKBOX_H
#define WORK_3_MACCHECKBOX_H

#include "Checkbox.h"

class MacCheckbox : public Checkbox {
public:
    void select() override {
        Checkbox::select();
        cout << "Mac Checkbox selected" << endl;
    }
};

#endif //WORK_3_MACCHECKBOX_H
