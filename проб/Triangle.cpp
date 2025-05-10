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
            system("cls"); // очистить экран
            //Simple triangle
            cout << "Simple triangle: " << endl;
            try
            {
                cout << "Создаем треугольник с вашими параметрами:\n";
                double a, b, c;
                cout << "Введите стороны треугольника (через пробел/entr): ";
                while (!(cin >> a >> b >> c))
                {
                    cout << "Ошибка ввода. Пожалуйста, введите три числа через пробел: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                Triangle<double> tri(a, b, c);
                tri.show();
                cout << "Периметр: " << tri.perimetr() << endl;
                cout << "Площадь: " << tri.area() << endl;
                cout << "Радиус вписанной окружности: " << tri.in_circle() << endl;
                cout << "Радиус описанной окружности: " << tri.out_circle() << endl;
                cout << "\nХотите изменить стороны? (1 - да, 2 - нет, 3 - выход)" << endl;
                int choise;
                cin >> choise;
                switch (choise)
                {
                case 1:
                    system("cls");
                    cout << "\nИзменим стороны через меню\n";
                    tri.change_sides();
                    cout << "\nИтоговое состояние треугольника:\n";
                    tri.show();
                    cout << "Периметр: " << tri.perimetr() << endl;
                    cout << "Площадь: " << tri.area() << endl;
                    cout << "Радиус вписанной окружности: " << tri.in_circle() << endl;
                    cout << "Радиус описанной окружности: " << tri.out_circle() << endl;
                    cout << endl;
                    break;

                case 2:
                    system("cls");
                    cout << "\nИтоговое состояние треугольника:\n";
                    tri.show();
                    cout << "Периметр: " << tri.perimetr() << endl;
                    cout << "Площадь: " << tri.area() << endl;
                    cout << "Радиус вписанной окружности: " << tri.in_circle() << endl;
                    cout << "Радиус описанной окружности: " << tri.out_circle() << endl;
                    cout << endl;
                    break;

                default:
                    system("cls");
                    cout << "Выход из программы.";
                    cout << endl;
                    break;
                }
            }
            catch (const exception& a)
            {
                cerr << "Ошибка: " << a.what() << endl;
            }
            break;
        case 2:
            system("cls");
            // Ravnostr triangle
            cout << "Ravnostr triangle: " << endl;
            try {
                cout << "Создаем равносторонний треугольник.\n";
                double side;
                cout << "Введите длину стороны треугольника: ";
                while (!(cin >> side) || side <= 0) {
                    cout << "Ошибка ввода. Введите положительное число: ";
                    cin.clear();
                    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                Ravnostor_Tr<double> tri(side);
                tri.show();
                cout << "Периметр: " << tri.perimetr() << endl;
                cout << "Площадь: " << tri.area() << endl;
                cout << "Радиус вписанной окружности: " << tri.in_circle() << endl;
                cout << "Радиус описанной окружности: " << tri.out_circle() << endl;

                cout << "\nХотите изменить сторону? (1 - да, 2 - нет): ";
                int choice;
                cin >> choice;
                if (choice == 1) {
                    tri.change_sides();
                    cout << "\nИтоговое состояние треугольника:\n";
                    tri.show();
                    cout << "Периметр: " << tri.perimetr() << endl;
                    cout << "Площадь: " << tri.area() << endl;
                    cout << "Радиус вписанной окружности: " << tri.in_circle() << endl;
                    cout << "Радиус описанной окружности: " << tri.out_circle() << endl;
                    cout << endl;
                }
                else {
                    cout << "Выход из программы.\n";
                }
            }
            catch (const exception& e) {
                cerr << "Ошибка: " << e.what() << endl;
            }
            break;
        case 3:
            system("cls");
            // Ravnobed triangle
            cout << "Ravnobed triangle: " << endl;
            try {
                cout << "Создаем треугольник с вашими параметрами:\n";
                double a, b;
                cout << "Введите 2 стороны треугольника (через пробел/entr): ";
                while (!(cin >> a >> b)) 
                {
                    cout << "Ошибка ввода. Пожалуйста, введите три числа через пробел: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                Ravnobed_Tr<double> tri(a, b);
                tri.show();
                cout << "Периметр: " << tri.perimetr() << endl;
                cout << "Площадь: " << tri.area() << endl;
                cout << "Радиус вписанной окружности: " << tri.in_circle() << endl;
                cout << "Радиус описанной окружности: " << tri.out_circle() << endl;
                cout << "\nХотите изменить стороны? (1 - да, 2 - нет, 3 - выход)" << endl;
                int choise;
                cin >> choise;
                switch (choise)
                {
                case 1:
                    cout << "\nИзменим стороны через меню\n";
                    tri.change_sides();
                    cout << "\nИтоговое состояние треугольника:\n";
                    tri.show();
                    cout << "Периметр: " << tri.perimetr() << endl;
                    cout << "Площадь: " << tri.area() << endl;
                    cout << "Радиус вписанной окружности: " << tri.in_circle() << endl;
                    cout << "Радиус описанной окружности: " << tri.out_circle() << endl;
                    break;

                case 2:
                    cout << "\nИтоговое состояние треугольника:\n";
                    tri.show();
                    cout << "Периметр: " << tri.perimetr() << endl;
                    cout << "Площадь: " << tri.area() << endl;
                    cout << "Радиус вписанной окружности: " << tri.in_circle() << endl;
                    cout << "Радиус описанной окружности: " << tri.out_circle() << endl;
                    break;

                default:
                    cout << "Выход из программы.";
                    exit(3);
                }
            }
            catch (const exception& a) {
                cerr << "Ошибка: " << a.what() << endl;
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
            cout << "Выход из программы.";
            exit(5);
        }
    }
    
    return 0;
}