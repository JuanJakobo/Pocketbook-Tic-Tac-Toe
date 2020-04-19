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

        //TODO: Get Language from config
        //TODO: Define fonts once and global 
        ifont* font = OpenFont("LiberationMono",40,1);
        SetFont(font, BLACK);

        //Sets eventDistributor as global EventHandler
        eventHandlerStatic = this;
        SetEventHandler(EventHandler::eventDistributorStatic);

        //TODO:  possibility to set panel inactive
        //void SetPanelType(int type);

        //Start new Content
        startNewGame();


}

EventHandler::~EventHandler()
{
        delete(game);
        delete(menu);
}




void EventHandler::startNewGame()
{
    if(game!=0 && menu !=0)
    {
        delete(game);
        delete(menu);
    }

    menu = new MenuHandler();
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
    {
		return EventHandler::pointerHandler(type,par1,par2);

    //TODO: define key events
	}else if (ISKEYEVENT(type))
    {
        return 0;
    }
    //TODO: Logger

    return 0;

}

int EventHandler::pointerHandler(int type, int par1, int par2)
{

    switch (type)
    {
    case EVT_POINTERDOWN:

       //TODO: only if is content area and not menu!
        if(game->checkFields(par1,par2))
        {
            //TODO: Move this part
            if(game->getMove()>4){
                if(game->checkForWinner()){
                    //TODO: Who has won?
                    Dialog(2,"Result","Somebody has won.","New game","Close",EventHandler::DialogHandlerStatic);
                }else if(game->gameOver()){
                    Dialog(2,"Result","Nobody has won.","New game","Close",EventHandler::DialogHandlerStatic);
                }

            }
            return 1;
        }
        //TODO: Define other pointer events

        return 0;
    default:
        //TODO: Logger
        return 0;
    }

    return 1;

}


//
void EventHandler::DialogHandlerStatic(int Button)
{
	Button==1 ? ClearScreen() : CloseApp();
        eventHandlerStatic->startNewGame();

}








