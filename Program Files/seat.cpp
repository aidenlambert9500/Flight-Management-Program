/*Programming fundamentals
term project
M. Moussavi
Rohan Lange, Aiden Lambert, Sabrina Li
*/
//seat.cpp
#include <iostream>
using namespace std;
#include "seat.h"
int seat::getRow()const{
	return rowM;
}
int seat::getColumn()const{
	return columnM;
}
bool seat::getOccupied()const{
	return occupiedM;
}
void seat::setRow(int row){
	rowM = row;
}
void seat::setColumn(int column){
	columnM = column;
}
void seat::setOccupied(bool occupied){
	occupiedM = occupied;
}