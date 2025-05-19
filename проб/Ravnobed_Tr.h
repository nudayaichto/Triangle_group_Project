#pragma once  //Annya
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
            cout << "\nMenu:\n"
                << "1. Change equal sides (a and c)\n"
                << "2. Change side b\n"
                << "3. Change all sides\n"
                << "4. Exit\n"
                << "Your choice: ";
            cin >> choice;

            if (choice == 4) break;

            try {
                switch (choice) {
                case 1:
                    cout << "Enter new value for equal sides (a and c): ";
                    cin >> newSide;
                    this->set_a(newSide);
                    this->set_c(newSide);
                    if (!isIsosceles()) throw invalid_argument("Not an isosceles triangle anymore");
                    break;
                case 2:
                    cout << "Enter new value for side b: ";
                    cin >> newSide;
                    this->set_b(newSide);
                    if (!isIsosceles()) throw invalid_argument("Not an isosceles triangle anymore");
                    break;
                case 3:
                    cout << "Enter new sides (a b c): ";
                    cin >> newSide1 >> newSide2 >> newSide;
                    this->set_a(newSide1);
                    this->set_b(newSide2);
                    this->set_c(newSide);
                    if (!isIsosceles()) throw invalid_argument("Not an isosceles triangle anymore");
                    break;
                default:
                    cout << "Invalid choice\n";
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

    T perimetr() const {
        if (!isIsosceles()) throw invalid_argument("Not an isosceles triangle anymore");
        return this->a + this->b + this->c;
    }

    double area() const {
        if (!isIsosceles()) throw invalid_argument("Not an isosceles triangle anymore");
        double p = static_cast<double>(perimetr()) / 2.0;
        double val = p * (p - this->a) * (p - this->b) * (p - this->c);
        if (val <= 0) return 0;
        return sqrt(val);
    }

    double in_circle() const {
        if (!isIsosceles()) throw invalid_argument("Not an isosceles triangle anymore");
        double S = area();
        if (S == 0) return 0;
        return 2.0 * S / static_cast<double>(perimetr());
    }

    double out_circle() const {
        if (!isIsosceles()) throw invalid_argument("Not an isosceles triangle anymore");
        double S = area();
        if (S == 0) return 0;
        return (static_cast<double>(this->a) * this->b * this->c) / (4.0 * S);
    }
};
