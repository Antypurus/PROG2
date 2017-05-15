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

vector<string> Line::getBusStops()const {
  return busStopList;
}

vector<int> Line::getTimings()const {
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

bool Line::hasStop(const std::string stop) const
{
	for (auto it = this->busStopList.begin();it != this->busStopList.end();++it) {
		if ((*it) == stop) {
			return true;
		}
	}
	return false;
}

void Line::finalize()
{
	int shiftDuration = 0;
	int prevEndTime = 360;
	for (auto it = this->timesList.begin();it != this->timesList.end();++it) {
		shiftDuration += *it;
	}
	shiftDuration--;
	for (unsigned int i = 0;i < nAutocarros;++i) {
		this->buses.push_back(Bus(i, 0, id));
	}
	unsigned int nShifts = (1080 / frequencia);
	for (unsigned int i = 0;i < 7;++i) {
		for (unsigned int j = 0;j < nShifts;++j) {
			this->shifts.push_back(new Shift(id, 0, j%buses.size(), prevEndTime, prevEndTime + shiftDuration));
			prevEndTime += frequencia - 1;
			this->shifts[j]->assignBus(&(this->buses[shifts[j]->getBusOrderNumber()]));
		}
		prevEndTime++;
		prevEndTime += 360;
	}
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
	this->nAutocarros = (unsigned int)(((double)(calcTraverTime()) / this->frequencia) + 1);
	return nAutocarros;
}

Shift * Line::getSHift(int startTime)
{
	for (size_t i = 0;i > this->shifts.size();++i) {
		if (shifts[i]->getStartTime() == startTime) {
			return shifts[i];
		}
	}
	printf("No Shift In This Line Starts At This Time\n");
	return nullptr;
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
