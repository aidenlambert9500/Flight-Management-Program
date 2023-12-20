/*Programming fundamentals
term project
M. Moussavi
Rohan Lange, Aiden Lambert, Sabrina Li
*/
//passenger.h
#ifndef AIRLINE_PASSENGER
#define AIRLINE_PASSENGER
#include "seat.h"
#include <string>
class passenger{
	public:
		passenger();
		passenger(string firstName, string lastName, int phoneNumber,seat* position,int passengerID);
		passenger(const passenger& source);
		passenger operator = (const passenger& rhs);
		seat* getSeat() const;
		//PROMISES:
		//			Returns pointer to passengers seat
		string getPhoneNumber() const;
		//PROMISES:
		//			Returns phone number of passenger
		string getFirstN() const;
		//PROMISES:
		//			Returns passengers first name
		string getLastN() const;
		//PROMISES:
		//			Returns passengers last name
		int getPassengerID() const;
		//PROMISES:
		//			Returns passengers ID Number
		int getSeatRow() const;
		//PROMISES:
		//			Returns passengers seat row
		int getSeatColumn() const;
		//PROMISES:
		//			Returns passengers seat column
		void setPhoneNumber(string phoneNumber);
		//REQUIRES:
		//			Valid phone number with 10 digits
		//PROMSIES:
		//			Sets phoneNumberM equal to phoneNumber
		void setFirstN(string firstName);
		//PROMISES:
		//			Sets firstNM equal to firstName
		void setLastN(string LastName);
		//PROMISES:
		//			Sets lastNM equal to lastName
		void setPassengerID(int passengerID);
		//PROMISES:
		//			sets passengerIDM equal to passengerID
		void setSeatRow(int row);
		//PROMISES:
		//			sets positionM.rowM = to row
		void setSeatColumn(int column);
		//PROMISES:
		//			sets positionM.columnM = to column
		void setSeat(seat* position);
		//PROMISES:
		//			points positionM to the passengers seat in the flights vector of vector of seats
	private:
		string phoneNumberM;
		string firstNM;
		string lastNM;
		int passengerIDM;
		seat* positionM;
};
#endif