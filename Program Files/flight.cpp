/*Programming fundamentals
term project
M. Moussavi
Rohan Lange, Aiden Lambert, Sabrina Li
*/
//flight.cpp
#include <iostream>
#include <iomanip>
using namespace std;
#include "flight.h"
flight::flight(){
	numberM = '\0';
	rowsM = 0;
	columnsM = 0;
}
flight::flight(string flightNumber, int rows, int columns){
	numberM = flightNumber;
	rowsM = rows;
	columnsM = columnsM;
	seatMapM.resize(rows,vector<seat>(columns));
	for(int i = 0; i<rows; i++){
		for(int j = 0; j<columns;j++){
			seatMapM[i][j].setRow(i+1);
			seatMapM[i][j].setColumn(j);
		}
	}
}
flight::flight(const flight& source){
	numberM = source.numberM;
	passengersM = source.passengersM;
	rowsM = source.rowsM;
	columnsM = source.columnsM;
	seatMapM.resize(rowsM,vector<seat>(columnsM));
	for(int i = 0; i < rowsM;i++){
		for(int j = 0; j< columnsM; j++){
			seatMapM[i][j] = source.seatMapM[i][j];
		}
	}
}
flight flight::operator =(const flight& rhs){
	if(this != &rhs){
		this->rowsM = rhs.rowsM;
		this->columnsM = rhs.columnsM;
		this->numberM = rhs.numberM;
		this->passengersM = rhs.passengersM;
		this->seatMapM.resize(this->rowsM,vector<seat>(this->columnsM));
		for(int i = 0; i < this->rowsM;i++){
			for(int j = 0; j< this->columnsM; j++){
				this->seatMapM[i][j] = rhs.seatMapM[i][j];
			}
		}
	}
	return *this;
}
seat* flight::getSeat(int row, int column){
	return &seatMapM[row][column];
}
int flight::getRows() const{
	return rowsM;
}
int flight::getColumns() const{
	return columnsM;
}
string flight::getNumber() const{
	return numberM;
}
void flight::setNumber(string flightNumber){
	numberM = flightNumber;
}
void flight::setRows(int rows){
	rowsM = rows;
}
void flight::setColumns(int columns){
	columnsM = columns;
}
void flight::setFileName(string fileName){
	fileNameM = fileName;
}
void flight::addPassenger(passenger newPassenger){
	passengersM.add(newPassenger);
}
void flight::removePassenger(int passengerID){
	passengersM.remove(passengerID);
}
void flight::printSeatMap(){
	cout<<"     ";
	for(int i = 0; i< columnsM;i++){
		cout << char('A'+i) << "   ";
	}
	cout<<endl;
	for (int i = 0; i<rowsM;i++){
		cout<<"   ";
		for(int j = 0; j<columnsM; j++){
			cout<<"+---";
		}
		cout<<"+"<<endl<<setw(3)<<i+1;
		for(int j = 0; j<columnsM; j++){
			cout<<"| ";
			if(seatMapM[i][j].getOccupied() == true){
				cout<<"X";
			}else{
				cout<<" ";
			}
			cout<<" ";
		}
		cout<<"|"<<endl;
	}
	cout<<setw(3)<<" ";
	for(int j = 0; j<columnsM; j++){
		if(j == columnsM-1){
			cout<<"+---+"<<endl;
		}else{
			cout<<"+---";
		}
	}
}
void flight::printPassengerList(){
	passengersM.printList();
}
void flight::readFromFile(){
	ifstream in(fileNameM);
	if(in.fail()){
		cout<<"Flight file"<<fileNameM<<"failed to open"<<endl;
	}else{
		string fileS;
		in >> numberM >> rowsM >> columnsM;
		seatMapM.resize(rowsM,vector<seat>(columnsM));
		for(int i = 0;i<rowsM;i++){
			for(int j = 0; j<columnsM;j++){
				seatMapM[i][j].setRow(i+1);
				seatMapM[i][j].setColumn(j);
			}
		}
		getline(in,fileS);
		while (!in.eof()){
			passenger newPassenger;
			getline(in,fileS);
			string firstN(fileS,0,19);
			newPassenger.setFirstN(firstN);
			string lastN(fileS,20,19);
			newPassenger.setLastN(lastN);
			string phoneN(fileS,40,19);
			newPassenger.setPhoneNumber(phoneN);
			string ID(fileS,64,5);
			newPassenger.setPassengerID(stoi(ID));
			if(isdigit(fileS[61]) == 1){
				string row(fileS,60,2);
				string column(fileS,62,1);
				newPassenger.setSeat(&seatMapM[stoi(row)-1][column[0]-'A']);
				seatMapM[stoi(row)-1][column[0]-'A'].setOccupied(true);
			}else{
				string row(fileS,60,1);
				string column(fileS,61,1);
				newPassenger.setSeat(&seatMapM[stoi(row)-1][column[0]-'A']);
				seatMapM[stoi(row)-1][column[0]-'A'].setOccupied(true);
			}
			this->addPassenger(newPassenger);
		}
		in.close();
	}
}
void flight::saveToFile(){
	ofstream out(fileNameM);
	if(out.fail()){
		cout<<"Flight file"<<fileNameM<<"failed to open"<<endl;
	}else{
		out << setw(9) <<left<< numberM << setw(6) << rowsM << columnsM<<endl;
		node* currentNode = passengersM.getHead();
		while(currentNode != 0){
			out << setw(20) << currentNode->item.getFirstN() << setw(20) << currentNode->item.getLastN() << setw(20) << currentNode->item.getPhoneNumber();
			if(currentNode->item.getSeatRow()>9){
				out << currentNode->item.getSeatRow()<<setw(2) << char(currentNode->item.getSeatColumn()+'A');
			}else{
				out << currentNode->item.getSeatRow()<<setw(3) << char(currentNode->item.getSeatColumn()+'A');
			}
			if(currentNode->next == 0){
				out << currentNode->item.getPassengerID();
			}else{
				out << currentNode->item.getPassengerID()<<endl;
			}
			currentNode = currentNode->next;
		}
		out.close();
	}
}
bool flight::validatePassengerID(int passengerID){
	return passengersM.validateID(passengerID);
}
bool flight::isOccupied(int row, int column){
	return seatMapM[row][column].getOccupied();
}