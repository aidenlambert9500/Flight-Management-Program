/*Programming fundamentals
term project
M. Moussavi
Rohan Lange, Aiden Lambert, Sabrina Li
*/
//llist.cpp
#include <iostream>
#include <cassert>
#include <iomanip>
#include <string>
using namespace std;
#include "passenger.h"
#include "llist.h"
llist::llist(){
	headM = 0;
}
llist::llist(passenger newPassenger){
	headM = new node;
	assert(headM != 0);
	headM->item = newPassenger;
	headM->next = 0; 
}
llist llist::operator =(const llist& rhs){
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
llist::~llist(){
	node* nextNode = headM;
	node*currentNode = headM;
	while(nextNode != 0){
		delete currentNode;
		currentNode = nextNode;
		nextNode = nextNode->next;
	}
	delete currentNode;
}
void llist::add(const passenger& newPassenger){
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
void llist::remove(const int& passengerID){
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
		delete doomedNode;
	}
}
void llist::printList(){
	cout<<setw(16)<<left<<"First Name"<<setw(16)<<"Last Name"<<setw(16)<<"Phone#"<<setw(6)<<"Row"<<setw(6)<<"Seat"<<setw(6)<<"ID"<<endl;
	//cout<<setfill('-')<<setw(63)<<"-";
	node* currentNode = headM;
	while(currentNode != 0){
		cout<<setw(16)<<currentNode->item.getFirstN()<<setw(16)<<currentNode->item.getLastN()<<setw(16)<<currentNode->item.getPhoneNumber();
		cout<<setw(6)<<currentNode->item.getSeatRow()<<setw(6)<<'A' + currentNode->item.getSeatColumn()<<setw(6)<<currentNode->item.getPassengerID()<<endl<<setfill("-")<<setw(63)<<"-";
	}
}