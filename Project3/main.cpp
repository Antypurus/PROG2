#include <iostream>
#include "Company.h"
#include "Line.h"
#include "Driver.h"
#include <unordered_map>


void LineMenu() {

}

void DriverMenu() {

}

int main(){
	std::string driverFilename = "motoristas.txt";
	std::string lineFilename = "linhas.txt";

	Empresa em("test","motoristas.txt","linhas.txt");

	system("cls");

	std::cout << "-------------------------" << std::endl;
	std::cout << "|      Main Menu        |" << std::endl;
	std::cout << "-------------------------" << std::endl;
	std::cout << "| 1 - List All Lines    |" << std::endl;
	std::cout << "| 2 - List All Drivers  |" << std::endl;
	std::cout << "| 3 - Add Driver        |" << std::endl;
	std::cout << "| 4 - Remove Driver     |" << std::endl;
	std::cout << "| 5 - Add Line          |" << std::endl;
	std::cout << "| 6 - Remove Line       |" << std::endl;
	std::cout << "| 7 - Exit              |" << std::endl;
	std::cout << "-------------------------" << std::endl;

	

	system("pause");
	return 0;
}
