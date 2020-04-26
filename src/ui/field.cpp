//------------------------------------------------------------------
// field.cpp
//
// Author:           JuanJakobo          
// Date:             19.4.2020
//   
//-------------------------------------------------------------------


#include "field.h"
#include "inkview.h"
#include "string"

using namespace std;

Field::Field(int X, int Y, int wid, int hei): startX(X), startY(Y), width(wid), height(hei){};

void Field::setContent(string con){
    content = con;
    DrawTextRect(startX,startY,width,height,content.c_str(), ALIGN_CENTER);
}

string Field::getContent()
{
    return content;
}


bool Field::operator==(const Field& f)
{
    if(!f.content.empty() && f.content.compare(content)==0)
        return true;
    return false;
}

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
    if (content.empty()) 
        return false;
    return true;
}