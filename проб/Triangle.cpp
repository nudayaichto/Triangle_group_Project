#include "Triangle.h" // Olya
#include "Ravnostor_Tr.h" //Kira
#include "Ravnobed_Tr.h" // Annya
#include "Right_Tr.h" // Yliana
#include <iostream>
#include <thread>
using namespace std;

int Get_number()
{
    int num;
    while (!(cin >> num))
    {
        cout << "Error: Please enter a valid number!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore();
    return num;
}

int main()
{
    setlocale(LC_ALL, "en_US.UTF-8");
    int choice;
    while (true)
    {
        cout << "------- MENU -------" << endl;
        cout << "1. Simple Triangle" << endl;
        cout << "2. Equilateral Triangle" << endl;
        cout << "3. Isosceles Triangle" << endl;
        cout << "4. Right Triangle" << endl;
        cout << "5. Exit" << endl;
        cout << "Your choice: ";
        choice = Get_number();
        switch (choice)
        {
        case 1:

            system("cls");
            cout << "Simple Triangle: " << endl;
            try
            {
                cout << "Creating a triangle with your parameters:\n";
                cout << "Enter the sides of the triangle (separated by spaces): ";
                double a, b, c;
                while (true)
                {
                    if (cin >> a >> b >> c) {
                        if (a > 0 && b > 0 && c > 0) {
                            break;
                        }
                        else {
                            cout << "Sides must be positive. Try again: ";
                        }
                    }
                    else {
                        cout << "Incorrect input. Input three digits: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
                cout << "\nThe first three digits are accepted.\n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                Triangle<double> tri(a, b, c);
                tri.show();
                cout << "Perimeter: " << tri.perimetr() << endl;
                cout << "Area: " << tri.area() << endl;
                cout << "Inscribed circle radius: " << tri.in_circle() << endl;
                cout << "Circumscribed circle radius: " << tri.out_circle() << endl;
                cout << "\nDo you want to change a side? (1 - yes, 2 - no, 3 - exit)" << endl;
                int choise = Get_number();
                switch (choise)
                {
                case 1:
                    system("cls");
                    cout << "\nSwitching sides through the menu\n";
                    tri.change_sides();
                    cout << "\nFinal state of the triangle:\n";
                    tri.show();
                    cout << "Perimeter: " << tri.perimetr() << endl;
                    cout << "Area: " << tri.area() << endl;
                    cout << "Inscribed circle radius: " << tri.in_circle() << endl;
                    cout << "Circumscribed circle radius: " << tri.out_circle() << endl;
                    cout << endl;
                    break;
                case 2:
                    system("cls");
                    cout << "\nFinal state of the triangle:\n";
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
                    cout << "Invalid number.";
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
            cout << "Equilateral Triangle: " << endl;
            try {
                cout << "Creating a triangle with your parameters.\n";
                double side;
                cout << "Enter side length: ";
                while (!(cin >> side) || side <= 0) {
                    cout << "Invalid input. Please enter positive number: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                //Ravnostor_Tr<double> tri(side);

                Ravnostor_Tr<double> tri;
                tri.set_side(side);
                tri.show();
                cout << "Perimeter: " << tri.perimetr(side) << endl;
                cout << "Area: " << tri.area(side) << endl;
                cout << "Inscribed circle radius: " << tri.in_circle(side) << endl;
                cout << "Circumscribed circle radius: " << tri.out_circle(side) << endl;

                cout << "\nChange side? (1 - yes, 2 - no, 3 - exit): ";
                int choice = Get_number();
                switch (choice) {
                case 1: {
                    tri.change_sides(side);
                    cout << "\nUpdated triangle:\n";
                    tri.show();
                    cout << "Perimeter: " << tri.perimetr(side) << endl;
                    cout << "Area: " << tri.area(side) << endl;
                    cout << "Inscribed circle radius: " << tri.in_circle(side) << endl;
                    cout << "Circumscribed circle radius: " << tri.out_circle(side) << endl;
                    break;
                }
                case 2:
                    break;
                case 3:
                    cout << "Exiting program.\n";
                    exit(0);
                default:
                    cout << "Invalid choice.\n";
                }
            }
            catch (const exception& e) {
                cerr << "Error: " << e.what() << endl;
            }
            break;
        case 3:
            system("cls");
            cout << "Isosceles Triangle: " << endl;
            try {
                cout << "Creating a triangle with your parameters.\n";

                double a, b;
                cout << "Enter 2 sides of the triangle (space/enter separated): ";
                while (!(cin >> a >> b) || a <= 0 || b <= 0)
                {
                    cout << "Input error. Please enter two positive numbers: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cout << "\nFirst two entered sides accepted.\n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                Ravnobed_Tr<double> tri(a, b);
                tri.show();
                cout << "Perimeter: " << tri.perimetr() << endl;
                cout << "Area: " << tri.area() << endl;
                cout << "Inscribed circle radius: " << tri.in_circle() << endl;
                cout << "Circumscribed circle radius: " << tri.out_circle() << endl;
                cout << "\nDo you want to change a side? (1 - yes, 2 - no, 3 - exit):" << endl;
                int choice = Get_number();
                switch (choice)
                {
                case 1:
                    system("cls");
                    tri.change_sides(1, 1);
                    cout << "\nFinal state of the triangle\n";
                    tri.show();
                    cout << "Perimeter: " << tri.perimetr() << endl;
                    cout << "Area: " << tri.area() << endl;
                    cout << "Inscribed circle radius: " << tri.in_circle() << endl;
                    cout << "Circumscribed circle radius: " << tri.out_circle() << endl;
                    break;

                case 2:
                    system("cls");
                    cout << "\nFinal state of the triangle:\n";
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

        case 4:
            system("cls");
            cout << "Right triangle: " << endl;
            try {
                cout << "Creating a triangle with your parameters.\n";
                cout << "Enter 2 sides of the triangle (space/enter separated): ";

                double leg1, leg2;
                while (!(cin >> leg1 >> leg2) || leg1 <= 0 || leg2 <= 0) {
                    cout << "Input error. Please enter two positive numbers: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cout << "\nFirst two entered sides accepted.\n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                Right_Tr<double> tri(leg1, leg2);
                tri.show();
                cout << "Perimeter: " << tri.perimetr(1) << endl;
                cout << "Area: " << tri.area(1) << endl;
                cout << "Inscribed circle radius: " << tri.in_circle(1) << endl;
                cout << "Circumscribed circle radius: " << tri.out_circle(1) << endl;
                cout << "\nDo you want to change a side? (1 - yes, 2 - no, 3 - exit):" << endl;
                int choice = Get_number();
                switch (choice)
                {
                case 1:
                    system("cls");
                    tri.change_sides(1, 1);
                    cout << "\nFinal state of the triangle\n";
                    tri.show();
                    cout << "Perimeter: " << tri.perimetr(1) << endl;
                    cout << "Area: " << tri.area(1) << endl;
                    cout << "Inscribed circle radius: " << tri.in_circle(1) << endl;
                    cout << "Circumscribed circle radius: " << tri.out_circle(1) << endl;
                    break;

                case 2:
                    system("cls");
                    cout << "\nFinal state of the triangle:\n";
                    tri.show();
                    cout << "Perimeter: " << tri.perimetr(1) << endl;
                    cout << "Area: " << tri.area(1) << endl;
                    cout << "Inscribed circle radius: " << tri.in_circle(1) << endl;
                    cout << "Circumscribed circle radius: " << tri.out_circle(1) << endl;
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

        case 5:
            cout << "Exiting program.\n";
            exit(5);
        default:
            system("cls");
            cout << "Incorrect number.\n";
            break;
        }
    }

    return 0;
