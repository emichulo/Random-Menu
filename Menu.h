#ifndef MENUH
#define MENUH

#include<iostream>
#include<vector>
#include<unordered_map>
#include<functional>

void setcolor(int k) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), k);
}

class SubMenu {
public:
	SubMenu& addOption(std::string option, std::function<void()> funct) {
		std::pair < std::string, std::function<void()>> p;
		p.first = option;
		p.second = funct;
		sm_data.push_back(p);
		return *this;
	}
	size_t size()const { return sm_data.size(); }
	std::pair < std::string, std::function<void()>>& operator[] (size_t index) { return sm_data[index]; }
	SubMenu& operator++ () {
		if (sm_index == sm_data.size() - 1)
			sm_index = 0;
		else
			++sm_index;
		return *this;
	}
	SubMenu& operator-- () {
		if (sm_index == 0)
			sm_index = sm_data.size()-1;
		else
			--sm_index;
		return *this;
	}
	size_t getIndex()const { return sm_index; }
private:
	std::vector<std::pair<std::string, std::function<void()>>> sm_data;
	size_t sm_index = 0;
};

class Menu {
public:
	void addMenu(const std::string& name) {
		m_data[name] = SubMenu{};
	}
	SubMenu& operator[] (const std::string& name) {return m_data.at(name);}

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

	void run(const std::string& name) {
		SubMenu& sm = m_data.at(name);
		print(sm);
		while (true) {
			if (GetAsyncKeyState(VK_LSHIFT)) {
				--sm;
				Sleep(200);
				print(sm);
			}
			if (GetAsyncKeyState(VK_RSHIFT)) {
				++sm;
				Sleep(200);
				print(sm);
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

