#ifndef MENUH
#define MENUH

#include<iostream>
#include<vector>
#include<unordered_map>
#include<functional>

class SubMenu {
public:
	SubMenu& addTitle(std::string title) {
		std::wstring temp = std::wstring(title.begin(), title.end());
		LPCWSTR tit;
		tit = temp.c_str();
		SetConsoleTitle(tit);
		return *this;
	}
	SubMenu& addOption(std::string option, std::function<void()> funct) {
		std::pair < std::string, std::function<void()>> p;
		p.first = option;
		p.second = funct;
		sm_data.push_back(p);
		return *this;
	}
	size_t size() const { return sm_data.size(); }
	std::pair<std::string, std::function<void()>>& operator[] (size_t index) { return sm_data[index]; }
	SubMenu& operator++() {
		if (sm_index == sm_data.size() - 1)
			sm_index = 0;
		else
			++sm_index;
		return *this;
	}
	SubMenu& operator--() {
		if (sm_index == 0)
			sm_index = sm_data.size()-1;
		else
			--sm_index;
		return *this;
	}
	size_t getIndex() const { return sm_index; }
	void print() {
		system("cls");
		for (size_t i = 0; i < this->size(); i++) {
			if (i == this->getIndex())
				setcolor(3);
			else
				setcolor(7);
			std::cout << i << "." << (*this)[i].first << "\n";
		}
		setcolor(7);
	}
private:
	std::vector<std::pair<std::string, std::function<void()>>> sm_data;
	size_t sm_index = 0;

	void setcolor(int k) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), k);
	}
};

class Menu {
public:
	Menu() {};
	void addMenu(const std::string& name) {
		m_data[name] = SubMenu{};
	}
	SubMenu& operator[] (const std::string& name) {return m_data.at(name);}

	void run(const std::string& name) {
		SubMenu& sm = m_data.at(name);
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
private:
	std::unordered_map<std::string, SubMenu> m_data;
};

#endif

