#include "Bus.h"


Bus::  Bus(unsigned int id, unsigned int driver, unsigned int line){
	this->driverId = driver;
	this->lineId = id;
	this->orderInLine = line;
}

////////////////////////////////
// get methods
///////////////////////////////
unsigned int Bus::getBusOrderInLine() const{
  return orderInLine;
}

unsigned int Bus::getDriverId() const{
  return driverId;
}

unsigned int Bus::getLineId() const{
  return lineId;
}

vector<Shift*> Bus::getSchedule() const{
  return schedule;
}


//////////////////////////////
// methods set
/////////////////////////////

unsigned int Bus::setDriverId(int ID){
	this->driverId = ID;
	return this->driverId;
}

unsigned int Bus::setLineId(int ID) {
	this->lineId = ID;
	return this->lineId;
}

////////////////////////////
// other methods
///////////////////////////

ostream & operator<<(ostream & os, const Bus & bus)
{
	os << "Line ID:" << bus.getLineId() << '\n';
	os << "Bus Order In Line:" << bus.getBusOrderInLine()<<'\n';
	os << "Bus Shifts:" << '\n';
	for (int i = 0; i < bus.getSchedule().size(); ++i) {
		os << "\t Shift Start Time:" << bus.getSchedule()[i]->getStartTime() << '\n';
		os << "\t Shift End Time:" << bus.getSchedule()[i]->getEndTime() << '\n'<<'\n';
	}
	os << '\n';
	return os;
}
