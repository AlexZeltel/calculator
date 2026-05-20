#include <iostream>
#include <cstdlib>
#include <limits>
#include <string>

#ifdef _WIN32
    #include <windows.h>
    #include <io.h>
    #include <fcntl.h>
#else
    #include <locale>
#endif

using namespace std;


void Print(const wstring& s) {
#ifdef _WIN32
    WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), s.c_str(), s.size(), NULL, NULL);
#else
    wcout << s;
#endif
}


void CleanScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}


bool readInt(int& value) {
    cin >> value;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return true;
}


int main() {
#ifdef _WIN32
    _setmode(_fileno(stdout), _O_U16TEXT);
#else
    locale::global(locale(""));
    wcout.imbue(locale());
#endif

    int a, b;
    const int MAX = 5;
    const int MIN = 1;
    int langChoice = 0;


    while (langChoice < 1 || langChoice > 3) {
        CleanScreen();
        Print(L"Choose language / Seleccione idioma:\n");
        Print(L"1 - English\n");
        Print(L"2 - Русский\n");
        Print(L"3 - Español\n");
        Print(L"> ");
        if (!readInt(langChoice) || langChoice < 1 || langChoice > 3) {
            Print(L"Invalid input. Try again.\n");
            Print(L"Press Enter...");
            cin.get();
        }
    }
    int lang = langChoice - 1; // 0=английский, 1=русский, 2=испанский


    wstring welcome, enterFirst, enterSecond, chooseAction, menu;
    wstring errNotNum, errUnknown, errDivZero, goodbye, pressEnter;

    if (lang == 0) {
        welcome = L"Welcome to the calculator!";
        enterFirst = L"Enter first number: ";
        enterSecond = L"Enter second number: ";
        chooseAction = L"Choose action:";
        menu = L"1 - Addition\n2 - Subtraction\n3 - Multiplication\n4 - Division\n5 - Exit";
        errNotNum = L"Error: not a number!";
        errUnknown = L"Error: unknown action!";
        errDivZero = L"Error: denominator cannot be zero!";
        pressEnter = L"Press Enter to continue...";
        goodbye = L"Goodbye!";
    } else if (lang == 1) {
        welcome = L"Добро пожаловать в калькулятор!";
        enterFirst = L"Введите первое число: ";
        enterSecond = L"Введите второе число: ";
        chooseAction = L"Выберите действие:";
        menu = L"1 - Сложение\n2 - Вычитание\n3 - Умножение\n4 - Деление\n5 - Выход";
        errNotNum = L"Ошибка: введено не число!";
        errUnknown = L"Ошибка: выбрано неизвестное действие!";
        errDivZero = L"Ошибка: знаменатель не может быть равен нулю!";
        pressEnter = L"Нажмите Enter, чтобы продолжить...";
        goodbye = L"Пока!";
    } else {
        welcome = L"¡Bienvenido a la calculadora!";
        enterFirst = L"Ingrese el primer número: ";
        enterSecond = L"Ingrese el segundo número: ";
        chooseAction = L"Elija una acción:";
        menu = L"1 - Suma\n2 - Resta\n3 - Multiplicación\n4 - División\n5 - Salir";
        errNotNum = L"Error: ¡no es un número!";
        errUnknown = L"Error: ¡acción desconocida!";
        errDivZero = L"Error: ¡el denominador no puede ser cero!";
        pressEnter = L"Presione Enter para continuar...";
        goodbye = L"¡Adiós!";
    }

    CleanScreen();


    while (true) {
        Print(welcome + L"\n");
        Print(enterFirst);
        cin >> a;
        Print(enterSecond);
        cin >> b;
        Print(chooseAction + L"\n");
        Print(menu + L"\n");

        int choice;
        if (!readInt(choice)) {
            Print(errNotNum + L"\n");
            Print(pressEnter);
            cin.get();
            CleanScreen();
            continue;
        }

        if (choice > MAX || choice < MIN) {
            Print(errUnknown + L"\n");
            Print(pressEnter);
            cin.get();
            CleanScreen();
            continue;
        }

        if (choice == 5) {
            Print(goodbye);
            break;
        }

        if (choice == 1) {
            Print(to_wstring(a) + L" + " + to_wstring(b) + L" = " + to_wstring(a + b) + L"\n");
        } else if (choice == 2) {
            Print(to_wstring(a) + L" - " + to_wstring(b) + L" = " + to_wstring(a - b) + L"\n");
        } else if (choice == 3) {
            Print(to_wstring(a) + L" * " + to_wstring(b) + L" = " + to_wstring(a * b) + L"\n");
        } else if (choice == 4) {
            if (b == 0) {
                Print(errDivZero + L"\n");
            } else {
                Print(to_wstring(a) + L" / " + to_wstring(b) + L" = " + to_wstring(a / b) + L"\n");
            }
        }

        Print(pressEnter);
        cin.get();
        CleanScreen();
    }

    return 0;
}
