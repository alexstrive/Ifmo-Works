#include <iostream>
#include "factory/GUI.h"
#include "factory/WindowsGUI.h"
#include "factory/MacGUI.h"
#include "builder/AirplaneBuilder.h"
#include "memento/Calculator.h"

#define Factory
#define Builder
#define Memento

int main() {
#if defined(Factory)

#define MAC

#if defined(MAC)
    GUI *factory = new MacGUI();
#elif defined(WINDOWS)
    GUI *factory = new WindowsGUI();
#endif

    cout << endl << "[!] Creating Items:" << endl;

    Button *button = factory->createButton();
    Checkbox *checkbox = factory->createCheckbox();
    MessageBox *messageBox = factory->createMessageBox();

    cout << endl << "[!] Actions: " << endl;

    button->click();
    checkbox->select();
    messageBox->show();
#endif

#if defined(Builder)
    AirplaneBuilder customAirplaneBuilder(Frame::AVERAGE, Metal::Aluminum, TurbineNumber::EIGHT);
    Airplane *firstCustomAirplane = customAirplaneBuilder.build();
    Airplane *secondCustomAirplane = customAirplaneBuilder.build();
#endif

#if defined(Memento)
    Calculator calculator(10);
    calculator.add(4);
    calculator.divide(10);
    calculator.multiply(12);
    calculator.subtract(10);

    calculator.undo();
    calculator.undo();
    calculator.redo();
    calculator.undo();

    cout << endl << "Calculator Current Value: " << calculator.getCurrentValue() << endl;
#endif

    return EXIT_SUCCESS;
}
