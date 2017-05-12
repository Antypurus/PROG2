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
	this->calculateNeededBuses();
}

void Line::addTimeListEntry(int time) {
	this->timesList.push_back(time);
	this->calculateNeededBuses();
}

int Line::operator+(const Line & line)
{
	int counter = 0;
	std::vector<std::string>comStr = line.getBusStops();
	for (auto it = comStr.begin(); it != comStr.end(); ++it) {
		for (auto ite = this->busStopList.begin(); ite != this->busStopList.end(); ++ite) {
			if (*ite == *it) {
				++counter;
			}
		}
	}
	return counter;
}

unsigned int Line::calcTraverTime() const
{
	unsigned int counter = 0;
	for (std::vector<int>::const_iterator it = this->timesList.begin(); it != this->timesList.end(); ++it) {
		counter += *it;
	}
	return counter * 2;
}

unsigned int Line::calculateNeededBuses()
{
	this->nAutocarros = (((double)(calcTraverTime()) / this->frequencia) + 1);
	return nAutocarros;
}

void Line::setFreq(int freq) {
	this->frequencia = freq;
}

ostream& operator<<(ostream& os, const Line& line) {
	os <<"Line ID:"<< line.getId()<<":"<<std::endl;
	os << "\tFrequencia:" << line.getFreq() << std::endl;
	os << "\tPercurso:\n\t";

	std::vector<std::string>places = line.getBusStops();
	std::vector<int>times = line.getTimings();

	std::vector<int>::iterator ite = times.begin();

	for (std::vector<std::string>::iterator it = places.begin();it != places.end();++it) {
		os << *it;
		if (ite != times.end()) {
			os << " - " << *ite << "min - ";
			++ite;
		}
	}

	return os;
}
