#include "Triangle.h" // Olya
#include "Ravnostor_Tr.h" //Kira
#include "Ravnobed_Tr.h" //Annya
#include "Right_Tr.h" //Yliana
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
            system("cls");
            cout << "Simple triangle: " << endl;
            try
            {
                cout << "Creating triangle with your parameters:\n";
                double a, b, c;
                cout << "Enter triangle sides (space/enter separated): ";
                while (!(cin >> a >> b >> c))
                {
                    cout << "Input error. Please enter three numbers separated by spaces: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                Triangle<double> tri(a, b, c);
                tri.show();
                cout << "Perimeter: " << tri.perimetr() << endl;
                cout << "Area: " << tri.area() << endl;
                cout << "Inscribed circle radius: " << tri.in_circle() << endl;
                cout << "Circumscribed circle radius: " << tri.out_circle() << endl;
                cout << "\nDo you want to change sides? (1 - yes, 2 - no, 3 - exit)" << endl;
                int choise;
                cin >> choise;
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

                default:
                    system("cls");
                    cout << "Exiting program.";
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

                Ravnostor_Tr<double> tri(side);
                tri.show();
                cout << "Perimeter: " << tri.perimetr() << endl;
                cout << "Area: " << tri.area() << endl;
                cout << "Inscribed circle radius: " << tri.in_circle() << endl;
                cout << "Circumscribed circle radius: " << tri.out_circle() << endl;

                cout << "\nDo you want to change the side? (1 - yes, 2 - no): ";
                int choice;
                cin >> choice;
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
                else {
                    cout << "Exiting program.\n";
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

                Ravnobed_Tr<double> tri(a, b);
                tri.show();
                cout << "Perimeter: " << tri.perimetr() << endl;
                cout << "Area: " << tri.area() << endl;
                cout << "Inscribed circle radius: " << tri.in_circle() << endl;
                cout << "Circumscribed circle radius: " << tri.out_circle() << endl;
                cout << "\nDo you want to change sides? (1 - yes, 2 - no, 3 - exit)" << endl;
                int choise;
                cin >> choise;
                switch (choise)
                {
                case 1:
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
                    cout << "\nFinal triangle state:\n";
                    tri.show();
                    cout << "Perimeter: " << tri.perimetr() << endl;
                    cout << "Area: " << tri.area() << endl;
                    cout << "Inscribed circle radius: " << tri.in_circle() << endl;
                    cout << "Circumscribed circle radius: " << tri.out_circle() << endl;
                    break;

                default:
                    cout << "Exiting program.";
                    exit(3);
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
                double leg1, leg2;
                cout << "Enter two legs (space/enter separated): ";
                while (!(cin >> leg1 >> leg2) || leg1 <= 0 || leg2 <= 0) {
                    cout << "Input error. Please enter two positive numbers: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                Right_Tr<double> tri(leg1, leg2);
                tri.show();
                cout << "Perimeter: " << tri.perimetr() << endl;
                cout << "Area: " << tri.area() << endl;
                cout << "Inscribed circle radius: " << tri.in_circle() << endl;
                cout << "Circumscribed circle radius: " << tri.out_circle() << endl;

                cout << "\nDo you want to change sides? (1 - yes, 2 - no, 3 - exit)" << endl;
                int choise;
                cin >> choise;
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

                default:
                    system("cls");
                    cout << "Exiting program." << endl;
                    exit(4);
                }
            }
            catch (const exception& e) {
               cerr << "Error: " << e.what() << endl;
           }
           break;

        default:
            system("cls");
            cout << "Exiting program.";
            exit(5);
        }
    }
    
    return 0;
}
