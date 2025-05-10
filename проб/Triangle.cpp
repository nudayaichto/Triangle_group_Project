#include "Triangle.h"
#include "Ravnostor_Tr.h" //Kira
#include "Ravnobed_Tr.h" //Annya
//#include ""
#include <iostream>
#include <thread> 
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    int choice;
    while (true)
    {
        cout << "-------MENU-------" << endl;
        cout << "1. Simple triangle" << endl;
        cout << "2. Ravnostr triangle" << endl;
        cout << "3. Ravnobed triangle" << endl;
        cout << "4. Pryam triangle" << endl;
        cout << "5. Exit" << endl;
        cout << "Your choice: "; 
        cin >> choice;
        switch (choice)
        {
        case 1:
            system("cls"); // �������� �����
            //Simple triangle
            cout << "Simple triangle: " << endl;
            try
            {
                cout << "������� ����������� � ������ �����������:\n";
                double a, b, c;
                cout << "������� ������� ������������ (����� ������/entr): ";
                while (!(cin >> a >> b >> c))
                {
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
                    system("cls");
                    cout << "\n������� ������� ����� ����\n";
                    tri.change_sides();
                    cout << "\n�������� ��������� ������������:\n";
                    tri.show();
                    cout << "��������: " << tri.perimetr() << endl;
                    cout << "�������: " << tri.area() << endl;
                    cout << "������ ��������� ����������: " << tri.in_circle() << endl;
                    cout << "������ ��������� ����������: " << tri.out_circle() << endl;
                    cout << endl;
                    break;

                case 2:
                    system("cls");
                    cout << "\n�������� ��������� ������������:\n";
                    tri.show();
                    cout << "��������: " << tri.perimetr() << endl;
                    cout << "�������: " << tri.area() << endl;
                    cout << "������ ��������� ����������: " << tri.in_circle() << endl;
                    cout << "������ ��������� ����������: " << tri.out_circle() << endl;
                    cout << endl;
                    break;

                default:
                    system("cls");
                    cout << "����� �� ���������.";
                    cout << endl;
                    break;
                }
            }
            catch (const exception& a)
            {
                cerr << "������: " << a.what() << endl;
            }
            break;
        case 2:
            system("cls");
            // Ravnostr triangle
            cout << "Ravnostr triangle: " << endl;
            try {
                cout << "������� �������������� �����������.\n";
                double side;
                cout << "������� ����� ������� ������������: ";
                while (!(cin >> side) || side <= 0) {
                    cout << "������ �����. ������� ������������� �����: ";
                    cin.clear();
                    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                Ravnostor_Tr<double> tri(side);
                tri.show();
                cout << "��������: " << tri.perimetr() << endl;
                cout << "�������: " << tri.area() << endl;
                cout << "������ ��������� ����������: " << tri.in_circle() << endl;
                cout << "������ ��������� ����������: " << tri.out_circle() << endl;

                cout << "\n������ �������� �������? (1 - ��, 2 - ���): ";
                int choice;
                cin >> choice;
                if (choice == 1) {
                    tri.change_sides();
                    cout << "\n�������� ��������� ������������:\n";
                    tri.show();
                    cout << "��������: " << tri.perimetr() << endl;
                    cout << "�������: " << tri.area() << endl;
                    cout << "������ ��������� ����������: " << tri.in_circle() << endl;
                    cout << "������ ��������� ����������: " << tri.out_circle() << endl;
                    cout << endl;
                }
                else {
                    cout << "����� �� ���������.\n";
                }
            }
            catch (const exception& e) {
                cerr << "������: " << e.what() << endl;
            }
            break;
        case 3:
            system("cls");
            // Ravnobed triangle
            cout << "Ravnobed triangle: " << endl;
            try {
                cout << "������� ����������� � ������ �����������:\n";
                double a, b;
                cout << "������� 2 ������� ������������ (����� ������/entr): ";
                while (!(cin >> a >> b)) 
                {
                    cout << "������ �����. ����������, ������� ��� ����� ����� ������: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                Ravnobed_Tr<double> tri(a, b);
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
            break;
        case 4:
            system("cls");
            //Pryam triangle
            cout << "Pryam triangle: " << endl;
            //
            //
            break;

        default:
            system("cls");
            cout << "����� �� ���������.";
            exit(5);
        }
    }
    
    return 0;
}