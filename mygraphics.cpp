#define _WIN32_WINNT 0x0500 
#include <windows.h> 
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<cstring>
using namespace std;

void myLine(int x1, int y1, int x2, int y2, COLORREF lineColor)
{

	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, lineColor); //2 is the width of the pen
	SelectObject(device_context, pen);
	MoveToEx(device_context, x1 + 650, y1, NULL);
	LineTo(device_context, x2 + 650, y2);
	DeleteObject(pen);

	ReleaseDC(console_handle, device_context);
}
void myRect(int x1, int y1, int x2, int y2, COLORREF lineColor, COLORREF fillColor)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, lineColor);
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(fillColor);
	SelectObject(device_context, brush);

	Rectangle(device_context, x1 + 550, y1, x2 + 550, y2);
	DeleteObject(pen);
	DeleteObject(brush);
	ReleaseDC(console_handle, device_context);
}
void myEllipse(int x1, int y1, int x2, int y2, COLORREF lineColor, COLORREF fillColor)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, lineColor);
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(fillColor);
	SelectObject(device_context, brush);
	Ellipse(device_context, x1 + 650, y1, x2 + 650, y2);
	DeleteObject(pen);
	DeleteObject(brush);
	ReleaseDC(console_handle, device_context);

}

void myDrawText(int x, int y, int ht, int score, COLORREF lineColor, COLORREF fillColor)
{
	CHAR wstr[10] = { 'S','c','o','r','e',':' };
	int i = 9, num;
	while (score % 10 >= 10 && i > 6)
	{
		num = score % 10;
		wstr[i] = num;
		score /= 10;
		i--;
	}
	wstr[6] = score;

	RECT rects;
	rects.left = x;
	rects.top = y;
	rects.right = x + ht;
	rects.bottom = y + ht;//(x,y,x+ht,y+ht);

	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	SetTextColor(device_context, lineColor);
	SetBkColor(device_context, fillColor);
	//DrawText(device_context, wstr, -1, &rects, DT_TOP | DT_NOCLIP);

	ReleaseDC(console_handle, device_context);

}

void myDrawTextWithFont(int x, int y, int ht, char  str[], COLORREF lineColor, COLORREF fillColor)
{
	CHAR wstr[20] = {};
	for (int i = 0;i < 20 && str[i];++i)
		wstr[i] = str[i];

	RECT rects;
	HFONT hFont;
	rects.left = x;
	rects.top = y;
	rects.right = x + ht;
	rects.bottom = y + ht;//(x,y,x+ht,y+ht);

	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);
	hFont = CreateFont(ht, 0, 0, 0, FW_DONTCARE, FALSE, TRUE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
		CLIP_DEFAULT_PRECIS, 1, VARIABLE_PITCH, TEXT("Impact"));
	SelectObject(device_context, hFont);

	SetTextColor(device_context, lineColor);
	SetBkColor(device_context, fillColor);
	//DrawText(device_context,wstr,-1,&rects,DT_TOP|DT_NOCLIP);
	DeleteObject(hFont);
	ReleaseDC(console_handle, device_context);

}

void mySetPixel(int x, int y, COLORREF colorVal)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	SetPixel(device_context, x, y, colorVal);
	ReleaseDC(console_handle, device_context);
}

void drawline(int x1, int y1, int x2, int y2, int choice)
{
	if (choice == 0)
	{
		for (int i = x1; i < x2; i++)
			mySetPixel(i, 0, RGB(255, 255, 255));
	}
}

void drawboard(int **arr , int size)
{
	/*cout << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}*/
	int y, x;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			
			if (arr[j][i] == 0) {
				//x = ((i * 35) + ((i * 35) + 35));
				for (int a = 0;a < 10;a++)
				{
					myRect(i * 35, j * 35, (i * 35) + 35, (j * 35) + 35, RGB(0, 0, 0), RGB(255,0,0));
				}
			}
			else if (arr[j][i] == 1) {
				//x = ((i * 35) + ((i * 35) + 35));
				for (int a = 0; a < 10; a++)
				{
					myRect(i * 35, j * 35, (i * 35) + 35, (j * 35) + 35, RGB(0, 0, 0), RGB(0, 255, 255));
				}
			}
			else if (arr[j][i] == 2) {
				//x = ((i * 35) + ((i * 35) + 35));
				for (int a = 0; a < 10; a++)
				{
					myRect(i * 35, j * 35, (i * 35) + 35, (j * 35) + 35, RGB(0, 0,0), RGB(255, 255, 0));
				}
			}
			else if (arr[j][i] == 3) {
				//x = ((i * 35) + ((i * 35) + 35));
				for (int a = 0; a < 10; a++)
				{
					myRect(i * 35, j * 35, (i * 35) + 35, (j * 35) + 35, RGB(0,0,0), RGB(50,50, 50));
				}
			}
			else if (arr[j][i] == 4) {
				//x = ((i * 35) + ((i * 35) + 35));
				for (int a = 0; a < 10; a++)
				{
					myRect(i * 35, j * 35, (i * 35) + 35, (j * 35) + 35, RGB(0, 0,0), RGB(20, 20, 20));
				}
			}
		}
	}

}


