#include "Company.h"
#include <fstream>
#include <sstream>
#include "Line.h"
#include "Driver.h"
#include <thread>
#include "Shift.h"

Empresa::Empresa(string nome, string ficheiro_drivers, string ficheiro_linhas){
	this->nome = nome;
	std::thread ld(&Empresa::loadAllDrivers,this,ficheiro_drivers);
	std::thread ll(&Empresa::loadAllLines, this,ficheiro_linhas);

	ll.join();
	ld.join();
}

////////////////////////////////
// get methods
///////////////////////////////

string Empresa::getNome() const{
  return nome;
}

//////////////////////////////
// set methods
/////////////////////////////

void Empresa::loadAllDrivers(string filename) {
	std::ifstream file(filename);
	std::string help;
	if (file.is_open()) {
		while (std::getline(file, help)) {
			size_t id = 0;
			std::string name;
			int HorasMaxPorDia = 0, HorasMaxPorSemana = 0, HorasDescanso = 0;

			static std::istringstream ss;
			ss.str(help);
			static std::istringstream sh;
			sh.clear();

			std::getline(ss, help, ';');//parse the id
			sh.str(help);
			sh >> id;
			sh.clear();

			std::getline(ss, name, ';');//parse the name
										//std::cout << "Name:" << name << std::endl;

			std::getline(ss, help, ';');//parse the max amount of hours per day
			sh.str(help);
			sh >> HorasMaxPorDia;
			sh.clear();
			//std::cout << "HorasMaxPorDia:" << HorasMaxPorDia << std::endl;

			std::getline(ss, help, ';');//parse the max amount of hours per week
			sh.str(help);
			sh >> HorasMaxPorSemana;
			sh.clear();
			//std::cout << "HorasMaxPorSemana:" << HorasMaxPorSemana << std::endl;

			std::getline(ss, help);//parse the amount of time of rest
			sh.str(help);
			sh >> HorasDescanso;
			sh.clear();
			//std::cout << "HorasDescanso:" << HorasDescanso << std::endl;

			this->condutores.push_back(Driver(name,id,HorasMaxPorDia,HorasMaxPorSemana,HorasDescanso));
			this->drivers.insert(std::make_pair(id, Driver(name, id, HorasMaxPorDia, HorasMaxPorSemana, HorasDescanso)));
			help.clear();
			name.clear();
			ss.clear();
		}
		std::cout << "@DriverParser:Finished Parsing Drivers" << std::endl;
	}
	else {
		std::cout << "Could Not Open This File: " <<filename<<"!"<<std::endl;
	}
	file.close();
}

void Empresa::loadAllLines(string filename) {
	std::ifstream file(filename);
	std::string fullLine;
	if (file.is_open()) {
		while (std::getline(file, fullLine)) {
			int ID;
			//std::cout << fullLine << std::endl;

			static std::istringstream parserHelp;
			parserHelp.clear();
			parserHelp.str(fullLine);
			static std::istringstream toParse;
			toParse.clear();

			std::getline(parserHelp, fullLine, ';');//parse the id
			toParse.str(fullLine);
			toParse >> ID;
			Line toAdd(ID);
			//std::cout << toAdd.ID << std::endl;
			toParse.clear();

			std::getline(parserHelp, fullLine, ';');//parse the frequency
			int freq;
			toParse.str(fullLine);
			toParse >> freq;
			toAdd.setFreq(freq);
			//std::cout << toAdd.freq << std::endl;
			toParse.clear();

			std::getline(parserHelp, fullLine, ';');//parse the stop points
			toParse.str(fullLine);
			fullLine.clear();

			while (std::getline(toParse, fullLine, ',')) {
				//std::cout << fullLine << std::endl;
				toAdd.addBusStop(fullLine);
				fullLine.clear();
			}
			toParse.clear();

			std::getline(parserHelp, fullLine);//parse the time between stop points
			toParse.str(fullLine);
			fullLine.clear();

			while (std::getline(toParse, fullLine, ',')) {
				static std::istringstream help2;
				help2.clear();
				help2.str(fullLine);
				int i = 0;
				help2 >> i;
				//std::cout << i << std::endl;
				toAdd.addTimeListEntry(i);
				help2.clear();
			}
			toParse.clear();
			this->linhas.push_back(toAdd);
			this->lines.insert(std::make_pair(ID, toAdd));
		}
		std::cout << "\n@LineParse:Finished Parsing Lines" << std::endl;
	}
	else {
		std::cout << "Could Not Open the File" << std::endl;
	}
	file.close();
}

