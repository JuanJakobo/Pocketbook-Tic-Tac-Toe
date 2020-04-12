#include "inkview.h"


void LoadGame(){
    //Writes a simple Hello World String on the screen

    char text[]="Hello World!";
    ifont* font = OpenFont("LiberationMono",40,1);
    SetFont(font, BLACK);
    DrawString(0,0,text);    
    FullUpdate();

}


int inkview_handler(int type, int par1, int par2){
    // main handler of the view, that reacts depending on the event that happend

    if(type==EVT_INIT){
    //Start of the program
        LoadGame();
        
        return 1;
    }

    return 0;
}

int main(){
    //Start of the program

    InkViewMain(inkview_handler);
    return 0;
}
