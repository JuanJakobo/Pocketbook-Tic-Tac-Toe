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
        * Creates a new field which is definied by its measurements
        * @param startX horizontal start coordinate of the field
        * @param startY vertical start coordinate of the field
        * @param width  width of the field beginning at start point
        * @param height height of the field beginning at start point
        */
        Field(int startX,int startY,int width,int height);

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
        * Compares the content of two fields
        * 
        * @param f argument of class field
        * @return bool returns true if the content of both field is the same
        */
        bool operator==(const Field& f);



        /**
        * Draws a reactangle on the screen  
        * 
        * @return void
        */
        void drawField();
        
        /**
        * Updates the screenarea of the field
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
        * Checks if a field contains a letter or not. 
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
