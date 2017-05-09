#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class Line;
class Driver;


using namespace std;

class Empresa{
private:
	bool shouldUpdate = false;
	string nome;
public:
	vector<Driver> condutores;
	vector<Line> linhas;

	std::unordered_map<unsigned int, Driver>drivers;
	std::unordered_map<unsigned int, Line>lines;

 public:
	 Empresa(string nome, string ficheiro_drivers, string ficheiro_linhas);
  // get methods
	 string getNome() const;
  // set Methods
private:
	void loadAllDrivers(string filename);
	void loadAllLines(string filename);
	bool doesDriverExist(const unsigned int id);
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
};
