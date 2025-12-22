#include "function.h"

void digitalSystem ( )
{
    char mainChoice;
    cout << "Преобразование систем счисления\t'1'\n";
    cin >> mainChoice;

    if ( mainChoice != '1' ) {
        cout << "Неверный ввод!\n";
        return;
    }

    char sourceBase;
    cout << "Из двоичной\t'a'\n"
        << "Из десятичной\t'b'\n"
        << "Из восьмеричной\t'c'\n"
        << "Из шестнадцатеричной\t'd'\n>> ";
    cin >> sourceBase;

    // --- ИЗ ДВОИЧНОЙ ---
    if ( sourceBase == 'a' ) {
        char targetBase;
        cout << "В десятичную\t'a'\n"
            << "В восьмеричную\t'b'\n"
            << "В шестнадцатеричную\t'c'\n>> ";
        cin >> targetBase;

        if ( targetBase != 'a' && targetBase != 'b' && targetBase != 'c' ) {
            cout << "Неверный ввод\n";
            return;
        }

        int bin;
        cout << "Введите двоичное число\n>> ";
        cin >> bin;

        // Проверка на двоичность
        int temp = bin;
        while ( temp > 0 ) {
            int d = temp % 10;
            if ( d != 0 && d != 1 ) {
                cout << "Неверный ввод (только 0 и 1)\n\n";
                return;
            }
            temp /= 10;
        }

        // Перевод в десятичную
        int dec = 0, power = 1, num = bin;
        while ( num > 0 ) {
            dec += (num % 10) * power;
            power *= 2;
            num /= 10;
        }

        // Вывод с itoa_s
        char result[33]; // 32 бита + '\0'
        if ( targetBase == 'a' ) {
            cout << "результат = " << dec << endl;
        }
        else if ( targetBase == 'b' ) {
            _itoa_s ( dec, result, sizeof ( result ), 8 );
            cout << "результат = " << result << "\n";
        }
        else if ( targetBase == 'c' ) {
            _itoa_s ( dec, result, sizeof ( result ), 16 );
            cout << "результат = " << result << "\n"; // itoa_s даёт строчные буквы; если нужны заглавные — можно заменить
        }
    }

    // --- ИЗ ДЕСЯТИЧНОЙ ---
    else if ( sourceBase == 'b' ) {
        char targetBase;
        cout << "В двоичную\t'a'\n"
            << "В восьмеричную\t'b'\n"
            << "В шестнадцатеричную\t'c'\n>> ";
        cin >> targetBase;

        if ( targetBase != 'a' && targetBase != 'b' && targetBase != 'c' ) {
            cout << "Неверный ввод\n";
            return;
        }

        int dec;
        cout << "Введите десятичное число\n>> ";
        cin >> dec;

        if ( dec < 0 ) {
            cout << "Неверный ввод\n";
            return;
        }

        char result[33];
        if ( targetBase == 'a' ) {
            _itoa_s ( dec, result, sizeof ( result ), 2 );
            cout << "результат = " << result << "\n";
        }
        else if ( targetBase == 'b' ) {
            _itoa_s ( dec, result, sizeof ( result ), 8 );
            cout << "результат = " << result << "\n";
        }
        else if ( targetBase == 'c' ) {
            _itoa_s ( dec, result, sizeof ( result ), 16 );
            cout << "результат = " << result << "\n";
        }
    }

    // --- ИЗ ВОСЬМЕРИЧНОЙ ---
    else if ( sourceBase == 'c' ) {
        char targetBase;
        cout << "В двоичную\t'a'\n"
            << "В десятичную\t'b'\n"
            << "В шестнадцатеричную\t'c'\n>> ";
        cin >> targetBase;

        if ( targetBase != 'a' && targetBase != 'b' && targetBase != 'c' ) {
            cout << "Неверный ввод\n";
            return;
        }

        int oct;
        cout << "Введите восьмеричное число\n>> ";
        cin >> oct;

        // Проверка
        int temp = oct;
        while ( temp > 0 ) {
            int d = temp % 10;
            if ( d < 0 || d > 7 ) {
                cout << "Неверный ввод (цифры 0–7)\n";
                return;
            }
            temp /= 10;
        }

        // Восьмеричная ? десятичная
        int dec = 0, power = 1, num = oct;
        while ( num > 0 ) {
            dec += (num % 10) * power;
            power *= 8;
            num /= 10;
        }

        char result[33];
        if ( targetBase == 'a' ) {
            _itoa_s ( dec, result, sizeof ( result ), 2 );
            cout << "результат = " << result << "\n";
        }
        else if ( targetBase == 'b' ) {
            cout << "результат = " << dec << "\n";
        }
        else if ( targetBase == 'c' ) {
            _itoa_s ( dec, result, sizeof ( result ), 16 );
            cout << "результат = " << result << "\n";
        }
    }

    // --- ИЗ ШЕСТНАДЦАТЕРИЧНОЙ ---
    else if ( sourceBase == 'd' ) {
        char targetBase;
        cout << "В двоичную\t'a'\n"
            << "В восьмеричную\t'b'\n"
            << "В десятичную\t'c'\n>> ";
        cin >> targetBase;

        if ( targetBase != 'a' && targetBase != 'b' && targetBase != 'c' ) {
            cout << "Неверный ввод\n";
            return;
        }

        char hexInput[10];
        cout << "Введите шестнадцатеричное число (макс. длина 7)\n>> ";
        cin >> hexInput;

        // Проверка длины и символов
        int len = 0;
        while ( hexInput[len] != '\0' ) {
            if ( len >= 7 ) {
                cout << "Слишком длинное число\n";
                return;
            }
            char c = hexInput[len];
            if ( !((c >= '0' && c <= '9') ||
                (c >= 'A' && c <= 'F') ||
                (c >= 'a' && c <= 'f')) ) {
                cout << "Неверный ввод\n";
                return;
            }
            len++;
        }

        // Перевод в десятичную (вручную, т.к. `atoi` не поддерживает hex)
        int dec = 0;
        for ( int i = 0; i < len; i++ ) {
            char c = hexInput[i];
            int digit;
            if ( c >= '0' && c <= '9' ) digit = c - '0';
            else if ( c >= 'A' && c <= 'F' ) digit = c - 'A' + 10;
            else if ( c >= 'a' && c <= 'f' ) digit = c - 'a' + 10;
            else {
                cout << "Ошибка\n";
                return;
            }
            dec = dec * 16 + digit;
        }

        char result[33];
        if ( targetBase == 'a' ) {
            _itoa_s ( dec, result, sizeof ( result ), 2 );
            cout << "результат = " << result << "\n";
        }
        else if ( targetBase == 'b' ) {
            _itoa_s ( dec, result, sizeof ( result ), 8 );
            cout << "результат = " << result << "\n";
        }
        else if ( targetBase == 'c' ) {
            cout << "результат = " << dec << "\n";
        }
    }

    else {
        cout << "Неверный ввод!\n";
    }
}