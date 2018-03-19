#include<iostream>
#include<windows.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<cstring>
using namespace std;
#define consoleWidth 80
#define consoleHeight 25
#define ROAD 40
enum TrangThai{up,down,left,right};
void TextColor (int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , color);
}
 void gotoXY(int column,int line)
{


	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = {0,0};
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut,' ',csbiInfo.dwSize.X * csbiInfo.dwSize.Y,Home,&dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut,csbiInfo.dwCursorPosition);
}
struct  toado{
    int x,y;
};

struct hinhdang {
    char a[3][3];
};
struct xe
{
    toado td;
    hinhdang hd;
};
void khoitao(xe &xe){
 xe.td.y=consoleHeight-2;
 xe.td.x=ROAD/2;
 xe.hd.a[0][1]='^';
 xe.hd.a[0][0]='0';
 xe.hd.a[0][2]='0';
 xe.hd.a[2][0]='0';
 xe.hd.a[2][2]='0';
 xe.hd.a[1][0]='|';
 xe.hd.a[1][1]='x';
 xe.hd.a[2][1]='-';
 xe.hd.a[1][2]='|';

}
void hienthi(const xe &xe){
    int kdong,kcot,x,y,i;
    for(i=1;i<25;i++)
        {
            gotoXY(1,i);
            cout<<"|"<<endl;
        }
    for(i=1;i<25;i++)
        {
            gotoXY(40,i);
            cout<<"|"<<endl;
        }

    for(kdong=-1;kdong<=1;kdong++)
        for(kcot=-1;kcot<=1;kcot++){
            x=kcot+xe.td.x;
            y=kdong+xe.td.y;gotoXY(x,y);
            gotoXY(x,y);
            cout<<xe.hd.a[kdong+1][kcot+1];
 }
}
int main(){
    xe xe;
    khoitao(xe);
    while (1){
        hienthi(xe);
        Sleep(200);
    }

}
