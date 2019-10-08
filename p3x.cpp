/*
 *	Dinh Tran
 *	p3.cpp
 *	Mar 6, 2019
 * 	Purpose: this program will run the tictactoe game in size
 * 	         of 3 x 3
 *  Input  : none
 * 	Process: the game will start with welcome message and intruction
 * 	         thought the game
 * 	Output : display the game and stats of the game in the end.
 */

#include <iostream>
#include <string>

#include "tictactoex.h"
using namespace std;

void welcome();
  // welcome message

  // input : none
  // modify: none
  // output: print out welcome message

void goodbye();
  // goodbye message

  // input : none
  // modify: none
  // output: print out goodbye message

int main(){
  // const variable yes
  const char YES = 'y';

  // variable
  bool winner;
  int row = 0, col = 0, turn = 0;
  int size = 0;
  char repeat = YES;

  welcome();
  // game start



  // when repeat is yes run game
  while (repeat == YES) {
    cout << "What size game you want: "
        << "(odd number between 3 to 25): ";
    cin >> size;
    cout << endl;
    if (size < 3 || size > 25 || size % 2 != 1) {
      cout << "------------------------------------------------" << endl;
      cout << "Please choose another odd "
          << "number betwwen 3 to 25" << endl;
    } else {
      tictactoe game(size);
      winner = false;
      game.resetBoard();
      cout << endl;
      cout << "----------------------" << endl;
      cout << "------Game start------" << endl;
      cout << "----------------------" << endl;
      cout << endl;
      // when no winner
      while (winner == false) {
        game.displayBoard();
        // when piece place is unvalid
        while (!game.placePiece(game.playerTurn(turn),row,col)) {
          game.displayBoard();
        }
        // check if game tie
        if (game.checkTie() != true) {
          // check if there is winner
          if (game.winner(game.getO()) != true
              && game.winner(game.getX()) != true) {
            turn++;
          } else {
            winner = true;
            game.showStats();
          }
        }else {
          winner = true;
          game.showStats();
        }

      }
      cout << endl;
      cout << "Continue? !! ( y or n )" ;
      cin >> repeat;
    }
  }
  cout << endl;
  goodbye();


	return 0;
}

void welcome() {

  cout << "--------------------------------------------------" << endl;
  cout << "\nWelcome to TicTacToe! " << endl;
  cout << "This is a TicTacToe game! \nTo win this, "
      << "try to get a hole line or column or diagonal"
      << " filled with the same X or O." << endl;
  cout << endl;
}

void goodbye() {

  cout << "Thank you for playing TicTacToe...good bye!" << endl;
  cout << endl;
}


