/*
 *	Dinh Tran
 *	tictactoe.cpp
 *	Mar 6, 2019
 * 	Purpose: implementation for tictactoe.h and
 * 	         used to run the game from welcome message
 * 	         , displayboard, resetboard, check valid
 * 	         location, check player turn, check winner and tie
 * 	         to show game and player stats and good bye message
 */


#include "tictactoex.h"

#include <iomanip>
#include <cstdlib>
#include <iostream>
using namespace std;

tictactoe :: tictactoe(int s) {
  // this is constructor create board with size

  // input : size
  // modify: create the 2 dimensional array
  // output: 2 dimensional array

  size = s;

  board = new char*[s];
  for (int i = 0; i < s; i++){
    board[i] = new char [s];
  }
}

tictactoe :: ~tictactoe() {
  // this is destructor

  // input : none
  // modify: this will delete the board
  // output: none

  for (int i = 0; i < size; i++){
    delete[] board[i];
  }
  delete[] board;
}

tictactoe :: tictactoe(const tictactoe &obj) {
  // this is a copy instructor

  // input : obj
  // modify: copy all contains and stats and board to new board
  // output: new board with all the contain and data same as obj

  // copy data
  playerX_Win = obj.playerX_Win;
  playerO_Win = obj.playerO_Win;
  playerTie = obj.playerTie;
  size = obj.size;

  // create new board and copy all to new board
  board = new char*[size];
  for (int i = 0; i < size; i++){
    board[i] = new char [size];
  }

  for (int r = 0; r < size; r++) {
    for (int c = 0; c < size; c++) {
      board[r][c] = obj.board[r][c];
    }
  }
}

tictactoe& tictactoe :: operator = (const tictactoe & obj) {
  // overloading operation
  // overload = operation

  // input : obj
  // modify: copy all data an contain to new board
  // output: new board with the same data and contain

  if (this != &obj) {
    for (int i = 0; i < size; i++)
      delete[] board[i];
    delete[] board;

    playerX_Win = obj.playerX_Win;
    playerO_Win = obj.playerO_Win;
    playerTie = obj.playerTie;

    board = new char*[size];
    for (int i = 0; i < size; i++){
      board[i] = new char [size];
    }

    for (int r = 0; r < size; r++) {
      for (int c = 0; c < size; c++) {
        board[r][c] = obj.board[r][c];
      }
    }
  }
    return *this;
}

void tictactoe::displayBoard() {
  // display board

  // input : none
  // modify: display the board with space
  // output: print out the board

  cout << endl << endl;
   for (int i = 0; i < COL_WIDTH - 1; i++)
      cout << SPACE;
   for (int i = 0; i < size; i++)
      cout << setw(COL_WIDTH) << i;
   cout << endl;
   for (int r = 0; r < size; r++) {
      cout << setw(COL_WIDTH) << r;
      for (int c = 0; c < size; c++)
         cout << SPACE << board[r][c] << VERTICAL;
      cout << endl;
      for (int i = 0; i < COL_WIDTH; i++)
         cout << SPACE;
      for (int d = 0; d < size * COL_WIDTH; d++)
         cout << DASH;
      cout << endl;
   }
}

void tictactoe :: resetBoard() {
  // reset board to only space

  // input : none
  // modify: fill the board will all the space
  // output: none

  for (int row = 0; row < size; row++) {
    for (int col = 0; col < size; col++) {
      board[row][col] = SPACE;
    }
  }
}

void tictactoe :: showStats() {
  // show stat

  // input : none
  // modify: none
  // output: print out game stats and the board.
  displayBoard();
  cout << "\n\nGame Stats" << endl;
  cout << "X win    : " << playerX_Win <<endl;
  cout << "O win    : " << playerO_Win <<endl;
  cout << "Game tie : " << playerTie <<endl;
}

int tictactoe :: playerTurn(int t) {
  // check whose turn

  // input : turn t
  // modify: if turn % 2 == 0 then is X turn other O turn
  // output: char X or char O

  if (t % 2 == 0) {
    cout << "X turn: " << endl;
    return getX();
  }
    cout << "O turn: " << endl;
    return getO();
}

