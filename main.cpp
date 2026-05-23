#include <iostream>
#include <cstdlib>
#include <limits>
#include <string>
#include <vector>
#include <cmath>

#ifdef _WIN32  //check windows
    #include <windows.h>
    #include <io.h>
    #include <fcntl.h>
#else // if not windows
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

bool readDouble(double& value) {
    cin >> value;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return true;
}

wstring fmt(double num) {
    wstring s = to_wstring(num);
    if (s.find(L'.') != wstring::npos) {
        s.erase(s.find_last_not_of(L'0') + 1);
        if (s.back() == L'.') s.pop_back();
    }
    return s;
}

int main() {
#ifdef _WIN32
    _setmode(_fileno(stdout), _O_U16TEXT);
#else
    locale::global(locale(""));
    wcout.imbue(locale());
#endif

    double a, b;
    const int MAX = 7; // max action
    const int MIN = 1; // min action
    int langChoice = 0; // select lang
    vector<wstring> history; //history

//main code
    while (langChoice < 1 || langChoice > 5) {
        CleanScreen();
        Print(L"Choose language:\n");
        Print(L"1 - English\n");
        Print(L"2 - Русский\n");
        Print(L"3 - Español\n");
        Print(L"4 - Français\n");
        Print(L"5 - Deutsch\n");
        Print(L"> ");
        if (!readInt(langChoice) || langChoice < 1 || langChoice > 5) {
            Print(L"\aInvalid input. Try again.\n");
            Print(L"Press Enter...");
            cin.get();
        }
    }
    int lang = langChoice - 1; // 0=english, 1=russian, 2=espanol, 3= french, 4=german


    wstring welcome, enterFirst, enterSecond, chooseAction, menu;
    wstring errNotNum, errUnknown, errDivZero, goodbye, pressEnter;
    wstring historyEmpty, historyTitle;

    if (lang == 0) {
        welcome = L"Welcome to the calculator!";
        enterFirst = L"Enter first number: ";
        enterSecond = L"Enter second number: ";
        chooseAction = L"Choose action:";
        menu = L"1 - Addition\n2 - Subtraction\n3 - Multiplication\n4 - Division\n5 - Exponentiation (second number is the exponent)\n6 - History\n7 - Exit";
        errNotNum = L"Error: not a number!";
        errUnknown = L"Error: unknown action!";
        errDivZero = L"Error: denominator cannot be zero!";
        pressEnter = L"Press Enter to continue...";
        goodbye = L"Goodbye!";
        historyTitle = L"Calculation History";
        historyEmpty = L"History is empty.";
    } else if (lang == 1) {
        welcome = L"Добро пожаловать в калькулятор!";
        enterFirst = L"Введите первое число: ";
        enterSecond = L"Введите второе число: ";
        chooseAction = L"Выберите действие:";
        menu = L"1 - Сложение\n2 - Вычитание\n3 - Умножение\n4 - Деление\n5 - Возведение в степень (второе число будет степенью)\n6 - История\n7 - Выход";
        errNotNum = L"Ошибка: введено не число!";
        errUnknown = L"Ошибка: выбрано неизвестное действие!";
        errDivZero = L"Ошибка: знаменатель не может быть равен нулю!";
        pressEnter = L"Нажмите Enter, чтобы продолжить...";
        goodbye = L"Пока!";
        historyTitle = L"История вычислений";
        historyEmpty = L"История пуста.";
    } else if (lang == 2) {
        welcome = L"¡Bienvenido a la calculadora!";
        enterFirst = L"Ingrese el primer número: ";
        enterSecond = L"Ingrese el segundo número: ";
        chooseAction = L"Elija una acción:";
        menu = L"1 - Suma\n2 - Resta\n3 - Multiplicación\n4 - División\n5 - Potenciación (el segundo número es el exponente)\n6 - Historial\n7 - Salir";
        errNotNum = L"Error: ¡no es un número!";
        errUnknown = L"Error: ¡acción desconocida!";
        errDivZero = L"Error: ¡el denominador no puede ser cero!";
        pressEnter = L"Presione Enter para continuar...";
        goodbye = L"¡Adiós!";
        historyTitle = L"Historial de cálculos";
        historyEmpty = L"El historial está vacío.";
    } else if (lang == 3) {
        welcome = L"Bienvenue dans la calculatrice !";
        enterFirst = L"Entrez le premier nombre : ";
        enterSecond = L"Entrez le second nombre : ";
        chooseAction = L"Choisissez une action :";
        menu = L"1 - Addition\n2 - Soustraction\n3 - Multiplication\n4 - Division\n5 - Exponentiation (le deuxième nombre est l'exposant)\n6 - Historique\n7 - Quitter";
        errNotNum = L"Erreur : ce n'est pas un nombre !";
        errUnknown = L"Erreur : action inconnue !";
        errDivZero = L"Erreur : le dénominateur ne peut pas être nul !";
        pressEnter = L"Appuyez sur Entrée pour continuer...";
        goodbye = L"Au revoir !";
        historyTitle = L"=== Historique des calculs ===";
        historyEmpty = L"L'historique est vide.";
    } else if (lang == 4) {
        welcome = L"Willkommen beim Taschenrechner!";
        enterFirst = L"Erste Zahl eingeben: ";
        enterSecond = L"Zweite Zahl eingeben: ";
        chooseAction = L"Aktion auswählen:";
        menu = L"1 - Addition\n2 - Subtraktion\n3 - Multiplikation\n4 - Division\n5 - Potenzierung (zweite Zahl ist der Exponent)\n6 - Verlauf\n7 - Beenden";
        errNotNum = L"Fehler: Keine Zahl!";
        errUnknown = L"Fehler: Unbekannte Aktion!";
        errDivZero = L"Fehler: Der Nenner darf nicht Null sein!";
        pressEnter = L"Drücken Sie die Eingabetaste, um fortzufahren...";
        goodbye = L"Auf Wiedersehen!";
        historyTitle = L"Berechnungsverlauf";
        historyEmpty = L"Der Verlauf ist leer.";
    }

    CleanScreen();


    while (true) {
        Print(welcome + L"\n");
        Print(chooseAction + L"\n");
        Print(menu + L"\n");
int choice;
        if (!readInt(choice)) {
            Print(L"\a" + errNotNum + L"\n");
            Print(pressEnter);
            cin.get();
            CleanScreen();
            continue;
        }

        if (choice > MAX || choice < MIN) {
            Print(L"\a" + errUnknown + L"\n");
            Print(pressEnter);
            cin.get();
            CleanScreen();
            continue;
        }

       if (choice == 6) {
    if (history.empty()) {
        Print(historyEmpty + L"\n");
    } else {
        Print(historyTitle + L"\n");
        for (size_t i = 0; i < history.size(); ++i) {
            Print(to_wstring(i + 1) + L") " + history[i] + L"\n");
        }
    }
    Print(pressEnter);
    cin.get();
    CleanScreen();
    continue;
}
        if (choice == 7) {
            Print(goodbye);
            break;
        }
Print(enterFirst);
        if (!readDouble(a)) {
            Print(L"\a" + errNotNum + L"\n");
            Print(pressEnter);
            cin.get();
            CleanScreen();
            continue;
        }
        Print(enterSecond);
        if (!readDouble(b)) {
            Print(L"\a" + errNotNum + L"\n");
            Print(pressEnter);
            cin.get();
            CleanScreen();
            continue;
        }


        if (choice == 1) {
            wstring result = fmt(a) + L" + " + fmt(b) + L" = " + fmt(a + b);
            Print(result + L"\n");
            history.push_back(result);
        } else if (choice == 2) {
            wstring result = fmt(a) + L" - " + fmt(b) + L" = " + fmt(a - b);
            Print(result + L"\n");
            history.push_back(result);
        } else if (choice == 3) {
            wstring result = fmt(a) + L" * " + fmt(b) + L" = " + fmt(a * b);
            Print(result + L"\n");
            history.push_back(result);
        } else if (choice == 4) {
            if (b == 0) {
                Print(errDivZero + L"\n");
            } else {
                wstring result = fmt(a) + L" / " + fmt(b) + L" = " + fmt(a / b);
                Print(result + L"\n");
                history.push_back(result);
            }
        } else if (choice == 5) {
                wstring result = fmt(a) + L" ^ " + fmt(b) + L" = " + fmt(pow(a, b));
                Print(result + L"\n");
                history.push_back(result);
        }

        Print(pressEnter);
        cin.get();
        CleanScreen();
    }

    return 0;
}
