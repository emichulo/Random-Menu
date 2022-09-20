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
private:
	std::vector<std::pair<std::string, std::function<void()>>> sm_data;
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

