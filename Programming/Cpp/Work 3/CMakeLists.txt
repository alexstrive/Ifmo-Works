cmake_minimum_required(VERSION 3.9)
project(LabWork3)

set(CMAKE_CXX_STANDARD 11)

add_executable(Work_3 main.cpp factory/GUI.h factory/items/Button.h Color.h factory/WindowsGUI.cpp factory/WindowsGUI.h factory/items/WindowsButton.h factory/items/MacButton.h factory/items/Checkbox.h factory/items/WindowsCheckbox.h factory/items/MacCheckbox.h factory/MacGUI.cpp factory/MacGUI.h factory/items/MessageBox.h factory/items/WindowsMessageBox.h factory/items/MacMessageBox.h builder/AirplaneBuilder.h builder/AirplaneBuilder.cpp builder/Airplane.cpp builder/Airplane.h memento/Calculator.h memento/CalculatorOriginator.h memento/Memento.h memento/CalculatorCaretaker.h builder/AirplaneParts.h)
#add_executable(Work_3 main.cpp factory/items/Button.h factory/items/Button.cpp factory/items/WindowsButton.cpp factory/items/WindowsButton.h)