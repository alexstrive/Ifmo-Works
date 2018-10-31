//
// Created by Alexey Novopashin on 20/03/2018.
//

#ifndef WORK_3_MACGUI_H
#define WORK_3_MACGUI_H


#include "GUI.h"

class MacGUI : public GUI {
public:
    MacGUI();

    Button *createButton() override;

    Checkbox *createCheckbox() override;

    MessageBox *createMessageBox() override;
};


#endif //WORK_3_MACGUI_H
