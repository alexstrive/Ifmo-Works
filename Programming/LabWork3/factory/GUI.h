//
// Created by Alexey Novopashin on 20/03/2018.
//

#ifndef WORK_3_ABSTRACTFACTORY_H
#define WORK_3_ABSTRACTFACTORY_H

#include "items/Button.h"
#include "items/Checkbox.h"
#include "items/MessageBox.h"

class GUI {
public:
    virtual Button *createButton() = 0;

    virtual Checkbox *createCheckbox() = 0;

    virtual MessageBox *createMessageBox() = 0;
};

#endif //WORK_3_ABSTRACTFACTORY_H
