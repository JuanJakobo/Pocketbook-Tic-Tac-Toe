//------------------------------------------------------------------
// game.h
//
// Author:           JuanJakobo          
// Date:             19.4.2020
// Description:      Contains the tik-tak-toe game logic    
//-------------------------------------------------------------------

#ifndef GAME
#define GAME

#include <vector>
#include "field.h"
 
class Game {
    public:

        /**
        * Constructor sets move to 0  
        */
        Game();

        /**
        * Getter for move
        * 
        * @return int move 
        */
        int getMove();

        /**
        * Draws the game board and filles the boardfiles vector
        * 
        * @param boardBeginX horizontal begin of the board
        * @param boardBeginY vertical begin of the board
        * @param boardWidth  width of the board
        * @param boardHeight heigth of the board
        * @return void
        */
        void drawBoard(int boardBeginX, int boardBeginY, int boardWidh, int boardHeight);

        /**
        * Iterates throw boardfields array and paints the move
        * 
        * @param x x coordinate of the point 
        * @param y y coordinate of the point
        * @return bool true if the field is empty
        */
        bool doMove(int x, int y);

        /**
        * Calculates if it is O or X turn
        * 
        * @return char* name of the player 
        */
        char *whosTurn();


        /**
        * Tests if the game is over
        * 
        * @return bool returns true if the move counts equals the fieldscount
        */
        bool gameOver();


        /**
        * Checks if a player has won
        *
        * @return bool true if a player has won
        */
        bool checkForWinner();

    private:
        std::vector<Field> boardfields;
        int yFieldCount;
        int xFieldCount;        
        int fieldsCount;
        int move;
        int fieldHeight;

};



#endif
