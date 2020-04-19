//------------------------------------------------------------------
// menuHandler.cpp
//
// Author:           JuanJakobo          
// Date:             19.4.2020
//   
//-------------------------------------------------------------------

#include "inkview.h"
#include "menuHandler.h"


MenuHandler::MenuHandler()
{
    //TODO: height of menu depending on Screensize
    menuHeight = 100;

    DrawTextRect(0,0,ScreenWidth(),menuHeight,"Tik-Tak-Tok",ALIGN_CENTER);
    DrawTextRect(0,0,ScreenWidth(),menuHeight,"Home",ALIGN_LEFT);
    DrawTextRect(0,0,ScreenWidth(),menuHeight,"Menu",ALIGN_RIGHT);

    contentHeight = (ScreenHeight() - PanelHeight() - menuHeight);
    contentWidth  =  ScreenWidth();
    contentBeginX =  0;
    contentBeginY = menuHeight;


    //TODO: include Menu
    //imenu menu[]=
    //{
    //    { ITEM_ACTIVE, 105, "@Exit"},
    //};
    //createMenu(menu);

}

void MenuHandler::drawPanel()
{
    SetHardTimer("PANELUPDATE", panelHandlerStatic, 110000);
	DrawPanel(NULL, "", NULL, -1);

}

void MenuHandler::handleMenu(int index)
{
	switch(index){    	
	case 105:
	 	CloseApp();
	 	break;     
 	}
}

int MenuHandler::getContentHeight()
{
    return contentHeight;
}

int MenuHandler::getContentWidth()
{
    return contentWidth;
}

int MenuHandler::getContentBeginX()
{
    return contentBeginX;
}

int MenuHandler::getContentBeginY()
{
    return contentBeginY;
}

void MenuHandler::panelHandlerStatic() 
{
    //TODO: Clean up
    DrawPanel(NULL, "", NULL, -1);
    SetHardTimer("PANELUPDATE", panelHandlerStatic, 110000);
}

void MenuHandler::createMenu(imenu menu[])
{
    //menu[8].type=ITEM_ACTIVE;
}
