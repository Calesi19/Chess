#pragma once
#include "piece.h"
#include <cassert>

class TestPiece
{
	// code for simplicity
	void run();
	Piece set();
	void teardown(Piece testPiece);

	
	// test assign by position
	void testAssign_Position_King();
	void testAssign_Position_InvalidRow();

	// test assign by piece
	void testAssign_Piece_Queen();
	void testAssign_Piece_Space();
	void testAssign_Piece_King();
	void testAssign_Piece_Rook();
	void testAssign_Piece_Bishop();
	void testAssign_Piece_Knight();
	void testAssign_Piece_Pawn();
	

	// test isWhite
	void testIsWhite_White();
	void testIsWhite_Black();
	void testIsWhite_Space();

	// test isMove
	void testIsMove_InvalidPosition();
	void testIsMove_ValidPosition();
	void testIsMove_Current_Position();

	// test getNMoves
	void testGetNMoves_NoMoves();
	void testGetNMoves_3Moves();

	// test getPosition
	void testGetPosition_ValidPosition();
	void testGetPosition_OutOfBounds();

	// test justMoved
	void testJustMoved_NoMoves();
	void testJustMoved_JustMoved();
	void testJustMoved_OldMove();

	// test getLetter
	void testGetLetter_King();
	void testGetLetter_Queen();
	void testGetLetter_Space();

	// test getMoves for pawn
	void testGetMoves_Pawn_Blocked();
	void testGetMoves_Pawn_SimpleMove();
	void testGetMoves_Pawn_InitialMove();
	void testGetMoves_Pawn_Capture();
	void testGetMoves_Pawn_Enpassant();
	void testGetMoves_Pawn_Promotion();

	// test getMoves for king
	void testGetMoves_King_FreeSpacesAllAround();
	void testGetMoves_King_BlockedAllAround();
	void testGetMoves_King_Capture();
	void testGetMoves_King_CastleKingHasMoved();
	void testGetMoves_King_CastleRookHasMoved();
	void testGetMoves_King_CastleBlocked();
	void testGetMoves_King_Castle();

};
