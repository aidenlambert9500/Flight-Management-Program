/*Programming fundamentals
term project
M. Moussavi
Rohan Lange, Aiden Lambert, Sabrina Li
*/
//flight.h
#ifndef AIRLINE_FLIGHT
#define AIRLINE_FLIGHT
#include <vector>
#include <string>
#include <fstream>
#include "passenger.h"
#include "seat.h"
#include "ollist.h"
class flight{
	public:
		flight();
		flight(string flightNumber,int rows, int columns);
		flight(const flight& source);
		flight operator =(const flight& rhs);
		seat* getSeat(int row, int column);
		//PROMISES:
		//			returns a pointer to the requested seat in the vector of vectors of seats
		int getRows() const;
		//PROMISES:
		//			returns the number of rows of seats on the flight
		int getColumns() const;
		//PROMISES:
		//			returns the number of columns of seats on the flight
		string getNumber() const;
		//PROMISES:
		//			returns the flight number
		void setNumber(string flightNumber);
		//REQUIRES: 
		//			integer of ___ length and valid flight number
		//PROMISES:
		//			sets numberM equal to flightNumber
		void setRows(int rows);
		//PROMISES:
		//			sets rowsM equal to rows
		void setColumns(int columns);
		//PROMISES:
		//			sets columnsM equal to columns
		void setFileName(string fileName);
		//PROMISES:
		//			sets fileNameM equal to fthe provided file name
		void addPassenger(passenger newPassenger);
		//REQUIRES:
		//			A complete instance of passenger with a unique passengerID
		//PROMISES:
		//			adds the provided passenger to the end of the passenger linked list 
		void removePassenger(int passengerID);
		//REQUIRES:
		//			A valid passengerID that is already in use in the linked list
		//PROMISES: 
		//			iterates through the linked list until it finds a passenger with the provided ID and removes them form the list
		void printSeatMap();
		//PROMISES:
		//			Iterates through the vector of vectors and prints all of the seats on the plain and whether or not they are occupied
		void printPassengerList();
		//PROMISES:
		//			Iterates through the linked list of passengers and prints all of the deatils from each one in order
		void readFromFile();
		//PROMISES:
		//			Opens file with name stored in fileNameM and sets numberM, rowsM, columnsM, and passengersM to values corresponding to data stored within the file
		void saveToFile();
		//PROMISES:
		//			Opens file with name stored in fileNameM and writes numberM, rowsM, columnsM, and passengersM's list of passengers to the file
		bool validatePassengerID(int passengerID);
		//REQUIRES:
		//			A 5 digit number
		//PROMISES:
		//			if passengerID already belongs to a passenger return 0 else return 1
		bool isOccupied(int row, int column);
		//REQUIRES:
		//			Valid row and column in setaMapM
		//PROMISES:
		//			returns whether or not the given seat is currently occupied;
	private:
		string numberM;
		string fileNameM;
		vector<vector<seat>> seatMapM;
		ollist passengersM;
		int rowsM;
		int columnsM;
};
#endif