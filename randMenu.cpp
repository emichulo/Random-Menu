#include <iostream>
#include<windows.h>
#include<string>

char mainMenu[3][50];

size_t cursor;

void SetColor(int k) {

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), k);

};

void assignment() {

    strcpy_s(mainMenu[0], 5, "#####");
    strcpy_s(mainMenu[1], 5, "#####");
    strcpy_s(mainMenu[2], 5, "#####");

}


int main()
{
    system("### Ur nasty menu ###");

    assignment();







    std::cout << "Hello World!\n";
}


