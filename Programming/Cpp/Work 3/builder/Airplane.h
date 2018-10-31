//
// Created by Alexey Novopashin on 20/03/2018.
//

#ifndef WORK_3_AIRPLANE_H
#define WORK_3_AIRPLANE_H


#include <sstream>
#include "iostream"
#include "string"
#include "AirplaneParts.h"

using namespace std;

class Airplane {
protected:
    Frame frame;
    Metal metal;
    TurbineNumber turbineNumber;
    string airplaneName;
public:
    Airplane(Frame frame, Metal metal, TurbineNumber turbineNumber, const string &airplaneName);
};


#endif //WORK_3_AIRPLANE_H
