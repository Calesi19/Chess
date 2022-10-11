#include "testPiece.h"
using namespace std;



// Mocks for Child Classes
class Rook : public Piece
{
public:
	Rook(int row, int col, bool fWite) : Piece(row, col, fWhite)
	{
		position.row = row;
		position.col = col;
	};
	char getLetter() { return 'r'; }
};

class King : public Piece
{
public:
	King(int row, int col, bool fWhite): Piece(row, col, fWhite) 
	{
		position.row = row;
		position.col = col;
	};
	char getLetter() { return 'k'; }


	vector<Position> getMoves(Board board, Rook rook1, Rook rook2)
	{
		vector<Position> list;
		return list;
	}
};

class Queen : public Piece
{
public:
	Queen(int row, int col, bool fWite) : Piece(row, col, fWhite)
	{
		position.row = row;
		position.col = col;
	};
	char getLetter() { return 'q'; }
};



class Knight : public Piece
{
public:
	Knight(int row, int col, bool fWite) : Piece(row, col, fWhite)
	{
		position.row = row;
		position.col = col;
	};
	char getLetter() { return 'n'; }
};

class Bishop : public Piece
{
public:
	Bishop(int row, int col, bool fWite) : Piece(row, col, fWhite)
	{
		position.row = row;
		position.col = col;
	};
	char getLetter() { return 'b'; }
};

class Pawn : public Piece
{
public:
	Pawn(int row, int col, bool fWite) : Piece(row, col, fWhite)
	{
		position.row = row;
		position.col = col;
	};
	char getLetter() { return 'p'; }
};

class Space : public Piece
{
public:
	Space(int row, int col, bool fWite) : Piece(row, col, fWhite)
	{
		position.row = row;
		position.col = col;
	};
	char getLetter() { return '-'; }
};


/*******************************************************
* RUN
* executes all unit tests for TestPiece
*******************************************************/
void TestPiece::run() 
{
	// test assign by position
	testAssign_Position_King();
	testAssign_Position_InvalidRow();

	// test assign by piece
	testAssign_Piece_Queen();
	testAssign_Piece_Space();
	testAssign_Piece_King();
	testAssign_Piece_Rook();
	testAssign_Piece_Bishop();
	testAssign_Piece_Knight();
	testAssign_Piece_Pawn();

	// test isWhite
	testIsWhite_White();
	testIsWhite_Black();
	testIsWhite_Space();

	// test isMove
	testIsMove_InvalidPosition();
	testIsMove_ValidPosition();
	testIsMove_Current_Position();

	// test getNMoves
	testGetNMoves_NoMoves();
	testGetNMoves_3Moves();

	// test getPosition
	testGetPosition_ValidPosition();
	testGetPosition_OutOfBounds();

	// test justMoved
	testJustMoved_NoMoves();
	testJustMoved_JustMoved();
	testJustMoved_OldMove();

	// test getLetter
	testGetLetter_King();
	testGetLetter_Queen();
	testGetLetter_Space();

	// test getMoves for pawn
	testGetMoves_Pawn_Blocked();
	testGetMoves_Pawn_SimpleMove();
	testGetMoves_Pawn_InitialMove();
	testGetMoves_Pawn_Capture();
	testGetMoves_Pawn_Enpassant();
	testGetMoves_Pawn_Promotion();

	// test getMoves for king
	testGetMoves_King_FreeSpacesAllAround();
	testGetMoves_King_BlockedAllAround();
	testGetMoves_King_Capture();
	testGetMoves_King_CastleKingHasMoved();
	testGetMoves_King_CastleRookHasMoved();
	testGetMoves_King_CastleBlocked();
	testGetMoves_King_Castle();
}

/*******************************************************
* SET
* sets up a Space piece
*******************************************************/
Piece TestPiece::set()
{
	Piece testPiece(5, 5, 0); //row 5, col 5, isWhite is false = 0
	return testPiece;
}

/*******************************************************
* TEAR DOWN
* destroys any objects used or created
*******************************************************/
void TestPiece::teardown(Piece testPiece)
{
	testPiece.~Piece();
}



//
// test assign by position
//
void TestPiece::testAssign_Position_King()
{
	// set
	Piece testPiece = set();
	Position pos(1, 5);

	// execute
	testPiece.assign(pos);
	
	// verify
	assert(testPiece.getLetter() == 'k');
	
	// teardown
	teardown(testPiece);
}

