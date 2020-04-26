//------------------------------------------------------------------
// main.h
//
// Author:           JuanJakobo          
// Date:             19.4.2020
// Description:      sets the inkview main handler   
//-------------------------------------------------------------------

#include "inkview.h"
#include "eventHandler.h"

/**
* Handles events and redirects them
* 
* @param type event type
* @param par1 first argument of the event
* @param par2 second argument of the event
* @return int returns if the event was handled
*/
int Inkview_handler(int type, int par1, int par2){
    

    EventHandler* events = 0;

    if(type==EVT_INIT)
    {
        events = new EventHandler();
        return 1;

    }else if(type==EVT_EXIT)
    {
        delete(events);
        return 1;
    }

    return 0;
}


int main(){

    OpenScreen();
	SetOrientation(0);

    InkViewMain(Inkview_handler);
    return 0;
}