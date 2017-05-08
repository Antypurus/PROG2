#include "Line.h"


Line::Line(unsigned int id){
	this->id = id;
}

////////////////
// get methods
////////////////

unsigned int Line::getId() const{
  return id;
}

vector<string> Line::getBusStops() const{
  return busStopList;
}

vector<int> Line::getTimings() const{
  return timesList;
}

int Line::getFreq()const {
	return this->frequencia;
}

//set methods//

void Line::addBusStop(string stop) {
	this->busStopList.push_back(stop);
}

void Line::addTimeListEntry(int time) {
	this->timesList.push_back(time);
}

void Line::setFreq(int freq) {
	this->frequencia = freq;
}

ostream& operator<<(ostream& os, const Line& line) {
	os <<"Line ID:"<< line.getId()<<":"<<std::endl;
	os << "\tFrequencia:" << line.getFreq() << std::endl;
	std::vector<int>::iterator ite = line.getTimings().begin();
	os << "\tPercurso:\n\t";
	for (int it = 0; it < line.getBusStops().size();++it) {
		os << line.getBusStops()[it];
		if (ite != line.getTimings().end()) {
			os << " - " << *ite << " min - ";
			ite++;
		}
	}
	return os;
}