void TestPiece::testAssign_Position_InvalidRow()
{
	// set
	Piece testPiece = set();
	Position pos(5, 5);

	// execute
	testPiece.assign(pos);

	// verify
	assert(testPiece.getLetter() == '-');

	// teardown
	teardown(testPiece);
}

//
// test assign by piece
//
void TestPiece::testAssign_Piece_Queen()
{
	// set
	Piece testPiece = set();
	Queen queen(4, 4, true);

	// execute
	testPiece.assign(queen);

	// verify
	assert(testPiece.getLetter() == 'q');

	// teardown
	teardown(testPiece);
	queen.~Queen();
}

void TestPiece::testAssign_Piece_Space()
{
	// set
	Piece testPiece = set();
	Space space(4, 4, false);

	// execute
	testPiece.assign(space);

	// verify
	assert(testPiece.getLetter() == '-');

	// teardown
	teardown(testPiece);
	space.~Space();
}


void TestPiece::testAssign_Piece_King()
{
	// set
	Piece testPiece = set();
	King king(4, 4, true);

	// execute
	testPiece.assign(king);

	// verify
	assert(testPiece.getLetter() == 'k');

	// teardown
	teardown(testPiece);
	king.~King();
}


void TestPiece::testAssign_Piece_Rook()
{
	// set
	Piece testPiece = set();
	Rook rook(4, 4, true);

	// execute
	testPiece.assign(rook);

	// verify
	assert(testPiece.getLetter() == 'r');

	// teardown
	teardown(testPiece);
	rook.~Rook();
}

void TestPiece::testAssign_Piece_Bishop()
{
	// set
	Piece testPiece = set();
	Bishop bishop(4, 4, true);

	// execute
	testPiece.assign(bishop);

	// verify
	assert(testPiece.getLetter() == 'b');

	// teardown
	teardown(testPiece);
	bishop.~Bishop();
}

void TestPiece::testAssign_Piece_Knight()
{
	// set
	Piece testPiece = set();
	Knight knight(4, 4, true);

	// execute
	testPiece.assign(knight);

	// verify
	assert(testPiece.getLetter() == 'n');

	// teardown
	teardown(testPiece);
	knight.~Knight();
}

void TestPiece::testAssign_Piece_Pawn()
{
	// set
	Piece testPiece = set();
	Pawn pawn(4, 4, true);

	// execute
	testPiece.assign(pawn);

	// verify
	assert(testPiece.getLetter() == 'p');

	// teardown
	teardown(testPiece);
	pawn.~Pawn();
}

//
// test isWhite
//

void TestPiece::testIsWhite_White()
{
	// set
	Piece testPiece = set();
	testPiece.fWhite = true;

	// execute
	bool isWhite = testPiece.isWhite();

	// verify
	assert(isWhite == true);

	// teardown
	teardown(testPiece);
}

void TestPiece::testIsWhite_Black() 
{
	// set
	Piece testPiece = set();
	testPiece.fWhite = false;

	// execute
	bool isWhite = testPiece.isWhite();

	// verify
	assert(isWhite == false);

	// teardown
	teardown(testPiece);
}

void TestPiece::testIsWhite_Space()
{
	// set
	Space testPiece(0, 0, false);

	// execute
	bool isWhite = testPiece.isWhite();

	// verify
	assert(isWhite == false);

	// teardown
	teardown(testPiece);
}

//
// test isMove
//
void TestPiece::testIsMove_InvalidPosition()
{
	// set
	Piece testPiece = set();
	testPiece.possibleMoves = {};
	Position pos(4, 4);

	// execute
	bool isMovePos = testPiece.isMove(pos);

	// verify
	assert(isMovePos == false);

	// teardown
	teardown(testPiece);
}

void TestPiece::testIsMove_ValidPosition()
{
	// set
	Piece testPiece = set();
	Position posibleMovePos(4, 4);
	testPiece.possibleMoves.push_back(posibleMovePos);
	Position pos(4, 4);

	// execute
	bool isMovePos = testPiece.isMove(pos);

	// verify
	assert(isMovePos == true);

	// teardown
	teardown(testPiece);
}
void TestPiece::testIsMove_Current_Position()
{
	// set
	Piece testPiece = set();
	Position posibleMovePos(4, 4);
	testPiece.possibleMoves.push_back(posibleMovePos);
	Position pos = testPiece.position;

	// execute
	bool isMovePos = testPiece.isMove(pos);

	// verify
	assert(isMovePos == false);

	// teardown
	teardown(testPiece);
}
//
// test getNMoves
//
void TestPiece::testGetNMoves_NoMoves()
{
	// set
	Piece testPiece = set();
	testPiece.nMoves = 0;

	// execute
	int numMoves = testPiece.getNMoves();

	// verify
	assert(numMoves == 0);

	// teardown
	teardown(testPiece);
}

