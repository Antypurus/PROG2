#include "Company.h"
#include <fstream>
#include <sstream>
#include "Line.h"
#include "Driver.h"
#include <thread>
#include "Shift.h"

Empresa::Empresa(string nome, string ficheiro_drivers, string ficheiro_linhas){
	this->nome = nome;
	this->fileFile = ficheiro_linhas;
	this->driverFile = ficheiro_drivers;
	std::thread ld(&Empresa::loadAllDrivers,this,ficheiro_drivers);
	std::thread ll(&Empresa::loadAllLines, this,ficheiro_linhas);
	ll.join();
	ld.join();
}

Empresa::~Empresa()
{
	if (this->shouldUpdate) {
		printf("Beggining Saving Required Files\n");
		this->saveAllDrivers();
		this->saveAllLines();
		printf("File Saving Sequence Finished \n");
		this->shouldUpdate = false;
	}
	else {
		printf("Exiting , no files required saving\n");
		return;
	}
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

void Empresa::saveAllDrivers()
{
	std::ofstream file(this->driverFile);
	static Driver help;
	if (file.is_open()) {
		for (auto it = this->drivers.begin();it != this->drivers.end();++it) {
			help = it->second;
			file << help.getId() << ";";
			file << help.getName() << ";";
			file << help.getShiftMaxDuration() << ";";
			file << help.getMaxWeekWorkingTime() << ";";
			file << help.getMinRestTime() << "\n";
		}
	}
	else {
		printf("Error Opening File , Information Failed to Be Saved\n");
		file.close();
		return;
	}
	file.close();
	return;
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
			toAdd.finalize();
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

void Empresa::saveAllLines()//NEed to Fix This ASAP
{
	ofstream file(this->fileFile);
	if (file.is_open()) {
		std::unordered_map<unsigned int, Line>lines = this->lines;
		for (auto it = lines.begin();it != lines.end();++it) {
			Line help = it->second;
			file << help.getId() << " ; ";
			file << help.getFreq() << " ; ";
			for (unsigned int i = 0;i < (help.getBusStops().size()-1);++i) {
				file << help.getBusStops()[i] << " , ";
			}
			file << help.getBusStops()[help.getBusStops().size() - 1] << " ; ";
			for (unsigned int i = 0;i < (help.getTimings().size() - 1);++i) {
				file << help.getTimings()[i] << " , ";
			}
			file << help.getTimings()[help.getTimings().size() - 1];
			file << '\n';
		}
	}
	else {
		printf("Failed To Open File Line Information Will Not Be Saved\n");
		file.close();
		return;
	}
	file.close();
	return;
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
	this->setShouldUpdate();
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
	this->setShouldUpdate();
	return;
}

void Empresa::changeDriverName(const unsigned int id, const std::string name) {
	if (!this->doesDriverExist(id)) {
		printf("There is no driver with this id\n");
		return;
	}
	this->drivers[id].setName(name);
	this->setShouldUpdate();
	return;
}

void Empresa::changeDriverMaxHourShift(const unsigned int id, const unsigned int maxHours)
{
	if (!this->doesDriverExist(id)) {
		printf("There is no driver with this id\n");
		return;
	}
	this->drivers[id].setMaxHoursPerShift(maxHours);
	this->setShouldUpdate();
	return;
}

void Empresa::changeDriverMaxHoursWeek(const unsigned int id, const unsigned int maxHours)
{
	if (!this->doesDriverExist(id)) {
		printf("There is no driver with this id\n");
		return;
	}
	this->drivers[id].setMaxHoursPerWeek(maxHours);
	this->setShouldUpdate();
	return;
}

void Empresa::changeDriverMinRestTime(const unsigned int id, const unsigned int minHours)
{
	if (!this->doesDriverExist(id)) {
		printf("There is no driver with this id\n");
		return;
	}
	this->drivers[id].setRestTimeBetweenShifts(minHours);
	this->setShouldUpdate();
	return;
}

void Empresa::addDriverShift(const unsigned int id,const unsigned int lineID, const unsigned int shiftNumber)
{
	if (!this->doesDriverExist(id)) {
		printf("There is no driver with this id\n");
		return;
	}

	if (!this->doesLineExist(lineID)) {
		printf("There is no line with this ID\n");
		return;
	}
	
	std::vector<Shift*> shifts = this->lines[lineID].getShifts();
	if (shiftNumber < 0 || shiftNumber >= shifts.size()) {
		printf("This shift does not exist\n");
		return;
	}
	this->drivers[id].assignShift(shifts[shiftNumber]);

	return;
}

std::vector<Driver> Empresa::getNotFullDrivers() const
{
	std::vector<Driver>ret;
	for (auto it = this->drivers.begin(); it != this->drivers.end(); ++it) {
		if (!it->second.isDriverFull()) {
			ret.push_back(it->second);
		}
	}
	return ret;
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

void Empresa::addBusStop(const unsigned int lineID, const std::string &stop, const unsigned int timeLastStop)
{
	if (!this->doesLineExist(lineID)) {
		printf("There is no line with this ID\n");
		return;
	}
	this->lines[lineID].addBusStop(stop);
	this->lines[lineID].addTimeListEntry(timeLastStop);
	this->setShouldUpdate();
	return;
}

void Empresa::addBusStop(const unsigned int lineID, const unsigned int pos, const std::string & stop, const unsigned int timeLastStop)
{
	if (!this->doesLineExist(lineID)) {
		printf("There is no line with this ID\n");
		return;
	}
	if (pos <= 0||pos>this->lines[lineID].getBusStops().size()) {
		printf("This Position In The List Does Not Exist\n");
		return;
	}
	if (pos == 1) {
		this->lines[lineID].getBusStops().insert(this->lines[lineID].getBusStops().begin(), stop);
		this->lines[lineID].getTimings().insert(this->lines[lineID].getTimings().begin(), timeLastStop);
		this->setShouldUpdate();
		return;
	}
	else {
		this->lines[lineID].getBusStops().insert(this->lines[lineID].getBusStops().begin() + (pos - 1), stop);
		this->lines[lineID].getTimings().insert(this->lines[lineID].getTimings().begin() + (pos - 1), timeLastStop);
		this->setShouldUpdate();
		return;
	}
	return;
}

void Empresa::editLineTime(const unsigned int lineID, const unsigned int pos, const unsigned int newTime)
{
	if (!this->doesLineExist(lineID)) {
		printf("There is no line with this ID\n");
		return;
	}
	if (pos<=0 || pos>this->lines[lineID].getTimings().size()) {
		printf("This position in the list does not exist\n");
		return;
	}
	if (newTime <= 0) {
		printf("This Time value Is Not Valid\n");
		return;
	}
	this->lines[lineID].getTimings()[pos - 1] = newTime;
	this->setShouldUpdate();
	return;
}

void Empresa::editLineStop(const unsigned int lineID, const unsigned int pos, const std::string stop)
{
	if (!this->doesLineExist(lineID)) {
		printf("There is no line with this ID\n");
		return;
	}
	if (this->lines[lineID].hasStop(stop)) {
		printf("This Stop Already Exists in the line\n");
		return;
	}
	if (pos <= 0 || pos>this->lines[lineID].getBusStops().size()) {
		printf("This position in the list does not exist\n");
		return;
	}
	this->lines[lineID].getBusStops()[pos - 1] = stop;
	this->setShouldUpdate();
	return;
}

void Empresa::changeLineFrequency(const unsigned int lineID, const unsigned int freq)
{
	if (!this->doesLineExist(lineID)) {
		printf("There is no line with this ID\n");
		return;
	}
	if (freq <= 0) {
		printf("This frequency value is not valid\n");
		return;
	}
	this->lines[lineID].setFreq(freq);
	this->setShouldUpdate();
	return;
}

std::vector<Line> Empresa::linesWithStop(std::string stop)
{
	std::vector<Line>ret;
	std::vector<std::string>help;
	for (auto it = this->lines.begin(); it != this->lines.end(); ++it) {
		help = it->second.getBusStops();
		for (auto ite = help.begin(); ite != help.end(); ++ite) {
			if ((*ite) == stop) {
				ret.push_back(it->second);
			}
		}
	}
	return ret;
}

std::vector<Shift*> Empresa::getPeriodsWithNoDriver() const
{
	std::vector<Shift*>shifts;
	//this is a const method , const iterators should be used
	//we used auto because the standard not only recomends its
	//usage but writhing auto it much faster than writhings
	//unordered_map<unsigned itn,Line>::const_iterator
	for (auto it = this->lines.begin();it != this->lines.end();++it) {
		for (auto ite = it->second.getShifts().begin();ite != it->second.getShifts().end();++ite) {
			if ((*ite)->getDriverId() == 0) {
				shifts.push_back(*ite);
			}
		}
	}
	return shifts;
}

unsigned int Empresa::busesInALine(const unsigned int lineId) 
{
	unsigned int counter = 0;
	if (!this->doesLineExist(lineId)) {
		printf("There is no line with this id\n");
		return counter;
	}
	counter = this->lines[lineId].getBuses().size();
	return counter;
}

Bus Empresa::getBus(const unsigned int lineId, const unsigned int busNumber)
{
	Bus bus;
	if (!this->doesLineExist(lineId)) {
		printf("There is no line with this id\n");
		return bus;
	}
	if (busNumber < 0 || busNumber >= this->lines[lineId].getBuses().size()) {
		printf("There is no bus in this line with that nus number\n");
		return bus;
	}
	bus = this->lines[lineId].getBuses()[busNumber];
	return bus;
}

bool Empresa::containStartAndFinish(const unsigned int lineID, const std::string start, const std::string end) const
{
	if (start == end) {
		printf("The Start Must Not Be The Same As The End\n");
		return false;
	}

	if (!this->doesLineExist(lineID)) {
		printf("There is no line with this id\n");
		return false;
	}

	bool hasStart = false;
	bool hasEnd = false;

	std::vector<std::string>check = this->lines.at(lineID).getBusStops();

	for (std::vector<std::string>::const_iterator it = check.begin();it != check.end();++it) {
		if (*it == start) {
			hasStart = true;
		}
		if (*it == end) {
			hasEnd = true;
		}
	}

	return (hasEnd && hasStart);
}

bool Empresa::containStartAndFinish(const unsigned int lineID1, const unsigned int lineID2, const std::string start, const std::string end) const
{
	if (start == end) {
		printf("The Start Must Not Be The Same As The End\n");
		return false;
	}

	if (!this->doesLineExist(lineID1)) {
		printf("There is no line with this id:%u\n",lineID1);
		return false;
	}

	if (!this->doesLineExist(lineID2)) {
		printf("There is no line with this id:%u\n",lineID2);
		return false;
	}

	bool hasStart = false;
	bool hasEnd = false;

	std::vector<std::string>v1 = this->lines.at(lineID1).getBusStops();
	std::vector<std::string>v2 = this->lines.at(lineID2).getBusStops();

	for (std::vector<std::string>::const_iterator it = v1.begin();it != v1.end();++it) {
		if (*it == start) {
			hasStart = true;
			break;
		}
		if (*it == end) {
			hasEnd = true;
			break;
		}
	}

	for (std::vector<std::string>::const_iterator it = v2.begin();it != v2.end();++it) {
		if (*it == start) {
			hasStart = true;
			break;
		}
		if (*it == end) {
			hasEnd = true;
			break;
		}
	}

	return (hasStart && hasEnd);
}

bool Empresa::hasSharedStop(const unsigned int lineID1, const unsigned int lineID2,std::string &res) const
{
	bool hasShared = false;

	if (!this->doesLineExist(lineID1)) {
		printf("There is no line with this id:%u\n", lineID1);
		return false;
	}

	if (!this->doesLineExist(lineID2)) {
		printf("There is no line with this id:%u\n", lineID2);
		return false;
	}

	std::vector < std::string > v1 = this->lines.at(lineID1).getBusStops();
	std::vector < std::string > v2 = this->lines.at(lineID2).getBusStops();

	for (auto it = v1.begin();it != v1.end();++it) {
		for (auto ite = v2.begin();it != v2.end();++ite) {
			if (*ite == *it) {
				res = *it;
				return true;
			}
		}
	}

	return hasShared;
}

int Empresa::isBefore(const unsigned int lineID, const std::string ref,const std::string dest) const
{
	if (!this->doesLineExist(lineID)) {
		printf("There is no line with this id:%u\n", lineID);
		return -1;
	}
	std::vector<std::string> check = this->lines.at(lineID).getBusStops();
	int found = 0;
	for (int i = 0;i < check.size();++i) {
		if (check[i] == ref) {
			found = i;
			break;
		}
	}

	for (int i = found;i >= 0;--i) {
		if (check[i]==dest) {
			return i;
		}
	}

	return -1;
}

int Empresa::isAfter(const unsigned int lineID, const std::string ref, const std::string dest) const
{
	if (!this->doesLineExist(lineID)) {
		printf("There is no line with this id:%u\n", lineID);
		return -1;
	}
	std::vector<std::string> check = this->lines.at(lineID).getBusStops();
	int found = 0;
	for (int i = 0;i < check.size();++i) {
		if (check[i] == ref) {
			found = i;
			break;
		}
	}

	for (int i = found;i <check.size();++i) {
		if (check[i] == dest) {
			return i;
		}
	}

	return -1;
}

std::vector<std::string> Empresa::getRoute(const std::string start, const std::string end) const
{
	std::vector<std::string>send;
	for (auto it = this->lines.begin();it != this->lines.end();++it) {
		if (this->containStartAndFinish(it->first, start, end)) {
			send.push_back(("Line:" + it->first));
		}

		for (auto ite = this->lines.begin();ite != this->lines.end();++ite) {
			if (it->first != ite->first) {
				std::string ref;
				if (this->hasSharedStop(it->first, ite->first,ref)) {
					if (this->containStartAndFinish(it->first, ite->first, start, end)) {
						std::string send_ = "Line:" + it->first;
						send_ = send_ + " Line:";
						send_ = send_ + to_string(ite->first);
						send.push_back((send_));
					}
				}

			}
		}

	}
	return send;
}
