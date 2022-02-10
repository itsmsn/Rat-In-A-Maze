#ifndef MYCONSOLE_H
#define MYCONSOLE_H
//this function outputs a string str at position (x,y) of the screen 
void OutputString(int x, int y, char *str);
//this function will clear the screen
void ClearScreen();
//this function is an alternative to ClearScreen(), when ClearScreen() does not work on windows 7
void ClearScreen1();
//this function will place the cursor at a certain position on the screen
void PlaceCursor(int x, int y);
unsigned int CheckWhichKeyPressed(bool &specialKey, int waitTime = 20);
void SetWindowSize(int width, int height);
bool SetColorAtPoint(int x, int y, int color);
//set the title of the window
void SetWindowTitle(char Title[]);
//will get the maximum and minimum x and y coordinates of the current window
void GetMaxWindowCoordinates(int &x, int &y);
void GetMaxWindowSize(int& maxHorizontal, int& maxVertical);
void maximized();

#endif
