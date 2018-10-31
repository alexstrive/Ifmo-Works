//
// Created by Alexey Novopashin on 20/03/2018.
//

#ifndef WORK_3_MESSAGEBOX_H
#define WORK_3_MESSAGEBOX_H

#include <iostream>

using namespace std;

class MessageBox {
protected:
    string title;
    string message;
public:
    virtual void show() = 0;

    void setTitle(const string &title) {
        this->title = title;
    }

    void setMessage(const string &message) {
        this->message = message;
    }
};

#endif //WORK_3_MESSAGEBOX_H
