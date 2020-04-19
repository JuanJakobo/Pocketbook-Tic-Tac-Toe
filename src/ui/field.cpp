//------------------------------------------------------------------
// field.cpp
//
// Author:           JuanJakobo          
// Date:             19.4.2020
//   
//-------------------------------------------------------------------


#include "field.h"
#include "inkview.h"
#include <string>

Field::Field(int X, int Y, int wid, int hei): startX(X), startY(Y), width(wid), height(hei){};

bool Field::compareContent(Field &field)
{
    if(field.containsContent() && std::strcmp(content,field.getContent())==0)
        return true;
    return false;
    
}

void Field::setContent(char *con){
    content = con;
    DrawTextRect(startX,startY,width,height,content, ALIGN_CENTER);
}

char *Field::getContent()
{
    return content;
};

void Field::drawField(){
    DrawRect(startX,startY,width,height,BLACK);
}

void Field::updateFieldArea()
{
    PartialUpdate(startX,startY,width,height);
}


bool Field::pointInsideField(int x, int y)
{
    if(x > startX && x < (startX + height) && y > startY && y < (width+startY))
        return true;
    return false;

}

bool Field::containsContent()
{
    if ((content != NULL)) 
        return true;
    return false;
}





