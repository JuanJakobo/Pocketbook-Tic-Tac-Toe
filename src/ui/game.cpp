//------------------------------------------------------------------
// game.cpp
//
// Author:           JuanJakobo          
// Date:             19.4.2020
//  
//-------------------------------------------------------------------

#include "inkview.h"
#include "game.h"
#include "field.h"

#include <vector>
#include <string>

using namespace std;


Game::Game():move(0){
        
}

int Game::getMove()
{
        return move;
}

void Game::nextMove()
{
    move++;
}

void Game::drawBoard(int boardBeginX, int boardBeginY, int boardWidh, int boardHeight)
{
        yFieldCount = 3;
        xFieldCount = 3;

        fieldHeight = boardHeight / yFieldCount;
        int fieldWidth = boardWidh / xFieldCount;
        int fieldBeginY;
        
        fieldsCount = yFieldCount * xFieldCount; 

        for (auto i = 0; i < xFieldCount; i++)
        {       
                for (auto j = 0; j < yFieldCount; j++)
                {
                        //On the first run the field should start at menuheight
                        if(i == 0)
                        {
                                fieldBeginY = boardBeginY;
                        }else
                        {
                                fieldBeginY = i * fieldHeight + boardBeginY;
                        }
                        boardfields.push_back(Field(j*fieldWidth,fieldBeginY,fieldWidth,fieldHeight));
                        boardfields[boardfields.size()-1].drawField();
                        
                }

        }
}

bool Game::doMove(int x, int y){

        ifont* font = OpenFont("LiberationMono",fieldHeight/2,1);
        SetFont(font, BLACK);

        for(auto& field : boardfields)
        {
                if(field.pointInsideField(x,y))
                {
                        if(field.containsContent())
                        {
                                Message(2,"Information","This move is not possible.",1000);
                                return false;
                        }

                        field.setContent(whosTurn());
                        field.updateFieldArea();
                        return true;
                }

        }
        
        return false;
}


string Game::whosTurn(){
        if(move%2==0)
                return  "O";
        return "X";
}


bool Game::gameOver(){
        if(move==(fieldsCount-1))
                return true;
        return false;
}

bool Game::checkForWinner(){

        //Row 1
        if(boardfields[0].containsContent() && boardfields[0] == boardfields[1] && boardfields[1] == boardfields[2])
        {
            return true;
        }  
        //row 2
        else if(boardfields[3].containsContent() && boardfields[3] == boardfields[4] && boardfields[4] == boardfields[5])
        {
            return true;   
        }
        //Row 3
        else if(boardfields[6].containsContent() && boardfields[6] == boardfields[7] && boardfields[7] == boardfields[8])
        {
            return true;   
        }
        //Column 1
        else if(boardfields[0].containsContent() && boardfields[0] == boardfields[3] && boardfields[3] == boardfields[6])
        {
            return true;   
        }
        //Column 2
        else if(boardfields[1].containsContent() && boardfields[1] == boardfields[4] && boardfields[4] == boardfields[7])
        { 
            return true;   
        }
        //Column 3
        else if(boardfields[2].containsContent() && boardfields[2] == boardfields[5] && boardfields[5] == boardfields[8])
        {
            return true;   
        }
        //Diagonal 1
        else if(boardfields[0].containsContent() && boardfields[0] == boardfields[4] && boardfields[4] == boardfields[8])
        {
            return true;   
        }
        //Diagonal 2
        else if(boardfields[2].containsContent() && boardfields[2] == boardfields[4] && boardfields[4] == boardfields[6])
        { 
            return true;   
        }

        return false;

}
