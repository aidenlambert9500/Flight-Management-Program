/*Programming fundamentals
term project
M. Moussavi
Rohan Lange, Aiden Lambert, Sabrina Li
*/
//passenger.cpp
#include <iostream>
#include <string>
using namespace std;
#include "seat.h"
#include "passenger.h"
passenger::passenger(){
	phoneNumberM = '\0';
	firstNM = '\0';
	lastNM = '\0';
	passengerIDM = 0;
	positionM = 0;
}
passenger::passenger(string firstName, string lastName, int phoneNumber,seat* position,int passengerID){
	firstNM = firstName;
	lastNM = lastName;
	phoneNumberM = phoneNumber;
	positionM = position;
	passengerIDM = passengerID;
}
passenger::passenger(const passenger& source){
	firstNM = source.firstNM;
	lastNM = source.lastNM;
	phoneNumberM = source.phoneNumberM;
	positionM = source.positionM;
	passengerIDM = source.passengerIDM;
}
passenger passenger::operator =(const passenger& rhs){
	if(this != &rhs){
		this->firstNM = rhs.firstNM;
		this->lastNM = rhs.lastNM;
		this->phoneNumberM = rhs.phoneNumberM;
		this->positionM = rhs.positionM;
		this->passengerIDM = rhs.passengerIDM;
	}
	return *this;
}
seat* passenger::getSeat() const{
	return positionM;
}
string passenger::getPhoneNumber() const{
	return phoneNumberM;
}
string passenger::getFirstN() const{
	return firstNM;
}
string passenger::getLastN() const{
	return lastNM;
}
int passenger::getPassengerID() const{
	return passengerIDM;
}
int passenger::getSeatRow() const{
	return positionM->getRow();
}
int passenger::getSeatColumn() const{
	return positionM->getColumn();
}
void passenger::setPhoneNumber(string phoneNumber){
	phoneNumberM = phoneNumber;
}
void passenger::setFirstN(string firstName){
	firstNM = firstName;
}
void passenger::setLastN(string lastName){
	lastNM = lastName;
}
void passenger::setPassengerID(int passengerID){
	passengerIDM = passengerID;
}
void passenger::setSeatRow(int row){
	positionM->setRow(row);
}
void passenger::setSeatColumn(int column){
	positionM->setColumn(column);
}
void passenger::setSeat(seat* position){
	positionM = position;
	position->setOccupied(true);
}
		