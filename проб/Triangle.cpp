#include "Triangle.h"
#include <iostream>
#include <thread> 
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    try {
        cout << "������� ����������� � ������ �����������:\n";
        double a, b, c;
        cout << "������� ������� ������������ (����� ������/entr): ";
        while (!(cin >> a >> b >> c)) {
            cout << "������ �����. ����������, ������� ��� ����� ����� ������: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        Triangle<double> tri(a, b, c);
        tri.show();
        cout << "��������: " << tri.perimetr() << endl;
        cout << "�������: " << tri.area() << endl;
        cout << "������ ��������� ����������: " << tri.in_circle() << endl;
        cout << "������ ��������� ����������: " << tri.out_circle() << endl;
        cout << "\n������ �������� �������? (1 - ��, 2 - ���, 3 - �����)" << endl;
        int choise;
        cin >> choise;
        switch (choise)
        {
        case 1:
            cout << "\n������� ������� ����� ����\n";
            tri.change_sides();
            cout << "\n�������� ��������� ������������:\n";
            tri.show();
            cout << "��������: " << tri.perimetr() << endl;
            cout << "�������: " << tri.area() << endl;
            cout << "������ ��������� ����������: " << tri.in_circle() << endl;
            cout << "������ ��������� ����������: " << tri.out_circle() << endl;
            break;

        case 2:
            cout << "\n�������� ��������� ������������:\n";
            tri.show();
            cout << "��������: " << tri.perimetr() << endl;
            cout << "�������: " << tri.area() << endl;
            cout << "������ ��������� ����������: " << tri.in_circle() << endl;
            cout << "������ ��������� ����������: " << tri.out_circle() << endl;
            break;

        default:
            cout << "����� �� ���������.";
            exit(3);
        }
    }
    catch (const exception& a) {
        cerr << "������: " << a.what() << endl;
    }
    return 0;
}