#include "function.h"
void asciiTable ( )
{
    char op;
    cout << "Десятичное число → символ\t'a'\nСимвол → десятичное число\t'b'\n>> ";
    cin >> op;

    if ( op == 'a' ) {
        unsigned int x;
        cout << "Введите число (0–255): ";
        cin >> x;
        if ( x > 255 ) {
            cout << "Ошибка: число вне диапазона ASCII (0–255).\n";
            return;
        }
        char ch = static_cast<char>(x);
        cout << "Dec: " << x << " | Символ: '" << ch << "'\n";
    }
    else if ( op == 'b' ) {
        char ch;
        cout << "Введите символ: ";
        cin >> ch;
        int dec = static_cast<int>(ch);
        if ( dec < 0 ) dec += 256;
        cout << "Символ: '" << ch << "' | Dec: " << dec << endl;
    }
    else {
        cout << "Неверный ввод!\n";
    }
}
