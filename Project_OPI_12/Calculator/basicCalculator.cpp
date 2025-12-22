#include "function.h"
void basicCalculator ( )
{
    char op;
    double x, y;
    cout << "Введите первое число, операцию, второе число (x + y)\n>> ";
    cin >> x >> op >> y;

    double result = 0;
    switch ( op ) {
        case '+': result = x + y; break;
        case '-': result = x - y; break;
        case '*': result = x * y; break;
        case '/':
            if ( y == 0 ) {
                cout << "Ошибка: деление на ноль!\n";
                return;
            }
            result = x / y;
            break;
        default:
            cout << "Неподдерживаемая операция!\n";
            return;
    }
    cout << "Результат = " << result << endl;
}
