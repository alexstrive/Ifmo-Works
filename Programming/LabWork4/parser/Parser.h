//
// Created by Alexey Novopashin on 14/05/2018.
//

#ifndef LABWORK4_PARSER_H
#define LABWORK4_PARSER_H


#include "../Currency.h"
#include <vector>

using namespace std;

class Parser {
public:
    static vector<Currency> getCurrencies(string filename);
};


#endif //LABWORK4_PARSER_H
