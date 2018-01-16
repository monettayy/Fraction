#include <windows.h>

#include "FractionMenu.h"

using namespace std;

void fullscreeen()
{
    /*** works on laptop or medium screens only ***/
    keybd_event(VK_MENU, 0x38, 0, 0);
    keybd_event(VK_RETURN, 0x1c, 0, 0);
    keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
}

int main()
{
    fullscreeen();
    system("pause");

    FractionMenu menu;
    do
    {
        system("cls");
        menu.displayItems();

        menu.setChoice(menu.selectedItem());

        if(menu.getChoice() == FractionMenu::Quit)
            break;

        menu.process();

        menu.setChoice(menu.tryAgain() ? 0 : 6);
    }while(menu.getChoice() != FractionMenu::Quit);

    FractionMenu::centerText("Thank you for using this application . . .");
}
