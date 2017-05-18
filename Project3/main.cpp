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
		case 1://add Driver - done
		{
			system("cls");
			int id = 0;
			string name = "";
			int ms = 0;//max shift;
			int mw = 0;//max week;
			int mr = 0;//min rest;
			option.clear();
			std::cout << "Driver ID:";
			std::cin >> help;
			option.str(help);
			option >> id;
			std::cout << "Driver Max Shift Duration:";
			option.clear();
			std::cin >> help;
			option.str(help);
			option >> ms;
			option.clear();
			std::cout << "Driver Max Week Work Time:";
			std::cin >> help;
			option.str(help);
			option >> mw;
			option.clear();
			std::cout << "Driver Min Rest Time Bewtween shifts:";
			std::cin >> help;
			option.str(help);
			option >> mr;
			std::cout << "Driver Name:";
			cin.ignore();
			std::getline(std::cin, help);
			empresa.addDriver(Driver(help, id, ms, mw, mr));
			help.clear();
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
		case 3://edit driver name - done
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
		case 4://edit max shift - done
		{
			system("cls");
			int id = 0;
			int mt = 0;
			option.clear();
			std::cout << "Driver ID:";
			std::cin >> help;
			option.str(help);
			option >> id;
			std::cout << "New Max Time Per Shift:";
			std::cin >> help;
			option.clear();
			option.str(help);
			option >> mt;
			empresa.changeDriverMaxHourShift(id, mt);
			system("pause");
			op = 0;
			break;
		}
		case 5://edit max week - done
		{
			system("cls");
			int id = 0;
			int mt = 0;
			option.clear();
			std::cout << "Driver ID:";
			std::cin >> help;
			option.str(help);
			option >> id;
			std::cout << "New Max Time Per Week:";
			std::cin >> help;
			option.clear();
			option.str(help);
			option >> mt;
			empresa.changeDriverMaxHoursWeek(id, mt);
			system("pause");
			op = 0;
			break;
		}
		case 6://edit min rest - done
		{
			system("cls");
			int id = 0;
			int mt = 0;
			option.clear();
			std::cout << "Driver ID:";
			std::cin >> help;
			option.str(help);
			option >> id;
			std::cout << "New Min Time Between Shifts:";
			std::cin >> help;
			option.clear();
			option.str(help);
			option >> mt;
			empresa.changeDriverMinRestTime(id, mt);
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
		std::cout << "|      6-List All Lines               |" << std::endl;
		std::cout << "|      7-Edit Stop                    |" << std::endl;
		std::cout << "|      8-Edit Time Between Stops      |" << std::endl;
		std::cout << "|      9-Lines With A Stop            |" << std::endl;
		std::cout << "|      10-Back                        |" << std::endl;
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
		case 1://done
		{
			int id=0, time=0;
			std::string name;
			help.clear();
			std::cout << "Line ID:";
			std::cin >> help;
			option.clear();
			option.str(help);
			option >> id;

			std::cout << "Stop Name:";
			cin.ignore();
			std::getline(std::cin, name);

			help.clear();
			std::cout << "Time Since Last Stop:";
			std::cin >> help;
			option.clear();
			option.str(help);
			option >> time;

			empresa.addBusStop(id, name, time);
			system("pause");
			op = 0;
			break;
		}
		case 2://done
		{
			int id = 0, time = 0;
			std::string name;
			help.clear();
			std::cout << "Line ID:";
			std::cin >> help;
			option.clear();
			option.str(help);
			option >> id;

			std::cout << "Stop Name:";
			cin.ignore();
			std::getline(std::cin, name);

			help.clear();
			std::cout << "Time To Next Stop:";
			std::cin >> help;
			option.clear();
			option.str(help);
			option >> time;

			empresa.addBusStop(id, 1, name, time);
			system("pause");
			op = 0;
			break;
		}
		case 3://done
		{
			int id = 0, time = 0,pos = 0;
			std::string name;
			help.clear();
			std::cout << "Line ID:";
			std::cin >> help;
			option.clear();
			option.str(help);
			option >> id;

			std::cout << "Stop Name:";
			cin.ignore();
			std::getline(std::cin, name);

			help.clear();
			std::cout << "Time To Next Stop:";
			std::cin >> help;
			option.clear();
			option.str(help);
			option >> time;

			help.clear();
			std::cout << "Position To Add In:";
			std::cin >> help;
			option.clear();
			option.str(help);
			option >> pos;

			empresa.addBusStop(id, pos, name, time);
			system("pause");
			op = 0;
			break;
		}
		case 4://change Line Frequency - done
		{
			system("cls");
			int id = 0,freq = 0;
			help.clear();
			std::cout << "Line ID:";
			std::cin >> help;
			option.clear();
			option.str(help);

			option >> id;

			help.clear();
			std::cout << "New Frequency:";
			std::cin >> help;
			option.clear();
			option.str(help);

			option >> freq;

			empresa.changeLineFrequency(id, freq);
			system("pause");
			op = 0;
			break;
		}
		case 5://List Bus Info - done
		{
			system("cls");
			int id = 0, pos = 0;
			help.clear();
			std::cout << "Line ID:";
			std::cin >> help;
			option.clear();
			option.str(help);

			option >> id;
			help.clear();
			std::cout << "Bus Order Number:";
			std::cin >> help;
			option.clear();
			option.str(help);

			option >> pos;
			Bus print = empresa.getBus(id, pos);
			std::cout << print << std::endl;;
			system("pause");
			op = 0;
			break;
		}
		case 6://done
		{
			system("cls");
			for (auto it = empresa.lines.begin(); it != empresa.lines.end(); ++it) {
				empresa.listLineInfo(it->first);
			}
			system("pause");
			op = 0;
			break;
		}
		case 7://edit stop
		{
			int id = 0,pos =0;
			string name = "";
			help.clear();
			std::cout << "Line ID:";
			std::cin >> help;
			option.clear();
			option.str(help);

			option >> id;

			help.clear();
			std::cout << "Position to Edit:";
			std::cin >> help;
			option.clear();
			option.str(help);

			option >> pos;

			std::cout << "New Stop Name:";
			cin.ignore();
			std::getline(cin, name);

			empresa.editLineStop(id, pos, name);

			op = 0;
			break;
		}
		case 8://edit time between stops
		{
			int id = 0, pos = 0, time =0;
			help.clear();
			std::cout << "Line ID:";
			std::cin >> help;
			option.clear();
			option.str(help);

			option >> id;

			help.clear();
			std::cout << "Position to Edit:";
			std::cin >> help;
			option.clear();
			option.str(help);

			option >> pos;

			help.clear();
			std::cout << "New Time Value:";
			std::cin >> help;
			option.clear();
			option.str(help);

			option >> time;

			empresa.editLineTime(id, pos, time);
			op = 0;
			break;
		}
		case 9:
		{
			string name = "";
			system("cls");
			std::cout << "Stop Name:";
			cin.ignore();
			std::getline(std::cin, name);
			auto vec = empresa.linesWithStop(name);
			for (int i = 0; i < vec.size(); ++i) {
				std::cout << vec[i] << std::endl;
			}
			system("pause");
			op = 0;
			return;
		}
		case 10:
			return;
		default:
			op = 0;
			break;
		}
	}
}

