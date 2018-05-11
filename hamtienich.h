#ifndef _HAMTIENICH
#define _HAMTIENICH

#include<windows.h>
#include <stdio.h>
#include <conio.h>
#define key_Up		1072
#define key_Down	1080
#define key_Left	1075
#define key_Right	1077
#define key_none	-1

//cai dat mau chu,mau nen
void TextColor (int );

//dua con tro toi vi tri tuong ung
void gotoXY(int,int);

//an,hien con tro tren man hinh
void ShowCur(bool );

//kiem tra viec nhap ban phim
int inputKey();

//xoa man hinh
void clrscr();
#endif // _HAMTIENICH







