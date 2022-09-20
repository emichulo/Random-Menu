#include <iostream>
#include <windows.h>
#include <string.h>

char mainMenu[3][50];

size_t cursor;

void SetColor(int k) {

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), k);

};

void assignment() {

    strcpy_s(mainMenu[0], 6, "aaaaa");
    strcpy_s(mainMenu[1], 6, "bbbbb");
    strcpy_s(mainMenu[2], 6, "ccccc");

};

void showMenu() {

    system("cls");
    for (unsigned int i = 0; i < 3; i++) {
        if (cursor == i)
            SetColor(3);
        else
            SetColor(7);
        std::cout << i + 1 << ". " << mainMenu[i] << "\n";
    }
    SetColor(7);

};

int main()
{
    system("title Ur nasty menu ");

    assignment();

    showMenu();

    while (true) {

        if (GetAsyncKeyState(VK_LSHIFT))
        {
            Sleep(100);
            if (cursor < 2)
                cursor++;
            else cursor = 0;
            showMenu();
        }
        if (GetAsyncKeyState(VK_RSHIFT))
        {
            Sleep(100);
            if (cursor > 0)
                cursor--;
            else cursor = 2;
            showMenu();
        }
        
    }
}


