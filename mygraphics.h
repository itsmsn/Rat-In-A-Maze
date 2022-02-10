#ifndef MYGRAPHICS_H
#define MYGRAPHICS_H
#include <windows.h>
void mySetPixel(int x,int y, COLORREF colorVal);
void myLine(int x1, int y1, int x2, int y2, COLORREF lineColor);
void myRect(int x1, int y1, int x2, int y2,COLORREF lineColor,COLORREF fillColor);
void myEllipse(int x1, int y1, int x2, int y2,COLORREF colorForeground,COLORREF colorBackground);
void myDrawText(int x,int y,int ht,int score,COLORREF lineColor,COLORREF fillColor);
void myDrawTextWithFont(int x,int y,int ht,char str[],COLORREF lineColor,COLORREF fillColor);
void drawboard(int **arr, int size);
void drawline(int x1, int y1, int x2, int y2, int choice);
#endif


