//
// Created by Alexey Novopashin on 03/04/2018.
//

#include "CPoint.h"

CPoint::CPoint(float x, float y) : x(x), y(y) {}

std::ostream &operator<<(std::ostream &os, const CPoint &point) {
    os << point.x << ", " << point.y << std::endl;
    return os;
}

CPoint operator+(const CPoint &left, const CPoint &right) {
    CPoint newPoint(left.x + right.x, left.y + right.y);

    return newPoint;
}

CPoint operator-(const CPoint &left, const CPoint &right) {
    CPoint newPoint(left.x - right.x, left.y - right.y);

    return newPoint;
}