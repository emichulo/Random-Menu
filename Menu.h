#ifndef MENUH
#define MENUH

#include "SubMenu.h"

class Menu {
public:
	Menu();
	void addMenu(const std::string& name);

	SubMenu& operator[](const std::string& name);

	void run(const std::string& name);
private:
	std::unordered_map<std::string, SubMenu> m_data;
};

#endif

