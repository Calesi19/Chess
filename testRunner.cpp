/***********************************************************************
 * CPP File:
 *    Test Runner : Run Unit tests
 * Author:
 *    Br. Helfrich
 * Summary:
 *    This will initialize the test files and run their respective tests.
 ************************************************************************/

#pragma once
#include "testBoard.h"
#include "testPiece.h"

class testRunner
{
public:
   void run()
   {
      testBoard testB;
      testB.run();
      TestPiece testP;
      testP.run();

   };


};