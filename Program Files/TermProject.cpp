/*Programming fundamentals
term project
M. Moussavi
Rohan Lange, Aiden Lambert, Sabrina Li
*/
//termProject.cpp
#include <iostream>
using namespace std;
#include "airline.h"
void programStart();
int getUserInput();
int main(){
		programStart();
		bool run = true;
		airline westJet;
		flight newFlight;
		newFlight.setFileName("flight_info.txt");
		newFlight.readFromFile();
		string firstFlight = newFlight.getNumber();
		//westJet.addFlight(newFlight);
		while(run == true){
			int userInput = getUserInput();
			switch(userInput){
				case 1:
					newFlight.printSeatMap();
					break;
				case 2:
					newFlight.printPassengerList();
					break;
				case 3:
				{
					passenger newPassenger;
					string newPassInS;
					int newPassInI;
					bool run2 = true;
					bool run3 = true;
					cout<<"Please enter the passenger id: ";
					cin >> newPassInI;
					while((newPassInI < 10000 || newPassInI > 99999)||!cin||run2){
						if((newPassInI < 10000 || newPassInI > 99999)||!cin){
							cin.clear();
							cin.ignore();
							cout <<endl<<"The Value You Entered Was Invalid. Please Enter a Valid ID:";
							cin >> newPassInI;
						}else{
							if (newFlight.validatePassengerID(newPassInI)== true){
								run2 = false;
							}else{
								cin.clear();
								cin.ignore();
								cout <<endl<<"The Value You Entered Was Invalid. Please Enter a Valid ID: ";
								cin >> newPassInI;
							}
						}
					}
					newPassenger.setPassengerID(newPassInI);
					cout<<endl<<"Please enter the passengers first name: ";
					cin >> newPassInS;
					newPassenger.setFirstN(newPassInS);
					cout<<endl<<"Please enter the passengers last name: ";
					cin >> newPassInS;
					newPassenger.setLastN(newPassInS);
					cin.clear();
					cin.ignore();
					cout<<endl<<"Please enter the passengers phone number with format ### ### ####: ";
					getline(cin,newPassInS);
					run2 = true;
					while(newPassInS.length() != 12||run2){
						if(newPassInS.length() != 12){
							cout<<endl<<"The phone number you entered was invalid, please input a valid number: ";
							getline(cin,newPassInS);
						}else{
							for(int i = 0; i<12; i++){
								if((i > -1 && i < 3)||(i > 3 && i < 7)||(i > 7 && i < 11)){
									if(newPassInS[i] < '0' || newPassInS[i] > '9'){
										cout<<endl<<"The phone number you entered was invalid, please input a valid number: ";
										getline(cin,newPassInS);
										break;
									}
								}else if(i == 3 || i == 7){
									if(newPassInS[i] != ' ' && newPassInS[i] != '-'){
										cout<<endl<<"The phone number you entered was invalid, please input a valid number: ";
										getline(cin,newPassInS);
										break;
									}
									newPassInS[i] = '-';
									
								}else{
									if(newPassInS[i] >= '0' &&  newPassInS[i] <= '9'){
										run2 = false;
									}else{
										cout<<endl<<"The phone number you entered was invalid, please input a valid number: ";
										getline(cin,newPassInS);
									}
								}
							}
						}
					}
					newPassenger.setPhoneNumber(newPassInS);
					while(run3){
						cout<<endl<<"Please enter the passengers desired row: ";
						cin >> newPassInI;
						while((newPassInI < 1 || newPassInI > newFlight.getRows())||!cin){
							cin.clear();
							cin.ignore();
							cout <<endl<<"The Value You Entered Was Invalid. Please Enter a Valid Row: ";
							cin >> newPassInI;
						}
						run2 = true;
						cout<<endl<<"Please enter the passengers desired column: ";
						cin >> newPassInS;
						while(newPassInS.length() != 1||run2){
							if(newPassInS.length() != 1){
								cout <<endl<<"The Value You Entered Was Invalid. Please Enter a Valid Column: ";
								cin >> newPassInS;
							}else{
								if((newPassInS[0]-'A')>=0 && (newPassInS[0]-'A') < newFlight.getColumns()){
									run2 = false;
								}else{
									cout <<endl<<"The Value You Entered Was Invalid. Please Enter a Valid Column: ";
									cin >> newPassInS;
								}
							}
						}
						if(newFlight.isOccupied(newPassInI-1,newPassInS[0]-'A') == false){
							run3 = false;
						}else{
							cout<<"the seat you have selected is currently occupied, please try again, here is the current seat map"<<endl;
							newFlight.printSeatMap();
						}
					}
					newPassenger.setSeat(newFlight.getSeat(newPassInI-1,newPassInS[0]-'A'));
					newFlight.addPassenger(newPassenger);
					break;
				}
				case 4:
				{
					int removePassID;
					bool run2 = true;
					cout<<"Please enter the passenger id of an existing passenger";
					cin >> removePassID;
					while((removePassID < 10000 || removePassID > 99999)||!cin||run2){
						if((removePassID < 10000 || removePassID > 99999)||!cin){
							cin.clear();
							cin.ignore();
							cout <<endl<<"The Value You Entered Was Invalid. Please Enter a Valid ID:";
							cin >> removePassID;
						}else{
							if (newFlight.validatePassengerID(removePassID)== false){
								run2 = false;
							}else{
								cin.clear();
								cin.ignore();
								cout <<endl<<"The ID you entered does not belong to a current passenger. Please Enter a Valid ID: ";
								cin >> removePassID;
							}
						}
					}
					newFlight.removePassenger(removePassID);
					break;
				}
				case 5:
					newFlight.saveToFile();
					break;
				case 6:
					run = false;
					break;
			}
		}
	return 0;
}
void programStart(){
	char stall[1];
	cout<<"Version: 1.0"<<endl<<"Term Project - Flight Managemnet Program in c++"<<endl<<"Produced by: Rohan Lange, Aiden Lambert, Sabrina Li"<<endl<<"Year: 2023"<<endl;
	cout<<endl<<"<<<Press Return to Continue>>>";
	cin.get(stall,1);
	cin.clear();
}
int getUserInput(){
	int userInput = 0;
	cout <<"Please select one of the following options:"<<endl;
	cout <<"1. Display Flight Seat Map."<<endl;
	cout <<"2. Display Passengers Information."<<endl;
	cout <<"3. Add a New Passenger."<<endl;
	cout <<"4. Remove an Existing Passenger."<<endl;
	cout <<"5. Save Data"<<endl;
	cout <<"6. Quit"<<endl<<endl;
	cout <<"Enter Your Choice: (1, 2, 3, 4, 5, or 6) ";
	cin >> userInput;
	while((userInput < 1 || userInput > 6)||!cin){
		cin.clear();
		cin.ignore();
		cout <<endl<<"The Value You Entered Was Invalid. Please Enter a Valid Selection: ";
		cin >> userInput;
	}
	return userInput;
}