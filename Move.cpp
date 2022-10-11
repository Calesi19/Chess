#include <iostream>
#include <cassert>

using namespace std;


class Move

{
private:
	Position source;

	Position dest;

	char piece;

	char capture;	

	bool enpassant;

	bool castleK;

	bool castleQ;

	bool isWhite;

	string error;


public:

	Move() {


	}

	string getText() {
		return error; // maybe ask?
	}

	Position getSrc() {
		return source;
	}

	Position getDes() {
		return dest;
	}

	char getPromotion() {
		// what ??
	}

	char getCapture() {
		return 
	}

	bool getEnPassant() {
		return enpassant;
	}

	bool getCastleK() {
		return castleK;
	}

	bool getCastleQ() {
		return castleQ;
	}

	bool getWhiteMove() {
		// ask
		return isWhite;
	}

	void setEnPassant() {
		// ask
	}

	void setCastle(bool isKing) {


	}

	void setCastleQ() {


	}

	void setWhiteMove() {
		// ask

	}
	
	void assign(Move move) {
		// Assign piece to a position

	}

	void assign(string string) {
		// Assign piece to a position using notation?

	}






};