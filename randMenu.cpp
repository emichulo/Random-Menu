#include <iostream>
#include<windows.h>
#include<string>

char mainMenu[3][50];

size_t cursor;

void SetColor(int k) {

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), k);

};

int main()
{
    system("### Ur nasty menu ###");

    strcpy_s(mainMenu[0], 5, "#####");
    strcpy_s(mainMenu[1], 5, "#####");
    strcpy_s(mainMenu[2], 5, "#####");







    std::cout << "Hello World!\n";
}


