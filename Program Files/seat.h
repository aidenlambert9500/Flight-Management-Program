/*Programming fundamentals
term project
M. Moussavi
Rohan Lange, Aiden Lambert, Sabrina Li
*/
//seat.h
#ifndef AIRLINE_SEAT
#define AIRLINE_SEAT
class seat{
	public:
		seat(): rowM(0), columnM(0), occupiedM(0){};
		seat(int row, int column, bool occupied): rowM(row),columnM(column),occupiedM(occupied){};
		void setRow(int row);
		//REQUIRES:
		//		row is greater than 0 and less than or equal to the last row in the given flight 
		//PROMISES:
		//		rowM is set equal to row
		void setColumn(int column);
		//REQUIRES:
		//		column is greater than 0 and less than or equal to the last column in the given flight 
		//PROMISES:
		//		columnM is set equal to column
		void setOccupied(bool occupied);
		//PROMISES:
		//sets occupiedM equal to occupied
		int getRow() const;
		//PROMISES:
		//returns row of seat
		int getColumn() const;
		//PROMISES:
		//returns column of seat
		bool getOccupied() const;
		//PROMISES:
		//returns whether or not the seat is occupied
	private:
		int rowM;
		int columnM;
		bool occupiedM;
};
#endif