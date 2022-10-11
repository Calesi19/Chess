#pragma once

#include "piece.h"
#include "uiDraw.h"

//nothing
class Board {
private:
   Piece pieces[64];
   int currentMove;
   ogstream gout;
public:
   //constructor
   //Board(gout, reset); probably just calls reset on start up so there is no repeated code?
   Board()
   {
      reset();
   };
   int getCurrentMove() { return currentMove; };
   bool whiteTurn() { return currentMove % 2; };
   //void display(posHover, posSelect);
   Piece get(int index) { return pieces[index]; }
   void free(int index) { pieces[index] ; };
   void reset()
   {
      // Generate 
      Piece Rook();
      Piece Knight();
      Piece Queen();
      Piece King();
      Piece Bishop();
      Piece Pawn();

      for (int i = 0; i < 64; i++)
      {
         switch (i)
         {
         case 0:

            
            pieces[i] = wRook;
         case 7:
            
            break;
         case 56:
            
            break;
         case 63:
            // Rooks generated
            break;
         case 1:
         case 6:
         case 57:
         case 62:
            // Knights generated
            break;
         case 2:
         case 5:
         case 58:
         case 61:
            // Bishops generated
            break;
         case 3:
         case 59:
            // Queens generated
            break;
         case 4:
         case 60:
            // Kings generated
            break;
         case 8:
         case 9:
         case 10:
         case 11:
         case 12:
         case 13:
         case 14:
         case 15:
         case 48:
         case 49:
         case 50:
         case 51:
         case 52:
         case 53:
         case 54:
         case 55:

            // pawns generated
            break;
         default:
            // Empyt Pieces generated
         }
      }
   };
   void move() { currentMove++; };
   void assign(Piece newPiece, int pos) { pieces[pos] = newPiece; };
   void swap(int pos1, int pos2)
   {
      Piece temp;
      temp = pieces[pos1];
      pieces[pos1] = pieces[pos2];
      pieces[pos2] = temp;
   };
   //assertboard();
};





