#pragma once
#include <iostream>
#include <limits>
#include <stdexcept>
#include "Triangle.h"
using namespace std;

template <class T>
class Ravnobed_Tr : public Triangle<T> {
public:
    Ravnobed_Tr();
    Ravnobed_Tr(T sideA, T sideB);

    bool isIsosceles() const;

    void change_sides(T Side1, T Side2);
};