void TestPiece::testGetNMoves_3Moves()
{
	// set
	Piece testPiece = set();
	testPiece.nMoves = 3;

	// execute
	int numMoves = testPiece.getNMoves();

	// verify
	assert(numMoves == 3);

	// teardown
	teardown(testPiece);
}

//
// test getPosition
//

void TestPiece::testGetPosition_ValidPosition()
{
	// set
	Piece testPiece = set();
	testPiece.position.row = 2;
	testPiece.position.col = 2;

	// execute
	Position pos = testPiece.getPosition();

	// verify
	assert(pos.col == testPiece.position.col);
	assert(pos.row == testPiece.position.row);

	// teardown
	teardown(testPiece);
}

void TestPiece::testGetPosition_OutOfBounds()
{
	// set
	Piece testPiece = set();
	testPiece.position.row = 0;
	testPiece.position.col = 0;

	// execute
	Position pos = testPiece.getPosition();

	// verify
	assert(pos.col == -1); // -1 represents error.
	assert(pos.row == -1);

	// teardown
	teardown(testPiece);
}

//
// test justMoved
//

void TestPiece::testJustMoved_NoMoves()
{
	// set
	Piece testPiece = set();
	testPiece.lastMove = 0;

	// execute
	bool justMoved = testPiece.justMoved(0);

	// verify
	assert(justMoved == false);

	// teardown
	teardown(testPiece);
}

void TestPiece::testJustMoved_JustMoved()
{
	// set
	Piece testPiece = set();
	testPiece.lastMove = 4;

	// execute
	bool justMoved = testPiece.justMoved(5);

	// verify
	assert(justMoved == true);

	// teardown
	teardown(testPiece);
}

void TestPiece::testJustMoved_OldMove()
{
	// set
	Piece testPiece = set();
	testPiece.lastMove = 3;

	// execute
	bool justMoved = testPiece.justMoved(6);

	// verify
	assert(justMoved == false);

	// teardown
	teardown(testPiece);
}

//
// test getLetter
//

void TestPiece::testGetLetter_King()
{
	// set
	King king(1, 5, true);

	// execute
	char letter = king.getLetter();

	// verify
	assert(letter == 'k');

	// teardown
	teardown(king);
}

void TestPiece::testGetLetter_Queen()
{
	// set
	Queen queen(1, 5, true);

	// execute
	char letter = queen.getLetter();

	// verify
	assert(letter == 'q');

	// teardown
	teardown(queen);
}

void TestPiece::testGetLetter_Space()
{
	// set
	Space space(1, 5, false);

	// execute
	char letter = space.getLetter();

	// verify
	assert(letter == '-');

	// teardown
	teardown(space);
}

//
// test getMoves for pawn
//

/***********************************************
* Board Layout:
* _________________
* |P              |
* |p              |
* |               |
* |               |
* |               |
* |               |
* |               |
* |               |
* -----------------
***********************************************/
void TestPiece::testGetMoves_Pawn_Blocked()
{
	// set
	Board chessBoard;

	for (int i = 0; i < 64; i++)
	{
		chessBoard.board[i] = '-';
	}
	chessBoard.board[0] = 'P';
	chessBoard.board[8] = 'p';

	Pawn pawn(7, 1, true);
	

	// execute
	vector<Position> posMoves = pawn.getMoves(chessBoard);

	// verify
	assert(posMoves.size() == 0);

	// teardown
	teardown(pawn);
}

/***********************************************
* Board Layout:
* _________________
* |               |
* |               |
* |               |
* |               |
* |p              |
* |               |
* |               |
* |               |
* -----------------
***********************************************/
void TestPiece::testGetMoves_Pawn_SimpleMove()
{
	// set
	Board chessBoard;

	for (int i = 0; i < 64; i++)
	{
		chessBoard.board[i] = '-';
	}
	chessBoard.board[32] = 'p';

	Pawn pawn(4, 1, true);


	// execute
	vector<Position> posMoves = pawn.getMoves(chessBoard);

	// verify
	assert(posMoves[0].col == 1);
	assert(posMoves[0].row == 4);
	assert(posMoves.size() == 1);

	// teardown
	teardown(pawn);
}

