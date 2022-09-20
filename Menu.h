#ifndef MENUH
#define MENUH

#include<iostream>
#include<vector>
#include<unordered_map>
#include<functional>

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
	size_t sm_index;
};

class Menu {
public:
	void addMenu(const std::string& name) {
		m_data[name] = SubMenu{};
	}
	SubMenu& getMenu(const std::string& name) {
		return m_data.at(name);
	}
private:
	std::unordered_map<std::string, SubMenu> m_data;


};





#endif

