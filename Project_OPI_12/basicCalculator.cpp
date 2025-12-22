#include "function.h"

void basicCalculator ( )
{
    double x, y;
    char op;

    cout << "Введите выражение: число, операцию (+ - * /), число\n";
    cout << "Например: 5 + 3\n>> ";

    // Пытаемся прочитать первое число
    if ( !(cin >> x) ) {
        cout << "Ошибка: первое значение должно быть числом!\n";
        cin.clear ( ); // сброс ошибки
        cin.ignore ( 1000, '\n' ); // удаляем мусор (до 1000 символов или до Enter)
        return;
    }

    // Читаем операцию
    if ( !(cin >> op) ) {
        cout << "Ошибка: не удалось прочитать операцию!\n";
        cin.clear ( );
        cin.ignore ( 1000, '\n' );
        return;
    }

    // Читаем второе число
    if ( !(cin >> y) ) {
        cout << "Ошибка: второе значение должно быть числом!\n";
        cin.clear ( );
        cin.ignore ( 1000, '\n' );
        return;
    }

    // Проверяем, что операция правильная
    if ( op != '+' && op != '-' && op != '*' && op != '/' ) {
        cout << "Ошибка: можно использовать только +, -, * или /.\n";
        return;
    }

    // Проверка деления на ноль
    if ( op == '/' && y == 0 ) {
        cout << "Ошибка: делить на ноль нельзя!\n";
        return;
    }

    // Считаем результат
    double result;
    if ( op == '+' ) result = x + y;
    else if ( op == '-' ) result = x - y;
    else if ( op == '*' ) result = x * y;
    else if ( op == '/' ) result = x / y;

    cout << "Результат = " << result << endl;
}