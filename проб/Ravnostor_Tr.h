#pragma once
#include <cmath>
template <class T>
class Ravnostor_Tr : public Triangle<T> {
public:
    /*Ravnostor_Tr() : Triangle<T>() {}

    Ravnostor_Tr(T side) : Triangle<T>(side, side, side) {
        if (side <= 0) {
            throw invalid_argument("Side must be positive");
        }
    }*/
    void set_side(T side) {
        if (side <= 0) {
            throw invalid_argument("Side must be positive");
        }
        this->set_sides(side, side, side);
    }

    bool isEquilateral() const {
        return (this->a == this->b) && (this->b == this->c);
    }

    void change_sides( T side) {
        int choice;
        T newSide = this->a;  
        while (true) {
            cout << "\nMenu:\n"
                << "0. Reset to default sides (1,1,1)\n"
                << "1. Change all sides\n"
                << "2. Exit\n"
                << "Your choice: ";

            if (!(cin >> choice)) {
                cout << "Error: please enter a number from 0 to 2.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            if (choice == 2) break;

            try {
                switch (choice) {
                case 0: {
                    this->set_sides(1, 1, 1);
                    break;
                }
                case 1:
                    cout << "Input new side (all sides equal): ";
                    cin >> newSide;
                    if (cin.fail() || newSide <= 0) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        throw invalid_argument("Side must be positive");
                    }
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    this->set_side(newSide);
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

    T perimetr(T qwe) const {
        if (!isEquilateral()) throw invalid_argument("Triangle is not equilateral");
        return this->a * 3;
    }

    double area(T qwe) const {
        if (!isEquilateral()) throw invalid_argument("Triangle is not equilateral");
        T a = this->a;
        return (sqrt(3) * pow(a, 2)) / 4;
    }

    double in_circle(T qwe) const {
        if (!isEquilateral()) throw invalid_argument("Triangle is not equilateral");
        T a = this->a;
        return (a * sqrt(3) / 6);
    }

    double out_circle(T qwe) const {
        if (!isEquilateral()) throw invalid_argument("Triangle is not equilateral");
        T a = this->a;
        return (sqrt(3) / 3) * a;
    }
};
