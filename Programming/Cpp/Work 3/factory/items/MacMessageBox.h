//
// Created by Alexey Novopashin on 20/03/2018.
//

#ifndef WORK_3_MACMESSAGEBOX_H
#define WORK_3_MACMESSAGEBOX_H

#include "MessageBox.h"

class MacMessageBox : public MessageBox {
public:
    void show() override {
        cout << "Mac Message Box showed" << endl;
    }
};

#endif //WORK_3_MACMESSAGEBOX_H
