#pragma once
#include <iostream>
#include <cmath>
using namespace std;

template <class T>
class Triangle
{
    T a, b, c;
public:
    Triangle() : a(1), b(1), c(1)
    {
        if (!isValid())
            throw invalid_argument("Error");
        if (!isComman())
            throw invalid_argument("Error");
    }

    Triangle(T A, T B, T C) : a(A), b(B), c(C)
    {
        if (!isValid()) throw invalid_argument("Error");
        if (!isComman()) throw invalid_argument("Error");
    }

    ~Triangle() = default;

        bool isValid() const
    {
        return (a > 0 && b > 0 && c > 0) && (a + b > c) && (a + c > b) && (b + c > a);
    }

    bool isComman() const
    {
        T p = (a + b + c) / 2;
        double area = sqrt(p * (p - a) * (p - b) * (p - c));
        return area > 1e-10;
    }

    void set_a(T A)
    {
        a = A;
        if (!isValid())
            throw invalid_argument("�������� �������� a");
    }

    void set_b(T B)
    {
        b = B;
        if (!isValid())
            throw invalid_argument("�������� �������� b");
    }

    void set_c(T C)
    {
        c = C;
        if (!isValid())
            throw invalid_argument("�������� �������� c");
    }
    void set_sides(T A, T B, T C)
    {
        a = A;
        b = B;
        c = C;
        if (!isValid())
            throw invalid_argument("�������� �������� ���� ������");
    }

    T get_a() const { return a; }
    T get_b() const { return b; }
    T get_c() const { return c; }

    void show() const {
        cout << "�������� ������: a = " << a << ", b = " << b << ", c = " << c << endl;
    }

    void change_sides() {
        int choice;
        T newSide, newSide1, newSide2, newSide3;
        while (true) {
            cout << "\n����:\n"
                << "1. �������� ������� a\n"
                << "2. �������� ������� b\n"
                << "3. �������� ������� c\n"
                << "4. �������� ��� �������\n"
                << "5. ����� �� ���������\n"
                << "�������� �����: ";
            cin >> choice;

            if (choice == 5) break;

            try {
                switch (choice) {
                case 1:
                    cout << "������� ����� �������� �: ";
                    cin >> newSide;
                    set_a(newSide);
                    break;
                case 2:
                    cout << "������� ����� �������� b: ";
                    cin >> newSide;
                    set_b(newSide);
                    break;
                case 3:
                    cout << "������� ����� �������� c: ";
                    cin >> newSide;
                    set_c(newSide);
                    break;
                case 4:
                    cin.ignore();
                    cout << "������� ����� �������� (������/entr): ";
                    cin >> newSide1 >> newSide2 >> newSide3;
                    set_sides(newSide1, newSide2, newSide3);
                    break;
                default:
                    cout << "����� �� ���������\n";
                    continue;
                }
                cout << "\n������� ��������: \n";
                show();
            }
            catch (const invalid_argument& e) {
                cout << "Error: " << e.what() << std::endl;
            }
        }
    }

    T perimetr() const {
        return a + b + c;
    }

    double area() const {
        double p = static_cast<double>(perimetr()) / 2.0;
        double val = p * (p - a) * (p - b) * (p - c);
        if (val <= 0) return 0; 
        return sqrt(val);
    }
    double in_circle() {
        double S = area();
        if (S == 0) return 0;
        return 2.0 * S / static_cast<double>(perimetr());
    }

    double out_circle() {
        double S = area();
        if (S == 0) return 0;
        return (static_cast<double>(a) * b * c) / (4.0 * S);
    }
};