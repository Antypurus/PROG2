#include <iostream>
#include "Company.h"
#include "Line.h"
#include "Driver.h"
#include <unordered_map>
#include <sstream>


void DriverMenu(Empresa &empresa) {
	int op = 0;
	while (op == 0) {
		system("cls");
		std::cout << "----------------------------------------------" << std::endl;
		std::cout << "|      Line Menu                             |" << std::endl;
		std::cout << "----------------------------------------------" << std::endl;
		std::cout << "|     1-Add Driver                           |" << std::endl;
		std::cout << "|     2-Remove Driver                        |" << std::endl;
		std::cout << "|     3-Edit Driver Name                     |" << std::endl;
		std::cout << "|     4-Edit Driver Max Time Per Shift       |" << std::endl;
		std::cout << "|     5-Edit Driver Max Time Per Week        |" << std::endl;
		std::cout << "|     6-Edit Driver Min Rest Between Shifts  |" << std::endl;
		std::cout << "|     7-See All Drivers                      |" << std::endl;
		std::cout << "|     8-See Driver Work                      |" << std::endl;
		std::cout << "|     9-List Drivers With Incomplete Service |" << std::endl;
		std::cout << "|     10-Back                                |" << std::endl;
		std::cout << "----------------------------------------------" << std::endl;

		std::stringstream option;
		std::string help;
		help.clear();
		std::cout << "Option:";
		std::cin >> help;
		option.clear();
		option.str(help);

		option >> op;

		switch (op) {
		case 1://add Driver
		{
			
			op = 0;
			break;
		}
		case 2://delete driver - done
		{
			system("cls");
			int id = 0;
			option.clear();
			std::cout << "Driver ID:";
			std::cin >> help;
			option.str(help);
			option >> id;
			empresa.removeDriver(id);
			system("pause");
			op = 0;
			break;
		}
		case 3://edit driver name
		{
			system("cls");
			int id = 0;
			option.clear();
			std::cout << "Driver ID:";
			std::cin >> help;
			option.str(help);
			option >> id;
			std::cout << "New Driver Name:";
			cin.ignore();
			std::getline(std::cin, help);
			empresa.changeDriverName(id, help);
			help.clear();
			system("pause");

			op = 0;
			break;
		}
		case 4://edit max shift
		{
			system("cls");
			int id = 0;
			option.clear();
			std::cout << "Driver ID:";
			std::cin >> help;
			option.str(help);
			option >> id;
			empresa.removeDriver(id);
			system("pause");
			op = 0;
			break;
		}
		case 5://edit max week
		{
			system("cls");
			int id = 0;
			option.clear();
			std::cout << "Driver ID:";
			std::cin >> help;
			option.str(help);
			option >> id;
			empresa.removeDriver(id);
			system("pause");
			op = 0;
			break;
		}
		case 6://edit min rest
		{
			system("cls");
			int id = 0;
			option.clear();
			std::cout << "Driver ID:";
			std::cin >> help;
			option.str(help);
			option >> id;
			empresa.removeDriver(id);
			system("pause");
			op = 0;
			break;
		}
		case 7://list all drivers - done
		{
			system("cls");
			for (auto it = empresa.drivers.begin(); it != empresa.drivers.end(); ++it) {
				std::cout << it->second << std::endl;
			}
			system("pause");
			op = 0;
			break;
		}
		case 8://see driver work - done
		{
			system("cls");
			int id = 0;
			option.clear();
			std::cout << "Driver ID:";
			std::cin >> help;
			option.str(help);
			option >> id;
			system("cls");
			empresa.listDriverWork(id);
			system("pause");

			op = 0;
			break;
		}
		case 9://list drivers not full - done
		{
			system("cls");
			std::vector<Driver>dr = empresa.getNotFullDrivers();
			for (int i = 0; i < dr.size(); ++i) {
				std::cout << dr[i] << std::endl;
			}
			system("pause");
			op = 0;
			break;
		}
		case 10: //exit - done
			return;
		default:
			op = 0;
			break;
		}
	}
}

void LineMenu(Empresa &empresa) {
	int op = 0;
	while (op == 0) {
		system("cls");
		std::cout << "---------------------------------------" << std::endl;
		std::cout << "|              Line Menu              |" << std::endl;
		std::cout << "---------------------------------------" << std::endl;
		std::cout << "|      1-Inset Bus Stop At End        |" << std::endl;
		std::cout << "|      2-Inset Bus Stop At Beggining  |" << std::endl;
		std::cout << "|      3-Inset Bus Stop In The Middle |" << std::endl;
		std::cout << "|      4-Change Line Frequency        |" << std::endl;
		std::cout << "|      5-List Bus Info                |" << std::endl;
		std::cout << "|      6-Back                         |" << std::endl;
		std::cout << "---------------------------------------" << std::endl;

		std::stringstream option;
		std::string help;
		help.clear();
		std::cout << "Option:";
		std::cin >> help;
		option.clear();
		option.str(help);

		option >> op;

		switch (op) {
		case 1:
		{
			op = 0;
			break;
		}
		case 2:
		{
			op = 0;
			break;
		}
		case 3:
		{
			op = 0;
			break;
		}
		case 4:
		{
			op = 0;
			break;
		}
		case 5:
		{
			op = 0;
			break;
		}
		case 6:
			return;
		default:
			op = 0;
			break;
		}
	}
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
		std::cout << "|     3-Shift Menu      |" << std::endl;
		std::cout << "|     4-Route Calculator|" << std::endl;
		std::cout << "|     5-Exit            |" << std::endl;
		std::cout << "-------------------------" << std::endl;

		std::stringstream option;
		std::string help;
		help.clear();
		std::cout << "Option:";
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
			LineMenu(em);
			op = 0;
			break;
		}
		case 3:
		{
			op = 0;
			break;
		}
		case 4:
		{
			op = 0;
			break;
		}
		case 5:
		{
			em.~Empresa();
			exit(0);
			break;
		}
		default:
			op = 0;
			break;
		}
	}
	system("pause");
	return 0;
}
