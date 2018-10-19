//
// Created by Alexey Novopashin on 14/05/2018.
//

#include "Parser.h"

vector<Currency> Parser::getCurrencies(string filename) {
    XMLDocument document;
    document.LoadFile(filename.c_str());

    XMLElement *root = document.FirstChildElement("ValCurs");
    XMLElement *currentChildElement = root->FirstChildElement("Valute");

    vector<Currency> currencies;

    // Iterate each Node
    while (currentChildElement != nullptr) {
        // Transform XML Node into class instance
        currencies.push_back(Currency::fromElement(currentChildElement));

        // Skip to next
        currentChildElement = currentChildElement->NextSiblingElement();
    }

    return currencies;
}
