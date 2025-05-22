#pragma once  //Annya
#include <limits>
template <class T>
class Ravnobed_Tr : public Triangle<T> {
public:
    //перегруженные функции для изменения сторон
    Ravnobed_Tr() : Triangle<T>() {};
    Ravnobed_Tr(T sideA, T sideB) : Triangle<T>(sideA, sideB, sideA) {
        if (!isIsosceles()) {
            throw invalid_argument("Недопустимые стороны равнобедренного треугольника");
        }
    }

    bool isIsosceles() const {
        return (this->a == this->b) || (this->b == this->c) || (this->a == this->c);
    }

    void change_sides(T Side1, T Side2) {
        int choice;
        double newSide, newSide1, newSide2;
        newSide = Side1;
        newSide1 = Side2;
        newSide2 = Side1;

        
        while (true) {
            cout << "\nMenu):\n"
                << "0. Base\n"
                << "1. Changed sides (a и c)\n"
                << "2. Changed b\n"
                << "3. Changed all\n"
                << "4. Exit\n"
                << "Your choise: ";
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
                case 0: {
                    Ravnobed_Tr <double> tri;
                    tri.show();
                    this->set_sides(tri.a, tri.b, tri.c);
                    break;
                }
                case 1:
                    cout << "Input new sides (a и c): ";
                    cin >> newSide;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (!isIsosceles()) throw invalid_argument("Not ravnobedr");
                    this->set_a(newSide);
                    this->set_c(newSide);       
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
                    cout << "Input new sides (a and c, b): ";
                    cin >> newSide >> newSide2;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    this->set_sides(newSide, newSide2, newSide);
                    /*this->set_a(newSide);
                    this->set_b(newSide2);
                    this->set_c(newSide);*/
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
            }
        }
    }
    //T perimetr(T qwe) const {
    //    return this->a + this->b + this->c;
    //}
    //double area(T qwe) const {
    //    double p = static_cast<double>(perimetr()) / 2.0;
    //    double val = p * (p - this->a) * (p - this->b) * (p - this->c);
    //    if (val <= 0) return 0;
    //    return sqrt(val);
    //}
    //double in_circle(T qwe) {
    //    double S = area(1);
    //    if (S == 0) return 0;
    //    return 2.0 * S / static_cast<double>(perimetr());
    //}
    //double out_circle(T qwe) {
    //    double S = area(1);
    //    if (S == 0) return 0;
    //    return (static_cast<double>(this->a) * this->b * this->c) / (4.0 * S);
    //}
};
