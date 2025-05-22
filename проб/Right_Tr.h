#pragma once
#include <cmath>
#include <iostream>
#include <limits>
#include <stdexcept>
using namespace std;

template <class T>
class Right_Tr : public Triangle<T> {
public:
    Right_Tr() : Triangle<T>(3,4,5) {}

    Right_Tr(T leg1, T leg2) : Triangle<T>(leg1, leg2, static_cast<T>(sqrt(leg1* leg1 + leg2 * leg2))) {
        if (!isRightTriangle()) {
            throw invalid_argument("Invalid sides for right triangle");
        }
    }

    bool isRightTriangle() const {
        T A = this->a;
        T B = this->b;
        T C = this->c;
        T maxSide = (A > B) ? ((A > C) ? A : C) : ((B > C) ? B : C);
        T side1, side2;
        if (maxSide == A) {
            side1 = B; side2 = C;
        }
        else if (maxSide == B) {
            side1 = A; side2 = C;
        }
        else {
            side1 = A; side2 = B;
        }
        return abs(maxSide * maxSide - (side1 * side1 + side2 * side2)) < 1e-10;
    }

    void change_sides(T Side1, T Side2) {
        int choice;
        T newLeg1 = Side1;
        T newLeg2 = Side2;
        T newA, newB, newC;

        while (true) {
            cout << "\nMenu:\n"
                << "0. Base\n"
                << "1. Change legs (a and b)\n"
                << "2. Change legs c\n"
                << "3. Change all\n"
                << "4. Change a\n"
                << "5. Change b\n"

                << "6. Exit\n"
                << "Your choice: ";

            if (!(cin >> choice)) {
                cout << "Error: please enter a number from 0 to 4.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (choice == 6) break;

            try {
                switch (choice) {
                case 0: {
                    Right_Tr<T> tri;
                    tri.show();
                    this->set_sides(tri.a, tri.b, tri.c);
                    break;
                }
                case 1:
                    cout << "Enter new values for legs (a and b): ";
                    cin >> newLeg1 >> newLeg2;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (!cin) throw invalid_argument("Invalid input");
                    if (newLeg1 <= 0 || newLeg2 <= 0) throw invalid_argument("Sides must be positive");
                   
                    this->set_sides(newLeg1, newLeg2, static_cast<T>(sqrt(newLeg1 * newLeg1 + newLeg2 * newLeg2)));
                    if (!isRightTriangle()) throw invalid_argument("Sides do not form a right triangle");
                    break;
                case 2:
                    cout << "Enter new value for hypotenuse (c): ";
                    cin >> newC;
                    if (!cin) throw invalid_argument("Invalid input");
                    if (newC <= 0) throw invalid_argument("Side must be positive");
                    set_c(newC);
                    if (!isRightTriangle()) throw invalid_argument("Sides do not form a right triangle");
                    break;
                case 3:
                    cout << "Enter new sides (a b c): ";
                    cin >> newA >> newB >> newC;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (!cin) throw invalid_argument("Invalid input");
                    if (newA <= 0 || newB <= 0 || newC <= 0) throw invalid_argument("Sides must be positive");
                    set_a(newA);
                    set_b(newB);
                    set_c(newC);
                    if (!isRightTriangle()) throw invalid_argument("Sides do not form a right triangle");
                    break; 
                case 4:
                    cout << "Enter new side (a): ";
                    cin >> newA;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (!cin) throw invalid_argument("Invalid input");
                    if (newA <= 0) throw invalid_argument("Sides must be positive");
                    
                    set_a(newA);
                    if (!isRightTriangle()) throw invalid_argument("Sides do not form a right triangle");
                    break;
                case 5:
                    cout << "Enter new side b: ";
                    cin >> newB;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (!cin) throw invalid_argument("Invalid input");
                    if (newB <= 0) throw invalid_argument("Sides must be positive");

                    set_b(newB);
                    if (!isRightTriangle()) throw invalid_argument("Sides do not form a right triangle");
                    break;
                
                default:
                    cout << "Incorrect number\n";
                    continue;
                }
                cout << "\nCurrent sides:\n";
                this->show();
            }
            catch (const invalid_argument& e) {
                cout << "Error: " << e.what() << endl;
            }
        }
    }
    void set_a(T newA) {
        if (newA <= 0) throw invalid_argument("Side must be positive");
        T b = this->b;
        T c = this->c;

        T newC = static_cast<T>(sqrt(newA * newA + b * b));
        this->a = newA;
        this->c = newC;
    }

    void set_b(T newB) {
        if (newB <= 0) throw invalid_argument("Side must be positive");
        T a = this->a;
        T c = this->c;

        T newC = static_cast<T>(sqrt(a * a + newB * newB));
        this->b = newB;
        this->c = newC;
    }

    void set_c(T newC) {
        if (newC <= 0) throw invalid_argument("Side must be positive");
        T a = this->a;

        if (newC <= a) throw invalid_argument("Hypotenuse must be greater than leg a");

        T newB = static_cast<T>(sqrt(newC * newC - a * a));
        this->c = newC;
        this->b = newB;
    }

    T perimetr(T qwe) const {
        if (!isRightTriangle()) throw invalid_argument("Triangle is not equilateral");
        return this->a + this->b + this->c;
    }

    double area(T qwe) const {
        if (!isRightTriangle()) throw invalid_argument("Triangle is not equilateral");
        T a = this->a;
        T b = this->b;
        return a*b/2;
    }

    double in_circle(T qwe) const {
        if (!isRightTriangle()) throw invalid_argument("Triangle is not equilateral");
        T a = this->a;
        T b = this->b;
        T c = this->c;
        return (a + b - c)/2;
    }

    double out_circle(T qwe) const {
        if (!isRightTriangle()) throw invalid_argument("Triangle is not equilateral");
        T c = this->c;
        return c/2;
    }
    //void change_sides() {
    //    change_sides(this->a, this->b);
    //}
                //case 2:
                //    cout << "Enter new value for hypotenuse (c): ";
                //    cin >> newC;
                //    if (!cin) throw invalid_argument("Invalid input");
                //    if (newC <= 0) throw invalid_argument("Side must be positive");
                //    this->set_c(newC);
                //    if (!isRightTriangle()) throw invalid_argument("Sides do not form a right triangle");
                //    break;/*case 2:
    //cout << "Enter new sides (a b c): ";
    //cin >> newA >> newB >> newC;
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //if (!cin) throw invalid_argument("Invalid input");
    //if (newA <= 0 || newB <= 0 || newC <= 0) throw invalid_argument("Sides must be positive");
    //this->set_a(newA);
    //this->set_b(newB);
    //this->set_c(newC);
    //if (!isRightTriangle()) throw invalid_argument("Sides do not form a right triangle");
    //break;*/
};
