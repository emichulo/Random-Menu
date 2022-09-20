#include<iostream>
#include<windows.h>
#include "Menu.h"

Menu obj;
void init() {
	obj.addMenu("Main Menu");
	obj.getMenu("Main Menu").addOption("aaaa", []() {std::cout << "wellcum"; }).addOption("bbbb", []() {});
};
void setcolor(int k) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), k);
}
void print(SubMenu& sm) {
	system("cls");
	for (size_t i = 0; i < sm.size(); i++) {
		if (i == sm.getIndex())
			setcolor(3);
		else
			setcolor(7);
		std::cout << i << "." << sm[i].first << "\n";
	}
	setcolor(7);
}

int main() {
	init();
	SubMenu& sm = obj.getMenu("Main Menu");
	print(sm);
	while (true) {
		if (GetAsyncKeyState(VK_LSHIFT)) {
			--sm;
			Sleep(100);
			print(sm);
		}
		if (GetAsyncKeyState(VK_RSHIFT)) {
			++sm;
			Sleep(100);
			print(sm);
		}
		if (GetAsyncKeyState(VK_CONTROL)) {
			sm[sm.getIndex()].second();
			Sleep(100);
		}
	}

	return 0;
}