/***********************************************
* Board Layout:
* _________________
* |               |
* |               |
* |               |
* |               |
* |               |
* |               |
* |p              |
* |               |
* -----------------
***********************************************/
void TestPiece::testGetMoves_Pawn_InitialMove()
{
	// set
	Board chessBoard;

	for (int i = 0; i < 64; i++)
	{
		chessBoard.board[i] = '-';
	}
	chessBoard.board[48] = 'p';

	Pawn pawn(2, 1, true);


	// execute
	vector<Position> posMoves = pawn.getMoves(chessBoard);

	// verify
	assert(posMoves[0].col == 1);
	assert(posMoves[0].row == 3);
	assert(posMoves[1].col == 1);
	assert(posMoves[1].row == 4);
	assert(posMoves.size() == 2);

	// teardown
	teardown(pawn);
}

/***********************************************
* Board Layout:
* _________________
* |               |
* |               |
* |               |
* |               |
* |               |
* |P P            |
* |p              |
* |               |
* -----------------
***********************************************/
void TestPiece::testGetMoves_Pawn_Capture()
{
	// set
	Board chessBoard;

	for (int i = 0; i < 64; i++)
	{
		chessBoard.board[i] = '-';
	}
	chessBoard.board[40] = 'P';
	chessBoard.board[41] = 'P';
	chessBoard.board[48] = 'p';

	Pawn pawn(2, 1, true);


	// execute
	vector<Position> posMoves = pawn.getMoves(chessBoard);

	// verify
	assert(posMoves[0].col == 2);
	assert(posMoves[0].row == 3);
	assert(posMoves.size() == 1);

	// teardown
	teardown(pawn);
}

/***********************************************
* Board Layout:
* _________________
* |               |
* |               |
* |N              |
* |p P            |
* |               |
* |               |
* |               |
* |               |
* -----------------
***********************************************/
void TestPiece::testGetMoves_Pawn_Enpassant()
{
	// set
	Board chessBoard;

	for (int i = 0; i < 64; i++)
	{
		chessBoard.board[i] = '-';
	}
	chessBoard.board[16] = 'N';
	chessBoard.board[24] = 'p';
	chessBoard.board[25] = 'P';

	Pawn pawn(5, 1, true);


	// execute
	vector<Position> posMoves = pawn.getMoves(chessBoard);

	// verify
	assert(posMoves[0].col == 2);
	assert(posMoves[0].row == 6);
	assert(posMoves.size() == 1);

	// teardown
	teardown(pawn);
}

/***********************************************
* Board Layout:
* _________________
* |               |
* |p              |
* |               |
* |               |
* |               |
* |               |
* |               |
* |               |
* -----------------
***********************************************/
void TestPiece::testGetMoves_Pawn_Promotion()
{
	// set
	Board chessBoard;

	for (int i = 0; i < 64; i++)
	{
		chessBoard.board[i] = '-';
	}
	chessBoard.board[8] = 'p';

	Pawn pawn(7, 1, true);


	// execute
	vector<Position> posMoves = pawn.getMoves(chessBoard);

	// verify
	assert(posMoves[0].col == 1);
	assert(posMoves[0].row == 8);
	assert(posMoves.size() == 1);
	assert(pawn.getLetter() == 'q');

	// teardown
	teardown(pawn);
}

//
// test getMoves for king
//

/***********************************************
* Board Layout:
*   1 2 3 4 5 6 7 8
*  _________________
* 8|               |
* 7|               |
* 6|               |
* 5|               |
* 4|      k        |
* 3|               |
* 2|               |
* 1|               |
*  -----------------
***********************************************/
void TestPiece::testGetMoves_King_FreeSpacesAllAround()
{
	// set
	Board chessBoard;

	for (int i = 0; i < 64; i++)
	{
		chessBoard.board[i] = '-';
	}
	chessBoard.board[35] = 'k';

	King king(4, 4, true);
	Rook rook(0, 0, true);

	// execute
	vector<Position> posMoves = king.getMoves(chessBoard, rook, rook);

	// verify
	assert(posMoves.size() == 8);

	assert(posMoves[0].col == 3);
	assert(posMoves[0].row == 5);

	assert(posMoves[1].col == 4);
	assert(posMoves[1].row == 5);

	assert(posMoves[2].col == 5);
	assert(posMoves[2].row == 5);

	assert(posMoves[3].col == 3);
	assert(posMoves[3].row == 4);

	assert(posMoves[4].col == 5);
	assert(posMoves[4].row == 4);

	assert(posMoves[5].col == 3);
	assert(posMoves[5].row == 3);

	assert(posMoves[6].col == 4);
	assert(posMoves[6].row == 3);

	assert(posMoves[7].col == 5);
	assert(posMoves[7].row == 3);
	
	// teardown
	teardown(king);
}

