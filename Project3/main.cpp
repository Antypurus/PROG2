#include <iostream>
#include "Company.h"
#include "Line.h"
#include "Driver.h"
#include <unordered_map>
#include <sstream>


void LineMenu(Empresa &empresa) {
	system("cls");
	std::cout << "-------------------------" << std::endl;
	std::cout << "|      Line Menu        |" << std::endl;
	std::cout << "-------------------------" << std::endl;
	std::cout << "|      Driver Menu      |" << std::endl;
	std::cout << "|      Driver Menu      |" << std::endl;
	std::cout << "|      Driver Menu      |" << std::endl;
	std::cout << "|      Driver Menu      |" << std::endl;
	std::cout << "|      Driver Menu      |" << std::endl;
	std::cout << "-------------------------" << std::endl;
}

void DriverMenu(Empresa &empresa) {
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
	std::cin>>help;
	optiom.clear();
	option.str(help);
	
	int op=0;
	option>>op;
	
	switch(op){
		case(1):break;
		case(2):break;
		default:break;
	}

	system("pause");
	return 0;
}
