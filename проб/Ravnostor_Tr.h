#pragma once //KIRA
template <class T>
class Ravnostor_Tr : public Triangle<T> {
public:
    Ravnostor_Tr() = default;

    Ravnostor_Tr(T side) : Triangle<T>(side, side, side) {
        if (side <= 0) {
            throw invalid_argument("Side must be positive");
        }
    }

    // Меню для изменения стороны равностороннего треугольника
    void change_sides() {
        int choice;
        T newSide;
        while (true) {
            cout << "\nMenu:\n"
                << "1. Change side (all sides will be equal)\n"
                << "2. Exit menu\n"
                << "Select option: ";
            cin >> choice;
            if (choice == 2) break;
            if (choice == 1) {
                cout << "Enter new side value: ";
                cin >> newSide;
                if (cin.fail() || newSide <= 0) {
                    cout << "Error: side must be a positive number.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                this->set_sides(newSide, newSide, newSide);
                cout << "Sides changed to " << newSide << endl;
                this->show();
            }
            else {
                cout << "Invalid choice.\n";
            }
        }
    }

    double area() const {
        T a = this->a;
        return (sqrt(3) / 4.0) * a * a;
    }

    double in_circle() const {
        T a = this->a;
        return a / (2.0 * sqrt(3));
    }

    double out_circle() const {
        T a = this->a;
        return a / sqrt(3);
    }

    T perimetr() const {
        return this->a * 3;
    }
};
