#include <string>
#include <sstream>
#include <iostream>
#include <limits>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

#include "Fraction.h"
#include "FractionMenu.h"

using namespace std;

FractionMenu::FractionMenu()
{
    //ctor
}

void FractionMenu::printTitle(string prompt)
{
    centerText("---------------------------");
    centerText(prompt);
    centerText(" ---------------------------\n");
}

void FractionMenu::displayItems()
{
    printTitle("FRACTION MENU");
    centerText("[1] Fraction Addition", 27);
    centerText("[2] Fraction Subtraction", 27);
    centerText("[3] Fraction Multiplication", 27);
    centerText("[4] Fraction Division", 27);
    centerText("[5] Fraction Comparison", 27);
    centerText("[6] Exit\n", 27);
}

int FractionMenu::selectedItem()
{
    int input;
    centerTextAsk("Enter your choice [ ]? ");

    //continuously ask choice until input is valid
    while(!(cin >> input) || (input < 1 || input > 6)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        centerTextAsk("Enter your choice [ ]? ");
    }

    return input;
}

bool FractionMenu::tryAgain()
{
    string input;
    cout << endl;
    centerTextAsk("Do you want to try again? [y if yes] ");
    cin >> input;
    return input == "y" || input == "Y";
}

Fraction FractionMenu::askFraction()
{
    int num, den;
    char delim;

    centerTextAsk("", 3);
    cin >> num >> delim >> den;

    if(num == 0 || den == 0)
    {
        centerText("Invalid Input!");
        return askFraction();
    }

    Fraction f(num, den);
    return f;
}

void FractionMenu::process()
{
    system("cls");
    string toDo = _choice == Addition ? "Addition" : _choice == Subtraction ? "Subtraction" : _choice == Multiplication ? "Multiplication" : _choice == Division ? "Division" : "Comparison";
    printTitle("Fraction " + toDo);

    centerText("First Fraction: ", 27);
    Fraction f1 = askFraction();

    centerText("Second Fraction: ", 27);
    Fraction f2 = askFraction();

    cout << endl;
    toDo = _choice == Addition ? " + " : _choice == Subtraction ? " - " : _choice == Multiplication ? " x " : _choice == Division ? " / " : " ? ";
    printTitle(f1.toString() + toDo + f2.toString());

    toDo = _choice == Addition ? "Sum" : _choice == Subtraction ? "Difference" : _choice == Multiplication ? "Product" : _choice == Division ? "Quotient" : "Result";
    centerText(toDo + ": ", 27);

    Fraction result;
    switch(_choice)
    {
        case Addition:
            result = f1.plusFraction(f2);
            break;
        case Subtraction:
            result = f1.minusFraction(f2);
            break;
        case Multiplication:
            result = f1.multiplyFraction(f2);
            break;
        case Division:
            result = f1.divideFraction(f2);
            break;
        case Comparison:
            switch(f1.compareFraction(f2))
            {
                case 0:
                    centerText(f1.toString() + " is equal to " + f2.toString());
                    break;
                case 1:
                    centerText(f1.toString() + " is greater than " + f2.toString());
                    break;
                case -1:
                    centerText(f1.toString() + " is less than " + f2.toString());
                    break;
            }
            return;
    }

    result.show();
}

void FractionMenu::centerText(string line)
{
    centerTextAsk(line, line.length());
    cout << endl;
}

void FractionMenu::centerText(string line, int len)
{
    centerTextAsk(line, len);
    cout << endl;
}

void FractionMenu::centerTextAsk(string line)
{
    centerTextAsk(line, line.length() + 1);
}

void FractionMenu::centerTextAsk(string line, int len)
{
    /*** print at the center of the console ***/
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int winWidth = csbi.srWindow.Right - csbi.srWindow.Left; //get screen width
    int pos = (int)((winWidth - len) / 2);
    for(int i=0; i<pos; i++) //print spaces before the target position
        cout << " ";
    cout << line;
}

FractionMenu::~FractionMenu()
{
    //dtor
}
