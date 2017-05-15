#include "Driver.h"
#include <iostream>

Driver::Driver(string name, unsigned int id, unsigned int maxHours, unsigned int maxWeekWorkingTime, unsigned int minRestTime){
	this->id = id;
	this->maxHours = maxHours;
	this->maxWeekWorkingTime = maxWeekWorkingTime;
	this->minRestTime = minRestTime;
	this->name = name;
}

//////////////
// get methods
//////////////

unsigned int Driver::getId() const{
  return id;
}

string Driver::getName() const{
  return this->name;
}

unsigned int Driver::getShiftMaxDuration() const{
  return maxHours;
}

unsigned int Driver::getMaxWeekWorkingTime() const{
  return maxWeekWorkingTime;
}

unsigned int Driver::getMinRestTime() const{
  return minRestTime;
}

vector<Shift> Driver::getShifts(){
  return shifts;
}

void Driver::setName(std::string name)
{
	this->name = name;
}

void Driver::setMaxHoursPerShift(unsigned int time)
{
	this->maxHours = time;
}

void Driver::setMaxHoursPerWeek(unsigned int time)
{
	this->maxWeekWorkingTime = time;
}

void Driver::setRestTimeBetweenShifts(unsigned int time)
{
	this->minRestTime = time;
}

void Driver::assignShift(Shift* shift)
{
	unsigned int delta = 0;
	delta = shift->getEndTime() - shift->getStartTime();
	printf("delta:%d\n", delta);
	if (delta > this->maxHours*60) {
		printf("This Shift Is Too Long For this Driver\n");
		return;
	}
	if (currentWeekTime + delta > this->maxWeekWorkingTime*60) {
		printf("With This Shift the Driver Would Go over the Max Hours per Week He Can Work For\n");
		return;
	}
	for (std::vector<Shift>::iterator it = this->shifts.begin();it != this->shifts.end();++it) {
		if (it->getEndTime() >= shift->getStartTime()) {
			if (((it)->getEndTime() - shift->getStartTime()) < this->minRestTime * 60) {
				printf("This Shift Doesnt Allow The Driver To Rest Properly Between Shift\n");
				return;
			}
		}
	}
	shift->setDriverId(this->id);
	this->currentWeekTime += delta;
	this->shifts.push_back(*shift);
}

void Driver::listWork()const {
	std::cout << "Driver ID:" << this->getId() << std::endl;
	std::cout << "\tWork:" << std::endl;
	for (std::vector<Shift>::const_iterator it = this->shifts.begin();it != this->shifts.end();++it) {
		std::cout << "\t" << *it << std::endl;
	}
	return;
}

bool Driver::isDriverFull() const
{
	if (this->currentWeekTime == this->maxWeekWorkingTime) {
		return true;
	}
	return false;
}

ostream & operator<<(ostream & os, const Driver & driver)
{
	os << "Driver ID:" << driver.getId()<<'\n';
	os << "\t Driver Name:" << driver.getName()<<'\n';
	os << "\t Driver Max Work Time Per Shift:" << driver.getShiftMaxDuration() << '\n';
	os << "\t Driver Max Work Time Per Week:" << driver.getMaxWeekWorkingTime() << '\n';
	os << "\t Driver Min Rest Time Between Shifts:" << driver.getMinRestTime() << '\n';
	return os;
}
