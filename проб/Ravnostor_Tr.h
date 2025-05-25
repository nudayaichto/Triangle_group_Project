#pragma once
#include <iostream>
#include <cmath>
#include <limits>
#include <stdexcept>
#include "Triangle.h"
using namespace std;

template <class T>
class Ravnostor_Tr : public Triangle<T> {
public:
    void set_side(T side);

    bool isEquilateral() const;

    void change_sides(T side);

    T perimetr(T qwe) const;
    double area(T qwe) const;
    double in_circle(T qwe) const;
    double out_circle(T qwe) const;
};
