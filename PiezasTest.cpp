/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/*
TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}
*/


// Tests each enum
TEST(TicTacToeBoard, checkEnums) {
  ASSERT_EQ(X, 'X');
  ASSERT_EQ(O, 'O');
  ASSERT_EQ(Invalid, '?');
  ASSERT_EQ(Blank, ' ');
}


// Ensure setup is proper
TEST(Piezas, buildBoard) {
  
  Piezas pieza;
  for(int i=0; i<BOARD_ROWS; i++)
    for(int j=0; j<BOARD_COLS; j++)
      ASSERT_EQ(pieza.pieceAt(i,j), Blank);
    
}


// Can a piece be placed
TEST(Piezas, placePiece) {
  Piezas pieza;
  ASSERT_EQ(pieza.dropPiece(0), X);
}


// Out of bounds check
TEST(Piezas, placeOut) {
  Piezas pieza;
  ASSERT_EQ(pieza.dropPiece(-1), Invalid);
  ASSERT_EQ(pieza.dropPiece(218), Invalid);
}


// Does the turn toggle properly
TEST(Piezas, testObtain) {
  Piezas pieza;
  
  Piece rx = pieza.dropPiece(0);
  ASSERT_EQ(rx, X) << "Expected X, received: " << rx;
  
  rx = pieze.dropPiece(0);
  ASSERT_EQ(pieza.dropPiece(0), O) << "Expected O, received: " << rx;
  
  rx = pieze.dropPiece(0);
  ASSERT_EQ(pieza.dropPiece(0), X) << "Expected X, received: " << rx;
}


// Ensure board can reset after a piece has been placed
TEST(Piezas, resetBoard) { 
  
  Piezas pieza;
  pieza.dropPiece(0);
  ASSERT_EQ(pieza.pieceAt(0,0), X);
  
  pieza.reset();
  for(int i=0; i<BOARD_ROWS; i++)
    for(int j=0; j<BOARD_COLS; j++)
      ASSERT_EQ(pieza.pieceAt(i,j), Blank);
    
}


// Ensure that pieces dropped don't exceed the maximum
TEST(Piezas, fullColumn) {
  Piezas pieza;
  pieza.dropPiece(0);
  pieza.dropPiece(0);
  pieza.dropPiece(0);
  ASSERT_EQ(pieza.dropPiece(0), Invalid);
}

/* template for C&P
TEST(Piezas, ) {
  
}
*/