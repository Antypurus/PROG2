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
  // get methods
  unsigned int getId() const;
  vector<string> getBusStops() const;
  vector<int> getTimings() const;
  int getFreq()const;
  // set methods
  void setFreq(int freq);
  void addBusStop(string stop);
  void addTimeListEntry(int time);
  // other methods
private:
	unsigned int calcTraverTime()const;//returns the time for a full loop of the line
	unsigned int calculateNeededBuses();//calculates the needed ammount of buses for this line

  friend ostream& operator<<(ostream& os, const Line& line);

};
