/*Programming fundamentals
term project
M. Moussavi
Rohan Lange, Aiden Lambert, Sabrina Li
*/
//ollist.h
#ifndef AIRLINE_LLIST
#define AIRLINE_LLIST
#include "passenger.h"
struct node {
  passenger item;
  node *next;
};
class ollist{
	public:
		ollist();
		ollist(passenger newPassenger);
		ollist& operator =(const ollist& rhs);
		~ollist();
		node* getHead();
		//PROMISES:
		//			returns headM
		void add(const passenger& newPassenger);
		//REQUIRES
		//			An instance of the passenger class 
		//PROMISES
		//			Adds the provided passenger to the end of the linked list
		void remove(const int& passengerID);
		//REQUIRES:
		//			A valid passengerID that is already in use in the linked list
		//PROMISES: 
		//			iterates through the linked list until it finds a passenger with the provided ID and removes them form the list
		void printList();
		//PROMISES:
		//			prints out all of the passenger information inside of the linked list
		bool validateID(int passengerID);
		//REQUIRES:
		//			A 5 digit number
		//PROMISES:
		//			if passengerID already belongs to a passenger return 0 else return 1
	private:
	  node *headM;
};
#endif