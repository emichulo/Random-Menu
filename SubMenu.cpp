#include "SubMenu.h"

	SubMenu::SubMenu()
		: sm_data(), sm_index(), sm_title() {}

    SubMenu& SubMenu::addTitle(const std::string& title) {
		sm_title = title;
		return *this;
	}

	SubMenu& SubMenu::addOption(std::string option, std::function<void()> funct) {
		std::pair < std::string, std::function<void()>> p;
		p.first = option;
		p.second = funct;
		sm_data.push_back(p);
		return *this;
	}

	size_t SubMenu::size() const { return sm_data.size(); }

	std::pair<std::string, std::function<void()>>& SubMenu::operator[] (size_t index) { return sm_data[index]; }

	SubMenu& SubMenu::operator++() {
		if (sm_index == sm_data.size() - 1)
			sm_index = 0;
		else
			++sm_index;
		return *this;
	}

	SubMenu& SubMenu::operator--() {
		if (sm_index == 0)
			sm_index = sm_data.size()-1;
		else
			--sm_index;
		return *this;
	}
    
	size_t SubMenu::getIndex() const { return sm_index; }

	std::string SubMenu::getTitle() { return sm_title; }

	void SubMenu::print() {
		system("cls");
		for (size_t i = 0; i < this->size(); ++i) {
			if (i == this->getIndex())
				setcolor(3);
			else
				setcolor(7);
			std::cout << i << "." << (*this)[i].first << "\n";
		}
		setcolor(7);
	}

    void SubMenu::setcolor(int k) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), k);
	}