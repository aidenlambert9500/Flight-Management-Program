/*Programming fundamentals
term project
M. Moussavi
Rohan Lange, Aiden Lambert, Sabrina Li
*/
//airline.h
#ifndef AIRLINE_AIRLINE
#define AIRLINE_AIRLINE
#include <vector>
#include <string>
#include "flight.h"
class airline{
	public:
		void addFlight(flight newFlight);
		//REQUIRES:
		//			A complete instance of the flight class
		//PROMISES:
		//			adds the provide flight to airlines vector of flights
		void removeFlight(string flightNumber);
		//REQUIRES:
		//			valid flight number of a flight that is currently stored inside the airlines vector of flights
		//PROMISES:
		//			removes the flight with the given flight number from the airlines vector of flights and resizes it accordingly
		flight getFlight(string flightNumber);
		//REQUIRES:
		//			valid flight number of a flight that is currently stored inside the airlines vector of flights
		//PROMISES:
		//			returns the flight with the given flight number,if that flight does not exist adds a new flight with that flight number
	private:
		vector<flight> flightsM;
};
#endif