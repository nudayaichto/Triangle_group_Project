#pragma once
#include "Triangle.h"
template <class T>
Triangle<T>::Triangle() : a(1), b(1), c(1)
{
    if (!isValid())
        throw invalid_argument("Incorrect triangle arguments");
    if (!isComman())
        throw invalid_argument("Incorrect triangle arguments");
}

template <class T>
Triangle<T>::Triangle(T A, T B, T C) : a(A), b(B), c(C)
{
    if (!isValid()) throw invalid_argument("Incorrect triangle arguments");
    if (!isComman()) throw invalid_argument("Incorrect triangle arguments");
}

template <class T>
bool Triangle<T>::isValid() const
{
    return (a > 0 && b > 0 && c > 0) && (a + b > c) && (a + c > b) && (b + c > a);
}

template <class T>
bool Triangle<T>::isComman() const
{
    T p = (a + b + c) / 2;
    double area = sqrt(p * (p - a) * (p - b) * (p - c));
    return area > 1e-10;
}

template <class T>
void Triangle<T>::set_a(T A)
{
    T oldA = a;
    a = A;
    if (!isValid())
    {
        a = oldA;
        throw invalid_argument("Invalid value for side a");
    }
}

template <class T>
void Triangle<T>::set_b(T B)
{
    T oldB = b;
    b = B;
    if (!isValid())
    {
        b = oldB;
        throw invalid_argument("Invalid value for side b");
    }
}

template <class T>
void Triangle<T>::set_c(T C)
{
    T oldC = c;
    c = C;
    if (!isValid())
    {
        c = oldC;
        throw invalid_argument("Invalid value for side c");
    }
}

template <class T>
void Triangle<T>::set_sides(T A, T B, T C)
{
    T oldA = a;
    T oldB = b;
    T oldC = c;
    a = A;
    b = B;
    c = C;
    if (!isValid())
    {
        a = oldA;
        b = oldB;
        c = oldC;
        throw invalid_argument("Invalid values for all sides");
    }
}

template <class T>
T Triangle<T>::get_a() const { return a; }

template <class T>
T Triangle<T>::get_b() const { return b; }

template <class T>
T Triangle<T>::get_c() const { return c; }

template <class T>
void Triangle<T>::show() const {
    cout << "Side lengths: a = " << a << ", b = " << b << ", c = " << c << endl;
}

template <class T>
void Triangle<T>::change_sides() {
    int choice;
    T newSide, newSide1, newSide2, newSide3;
    while (true) {
        cout << "\nMenu:\n"
            << "0. Base\n"
            << "1. Change side a\n"
            << "2. Change side b\n"
            << "3. Change side c\n"
            << "4. Change all sides\n"
            << "5. Exit\n"
            << "Select option: ";
        if (!(cin >> choice))
        {
            cout << "Ошибка: введите число от 1 до 5.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue; // повторить ввод
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 5) break;

        try {
            switch (choice) {
            case 0: {
                Triangle <double> tri;
                tri.show();
                this->set_sides(tri.a, tri.b, tri.c);
                break;
            }
            case 1:
                cout << "Enter new value for a: ";

                if (!(cin >> newSide))
                {
                    cout << "Ошибка: введите число.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue; // повторить ввод
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                set_a(newSide);
                break;

            case 2:
                cout << "Enter new value for b: ";
                if (!(cin >> newSide))
                {
                    cout << "Ошибка: введите число.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue; // повторить ввод
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                set_b(newSide);
                break;

            case 3:
                cout << "Enter new value for c: ";
                if (!(cin >> newSide))
                {
                    cout << "Ошибка: введите число.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue; // повторить ввод
                }
                set_c(newSide);
                break;
            case 4:
                cout << "Enter new values (space/enter separated): ";
                if (!(cin >> newSide1 >> newSide2 >> newSide3))
                {
                    cout << "Ошибка: введите числа.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue; // повторить ввод
                }
                set_sides(newSide1, newSide2, newSide3);
                break;

            default:
                cout << "Exiting program\n";
                continue;
            }
            cout << "\nCurrent values: \n";
            show();
        }
        catch (const invalid_argument& e) {
            cout << "Error: " << e.what() << std::endl;
        }
    }
}

template <class T>
T Triangle<T>::perimetr() const {
    return a + b + c;
}

template <class T>
double Triangle<T>::area() const {
    double p = static_cast<double>(perimetr()) / 2.0;
    double val = p * (p - a) * (p - b) * (p - c);
    if (val <= 0) return 0;
    return sqrt(val);
}

template <class T>
double Triangle<T>::in_circle() {
    double S = area();
    if (S == 0) return 0;
    return 2.0 * S / static_cast<double>(perimetr());
}

template <class T>
double Triangle<T>::out_circle() {
    double S = area();
    if (S == 0) return 0;
    return (static_cast<double>(a) * b * c) / (4.0 * S);
}
