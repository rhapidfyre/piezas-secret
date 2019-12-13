#include "Piezas.h"
#include <vector>
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and 
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and 
 * specifies it is X's turn first
**/
Piezas::Piezas() {
  
  turn = X;
  
  // Alloc columns using constructor and populate it with "Blank"
  std::vector<Piece> rowInfo(BOARD_COLS, Blank);
  
  // After two hours of beating my head, I found resize. Let's try it?
  //http://www.cplusplus.com/reference/vector/vector/resize/
  board.resize(BOARD_ROWS, rowInfo);
  
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset() {
  for(int i=0; i<BOARD_ROWS; i++)
    for(int j=0; j<BOARD_COLS; j++)
      board[i][j] = Blank;
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does 
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value 
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/ 
Piece Piezas::dropPiece(int column)
{
    
    // Since the turn always toggles, toggle the turn
    // Capture the current turn to `temp`
    Piece temp = turn;
    Piece next = (turn == X) ? X : O;
      
    if (column < 0 || column >= BOARD_COLS) return Invalid;
    
    // If topmost row is occupied, this column is full
    if (board[2][column] != Blank) {
      return Blank;
    }
    
    // Otherwise a row is available for this column
    else {
      for (int i=0;i<BOARD_ROWS;i++) {
        // Stop at the first blank row and then place the piece
        if (board[i][column] == Blank) {
          board[i][column] = temp;
          return board[i][column];
        }
      }
    }
    
    return Invalid;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{
  
  if (row    >= BOARD_ROWS || row    < 0) return Invalid;
  if (column >= BOARD_COLS || column < 0) return Invalid;
  
  // I thought you could index a vector but this doesn't seem to work.
  // Gives a Seg Fault... But I have no idea.
  return board[row][column];
  
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's 
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/
Piece Piezas::gameState()
{
  /*
  bool gameOver = true;
  for(int i=0; i<BOARD_ROWS; i++)
    for(int j=0; j<BOARD_COLS; j++)
      if (board[i][j] == Blank)
        gameOver = false;
    
  */
  return Blank;
}