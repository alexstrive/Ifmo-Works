//
// Created by Alexey Novopashin on 20/03/2018.
//

#include "Airplane.h"

Airplane::Airplane(Frame frame, Metal metal, TurbineNumber turbineNumber, const string &airplaneName)
        : frame(frame), metal(metal), turbineNumber(turbineNumber), airplaneName(airplaneName) {}