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

using namespace std;


Game::Game():move(0){
        
}

int Game::getMove()
{
        return move;
}

void Game::drawBoard(int boardBeginX, int boardBeginY, int boardWidh, int boardHeight)
{
        yFieldCount = 3;
        xFieldCount = 3;

        int fieldHeight = boardHeight / yFieldCount;
        int fieldWidth = boardWidh / xFieldCount;
        int fieldBeginY;
        
        fieldsCount = yFieldCount * xFieldCount; 


        for (int i = 0; i < xFieldCount; i++)
        {       
                for (int j = 0; j < yFieldCount; j++)
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

bool Game::checkFields(int x, int y){


        //TODO: font size depending on field size
        ifont* font = OpenFont("LiberationMono",200,1);
        SetFont(font, BLACK);

        for (unsigned int i = 0; i < boardfields.size(); i++)
        {
                if(boardfields[i].pointInsideField(x,y))
                {
                        if(boardfields[i].containsContent()){
                                //TODO: select correct bitmap id
                                Message(1,"Error","This move is not possible",100);
                                return false;
                        }else{
                                //TODO: move 
                                doMove(i);
                                return true;
                        }
                }
        }

        return false;
        

}

void Game::doMove(int fieldID)
{
        boardfields[fieldID].setContent(whosTurn());

        move++;
        //TODO: draw on screen whos turn it is

        boardfields[fieldID].updateFieldArea();

}

char *Game::whosTurn(){
        if(move%2==0)
                return  "O";
        return "X";
}


bool Game::gameOver(){
        if(move==fieldsCount)
                return true;
        return false;
}

bool Game::checkForWinner(){

        //Row 1
        if(boardfields[0].containsContent() && boardfields[0].compareContent(boardfields[1]) && boardfields[1].compareContent(boardfields[2]))
        {
            return true;
        }  
        //row 2
        else if(boardfields[3].containsContent() && boardfields[3].compareContent(boardfields[4]) && boardfields[4].compareContent(boardfields[5]))
        {
            return true;   
        }
        //Row 3
        else if(boardfields[6].containsContent() && boardfields[6].compareContent(boardfields[7]) && boardfields[7].compareContent(boardfields[8]))
        {
            return true;   
        }
        //Column 1
        else if(boardfields[0].containsContent() && boardfields[0].compareContent(boardfields[3]) && boardfields[3].compareContent(boardfields[6]))
        {
            return true;   
        }
        //Column 2
        else if(boardfields[1].containsContent() && boardfields[1].compareContent(boardfields[4]) && boardfields[4].compareContent(boardfields[7]))
        { 
            return true;   
        }
        //Column 3
        else if(boardfields[2].containsContent() && boardfields[2].compareContent(boardfields[5]) && boardfields[5].compareContent(boardfields[8]))
        {
            return true;   
        }
        //Diagonal 1
        else if(boardfields[0].containsContent() && boardfields[0].compareContent(boardfields[4]) && boardfields[4].compareContent(boardfields[8]))
        {
            return true;   
        }
        //Diagonal 2
        else if(boardfields[2].containsContent() && boardfields[2].compareContent(boardfields[4]) && boardfields[4].compareContent(boardfields[6]))
        { 
            return true;   
        }

        return false;

}

