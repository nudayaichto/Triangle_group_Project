#pragma once
#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

template <class T>
class Triangle
{
protected:
    T a, b, c;
public:
    Triangle();
    Triangle(T A, T B, T C);
    ~Triangle() = default;

    bool isValid() const;
    bool isComman() const;

    void set_a(T A);
    void set_b(T B);
    void set_c(T C);
    void set_sides(T A, T B, T C);

    T get_a() const;
    T get_b() const;
    T get_c() const;

    void show() const;
    void change_sides();

    T perimetr() const;
    double area() const;
    double in_circle();
    double out_circle();
};
