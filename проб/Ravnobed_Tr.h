#pragma once  //Annya
template <class T>
class Ravnobed_Tr : public Triangle<T> {
public:
    //������������� ������� ��� ��������� ������
    Ravnobed_Tr() = default;
    Ravnobed_Tr(T sideA, T sideB) : Triangle<T>(sideA, sideB, sideA) {
        if (!isIsosceles()) {
            throw invalid_argument("�������� ������� ��� ��������������� ������������");
        }
    }

    bool isIsosceles() const {
        return (this->a == this->b) || (this->b == this->c) || (this->a == this->c);
    }

    void change_sides() {
        int choice;
        T newSide, newSide1, newSide2;
        while (true) {
            cout << "\n����:\n"
                << "1. �������� ������ ������� (a � c)\n"
                << "2. �������� ������� b\n"
                << "3. �������� ��� �������\n"
                << "4. ����� �� ���������\n"
                << "�������� �����: ";
            cin >> choice;

            if (choice == 4) break;

            try {
                switch (choice) {
                case 1:
                    cout << "������� ����� �������� ��� ������ ������ (a � c): ";
                    cin >> newSide;
                    this->set_a(newSide);
                    this->set_c(newSide);
                    if (!isIsosceles()) throw invalid_argument("����������� �������� ���� ��������������");
                    break;
                case 2:
                    cout << "������� ����� �������� ��� ������� b: ";
                    cin >> newSide;
                    this->set_b(newSide);
                    if (!isIsosceles()) throw invalid_argument("����������� �������� ���� ��������������");
                    break;
                case 3:
                    cout << "������� ����� �������� (a b c): ";
                    cin >> newSide1 >> newSide2 >> newSide;
                    this->set_a(newSide1);
                    this->set_b(newSide2);
                    this->set_c(newSide);
                    if (!isIsosceles()) throw invalid_argument("����������� �������� ���� ��������������");
                    break;
                default:
                    cout << "������������ ����� ����\n";
                    continue;
                }
                cout << "\n������� �������� ������: \n";
                this->show();
            }
            catch (const invalid_argument& e) {
                cout << "������: " << e.what() << endl;
            }
        }
    }

    T perimetr() const {
        if (!isIsosceles()) throw invalid_argument("����������� �������� ���� ��������������");
        return this->a + this->b + this->c;
    }

    double area() const {
        if (!isIsosceles()) throw invalid_argument("����������� �������� ���� ��������������");
        double p = static_cast<double>(perimetr()) / 2.0;
        double val = p * (p - this->a) * (p - this->b) * (p - this->c);
        if (val <= 0) return 0;
        return sqrt(val);
    }

    double in_circle() const {
        if (!isIsosceles()) throw invalid_argument("����������� �������� ���� ��������������");
        double S = area();
        if (S == 0) return 0;
        return 2.0 * S / static_cast<double>(perimetr());
    }

    double out_circle() const {
        if (!isIsosceles()) throw invalid_argument("����������� �������� ���� ��������������");
        double S = area();
        if (S == 0) return 0;
        return (static_cast<double>(this->a) * this->b * this->c) / (4.0 * S);
    }
};