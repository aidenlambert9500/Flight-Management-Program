/*Programming fundamentals
term project
M. Moussavi
Rohan Lange, Aiden Lambert, Sabrina Li
*/
//airline.cpp
#include <iostream>
using namespace std;
#include "airline.h"
void airline::addFlight(flight newFlight){
	flightsM.push_back(newFlight);
}
void airline::removeFlight(string flightNumber){
	for (int i = 0; i< int(flightsM.size());i++){
		if(flightsM[i].getNumber() == flightNumber){
			flightsM.erase(flightsM.begin()+i);
			return;
		}
	}
}
flight airline::getFlight(string flightNumber){
	for (int i = 0; i< int(flightsM.size());i++){
		if(flightsM[i].getNumber() == flightNumber){
			return flightsM[i];
		}
	}
	flight newFlight;
	newFlight.setNumber(flightNumber);
	this->addFlight(newFlight);
	return newFlight;
}