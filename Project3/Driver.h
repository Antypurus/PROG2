#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Shift.h"


using namespace std;

class Driver{
 private:
  unsigned int id;
  string name;
  unsigned int maxHours;        // maximum duration of a shift
  unsigned int maxWeekWorkingTime;  // maximum number of hours of work in a week
  unsigned int minRestTime;     // minimum number of rest hours between shifts
  unsigned int currentWeekTime = 0;
  vector<Shift> shifts;         // assigned shifts
 public:
  Driver(string name, unsigned int id, unsigned int maxHours, unsigned int maxWeekWorkingTime, unsigned int minRestTime);
  Driver() {}
  unsigned int getId() const;
  string getName() const;
  unsigned int getShiftMaxDuration() const;
  unsigned int getMaxWeekWorkingTime() const;
  unsigned int getMinRestTime() const;
  vector<Shift> getShifts();

  void setName(std::string name);
  void setMaxHoursPerShift(unsigned int time);
  void setMaxHoursPerWeek(unsigned int time);
  void setRestTimeBetweenShifts(unsigned int time);

  void assignShift(Shift* shift);
  void listWork()const;

  bool isDriverFull()const;

  friend ostream& operator<<(ostream &os, const Driver &driver);


};
