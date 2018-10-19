//
// Created by Alexey Novopashin on 03/04/2018.
//

#ifndef TESTWORK1_CPOINT_H
#define TESTWORK1_CPOINT_H


#include <ostream>

class CPoint {
private:
    float x, y;
public:
    CPoint(float x, float y);

    friend std::ostream &operator<<(std::ostream &os, const CPoint &point);
    friend CPoint operator+(const CPoint &left, const CPoint &right);
    friend CPoint operator-(const CPoint &left, const CPoint &right);
};


#endif //TESTWORK1_CPOINT_H
