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

    menuHeight = 100;

    ifont* font = OpenFont("LiberationMono-Bold",menuHeight/2,1);
    SetFont(font, BLACK);

    DrawTextRect(0,0,ScreenWidth(),menuHeight,"Tik-Tak-Tok",ALIGN_CENTER);

    contentHeight = (ScreenHeight() - PanelHeight() - menuHeight);
    contentWidth  =  ScreenWidth();
    contentBeginX =  0;
    contentBeginY = menuHeight;

}

void MenuHandler::drawPanel()
{
    SetHardTimer("PANELUPDATE", panelHandlerStatic, 110000);
	DrawPanel(NULL, "", NULL, -1);

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
    DrawPanel(NULL, "", NULL, -1);
    SetHardTimer("PANELUPDATE", panelHandlerStatic, 110000);
}

