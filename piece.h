#pragma once
#include <vector>
//#include "ogstream.h"
#include "board.h."

using namespace std;

class TestPiece;
//
///***************************************************
//* MOCK of board class
//***************************************************/
//class Board
//{
//public:
//	char board[64];
//};

/****************************************************
* MOCK of Position Class
*****************************************************/
class Position
{
public:
	Position(int row, int col) : row(row), col(col) {}
	Position() : row(0), col(0) {}
	int row;
	int col;
};

class Piece
{
	friend class TestPiece;

protected:
	Position position;
	bool fWhite;
	int nMoves;
	int lastMove = 0;
	char pieceType = 'e';
	vector<Position> possibleMoves;

public:
	Piece();
	Piece(int row, int col, bool fWhite, char type) : position(Position(row, col)), fWhite(fWhite),
		nMoves(0), lastMove(0), pieceType(type) {};
	Piece(char type)
	{
		pieceType = type;
	};

	void assign(Position pos) { position = pos; };
	void assign(Piece piece) {};

	bool isWhite() { return true; };
	bool isMove(Position pos) { return true; };

	int getNMoves() { return 0; };
	Position getPosition() { return position; };

	bool justMoved(int currentMove) { return true; };
	virtual char getLetter() { return pieceType; };
	virtual void display(ogstream gout) {};

	virtual vector<Position> getMoves(Board board)
	{
		vector<Position> vect;
		return vect;
	};

};
