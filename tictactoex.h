/*
 * Dinh Tran
 * tictactoe.h
 *
 * Mar 6, 2019
 * specification file for TicTacToe class to used to update
 * the game, draw board, access player data and run the game.
 */

#ifndef TICTACTOEX_H_
#define TICTACTOEX_H_

class tictactoe {

  public:


    tictactoe(int);
    /*
     * create board with size
     * precondition : size
     * postcondition: new board with a size
     */

    ~tictactoe();
    /*
     * destructor
     * precondition: non
     * postcondition: delete the board;
     */

    tictactoe(const tictactoe&);
    /*
     * copy contructor
     * predondition: obj
     * postcondition: all the element and the board are copied
     */

    tictactoe& operator = (const tictactoe&);
    /*
     * overloaded assignment operator
     * overloaded = operator
     */

    void displayBoard();
    /*
     * constructor display the board
     * precondition: none
     * postcondition: display the board and all
     *                the value contain
     */
    void resetBoard();
    /*
     * constructor reseting the board to empty space
     * precondition: none
     * postcondition: the board is empty with space
     */
    void showStats();
    /*
     * constructor show game stats
     * precondition: none
     * postcondition: print the board number of win of each player
     *                and number of tie
     */

    void setSize();

    int playerTurn(int);
    /*
     * constructor assign the player turn
     * precondition: number of turn
     * postcondition return X turn or O turn
     */

    char getX();
    /*
     * constructor get char X
     * precondition : none
     * postcondition : return char X
     */

    char getO();
    /*
     * constructor get char O
     * precondition : none
     * postcondition : return char O
     */

    bool checkRow(char);
    /*
     * constructor check row
     * precondition : take piece
     * postconeition : return true if 1 row contain all same piece
     */

    bool checkCol(char);
    /*
     * constructor check column
     * precondition : take piece
     * postcondition : return true if 1 column contain all same piece
     */

    bool checkDiag(char);
    /*
     * constructor check diagnal
     * precondition : take piece
     * postcondition : return true if left to right diag contain all
     *                 same piece or right to left diag contain all
     *                 same piece.
     */

    bool placePiece(char, int, int);
    /*
     * constructor check valid move
     * precondition : piece, number of row and number of column
     * postcondition: return if the place is valid or invalid
     */

    bool winner(char);
    /*
     * constructor check if there is a winner
     * precondition : piece
     * postcondition: return true if checkRow or checkCol or
     *                checkDiag is true
     */

    bool checkTie();
    /*
     * constructor check if it is a tie
     * precondition : none
     * postcondition: return if there is a tie
     */

  private:
    char ** board; // the 2d board
    int playerX_Win = 0; // number of wins of player X
    int playerO_Win = 0; // number of wins of player O
    int playerTie = 0; // number of tie game
    int size; // the size of board
    static const char SPACE = ' '; // constant variable space
    static const int COL_WIDTH = 3; // constant variable comlumn width
    static const char VERTICAL = '|'; // constant variable vertical
    static const char DASH = '-'; // constant variable dash
    static const char X = 'X'; // constant variable X
    static const char O = 'O'; // constant variable O

};

#endif /* TICTACTOEX_H_ */
