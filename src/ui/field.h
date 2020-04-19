//------------------------------------------------------------------
// field.h
//
// Author:           JuanJakobo          
// Date:             19.4.2020
// Description:      Handles game fields    
//-------------------------------------------------------------------

#ifndef FIELD
#define FIELD
 
class Field {
    public:

        /**
        * TODO:
        */
        Field(int startX,int startY,int width,int height);

        //TODO: use bool operator==(Rect &rec);
        /**
        * TODO:
        * 
        * @param re 
        * @return bool
        */
        bool compareContent(Field &re);

        /**
        * Setter for content
        * 
        * @param con content
        * @return void
        */
        void setContent(char *con);

        /**
        * Getter for content
        * 
        * @return returns content
        */
        char* getContent();

        /**
        * TODO:
        * 
        * @return void
        */
        void drawField();
        
        /**
        * TODO:
        * 
        * @return void
        */
        void updateFieldArea();

        /**
        * Functions needed to call C function, redirects to real function
        * 
        * @param type event type
        * @param par1 first argument of the event
        * @param par2 second argument of the event
        * @return int returns if the event was handled
        */
        bool pointInsideField(int x, int y);

        /**
        * TODO:
        * 
        * @return bool true if the field has content
        */
        bool containsContent();

    private:
        int startX;
        int startY;
        int width;
        int height;
        char *content;

};



#endif
