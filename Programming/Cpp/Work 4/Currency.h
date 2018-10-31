//
// Created by Alexey Novopashin on 14/05/2018.
//

#ifndef LABWORK4_CURRENCY_H
#define LABWORK4_CURRENCY_H

#include <iostream>
#include "parser/tinyxml2.h"

using namespace std;
using namespace tinyxml2;

class Currency {
private:
    int id;
    string code;
    int nominal;
    string name;
    float value;
public:
    Currency(int id, const string &code, int nominal, const string &name, float value) : id(id), code(code),
                                                                                         nominal(nominal), name(name),
                                                                                         value(value) {}
    static Currency fromElement(XMLElement *element);

    Currency convert(Currency targetCurrency);

    float getCourse();

    const string &getCode() const;
};


#endif //LABWORK4_CURRENCY_H