bool Empresa::doesDriverExist(const unsigned int id)const
{
	unsigned int c = this->drivers.count(id);
	if (c != 0) {
		return true;
	}
	return false;
}

bool Empresa::doesLineExist(const unsigned int id) const
{
	if (lines.count(id)!=0){
		return true;
	}
	return false;
}


////////////////////////////
// other methods
///////////////////////////
void Empresa::distribuiServico(){
	//TODO
}

void Empresa::addDriver(const Driver &driver)
{
	int c = this->drivers.count(driver.getId());
	if (c != 0) {
		printf("There is already a driver with this id\n");
		return;
	}
	this->drivers.insert(std::make_pair(driver.getId(), driver));
	return;
}

void Empresa::removeDriver(const unsigned int id)
{
	int c = this->drivers.count(id);
	if (c == 0) {
		printf("There is no driver with this id\n");
		return;
	}
	auto iterator = this->drivers.find(id);
	this->drivers.erase(iterator);
	return;
}

void Empresa::changeDriverName(const unsigned int id, const std::string name) {
	if (!this->doesDriverExist(id)) {
		printf("There is no driver with this id\n");
		return;
	}
	this->drivers[id].setName(name);
	return;
}

void Empresa::changeDriverMaxHourShift(const unsigned int id, const unsigned int maxHours)
{
	if (!this->doesDriverExist(id)) {
		printf("There is no driver with this id\n");
		return;
	}
	this->drivers[id].setMaxHoursPerShift(id);
	return;
}

void Empresa::changeDriverMaxHoursWeek(const unsigned int id, const unsigned int maxHours)
{
	if (!this->doesDriverExist(id)) {
		printf("There is no driver with this id\n");
		return;
	}
	this->drivers[id].setMaxHoursPerWeek(maxHours);
	return;
}

void Empresa::changeDriverMinRestTime(const unsigned int id, const unsigned int minHours)
{
	if (!this->doesDriverExist(id)) {
		printf("There is no driver with this id\n");
		return;
	}
	this->drivers[id].setRestTimeBetweenShifts(minHours);
	return;
}

void Empresa::addDriverShift(const unsigned int id, const Shift &shift)
{
	if (!this->doesDriverExist(id)) {
		printf("There is no driver with this id\n");
		return;
	}
	this->drivers[id].assignShift(shift);
	return;
}
/*
void Empresa::changeDriverID(const unsigned int initId, const unsigned int afterID)
{
	if (!this->doesDriverExist(initId)) {
		printf("There is no driver with this id\n");
		return;
	}
	if (this->doesDriverExist(afterID)) {
		printf("There is already a driver with the id you want to change this driver to"\n);
		return;
	}
	Driver driver = this->drivers[initId];
}*/

void Empresa::listDriverWork(const unsigned int id) const
{
	if (!(this->doesDriverExist(id))) {
		printf("There is no drier with this id\n");
		return;
	}
	this->drivers.at(id).listWork();
	return;
}

void Empresa::listLineInfo(const unsigned int id) const
{
	if (!this->doesLineExist(id)) {
		printf("There is no line with this id\n");
		return;
	}
	std::cout << this->lines.at(id) << std::endl;
}

std::vector<Line> Empresa::linesWithStop(std::string stop)
{
	return std::vector<Line>();
}
