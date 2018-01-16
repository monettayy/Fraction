#ifndef FRACTIONMENU_H
#define FRACTIONMENU_H

#include <string>
#include <iostream>

#include "Fraction.h"

using namespace std;

class FractionMenu
{
    public:
        FractionMenu();

        enum Menu {Addition, Subtraction, Multiplication, Division, Comparison, Quit};

        void setChoice(int c)       { _choice = (Menu)(c - 1);}
        Menu getChoice()            { return _choice; }

        void printTitle(string);
        void displayItems();
        int selectedItem();
        bool tryAgain();
        Fraction askFraction();

        void process();

        static void centerText(string);
        static void centerText(string, int);
        static void centerTextAsk(string);
        static void centerTextAsk(string, int);

        virtual ~FractionMenu();
    protected:

    private:
        Menu _choice;
};

#endif // FRACTIONMENU_H