/***********************************************
* Board Layout:
*   1 2 3 4 5 6 7 8
*  _________________
* 8|               |
* 7|               |
* 6|               |
* 5|    N p p      |
* 4|    p k p      |
* 3|    p p p      |
* 2|               |
* 1|               |
*  -----------------
***********************************************/
void TestPiece::testGetMoves_King_BlockedAllAround()
{
	// set
	Board chessBoard;

	for (int i = 0; i < 64; i++)
	{
		chessBoard.board[i] = '-';
	}
	chessBoard.board[26] = 'N';
	chessBoard.board[27] = 'p';
	chessBoard.board[28] = 'p';
	chessBoard.board[34] = 'p';
	chessBoard.board[35] = 'k';
	chessBoard.board[36] = 'p';
	chessBoard.board[42] = 'p';
	chessBoard.board[43] = 'p';
	chessBoard.board[44] = 'p';

	King king(4, 4, true);
	Rook rook(0, 0, true);

	// execute
	vector<Position> posMoves = king.getMoves(chessBoard, rook, rook);

	// verify
	assert(posMoves.size() == 1);
	assert(posMoves[0].row == 5);
	assert(posMoves[0].col == 3);

	// teardown
	teardown(king);
}

void TestPiece::testGetMoves_King_Capture()
{
	// set
	Board chessBoard;

	for (int i = 0; i < 64; i++)
	{
		chessBoard.board[i] = '-';
	}
	chessBoard.board[26] = 'p';
	chessBoard.board[27] = 'p';
	chessBoard.board[28] = 'p';
	chessBoard.board[34] = 'p';
	chessBoard.board[35] = 'k';
	chessBoard.board[36] = 'p';
	chessBoard.board[42] = 'p';
	chessBoard.board[43] = 'p';
	chessBoard.board[44] = 'p';

	King king(4, 4, true);
	Rook rook(0, 0, true);

	// execute
	vector<Position> posMoves = king.getMoves(chessBoard, rook, rook);

	// verify
	assert(posMoves.size() == 0);

	// teardown
	teardown(king);
}

/***********************************************
* Board Layout:
*   1 2 3 4 5 6 7 8
*  _________________
* 8|               |
* 7|               |
* 6|               |
* 5|               |
* 4|               |
* 3|               |
* 2|p p p p p p p p|
* 1|r       k b n r|
*  -----------------
***********************************************/
void TestPiece::testGetMoves_King_CastleKingHasMoved()
{
	// set
	Board chessBoard;

	for (int i = 0; i < 64; i++)
	{
		chessBoard.board[i] = '-';
	}
	chessBoard.board[48] = 'p';
	chessBoard.board[49] = 'p';
	chessBoard.board[50] = 'p';
	chessBoard.board[51] = 'p';
	chessBoard.board[52] = 'p';
	chessBoard.board[53] = 'p';
	chessBoard.board[54] = 'p';
	chessBoard.board[55] = 'p';
	chessBoard.board[56] = 'r';
	chessBoard.board[60] = 'k';
	chessBoard.board[61] = 'b';
	chessBoard.board[62] = 'n';
	chessBoard.board[63] = 'r';

	King king(1, 5, true);
	king.nMoves = 2;

	Rook rook1(1, 1, true);
	Rook rook2(1, 8, true);
	rook1.nMoves = 0;
	rook2.nMoves = 0;

	// execute
	vector<Position> posMoves = king.getMoves(chessBoard, rook1, rook2);

	// verify
	assert(posMoves.size() == 1);

	// teardown
	teardown(king);
}

