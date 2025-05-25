#pragma once
#include "Triangle.h"

template <class T>
class Right_Tr : public Triangle<T> {
public:
    Right_Tr();
    Right_Tr(T leg1, T leg2);

    bool isRightTriangle() const;
    void change_sides(T Side1, T Side2);
    void set_a(T newA);
    void set_b(T newB);
    void set_c(T newC);

    T perimetr(T qwe) const;
    double area(T qwe) const;
    double in_circle(T qwe) const;
    double out_circle(T qwe) const;
};
