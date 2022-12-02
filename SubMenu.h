#ifndef SUBMENUH
#define SUBMENUH

#ifndef MENUH
// You should not use "SubMenu.h" by itself, rather include "Menu.h"
// #error "SubMenu.h can't be included alone"
#endif

#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>
#include <windows.h>

class SubMenu {
public:
	SubMenu();

	SubMenu& addTitle(const std::string& title);
	SubMenu& addOption(std::string option, std::function<void()> funct);

	size_t size() const;

	std::pair<std::string, std::function<void()>>& operator[] (size_t index);

	SubMenu& operator++();
	SubMenu& operator--();

	size_t getIndex() const;
	std::string getTitle();

	void print();
private:
	std::vector<std::pair<std::string, std::function<void()>>> sm_data;
	size_t sm_index = 0;
	std::string sm_title;

	void setcolor(int k);
};

#endif