#include <iostream>
#include "CPoint.h"

int main() {
    CPoint p = CPoint(10, 10) + CPoint(20, 20) - CPoint(15, 15);
    std::cout << p;
    return 0;
}