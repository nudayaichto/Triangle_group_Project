#include "Triangle.h" // Olya
#include "Ravnostor_Tr.h" //Kira
#include "Ravnobed_Tr.h" //Annya
#include "Right_Tr.h" //Yliana
#include <iostream>
#include <thread> 
using namespace std;

int Get_number()
{
    int num;
    while(!(cin>>num))
    {
        cout << "������: �������� �����!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore();
    return num;
}
double Get_double() {
    double input;
    while (true) {
        cin >> input;
        if (cin.fail()) {
            system("cls");
            cout << "������������ ����. ����������, ������� �����: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            return input;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    int choice;
    while (true)
    {
        cout << "------- ����-------" << endl;
        cout << "1. ������� �����������" << endl;
        cout << "2. �������������� �����������" << endl;
        cout << "3. �������������� �����������" << endl;
        cout << "4. ������ �����������" << endl;
        cout << "5. �����" << endl;
        cout << "��� �����: ";
        choice = Get_number();
        switch (choice)
        {
        case 1:
            system("cls");
            cout << "������� �����������: " << endl;
            try
            {               
                cout << "������� ����������� � ������ �����������:\n";
                cout << "������� ������� ������������ (����� ������): ";
                double a = Get_double();
                double b = Get_double();
                double c = Get_double();
            
                Triangle<double> tri(a, b, c);
                tri.show();
                cout << "��������: " << tri.perimetr() << endl;
                cout << "�������: " << tri.area() << endl;
                cout << "������ ��������� ����������: " << tri.in_circle() << endl;
                cout << "��������� ������ ����������: " << tri.out_circle() << endl;
                cout << "\n�� ������ �������� �������? ((1 - ��, 2 - ���, 3 - �����)" << endl;
                int choise = Get_number();
                switch (choise)
                {
                case 1:
                    system("cls");
                    cout << "\n������������ ������ ����� ����\n";
                    tri.change_sides();
                    cout << "\n�������� ��������� ������������:\n";
                    tri.show();
                    cout << "��������: " << tri.perimetr() << endl;
                    cout << "�������: " << tri.area() << endl;
                    cout << "������ ��������� ����������: " << tri.in_circle() << endl;
                    cout << "��������� ������ ����������: " << tri.out_circle() << endl;
                    cout << endl;
                    break;

                case 2:
                    system("cls");
                    cout << "\n�������� ��������� ������������:\n";
                    tri.show();
                    cout << "��������: " << tri.perimetr() << endl;
                    cout << "�������: " << tri.area() << endl;
                    cout << "������ ��������� ����������: " << tri.in_circle() << endl;
                    cout << "��������� ������ ����������: " << tri.out_circle() << endl;
                    cout << endl;
                    break;
                case 3:
                    system("cls");
                    cout << "������������ ���������.";
                    exit(3);

                default:
                    system("cls");
                    cout << "�������� �����.";
                    cout << endl;
                    break;
                }
            }
            catch (const exception& a)
            {
                cerr << "Error: " << a.what() << endl;
            }
            break;
        case 2:
            system("cls");
            cout << "Ravnostr triangle: " << endl;
            try {
                cout << "Creating equilateral triangle.\n";

                double side;
                cout << "Enter triangle side length: ";
                while (!(cin >> side) || side <= 0) {
                    cout << "Input error. Please enter a positive number: ";
                    cin.clear();
                }
                cout << "\nThe first digit is accepted. \n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                Ravnostor_Tr<double> tri(side);
                tri.show();
                cout << "Perimeter: " << tri.perimetr() << endl;
                cout << "Area: " << tri.area() << endl;
                cout << "Inscribed circle radius: " << tri.in_circle() << endl;
                cout << "Circumscribed circle radius: " << tri.out_circle() << endl;

                cout << "\nDo you want to change the side? (1 - yes, 2 - no(to menu), 3 - exiting programm): ";
                int choice = Get_number();
                if (choice == 1) {
                    tri.change_sides();
                    cout << "\nFinal triangle state:\n";
                    tri.show();
                    cout << "Perimeter: " << tri.perimetr() << endl;
                    cout << "Area: " << tri.area() << endl;
                    cout << "Inscribed circle radius: " << tri.in_circle() << endl;
                    cout << "Circumscribed circle radius: " << tri.out_circle() << endl;
                    cout << endl;
                }
                else if(choice == 3) {
                    cout << "Exiting program.\n";
                    exit(3);
                }
            }
            catch (const exception& e) {
                cerr << "Error: " << e.what() << endl;
            }
            break;
        case 3:
            system("cls");
            cout << "Ravnobed triangle: " << endl;
            try {
                cout << "Creating triangle with your parameters:\n";
              
                double a, b;
                cout << "Enter 2 triangle sides (space/enter separated): ";
                while (!(cin >> a >> b)) 
                {
                    cout << "Input error. Please enter two numbers separated by spaces: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cout << "\nThe first two digits are accepted. \n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                Ravnobed_Tr<double> tri(a, b);
                tri.show();
                cout << "Perimeter: " << tri.perimetr() << endl;
                cout << "Area: " << tri.area() << endl;
                cout << "Inscribed circle radius: " << tri.in_circle() << endl;
                cout << "Circumscribed circle radius: " << tri.out_circle() << endl;
                cout << "\nDo you want to change sides? (1 - yes, 2 - no(to menu), 3 - exiting programm)" << endl;
                int choice = Get_number();
                switch (choice)
                {
                case 1:
                    system("cls");
                    cout << "\nChanging sides through menu\n";
                    tri.change_sides();
                    cout << "\nFinal triangle state:\n";
                    tri.show();
                    cout << "Perimeter: " << tri.perimetr() << endl;
                    cout << "Area: " << tri.area() << endl;
                    cout << "Inscribed circle radius: " << tri.in_circle() << endl;
                    cout << "Circumscribed circle radius: " << tri.out_circle() << endl;
                    break;

                case 2:
                    system("cls");
                    cout << "\nFinal triangle state:\n";
                    tri.show();
                    cout << "Perimeter: " << tri.perimetr() << endl;
                    cout << "Area: " << tri.area() << endl;
                    cout << "Inscribed circle radius: " << tri.in_circle() << endl;
                    cout << "Circumscribed circle radius: " << tri.out_circle() << endl;
                    break;
                case 3:
                    system("cls");
                    cout << "Exiting program.";
                    exit(3);

                default:
                    cout << "Incorrect number.";
                    break;
                }
            }
            catch (const exception& a) {
                cerr << "Error: " << a.what() << endl;
            }
            break;
        case 4:
            system("cls");
            cout << "Pryam triangle: " << endl;
            try {
                cout << "Creating right triangle.\n";
                cout << "Enter two legs (space/enter separated): ";

                double leg1, leg2;
                while (!(cin >> leg1 >> leg2) || leg1 <= 0 || leg2 <= 0) {
                    cout << "Input error. Please enter two positive numbers: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cout << "\nThe first two digits are accepted. \n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                Right_Tr<double> tri(leg1, leg2);
                tri.show();
                cout << "Perimeter: " << tri.perimetr() << endl;
                cout << "Area: " << tri.area() << endl;
                cout << "Inscribed circle radius: " << tri.in_circle() << endl;
                cout << "Circumscribed circle radius: " << tri.out_circle() << endl;
                cout << "\nDo you want to change sides? (1 - yes, 2 - no, 3 - exit)" << endl;
                int choise = Get_number();
                switch (choise)
                {
                case 1:
                    system("cls");
                    cout << "\nChanging sides through menu\n";
                    tri.change_sides();
                    cout << "\nFinal triangle state:\n";
                    tri.show();
                    cout << "Perimeter: " << tri.perimetr() << endl;
                    cout << "Area: " << tri.area() << endl;
                    cout << "Inscribed circle radius: " << tri.in_circle() << endl;
                    cout << "Circumscribed circle radius: " << tri.out_circle() << endl;
                    cout << endl;
                    break;

                case 2:
                    system("cls");
                    cout << "\nFinal triangle state:\n";
                    tri.show();
                    cout << "Perimeter: " << tri.perimetr() << endl;
                    cout << "Area: " << tri.area() << endl;
                    cout << "Inscribed circle radius: " << tri.in_circle() << endl;
                    cout << "Circumscribed circle radius: " << tri.out_circle() << endl;
                    cout << endl;
                    break;
                case 3:
                    system("cls");
                    cout << "Exiting program.";
                    exit(3);

                default:
                    system("cls");
                    cout << "Incorrect number." << endl;
                    break;
                }
            }
            catch (const exception& e) {
               cerr << "Error: " << e.what() << endl;
           }
           break;
        case 5 :
            cout << "Exiting program. \n  ";
            exit(5);
        default:
            system("cls");
            cout << "Incorrect number. \n  ";
            break;
        }
    }
    
    return 0;
}
