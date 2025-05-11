#pragma once

template <class T>
class Right_Tr : public Triangle<T> {
public:
    Right_Tr() = default;

    // Конструктор с двумя катетами, гипотенуза вычисляется автоматически
    Right_Tr(T leg1, T leg2) : Triangle<T>(leg1, leg2, static_cast<T>(sqrt(leg1* leg1 + leg2 * leg2))) {
        if (!isRightTriangle()) {
            throw invalid_argument("Invalid sides for right triangle");
        }
    }

    // Проверка прямоугольности по теореме Пифагора
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

    // Меню для изменения сторон
    void change_sides() {
        int choice;
        T newLeg1, newLeg2;
        while (true) {
            cout << "\nMenu:\n"
                << "1. Change legs (a and b)\n"
                << "2. Change all sides (a, b, c)\n"
                << "3. Exit\n"
                << "Your choice: ";
            cin >> choice;

            if (choice == 3) break;

            try {
                switch (choice) {
                case 1:
                    cout << "Enter new values for legs (a and b): ";
                    cin >> newLeg1 >> newLeg2;
                    if (newLeg1 <= 0 || newLeg2 <= 0)
                        throw invalid_argument("Sides must be positive");
                    this->a = newLeg1;
                    this->b = newLeg2;
                    this->c = static_cast<T>(sqrt(newLeg1 * newLeg1 + newLeg2 * newLeg2));
                    if (!isRightTriangle())
                        throw invalid_argument("Sides do not form a right triangle");
                    break;
                case 2:
                    T newA, newB, newC;
                    cout << "Enter new sides (a b c): ";
                    cin >> newA >> newB >> newC;
                    if (newA <= 0 || newB <= 0 || newC <= 0)
                        throw invalid_argument("Sides must be positive");
                    this->a = newA;
                    this->b = newB;
                    this->c = newC;
                    if (!isRightTriangle())
                        throw invalid_argument("Sides do not form a right triangle");
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

    // Периметр
    T perimetr() const {
        if (!isRightTriangle())
            throw invalid_argument("Not a right triangle");
        return this->a + this->b + this->c;
    }

    // Площадь
    double area() const {
        if (!isRightTriangle())
            throw invalid_argument("Not a right triangle");
        return 0.5 * this->a * this->b;
    }

    // Радиус вписанной окружности
    double in_circle() const {
        if (!isRightTriangle())
            throw invalid_argument("Not a right triangle");
        return (this->a + this->b - this->c) / 2.0;
    }

    // Радиус описанной окружности
    double out_circle() const {
        if (!isRightTriangle())
            throw invalid_argument("Not a right triangle");
        return this->c / 2.0;
    }
};