void shiftMenu(Empresa &empresa) {
	int op = 0;
	while (op == 0) {
		system("cls");
		std::cout << "-----------------------------------" << std::endl;
		std::cout << "|      Shift Menu                 |" << std::endl;
		std::cout << "-----------------------------------" << std::endl;
		std::cout << "|     1-Assign Shift              |" << std::endl;
		std::cout << "|     2-List Shifts With No Driver|" << std::endl;
		std::cout << "|     3-List All Shifts           |" << std::endl;
		std::cout << "|     4-Exit                      |" << std::endl;
		std::cout << "-----------------------------------" << std::endl;

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
			system("cls");
			int id = 0, pos = 0, dID = 0;
			help.clear();
			std::cout << "Line ID:";
			std::cin >> help;
			option.clear();
			option.str(help);

			option >> id;

			help.clear();
			std::cout << "Shift Number:";
			std::cin >> help;
			option.clear();
			option.str(help);

			option >> pos;

			help.clear();
			std::cout << "Driver ID:";
			std::cin >> help;
			option.clear();
			option.str(help);

			option >> dID;

			empresa.addDriverShift(dID, id, pos);
			system("pause");
			op = 0;
			break;
		}
		case 2:
		{
			auto vec = empresa.getPeriodsWithNoDriver();
			for (int i = 0; i < vec.size(); ++i) {
				std::cout << *vec[i] << std::endl;
			}
			system("pause");
			op = 0;
			break;
		}
		case 3:
		{
			for (auto it = empresa.lines.begin(); it != empresa.lines.end(); ++it) {
				std::vector<Shift*>shifts = it->second.getShifts();
				for (auto ite = shifts.begin(); ite != shifts.end(); ++ite) {
					std::cout << **ite << std::endl;
				}
			}
			system("pause");
			op = 0;
			break;
		}
		case 4:
			return;
		default:
			op = 0;
			break;
		}

	}
}

void routeCalculator(Empresa& empresa) {
	system("cls");
	cout << "Starting Point:";
	string start = "";
	cin.ignore();
	getline(cin, start);
	cin.clear();
	cout << "Ending Point:";
	string end = "";
	getline(cin, end);

	vector<string>check = empresa.getRoute(start, end);

	if (check.size() == 0) {
		printf("Unable To Find Route\n");
		system("pause");
		return;
	}

	for (int i = 0; i < check.size(); ++i) {
		cout << check[i] << endl;
	}
	system("pause");
	return;
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
			shiftMenu(em);
			op = 0;
			break;
		}
		case 4:
		{
			routeCalculator(em);
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
