//
// Created by Alexey Novopashin on 20/03/2018.
//

#ifndef WORK_3_WINDOWSMESSAGEBOX_H
#define WORK_3_WINDOWSMESSAGEBOX_H

#include "MessageBox.h"

class WindowsMessageBox : public MessageBox {
public:
    WindowsMessageBox() {
    }

    void show() override {
        cout << "Windows Message Box showed!" << endl;
    }
};

#endif //WORK_3_WINDOWSMESSAGEBOX_H
