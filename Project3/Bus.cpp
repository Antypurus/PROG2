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
