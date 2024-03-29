#include "Shift.h"
#include "Bus.h"

Shift::Shift(unsigned int busLineId, unsigned int driverId, unsigned int busNumber, unsigned int startTime, unsigned int endTime){
	this->busLineId = busLineId;
	this->driverId = driverId;
	this->busOrderNumber = busNumber;
	this->startTime = startTime;
	this->endTime = endTime;
}

// methods get
unsigned int Shift::getBusLineId() const{
  return busLineId;
}

unsigned int Shift::getDriverId() const{
  return driverId;
}
unsigned int Shift::getBusOrderNumber() const{
  return busOrderNumber;
}

unsigned int Shift::getStartTime() const{
  return startTime;
}

unsigned int Shift::getEndTime() const{
  return endTime;
}

void Shift::assignBus(Bus * bus)
{
	this->bus = bus;
	bus->schedule.push_back(this);
}

///////////////
// set methods
//////////////

unsigned int Shift::setBusLineId(unsigned int busLineId){
  this->busLineId = busLineId;
  return 0;
}

unsigned int Shift::setDriverId(unsigned int driverId){
  this->driverId = driverId;
  return 0;
}

unsigned int Shift::setBusOrderNumber(unsigned int busOrderNumber){
  this->busOrderNumber = busOrderNumber;
  return 0;
}

unsigned int Shift::setStartTime(unsigned int startTime){
  this->startTime = startTime;
  return 0;
}

unsigned int Shift::setEndTime(unsigned int endTime){
  this->endTime = endTime;
  return 0;
}

ostream & operator<<(ostream &os, const Shift shift)
{
	os << "Line ID:" << shift.getBusLineId();
	os << " Bus ID:" << shift.getBusOrderNumber();
	os << " Shift start Time:" << shift.getStartTime();
	os << " Shift End Time:" << shift.getEndTime();
	return os;
}
