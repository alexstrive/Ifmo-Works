//
// Created by Alexey Novopashin on 20/03/2018.
//

#include "MacGUI.h"
#include "items/MacButton.h"
#include "items/MacCheckbox.h"
#include "items/MacMessageBox.h"

MacGUI::MacGUI() {
    cout << "Mac Factory created" << endl << endl;
}

Button *MacGUI::createButton() {
    cout << "Mac Button created" << endl;
    return new MacButton();
}

Checkbox *MacGUI::createCheckbox() {
    cout << "Mac Checkbox created" << endl;
    return new MacCheckbox();
}

MessageBox *MacGUI::createMessageBox() {
    cout << "Mac Message Box created" << endl;
    return new MacMessageBox();
}
