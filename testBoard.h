#pragma once
#include <iostream>
#include "board.h"
#include <cassert>

using namespace std;


class testBoard
{

public:

	void run() {
		cout << "Testing: constructor" << endl;
		test_constructor();
		cout << "Constructor success" << endl;

		//test_getCurrentMove_noMoves();

		//test_getCurrentMove_multipleMoves();

		cout << "Testing: whiteTurn as white" << endl;
		test_whiteTurn_whiteTurn();
		cout << "White turn success" << endl;

		cout << "Testing: whiteTurn as black" << endl;
		test_whiteTurn_blackTurn();
		cout << "Black turn success" << endl;

		cout << "Testing: Get a piece from the board" << endl;
		test_get_getPawn();
		cout << "get pawn success" << endl;

		cout << "Testing: free up king space" << endl;
		test_free_freeUpKing();
		cout << "free king success" << endl;

		cout << "skip Testing: test board reset" << endl;
		//test_reset_resetBoardToDefault();
		cout << "Reset success" << endl;

		cout << "skip Testing: pawn forward twice" << endl;
		//test_move_movePawnForwardTwice();
		cout << "pawn moved forward twice success" << endl;

		cout << "Testing: move Knight" << endl;
		test_move_moveKnight();
		cout << "kinght move success" << endl;

		cout << "Testing: assign king square pawn " << endl;
		test_assign_kingSquarePawn();
		cout << "King square now pawn success" << endl;

		cout << "Testing: swap king spaces" << endl;
		test_swap_swapKings();
		cout << "King swap success" << endl;

	}

private:

	void test_constructor() const {
		//Setup
		Board board;
		//for counting how many peices are on the board
		int blackPawns;
		int blackRooks;
		int blackKnights;
		int blackBishops;
		int blackQueen;
		int blackKing;

		int whitePawns;
		int whiteRooks;
		int whiteKnights;
		int whiteBishops;
		int whiteQueen;
		int whiteKing;


		//Exercise

		for (int i = 0; i < 64; i++) {

			char pieceLetter = board.get(i).getLetter();

			switch (pieceLetter) {

			case 'p':
				blackPawns++;

			case 'r':
				blackRooks++;

			case 'k':
				blackKnights++;

			case 'b':
				blackBishops++;

			case 'q':
				blackQueen++;

			case 't':
				blackKing++;

			case 'P':
				whitePawns++;

			case 'R':
				whiteRooks++;

			case 'K':
				whiteKnights++;

			case 'B':
				whiteBishops++;

			case 'Q':
				whiteQueen++;

			case 'T':
				whiteKing++;
			}
		}


		//Verify
		//check that the board has the correct number of peices.
		assert(board.getCurrentMove() == 0);

		assert(blackPawns == 8);
		assert(blackRooks == 2);
		assert(blackKnights == 2);
		assert(blackBishops == 2);
		assert(blackQueen == 1);
		assert(blackKing == 1);

		assert(whitePawns == 8);
		assert(whiteRooks == 2);
		assert(whiteKnights == 2);
		assert(whiteBishops == 2);
		assert(whiteQueen == 1);
		assert(whiteKing == 1);


		//Teardown
	};

	void test_getCurrentMove_noMoves() const {

		//Setup
		Board board;

		//Exercise
		int currentMove = board.getCurrentMove();

		//Verify
		assert(currentMove == 0);

		//Teardown
	};

	//uncomment out when move is done
	//void test_getCurrentMove_multipleMoves() const {

	//	//Setup
	//	Board board;
	//	Piece piece = board.get(2);
	//	Move moves[] = piece.getMoves(board);

	//	//Exercise
	//	board.move(moves[1]);
	//	int currentMove = board.getCurrentMove()

	//	//Verify
	//	assert(currentMove == 1);

	//	//Teardown
	//};



	void test_whiteTurn_whiteTurn() const {

		//Setup
		Board board;

		//Exercise
		bool isWhiteTurn = board.whiteTurn();

		//Verify
		assert(isWhiteTurn == true);

		//Teardown

	};

	void test_whiteTurn_blackTurn() const {

		//Setup
		Board board;
		Piece piece = board.get(2);
		//Move moves[] = piece.getMoves(board);
		//board.move(moves[1]);

		//temp move, only increments current move count
		board.move();

		//Exercise
		bool isWhiteTurn = board.whiteTurn();

		//Verify
		assert(isWhiteTurn == true);

		//Teardown

	};


	void test_get_getPawn() const {

		//Setup
		Board board;

		//Exercise
		Piece piece = board.get(9);

		//Verify
		assert(piece.getLetter()) == 'p'); //how do we know if its pawn

		//Teardown

	};

	void test_reset_resetBoardToDefault() const {

		//Setup
		Board board;

		//Exercise
		board.swap(9, 3);
		board.reset();

		//Verify
		assert(board.get(9).getLetter()) == 'p'); //how do we know if its pawn

		//Teardown

	};

	void test_move_movePawnForwardTwice() const {

		//Setup
		Board board;
		Piece piece = board.get(9);
		Move moves[] = piece.getMoves(board);

		//Exercise
		board.move(moves[1]);

		//Verify
		assert(board.get(22).getLetter()) == 'p'); //how do we know if its pawn

		//Teardown

	};

	void test_move_moveKnight() const {

		//Setup
		Board board;
		Piece piece = board.get(2);
		Move moves[] = piece.getMoves(board);

		//Exercise
		board.move(moves[1]);

		//Verify
		assert(board.get(16).getLetter()) == 'k'); //how do we know if its knight

		//Teardown


	};

	void test_assign_kingSquarePawn() const
	{
		//Setup
		Board board;
		Piece test_pawn = Piece('p');

		//Exercise
		board.assign(test_pawn, 5);

		//Verify
		assert(board.get(5).getLetter() == 'p'); // king square should now be a pawn

		//Teardwon
	};

	void test_swap_swapKings() const {

		//Setup
		Board board;


		//Exercise
		board.swap(5, 61);

		//Verify
		assert(board.get(5).getLetter() == 't'); //how do we know if its king
		assert(board.get(61).getLetter() == 'T'); //how do we know if its king

		//Teardown


	};

	test_free_freeUpKing()
	{
		//Setup
		Board board;

		//Exercise
		board.free(5);

		//Verify
		assert(board.get(5).getLetter() == 'e'); // 'e' should be an empty space

		//Teardwon

	};


};