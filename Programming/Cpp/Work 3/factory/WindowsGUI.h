//
// Created by Alexey Novopashin on 20/03/2018.
//

#ifndef WORK_3_WINDOWSGUI_H
#define WORK_3_WINDOWSGUI_H


#include "GUI.h"

class WindowsGUI : public GUI {
public:
    WindowsGUI();

    Button *createButton() override;

    Checkbox *createCheckbox() override;

    MessageBox *createMessageBox() override;
};


#endif //WORK_3_WINDOWSGUI_H
