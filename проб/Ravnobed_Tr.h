#pragma once  //Annya
#include <limits>
template <class T>
class Ravnobed_Tr : public Triangle<T> {
public:
    //перегруженные функции для изменения сторон
    Ravnobed_Tr() = default;
    Ravnobed_Tr(T sideA, T sideB) : Triangle<T>(sideA, sideB, sideA) {
        if (!isIsosceles()) {
            throw invalid_argument("Недопустимые стороны равнобедренного треугольника");
        }
    }

    bool isIsosceles() const {
        return (this->a == this->b) || (this->b == this->c) || (this->a == this->c);
    }

    void change_sides() {
        int choice;
        T newSide, newSide1, newSide2;
        while (true) {
            cout << "\nMenu):\n"
                << "1. Changed sides (a и c)\n"
                << "2. Changed b\n"
                << "3. Changed all\n"
                << "4. Exit\n"
                << "Your choise: ";
            //cin >> choice;
            if (!(cin >> choice))
            {
                cout << "Ошибка: введите число от 1 до 5.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue; // повторить ввод
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (choice == 4) break;

            try {
                switch (choice) {
                case 1:
                    cout << "Input new sides (a и c): ";
                    cin >> newSide;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    this->set_a(newSide);
                    this->set_c(newSide);
                    if (!isIsosceles()) throw invalid_argument("Not ravnobedr");
                    break;
                case 2:
                    cout << "Input new b: ";
                    cin >> newSide;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    this->set_b(newSide);
                    if (!isIsosceles()) throw invalid_argument("Not ravnobedr");
                    break;
                case 3:
                    cout << "Input new sides (a, b, c): ";
                    cin >> newSide1 >> newSide2 >> newSide;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    this->set_a(newSide1);
                    this->set_b(newSide2);
                    this->set_c(newSide);
                    if (!isIsosceles()) throw invalid_argument("Not ravnobedr");
                    break;
                default:
                    cout << "incorrect numb\n";
                    continue;
                }
                cout << "\nCurrent sides: \n";
                this->show();
            }
            catch (const invalid_argument& e) {
                cout << "Error: " << e.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }

    T perimetr() const {
        if (!isIsosceles()) throw invalid_argument("Not ravnobedr");
        return this->a + this->b + this->c;
    }

    double area() const {
        if (!isIsosceles()) throw invalid_argument("Not ravnobedr");
        double p = static_cast<double>(perimetr()) / 2.0;
        double val = p * (p - this->a) * (p - this->b) * (p - this->c);
        if (val <= 0) return 0;
        return sqrt(val);
    }

    double in_circle() const {
        if (!isIsosceles()) throw invalid_argument("Not ravnobedr");
        double S = area();
        if (S == 0) return 0;
        return 2.0 * S / static_cast<double>(perimetr());
    }

    double out_circle() const {
        if (!isIsosceles()) throw invalid_argument("Not ravnobedr");
        double S = area();
        if (S == 0) return 0;
        return (static_cast<double>(this->a) * this->b * this->c) / (4.0 * S);
    }
};
