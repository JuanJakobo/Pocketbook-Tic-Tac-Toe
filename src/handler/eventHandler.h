//------------------------------------------------------------------
// eventHandler.h
//
// Author:           JuanJakobo          
// Date:             19.4.2020
// Description:      Contains the tik-tak-toe game logic    
//-------------------------------------------------------------------

#ifndef EVENT_HANDLER
#define EVENT_HANDLER

#include "game.h"
#include "menuHandler.h"
#include "string"

using namespace std;

class EventHandler {
    public:
        
        /**
        * Defines fonds, sets global Event Handler and starts new content 
        */
        EventHandler();


        /**
        * Destructor destroys pointer to game and menu  
        */
        ~EventHandler();

        /**
        * Handles events and redirects them
        * 
        * @param type event type
        * @param par1 first argument of the event
        * @param par2 second argument of the event
        * @return int returns if the event was handled
        */
        int eventDistributor(int type, int par1, int par2);

    private:

        static EventHandler *eventHandlerStatic;
        Game *game;
        MenuHandler *menu;
        string result;
 

        /**
        * Creates and draws menu and game; after this updates the screen
        * 
        * @return void
        */
        void startNewGame();

        /**
        * Handles pointer Events
        * 
        * @param type event type
        * @param par1 first argument of the event
        * @param par2 second argument of the event
        * @return int returns if the event was handled
        */
        int pointerHandler(int type, int par1, int par2);

        /**
        * Handles the end of the game dialog and lets the user
        * choose inbetween starting a new game or closing the app
        * 
        * @param Button id of the button that was pressed
        * @return void
        */
        static void DialogHandlerStatic(int Button);

};

#endif