//------------------------------------------------------------------
// eventHandler.cpp
//
// Author:           JuanJakobo          
// Date:             19.4.2020
//   
//-------------------------------------------------------------------

#include "inkview.h"
#include "eventHandler.h"
#include "menuHandler.h"
#include "game.h"
#include <string>

EventHandler * EventHandler::eventHandlerStatic;

EventHandler::EventHandler()
{

        //Sets eventDistributor as global EventHandler
        eventHandlerStatic = this;
        SetEventHandler(EventHandler::eventDistributorStatic);

        //Start new Content
        startNewGame();

}

EventHandler::~EventHandler()
{
        delete game;
        delete menu;
        delete eventHandlerStatic;
}




void EventHandler::startNewGame()
{

    if(game!=nullptr && menu!=nullptr)
    {
        //delete game;
        game=nullptr;
        menu=nullptr;
        result.clear();
    }

    menu = new MenuHandler("Tik-Tak-Tok");
    menu->drawPanel();

    game = new Game();
    game->drawBoard(menu->getContentBeginX(), menu->getContentBeginY(), menu->getContentWidth(), menu->getContentHeight());

    FullUpdate();

}

int EventHandler::eventDistributorStatic(int type, int par1, int par2)
{
    return eventHandlerStatic->eventDistributor(type,par1,par2);
}

int EventHandler::eventDistributor(int type, int par1, int par2)
{

    if (ISPOINTEREVENT(type))
		return EventHandler::pointerHandler(type,par1,par2);

    return 0;

}

int EventHandler::pointerHandler(int type, int par1, int par2)
{
    if(type==EVT_POINTERDOWN)
    {
        if(game->doMove(par1,par2))
        {
            if(game->getMove()>3)
            {

                if(game->checkForWinner())
                {
                    result = game->whosTurn() + " has won.";
                }
                else if(game->gameOver())
                {
                    result = "Nobdoy has won.";
                }

                if(!result.empty())
                {
                    Dialog(2,"Result",result.c_str(),"New game","Close",EventHandler::DialogHandlerStatic);

                }
            }

            game->nextMove();

        }

        return 1;
    }

    return 0;

}

void EventHandler::DialogHandlerStatic(int Button)
{
	Button==1 ? ClearScreen() : CloseApp();
        eventHandlerStatic->startNewGame();

}