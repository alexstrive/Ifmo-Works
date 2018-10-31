//
// Created by Alexey Novopashin on 20/03/2018.
//

#include "WindowsGUI.h"
#include "items/WindowsButton.h"
#include "items/WindowsCheckbox.h"
#include "items/WindowsMessageBox.h"

WindowsGUI::WindowsGUI() {
    cout << "Windows Factory created" << endl << endl;
}

Button *WindowsGUI::createButton() {
    cout << "Windows Button created" << endl;
    return new WindowsButton();
}

Checkbox *WindowsGUI::createCheckbox() {
    cout << "Windows Checkbox created" << endl;
    return new WindowsCheckbox();
}

MessageBox *WindowsGUI::createMessageBox() {
    cout << "Windows MessageBox created" << endl;
    return new WindowsMessageBox();
}
