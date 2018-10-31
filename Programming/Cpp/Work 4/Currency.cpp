#include "Currency.h"

string unwrap(const XMLElement *element, const string name) {
    return element->FirstChildElement(name.c_str())->GetText();
}

Currency Currency::fromElement(XMLElement *element) {

    int id = stoi(unwrap(element, "NumCode"));
    string code = unwrap(element, "CharCode");
    int nominal = stoi(unwrap(element, "Nominal"));
    string name = unwrap(element, "Name");

    string rawValue = unwrap(element, "Value");
    rawValue.replace(rawValue.find(','), rawValue.find(',') - 1, ".");

    float value = stof(rawValue);

    return Currency(id, code, nominal, name, value);
}

Currency Currency::convert(Currency targetCurrency) {
    float newValue = value / targetCurrency.getCourse();

    return Currency(id, code, nominal, name, newValue);
}

float Currency::getCourse() {
    return this->value / this->nominal;
}

const string &Currency::getCode() const {
    return code;
}
