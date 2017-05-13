#pragma once

#include <iostream>
#include <vector>

#include "Shift.h"


using namespace std;

class Bus{
 private:
  unsigned int orderInLine;
  unsigned int driverId;
  unsigned int lineId;
  vector<Shift*> schedule;
 public:
  Bus(unsigned int id, unsigned int driver, unsigned int line);
  Bus() :orderInLine(0), driverId(0), lineId(0) {}
  // get methods
  unsigned int getBusOrderInLine() const;
  unsigned int getDriverId() const;
  unsigned int getLineId() const;
  vector<Shift*> getSchedule() const;
  void addShift(Shift* shift) {
	  this->schedule.push_back(shift);
  }
  // set methods
    unsigned int setDriverId(int ID);
    unsigned int setLineId(int ID);
  // other methods

};
