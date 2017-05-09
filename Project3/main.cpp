#include <iostream>
#include "Company.h"
#include "Line.h"
#include "Driver.h"
#include <unordered_map>
#include <sstream>


void DriverMenu(Empresa &empresa) {
	system("cls");
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "|      Line Menu                             |" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "|     1-Add Driver                           |" << std::endl;
	std::cout << "|     2-Remove Driver                        |" << std::endl;
	std::cout << "|     3-Edit Driver                          |" << std::endl;
	std::cout << "|     4-See All Drivers                      |" << std::endl;
	std::cout << "|     5-See Driver Work                      |" << std::endl;
	std::cout << "|     6-List Drivers With Incomplete Service |" << std::endl;
	std::cout << "|     7-Add Shift To Driver                  |" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	system("pause");
}

void LineMenu(Empresa &empresa) {
	system("cls");
	std::cout << "-------------------------" << std::endl;
	std::cout << "|      Driver Menu      |" << std::endl;
	std::cout << "-------------------------" << std::endl;
	std::cout << "|      Driver Menu      |" << std::endl;
	std::cout << "|      Driver Menu      |" << std::endl;
	std::cout << "|      Driver Menu      |" << std::endl;
	std::cout << "|      Driver Menu      |" << std::endl;
	std::cout << "|      Driver Menu      |" << std::endl;
	std::cout << "-------------------------" << std::endl;
}

int main(){
	std::string driverFilename = "motoristas.txt";
	std::string lineFilename = "linhas.txt";

	Empresa em("test","motoristas.txt","linhas.txt");
	int op = 0;
	while (op == 0) {
		system("cls");

		std::cout << "-------------------------" << std::endl;
		std::cout << "|      Main Menu        |" << std::endl;
		std::cout << "-------------------------" << std::endl;
		std::cout << "|     1-Driver Menu     |" << std::endl;
		std::cout << "|     2-Line Menu       |" << std::endl;
		std::cout << "|      Driver Menu      |" << std::endl;
		std::cout << "|      Driver Menu      |" << std::endl;
		std::cout << "|      Driver Menu      |" << std::endl;
		std::cout << "-------------------------" << std::endl;

		std::stringstream option;
		std::string help;
		help.clear();
		std::cin >> help;
		option.clear();
		option.str(help);

		option >> op;

		switch (op) {
		case 1:
		{
			DriverMenu(em);
			op = 0;
			break;
		}
		case 2:
		{
			break;
		}
		default:break;
		}
	}
	system("pause");
	return 0;
}
