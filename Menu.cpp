#include "Menu.h"

    Menu::Menu() 
		: m_data() {}

	void Menu::addMenu(const std::string& name) {
		m_data[name] = SubMenu{};
	}

	SubMenu& Menu::operator[](const std::string& name) {return m_data.at(name);}

	void Menu::run(const std::string& name) {
		SubMenu& sm = m_data.at(name);
		system((std::string("title ") + sm.getTitle()).data());
		sm.print();
		while (true) {
			if (GetAsyncKeyState(VK_LSHIFT)) {
				--sm;
				Sleep(200);
				sm.print();
			}
			if (GetAsyncKeyState(VK_RSHIFT)) {
				++sm;
				Sleep(200);
				sm.print();
			}
			if (GetAsyncKeyState(VK_CONTROL)) {
				Sleep(200);
				sm[sm.getIndex()].second();
			}
		}
	}