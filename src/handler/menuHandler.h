//------------------------------------------------------------------
// eventHandler.h
//
// Author:           JuanJakobo          
// Date:             19.4.2020
// Description:      Handles the menubar and the menu   
//-------------------------------------------------------------------

#ifndef MENU_HANDLER
#define MENU_HANDLER


class MenuHandler {
    public:
        /**
        * Defines fonds, sets global Event Handler and starts new content 
        */
        MenuHandler();

        /**
        * Functions needed to call C function, redirects to real function
        * 
        * @param type event type
        * @param par1 first argument of the event
        * @param par2 second argument of the event
        * @return int returns if the event was handled
        */
        void drawPanel();

        int getContentHeight();
        int getContentWidth();
        int getContentBeginX();
        int getContentBeginY();

    private:
        int menuHeight;
        int contentHeight;
        int contentWidth;
        int contentBeginX;
        int contentBeginY;

        /**
        * Functions needed to call C function, handles the panel
        * 
        * @return void
        */
        static void panelHandlerStatic(); 

};



#endif
