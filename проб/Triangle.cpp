#include "Triangle.h"
#include <iostream>
#include <thread> 
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    try {
        cout << "Создаем треугольник с вашими параметрами:\n";
        double a, b, c;
        cout << "Введите стороны треугольника (через пробел/entr): ";
        while (!(cin >> a >> b >> c)) {
            cout << "Ошибка ввода. Пожалуйста, введите три числа через пробел: ";
            cin.clear();
            //cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
            cout << "\nИтоговое состояние треугольника: \n";
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
    return 0;
}
