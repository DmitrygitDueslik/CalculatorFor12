#include "function.h"
int main ( )
{

    SetConsoleOutputCP ( 1251 );
    SetConsoleCP ( 1251 );

    char option;
    cout << "\t\t***************************************************************************************" << endl;
    cout << "\t\t**   #####                                                                           **" << endl;
    cout << "\t\t**  #     #     ##    #        ####   #    #  #          ##     ###   ####   #####   **" << endl;
    cout << "\t\t**  #          #  #   #       #    #  #    #  #         #  #     #   #    #  #    #  **" << endl;
    cout << "\t\t**  #         #    #  #       #       #    #  #        #    #    #   #    #  #    #  **" << endl;
    cout << "\t\t**  #         ######  #       #       #    #  #        ######    #   #    #  #####   **" << endl;
    cout << "\t\t**  #     #  #      # #       #    #  #    #  #       #      #   #   #    #  #   #   **" << endl;
    cout << "\t\t**   #####   #      #  ######  ####    ####   ######  #      #   #    ####   #    #  **" << endl;
    cout << "\t\t***************************************************************************************" << endl;
    cout << "-------------------------------------------------------------------------------------------------------"
        << endl;
    do {
        cout << endl
            << "Простой калькулятор\t\t'a'\n"
            << "Расширенный калькулятор\t\t'b'\n"
            << "Таблица ASCII\t\t\t'c'\n"
            << "Системы счисления\t\t'd'\n"
            << "Бинарный калькулятор\t\t'e'\n"
            << "Выход из программы\t\t'f'\n"
            << "\n>> ";
        cin >> option;

        if ( option == 'a' ) {
            basicCalculator ( );
        }
        else if ( option == 'b' ) {
            advancedCalculator ( );
        }
        else if ( option == 'c' ) {
            asciiTable ( );
        }
        else if ( option == 'd' ) {
            digitalSystem ( );
        }
        else if ( option == 'e' ) {
            binaryCalculation ( );
        }
        else if ( option == 'f' ) {
            cout << "Неверный ввод!\n";
        }
    } while ( option != 'f' );
}
