#pragma once

#include <iostream>
#include <string>
#include <vector>



using namespace std;

class Line{
 private:
  unsigned int id;
  vector<string> busStopList;
  vector<int> timesList;
  int frequencia;
  unsigned int nAutocarros;
 public:
  Line(unsigned int id);
  Line() { this->id = 0; }
  // get methods
  unsigned int getId() const;
  vector<string> getBusStops() const;
  vector<int> getTimings() const;
  int getFreq()const;
  // set methods
  void setFreq(int freq);
  void addBusStop(string stop);
  void addTimeListEntry(int time);
  bool hasStop(const std::string stop)const;
  // other methods
  int operator+(const Line &line);//return the number of shared stops
private:
	unsigned int calcTraverTime()const;//returns the time for a full loop of the line
	unsigned int calculateNeededBuses();//calculates the needed ammount of buses for this line

  friend ostream& operator<<(ostream& os, const Line& line);

};
