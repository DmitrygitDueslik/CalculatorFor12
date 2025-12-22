#include "function.h"
void advancedCalculator ( )
{
    cout << "\n=== Расширенный калькулятор ===\n";
    cout << "a — Квадратный корень (корень числа x)\n";
    cout << "b — Возведение в степень (x^y)\n";
    cout << "c — Натуральный логарифм (ln x)\n";
    cout << "d — Модуль числа (|x|)\n";
    cout << "e — Синус (sin x, x в градусах)\n";
    cout << "f — Косинус (cos x, x в градусах)\n";
    cout << "g — Тангенс (tan x, x в градусах)\n";
    cout << "h — Котангенс (ctg x, x в градусах)\n";
    cout << "i — Перевод углов: градусы ? радианы\n";
    cout << ">> ";

    char choice;
    cin >> choice;

    switch ( choice ) {
        case 'a': calculateSqrt ( ); break;
        case 'b': calculatePower ( ); break;
        case 'c': calculateLog ( ); break;
        case 'd': calculateAbs ( ); break;
        case 'e': calculateSin ( ); break;
        case 'f': calculateCos ( ); break;
        case 'g': calculateTan ( ); break;
        case 'h': calculateCtg ( ); break;
        case 'i': angleConversion ( ); break;
        default:
            cout << "Ошибка: неверный выбор.\n";
    }
}
double degreesToRadians ( double degrees )
{
    const double PI = acos ( -1.0 );
    return degrees * PI / 180.0;
}

void calculateSin ( )
{
    double deg;
    cout << "Введите угол в градусах: ";
    if ( !(cin >> deg) ) {
        cout << "Ошибка ввода!\n";
        cin.clear ( );
        cin.ignore ( 1000, '\n' );
        return;
    }
    double rad = degreesToRadians ( deg );
    cout << fixed << setprecision ( 6 );
    cout << "sin(" << deg << "°) = " << sin ( rad ) << endl;
}

void calculateCos ( )
{
    double deg;
    cout << "Введите угол в градусах: ";
    if ( !(cin >> deg) ) {
        cout << "Ошибка ввода!\n";
        cin.clear ( );
        cin.ignore ( 1000, '\n' );
        return;
    }
    double rad = degreesToRadians ( deg );
    cout << fixed << setprecision ( 6 );
    cout << "cos(" << deg << "°) = " << cos ( rad ) << endl;
}

void calculateTan ( )
{
    double deg;
    cout << "Введите угол в градусах: ";
    if ( !(cin >> deg) ) {
        cout << "Ошибка ввода!\n";
        cin.clear ( );
        cin.ignore ( 1000, '\n' );
        return;
    }
    double rad = degreesToRadians ( deg );
    double s = sin ( rad );
    double c = cos ( rad );

    // Проверка на близость к нулю (cos ? 0 ? tan ? ?)
    if ( abs ( c ) < 1e-10 ) {
        cout << "Ошибка: тангенс не определён при cos(x) ? 0 (например, 90°, 270° и т.д.)\n";
        return;
    }

    double tanVal = s / c;
    cout << fixed << setprecision ( 6 );
    cout << "tan(" << deg << "°) = " << tanVal << endl;
}

void calculateCtg ( )
{
    double deg;
    cout << "Введите угол в градусах: ";
    if ( !(cin >> deg) ) {
        cout << "Ошибка ввода!\n";
        cin.clear ( );
        cin.ignore ( 1000, '\n' );
        return;
    }
    double rad = degreesToRadians ( deg );
    double s = sin ( rad );
    double c = cos ( rad );

    // Проверка: sin ? 0 ? ctg ? ?
    if ( abs ( s ) < 1e-10 ) {
        cout << "Ошибка: котангенс не определён при sin(x) ? 0 (например, 0°, 180° и т.д.)\n";
        return;
    }

    double ctgVal = c / s;
    cout << fixed << setprecision ( 6 );
    cout << "ctg(" << deg << "°) = " << ctgVal << endl;
}

void angleConversion ( )
{
    char choice;
    cout << "\n--- Перевод углов ---\n";
    cout << "a — Градусы ? радианы\n";
    cout << "b — Радианы ? градусы\n>> ";
    cin >> choice;

    if ( choice == 'a' ) {
        double deg;
        cout << "Введите угол в градусах: ";
        if ( !(cin >> deg) ) {
            cout << "Ошибка ввода!\n";
            cin.clear ( );
            cin.ignore ( 1000, '\n' );
            return;
        }
        double rad = degreesToRadians ( deg );
        cout << fixed << setprecision ( 6 );
        cout << deg << " градусов = " << rad << " радиан\n";
    }
    else if ( choice == 'b' ) {
        double rad;
        cout << "Введите угол в радианах: ";
        if ( !(cin >> rad) ) {
            cout << "Ошибка ввода!\n";
            cin.clear ( );
            cin.ignore ( 1000, '\n' );
            return;
        }
        const double PI = acos ( -1.0 );
        double deg = rad * 180.0 / PI;
        cout << fixed << setprecision ( 6 );
        cout << rad << " радиан = " << deg << " градусов\n";
    }
    else {
        cout << "Неверный выбор.\n";
    }
}

// ======================
// ОСТАЛЬНЫЕ МАТЕМАТИЧЕСКИЕ ФУНКЦИИ
// ======================

void calculateSqrt ( )
{
    double x;
    cout << "Введите число (x ? 0): ";
    if ( !(cin >> x) ) {
        cout << "Ошибка ввода!\n";
        cin.clear ( );
        cin.ignore ( 1000, '\n' );
        return;
    }
    if ( x < 0 ) {
        cout << "Ошибка: квадратный корень из отрицательного числа не определён (в ?).\n";
        return;
    }
    cout << "Результат = " << fixed << setprecision ( 6 ) << sqrt ( x ) << endl;
}

void calculatePower ( )
{
    double x, y;
    cout << "Введите основание (x): ";
    if ( !(cin >> x) ) {
        cout << "Ошибка ввода!\n";
        cin.clear ( );
        cin.ignore ( 1000, '\n' );
        return;
    }
    cout << "Введите показатель (y): ";
    if ( !(cin >> y) ) {
        cout << "Ошибка ввода!\n";
        cin.clear ( );
        cin.ignore ( 1000, '\n' );
        return;
    }

    if ( x == 0 && y == 0 ) {
        cout << "Ошибка: 0^0 не определено.\n";
        return;
    }
    if ( x == 0 && y < 0 ) {
        cout << "Ошибка: деление на ноль (0 в отрицательной степени).\n";
        return;
    }

    double result = pow ( x, y );
    cout << "Результат = " << fixed << setprecision ( 6 ) << result << endl;
}

void calculateLog ( )
{
    double x;
    cout << "Введите число (x > 0): ";
    if ( !(cin >> x) ) {
        cout << "Ошибка ввода!\n";
        cin.clear ( );
        cin.ignore ( 1000, '\n' );
        return;
    }
    if ( x <= 0 ) {
        cout << "Ошибка: логарифм определён только для положительных чисел.\n";
        return;
    }
    cout << "Результат = " << fixed << setprecision ( 6 ) << log ( x ) << endl;
}

void calculateAbs ( )
{
    double x;
    cout << "Введите число: ";
    if ( !(cin >> x) ) {
        cout << "Ошибка ввода!\n";
        cin.clear ( );
        cin.ignore ( 1000, '\n' );
        return;
    }
    cout << "Результат = " << fixed << setprecision ( 6 ) << abs ( x ) << endl;
}