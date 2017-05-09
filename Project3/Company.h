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
  string nome;
public:
  vector<Driver> condutores;
  vector<Line> linhas;

  std::unordered_map<unsigned int, Driver>drivers;
  std::unordered_map<unsigned int, Line>lines;

 public:
	 Empresa(string nome,string ficheiro_drivers,string ficheiro_linhas);
  // get methods
  string getNome() const;
  // set Methods
private:
  void loadAllDrivers(string filename);
  void loadAllLines(string filename);
public:
  // other methods
  void distribuiServico();
  void addDriver(Driver driver);
};
