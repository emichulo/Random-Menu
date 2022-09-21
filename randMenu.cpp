#include<iostream>
#include<windows.h>
#include "Menu.h"

Menu obj;
void init() {
	obj.addMenu("Main Menu");
	obj.addMenu("Secound Menu");

	
	obj["Main Menu"]
		.addTitle("Main Menu")
		.addOption("Go To Secound Menu", []() {obj.run("Secound Menu"); })
		.addOption("bbbb", []() {});
	obj["Secound Menu"]
		.addTitle("Secound Menu")
		.addOption("Nothing", []() {})
		.addOption("Go To Main Menu", []() {obj.run("Main Menu"); })
		.addOption("Exit", []() {exit(-1); });
};

int main() {
	init();
	obj.run("Main Menu");

	return 0;
}