char tictactoe :: getX() {
  // getX

  // input : none
  // modify: none
  // output: return char X

  return X;
}

char tictactoe :: getO() {
  // getO

  // input: none
  // modify: none
  // output: return char O

  return O;
}

bool tictactoe :: checkRow(char piece) {
  // check row

  // input : piece
  // modify: if the row contain the same piece return true
  // output: true or false

  int rowCheck = 0;

  // run through each row and add 1 to rowCheck if it contain same
  for (int r = 0; r < size; r++) {
    for (int c = 0; c < size; c++) {
      if (board[r][c] == piece) {
        rowCheck++;
      }
    }
    if (rowCheck == size) {
      if (piece == X) {
        cout << "X win this game!!!" << endl;
        playerX_Win++;
      } else {
        cout << "O win this game!!!" << endl;
        playerO_Win++;
      }
      return true;
    }
    rowCheck = 0;
  }
  return false;

}

bool tictactoe :: checkCol(char piece) {
  // check columns

  // input : piece
  // modify: if the columns contain the same piece return true
  // output: true or false

  int colCheck = 0;
  for (int c = 0; c < size; c++) {
    colCheck = 0;
    for (int r = 0; r < size; r++) {
      if (board[r][c] == piece) {
        colCheck++;
      }
    }

    if (colCheck == size) {
      if (piece == X) {
        cout << "X win this game!!!" << endl;
        playerX_Win++;
      } else {
        cout << "O win this game!!!" << endl;
        playerO_Win++;
      }
      return true;
    } else {
      colCheck = 0;
    }
  }
  return false;
}

bool tictactoe :: checkDiag(char piece) {
  // check diagonal

  // input : piece
  // modify: if the diagonal contain the same piece return true
  // output: true or false

  int checkL_Diag = 0, checkR_Diag = 0;

  for (int r = 0; r < size; r++) {
    for (int c = 0; c < size; c++) {
      if (c == r){
        if (board[r][c] == piece) {
          checkR_Diag++;
        }
      }

      if (c + r == 2) {
        if (board[r][c] == piece) {
          checkL_Diag++;
        }
      }
    }
  }

  if (checkL_Diag == size || checkR_Diag == size) {
    if (piece == X) {
      checkL_Diag = 0, checkR_Diag = 0;
      cout << "X win this game!!!" << endl;
      playerX_Win++;
      return true;
    } else {
      checkL_Diag = 0, checkR_Diag = 0;
      cout << "O win this game!!!" << endl;
      playerO_Win++;
      return true;
    }
  } else {
    checkL_Diag = 0, checkR_Diag = 0;
    return false;
  }
}

bool tictactoe :: placePiece(char piece, int row, int col) {
  // check if the place if empty

  // input : piece, row, column
  // modify: if the row and col chosen not space then return false
  // output: true or false

  cout << "Choose row: ";
  cin >> row;
  cout << "Choose col: ";
  cin >> col;
  if (row < size && col < size) {
    if (board [row][col] == ' ') {
    board[row][col] = piece;
    return true;
    }
  }
  cout << endl;
  cout << "INVALID MOVE. Please try again" << endl;
  return false;
}

bool tictactoe :: winner(char piece) {
  // check winner

  // input : piece
  // modify: none
  // output: return true when one of checkRow, checkCol,
  //         checkDiag true

  return checkRow(piece) || checkCol(piece)
      || checkDiag(piece);
}

bool tictactoe :: checkTie() {
  // check tie

  // input : none
  // modify: check if all the space are filled
  // output: return true if all space are filled

  int filled = 0;
  for (int r = 0; r < size; r++) {
    for (int c = 0; c < size; c++) {
      if (board[r][c] != SPACE) {
        filled++;
      }
    }
  }

  if (filled == size*size) {
    cout << "Out of Move!! \nThis game is tie" << endl;
    playerTie ++;
    return true;
  } else {
    return false;
  }
}
