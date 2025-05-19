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
        cout << "Ошибка: Вводимая цифра!\n";
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
            cout << "Некорректный ввод. Пожалуйста, введите число: ";
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
        cout << "------- МЕНЮ-------" << endl;
        cout << "1. Простой треугольник" << endl;
        cout << "2. Равносторонний треугольник" << endl;
        cout << "3. Равнобедренный треугольник" << endl;
        cout << "4. Прямой треугольник" << endl;
        cout << "5. Выход" << endl;
        cout << "Ваш выбор: ";
        choice = Get_number();
        switch (choice)
        {
        case 1:
            system("cls");
            cout << "Простой треугольник: " << endl;
            try
            {               
                cout << "Создаем треугольник с вашими параметрами:\n";
                cout << "Введите стороны треугольника (через пробел): ";
                double a = Get_double();
                double b = Get_double();
                double c = Get_double();
            
                Triangle<double> tri(a, b, c);
                tri.show();
                cout << "Периметр: " << tri.perimetr() << endl;
                cout << "Площадь: " << tri.area() << endl;
                cout << "Радиус вписанной окружности: " << tri.in_circle() << endl;
                cout << "Описанный радиус окружности: " << tri.out_circle() << endl;
                cout << "\nВы хотите изменить сторону? ((1 - да, 2 - нет, 3 - выход)" << endl;
                int choise = Get_number();
                switch (choise)
                {
                case 1:
                    system("cls");
                    cout << "\nПереключение сторон через меню\n";
                    tri.change_sides();
                    cout << "\nКонечное состояние треугольника:\n";
                    tri.show();
                    cout << "Периметр: " << tri.perimetr() << endl;
                    cout << "Площадь: " << tri.area() << endl;
                    cout << "Радиус вписанной окружности: " << tri.in_circle() << endl;
                    cout << "Описанный радиус окружности: " << tri.out_circle() << endl;
                    cout << endl;
                    break;

                case 2:
                    system("cls");
                    cout << "\nКонечное состояние треугольника:\n";
                    tri.show();
                    cout << "Периметр: " << tri.perimetr() << endl;
                    cout << "Площадь: " << tri.area() << endl;
                    cout << "Радиус вписанной окружности: " << tri.in_circle() << endl;
                    cout << "Описанный радиус окружности: " << tri.out_circle() << endl;
                    cout << endl;
                    break;
                case 3:
                    system("cls");
                    cout << "Существующая программа.";
                    exit(3);

                default:
                    system("cls");
                    cout << "Неверный номер.";
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
            cout << "Равносторонний треугольник: " << endl;
            try {
                cout << "Создание треугольника с вашими параметрами.\n";

                double side;
                cout << "Введите значение стороны треугольника: ";
                while (!(cin >> side) || side <= 0) {
                    cout << "Некорректный ввод. Пожалуйста, введите число:";
                    cin.clear();
                }
                cout << "\nПервое введенное число принято. \n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                Ravnostor_Tr<double> tri(side);
                tri.show();
                cout << "Периметр: " << tri.perimetr() << endl;
                cout << "Площадь: " << tri.area() << endl;
                cout << "Радиус вписанной окружности: " << tri.in_circle() << endl;
                cout << "Описанный радиус окружности: " << tri.out_circle() << endl;

                cout << "\nВы хотите изменить сторону? ((1 - да, 2 - нет, 3 - выход): ";
                int choice = Get_number();
                if (choice == 1) {
                    tri.change_sides();
                    cout << "\nКонечное состояние треугольника:\n";
                    tri.show();
                    cout << "Периметр: " << tri.perimetr() << endl;
                    cout << "Площадь: " << tri.area() << endl;
                    cout << "Радиус вписанной окружности: " << tri.in_circle() << endl;
                    cout << "Описанный радиус окружности: " << tri.out_circle() << endl;
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
            cout << "Равнобедренный треугольник: " << endl;
            try {
                cout << "Создание треугольника с вашими параметрами.\n";
              
                double a, b;
                cout << "Введите 2 стороны треугольника (space/enter separated): ";
                while (!(cin >> a >> b)) 
                {
                    cout << "Ошибка ввода. Пожалуйста, введите две стороны: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cout << "\nДве первые введенные стороны приняты. \n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                Ravnobed_Tr<double> tri(a, b);
                tri.show();
                cout << "Периметр: " << tri.perimetr() << endl;
                cout << "Площадь: " << tri.area() << endl;
                cout << "Радиус вписанной окружности: " << tri.in_circle() << endl;
                cout << "Описанный радиус окружности: " << tri.out_circle() << endl;
                cout << "\nВы хотите изменить сторону? ((1 - да, 2 - нет, 3 - выход):" << endl;
                int choice = Get_number();
                switch (choice)
                {
                case 1:
                    system("cls");
                    //cout << "\nChanging sides through menu\n";
                    tri.change_sides();
                    cout << "\nКонечное состояние треугольника\n";
                    tri.show();
                    cout << "Периметр: " << tri.perimetr() << endl;
                    cout << "Площадь: " << tri.area() << endl;
                    cout << "Радиус вписанной окружности: " << tri.in_circle() << endl;
                    cout << "Описанный радиус окружности: " << tri.out_circle() << endl;
                    break;

                case 2:
                    system("cls");
                    cout << "\nКонечное состояние треугольника:\n";
                    tri.show();
                    cout << "Периметр: " << tri.perimetr() << endl;
                    cout << "Площадь: " << tri.area() << endl;
                    cout << "Радиус вписанной окружности: " << tri.in_circle() << endl;
                    cout << "Описанный радиус окружности: " << tri.out_circle() << endl;
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
            cout << "Прямоугольный треугольник: " << endl;
            try {
                cout << "Создаем треугольник с вашими параметрами.\n";
                cout << "введите два катета (space/enter separated): ";

                double leg1, leg2;
                while (!(cin >> leg1 >> leg2) || leg1 <= 0 || leg2 <= 0) {
                    cout << "Input error. Please enter two positive numbers: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cout << "\nПервые два числа приняты. \n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                Right_Tr<double> tri(leg1, leg2);
                tri.show();
                cout << "Периметр: " << tri.perimetr() << endl;
                cout << "Площадь: " << tri.area() << endl;
                cout << "Радиус вписанной окружности: " << tri.in_circle() << endl;
                cout << "Описанный радиус окружности: " << tri.out_circle() << endl;
                cout << "\nВы хотите изменить сторону? ((1 - да, 2 - нет, 3 - выход):" << endl;
                int choise = Get_number();
                switch (choise)
                {
                case 1:
                    system("cls");
                    //cout << "\nChanging sides through menu\n";
                    tri.change_sides();
                    cout << "\nКонечное состояние треугольника:\n";
                    tri.show();
                    cout << "Периметр: " << tri.perimetr() << endl;
                    cout << "Площадь: " << tri.area() << endl;
                    cout << "Радиус вписанной окружности: " << tri.in_circle() << endl;
                    cout << "Описанный радиус окружности: " << tri.out_circle() << endl;
                    cout << endl;
                    break;

                case 2:
                    system("cls");
                    cout << "\nКонечное состояние треугольника:\n";
                    tri.show();
                    cout << "Периметр: " << tri.perimetr() << endl;
                    cout << "Площадь: " << tri.area() << endl;
                    cout << "Радиус вписанной окружности: " << tri.in_circle() << endl;
                    cout << "Описанный радиус окружности: " << tri.out_circle() << endl;
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
