#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "Bus.h"

class Line;
class Driver;
class Shift;

using namespace std;

class Empresa{
private:
	bool shouldUpdate = false;
	string nome;
	std::string driverFile = "";
	std::string fileFile = "";
public:
	vector<Driver> condutores;
	vector<Line> linhas;

	std::unordered_map<unsigned int, Driver>drivers;
	std::unordered_map<unsigned int, Line>lines;
	
 public:
	 Empresa(string nome, string ficheiro_drivers, string ficheiro_linhas);
	 ~Empresa();
	 // get methods
	 string getNome() const;
	// set Methods
private:
	void loadAllDrivers(string filename);
	void saveAllDrivers();
	void loadAllLines(string filename);
	void saveAllLines();
	bool doesDriverExist(const unsigned int id)const;
	bool doesLineExist(const unsigned int id)const;
	void setShouldUpdate() { this->shouldUpdate = true; }
public:
	// other methods
	void distribuiServico();
	//methods for chanings details with the drivers
	void addDriver(const Driver &driver);
	void removeDriver(const unsigned int  id);
	void changeDriverName(const unsigned int id, const std::string name);
	void changeDriverMaxHourShift(const unsigned int id, const unsigned int maxHours);
	void changeDriverMaxHoursWeek(const unsigned int id, const unsigned int maxHours);
	void changeDriverMinRestTime(const unsigned int id, const unsigned int minHours);
	void addDriverShift(const unsigned int id, const unsigned int lineID, const unsigned int shiftNumber);
	std::vector<Driver> getNotFullDrivers()const;
	//void changeDriverID(const unsigned int initId, const unsigned int afterID);
	void listDriverWork(const unsigned int id)const;
	//Line Related methods
	void listLineInfo(const unsigned int id)const;
	void addBusStop(const unsigned int lineID, const std::string &stop, const unsigned int timeLastStop);
	void addBusStop(const unsigned int lineID, const unsigned int pos, const std::string &stop, const unsigned int timeLastStop);
	void editLineTime(const unsigned int lineID, const unsigned int pos, const unsigned int newTime);
	void editLineStop(const unsigned int lineID, const unsigned int pos, const std::string stop);
	void changeLineFrequency(const unsigned int lineID, const unsigned int freq);
	std::vector<Line> linesWithStop(std::string stop);

	std::vector<Shift*> getPeriodsWithNoDriver()const;
	unsigned int busesInALine(const unsigned int lineId);
	Bus getBus(const unsigned int lineId, const unsigned int busNumber);

private:
	bool containStartAndFinish(const unsigned int lineID, const std::string start, const std::string end)const;
	bool containStartAndFinish(const unsigned int lineID1, const unsigned int lineID2, const std::string start, const std::string end)const;
	bool hasSharedStop(const unsigned int lineID1,const unsigned int lineID2,std::string &res)const;
	int isBefore(const unsigned int lineID, const std::string ref, const std::string dest)const;
	int isAfter(const unsigned int lineID, const std::string ref, const std::string dest)const;

public:
	std::vector<std::string> getRoute(const std::string start, const std::string end)const;
};