/***********************************************
* Board Layout:
*   1 2 3 4 5 6 7 8
*  _________________
* 8|               |
* 7|               |
* 6|               |
* 5|               |
* 4|               |
* 3|               |
* 2|p p p p p p p p|
* 1|r       k b n r|
*  -----------------
***********************************************/
void TestPiece::testGetMoves_King_CastleRookHasMoved()
{
	// set
	Board chessBoard;

	for (int i = 0; i < 64; i++)
	{
		chessBoard.board[i] = '-';
	}
	chessBoard.board[48] = 'p';
	chessBoard.board[49] = 'p';
	chessBoard.board[50] = 'p';
	chessBoard.board[51] = 'p';
	chessBoard.board[52] = 'p';
	chessBoard.board[53] = 'p';
	chessBoard.board[54] = 'p';
	chessBoard.board[55] = 'p';
	chessBoard.board[56] = 'r';
	chessBoard.board[60] = 'k';
	chessBoard.board[61] = 'b';
	chessBoard.board[62] = 'n';
	chessBoard.board[63] = 'r';

	King king(1, 5, true);
	king.nMoves = 0;

	Rook rook1(1, 1, true);
	Rook rook2(1, 8, true);
	rook1.nMoves = 1;
	rook2.nMoves = 1;

	// execute
	vector<Position> posMoves = king.getMoves(chessBoard, rook1, rook2);

	// verify
	assert(posMoves.size() == 1);

	// teardown
	teardown(king);
}

/***********************************************
* Board Layout:
*   1 2 3 4 5 6 7 8
*  _________________
* 8|               |
* 7|               |
* 6|               |
* 5|               |
* 4|               |
* 3|               |
* 2|p p p p p p p p|
* 1|r n     k b n r|
*  -----------------
***********************************************/
void TestPiece::testGetMoves_King_CastleBlocked()
{
	// set
	Board chessBoard;

	for (int i = 0; i < 64; i++)
	{
		chessBoard.board[i] = '-';
	}
	chessBoard.board[48] = 'p';
	chessBoard.board[49] = 'p';
	chessBoard.board[50] = 'p';
	chessBoard.board[51] = 'p';
	chessBoard.board[52] = 'p';
	chessBoard.board[53] = 'p';
	chessBoard.board[54] = 'p';
	chessBoard.board[55] = 'p';
	chessBoard.board[56] = 'r';
	chessBoard.board[57] = 'n';
	chessBoard.board[60] = 'k';
	chessBoard.board[61] = 'b';
	chessBoard.board[62] = 'n';
	chessBoard.board[63] = 'r';

	King king(1, 5, true);
	king.nMoves = 0;

	Rook rook1(1, 1, true);
	Rook rook2(1, 8, true);
	rook1.nMoves = 0;
	rook2.nMoves = 0;

	// execute
	vector<Position> posMoves = king.getMoves(chessBoard, rook1, rook2);

	// verify
	assert(posMoves.size() == 1);

	// teardown
	teardown(king);
}

/***********************************************
* Board Layout:
*   1 2 3 4 5 6 7 8
*  _________________
* 8|               |
* 7|               |
* 6|               |
* 5|               |
* 4|               |
* 3|               |
* 2|p p p p p p p p|
* 1|r       k b n r|
*  -----------------
***********************************************/
void TestPiece::testGetMoves_King_Castle()
{
	// set
	Board chessBoard;

	for (int i = 0; i < 64; i++)
	{
		chessBoard.board[i] = '-';
	}
	chessBoard.board[48] = 'p';
	chessBoard.board[49] = 'p';
	chessBoard.board[50] = 'p';
	chessBoard.board[51] = 'p';
	chessBoard.board[52] = 'p';
	chessBoard.board[53] = 'p';
	chessBoard.board[54] = 'p';
	chessBoard.board[55] = 'p';
	chessBoard.board[56] = 'r';
	chessBoard.board[57] = 'n';
	chessBoard.board[60] = 'k';
	chessBoard.board[61] = 'b';
	chessBoard.board[63] = 'r';

	King king(1, 5, true);
	king.nMoves = 0;

	Rook rook1(1, 1, true);
	Rook rook2(1, 8, true);
	rook1.nMoves = 0;
	rook2.nMoves = 0;

	// execute
	vector<Position> posMoves = king.getMoves(chessBoard, rook1, rook2);

	// verify
	assert(posMoves.size() == 2);
	assert(posMoves[1].row == 1);
	assert(posMoves[1].col == 3);

	// teardown
	teardown(king);
}