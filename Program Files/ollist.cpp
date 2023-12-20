/*Programming fundamentals
term project
M. Moussavi
Rohan Lange, Aiden Lambert, Sabrina Li
*/
//ollist.cpp
#include <iostream>
#include <cassert>
#include <iomanip>
#include <string>
using namespace std;
#include "passenger.h"
#include "ollist.h"
ollist::ollist(){
	headM = 0;
}
ollist::ollist(passenger newPassenger){
	headM = new node;
	assert(headM != 0);
	headM->item = newPassenger;
	headM->next = 0; 
}
ollist& ollist::operator =(const ollist& rhs){
	if(this != &rhs){
		if(rhs.headM != 0){
			this->headM = new node;
			this->headM->item = rhs.headM->item;
			this->headM->next = rhs.headM->next;
			node* currentNode = headM->next;
			while(currentNode != 0){
				node* newNode = new node;
				newNode->item = currentNode->item;
				newNode->next = currentNode->next;
				currentNode = currentNode->next;
			}
		}
	}
	return *this;
}
ollist::~ollist(){
	node* nextNode = headM->next;
	node*currentNode = headM;
	while(nextNode != 0){
		delete currentNode;
		currentNode = nextNode;
		nextNode = nextNode->next;
	}
	delete currentNode;
}
node* ollist::getHead(){
	return headM;
}
void ollist::add(const passenger& newPassenger){
	node* newNode = new node;
	assert(newNode != 0);
	newNode->item = newPassenger;
	if(headM == 0||newPassenger.getPassengerID() <= headM->item.getPassengerID()){
		newNode->next = headM;
		headM = newNode;
	}else{
		node* before = headM;
		node* after = headM->next;
		while(after != 0 && newPassenger.getPassengerID() > after->item.getPassengerID()){
			before = after;
			after = after->next;
		}
		newNode->next = after;
        before->next = newNode;
	}
}
void ollist::remove(const int& passengerID){
	if(headM==0|| passengerID < headM->item.getPassengerID()){
		return;
	}
	node *doomedNode = 0;
	node *before = headM;
	node *maybeDoomed = headM->next;
	if(passengerID == headM->item.getPassengerID()){
		doomedNode = headM;
		headM = headM->next;
	}else{
		while(maybeDoomed != 0&& passengerID > maybeDoomed->item.getPassengerID()){
			before = maybeDoomed;
			maybeDoomed = maybeDoomed->next;
		}
		doomedNode = maybeDoomed;
	}
	if(doomedNode != 0){
		before->next = doomedNode->next;
		doomedNode->item.getSeat()->setOccupied(false);
		delete doomedNode;
	}
}
void ollist::printList(){
	cout<<setw(19)<<left<<"First Name"<<setw(19)<<"Last Name"<<setw(18)<<"Phone#"<<setw(6)<<"Row"<<setw(8)<<"Seat"<<setw(6)<<"ID"<<endl<<setfill('-')<<setw(74)<<"-"<<endl<<setfill(' ');
	node* currentNode = headM;
	while(currentNode != 0){
		cout<<setw(19)<<currentNode->item.getFirstN()<<setw(19)<<currentNode->item.getLastN()<<setw(19)<<currentNode->item.getPhoneNumber();
		cout<<setw(6)<<currentNode->item.getSeatRow()<<setw(8)<<char('A' + currentNode->item.getSeatColumn())<<setw(6)<<currentNode->item.getPassengerID()<<endl<<setfill('-')<<setw(74)<<"-"<<endl<<setfill(' ');
		currentNode = currentNode->next;
	}
}
bool ollist::validateID(int passengerID){
	node* currentNode = headM;
	while(currentNode != 0){
		if(currentNode->item.getPassengerID() == passengerID){
			return false;
		}
		currentNode = currentNode->next;
	}
	return true;
}