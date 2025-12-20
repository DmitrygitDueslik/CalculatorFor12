#include "function.h"
/*
* Функция-проверка, возвращает true / false в зависимости от того, является ли число бинарным.
* Проходим по каждому символу массива. Если встречаем что-то, кроме '0' или '1' - ошибка.
*/
bool isBinary ( const char* input )
{
    for ( int i = 0; input[i] != '\0'; i++ ) {
        if ( input[i] != '0' && input[i] != '1' )
            return false;
    }
    return true;
}
/*
* Перевод бинарного числа в десятичное позиционным методом вычисления значения числа.
*/
int binToDec ( const char* input )
{
    int dec = 0;
    for ( int i = 0; input[i] != '\0'; i++ ) {
        dec = dec * 2 + (input[i] - '0');
    }
    return dec;
}
/*
* Перевод десятичного числа в бинарное методом записи остатков.
*/
void decToBin ( int dec, char* out )
{
    if ( dec == 0 ) {
        out[0] = '0';
        out[1] = '\0';
        return;
    }
    char temp[65];
    int index = 0;

    while ( dec > 0 ) {
        temp[index++] = dec % 2 + '0';
        dec /= 2;
    }

    // Записываем число в обратном виде.
    for ( int i = 0; i < index; i++ ) {
        out[i] = temp[index - 1 - i];
    }
    out[index] = '\0';
}
/*
* Арифметические операции над десятичными числами.
* Поддерживаемые операции: + - * /
*/
int binaryArithmetic ( int a, int b, const char* operation )
{
    if ( operation[0] == '+' ) return a + b;
    if ( operation[0] == '-' ) return a - b;
    if ( operation[0] == '*' ) return a * b;
    if ( operation[0] == '/' ) {
        if ( b == 0 ) {
            cout << "Ошибка: деление на ноль!\n";
            return 0;
        }
        return a / b;
    }
    cout << "Ошибка: некорректная арифметическая операций!\n";
    return 0;
}

/*
* Логические и побитовые операции над десятичными числами
* Поддерживаемые операции: & | ^ << >>
*/
int binaryLogic ( int a, int b, const char* operation )
{
    if ( operation[0] == '&' ) return a & b;
    if ( operation[0] == '|' ) return a | b;
    if ( operation[0] == '^' ) return a ^ b;
    if ( operation[0] == '<' && operation[1] == '<' ) return a << b;
    if ( operation[0] == '>' && operation[1] == '>' ) return a >> b;

    cout << "Ошибка: некорректная логическая операция!\n";
    return 0;
}

/*
* Главная функция бинарного калькулятора
* 
* 1. Ввод двух бинарных чисел и операцию
* 2. Проверка корректности
* 3. Перевод в десятичную систему
* 4. Выполнение операции
* 5. Перевод результата обратно в бинарную
*/
void binaryCalculation ( )
{

    char bin1[65], bin2[65], operation[3];

    cout << "Все доступные (на данный момент) операции:\n"
        << "Арифметические операции:\t\tЛогические операции:\n"
        << "[ + ] - сложение\t\t [ & ] - AND (логическое И)\n"
        << "[ - ] - вычитание\t\t [ | ] - OR (логическое ИЛИ)\n"
        << "[ * ] - умножение\t\t [ ^ ] - XOR (исклюающее ИЛИ)\n"
        << "[ / ] - деление\t\t\t [ << ], [ >> ] - сдвиги (ВЛЕВО, ВПРАВО, соответственно)\n\n"
        << "Введите выражение (например: 1010 + 10)(В ДВОИЧНОЙ СИСТЕМЕ!!!)\n";
    cin >> bin1 >> operation >> bin2;

    if ( !isBinary ( bin1 ) ) {
        cout << "Ошибка: первое число не является двоичным!\n";
        return;
    }

    if ( !isBinary ( bin2 ) ) {
        cout << "Ошибка: второе число не является двоичным!\n";
        return;
    }

    int dec1 = binToDec ( bin1 );
    int dec2 = binToDec ( bin2 );
    int result = 0;

    if ( operation[0] == '+' || operation[0] == '-' || operation[0] == '*' || operation[0] == '/' ) {
        result = binaryArithmetic ( dec1, dec2, operation );
    }
    else {
        result = binaryLogic ( dec1, dec2, operation );
    }

    char out[65];
    if ( result < 0 ) {
        cout << "Результат = -";
        decToBin ( -result, out );
        cout << out << "\n";
        return;
    }
    else {
        decToBin ( result, out );
    }

    cout << "Результат = " << out << "\n";
}
