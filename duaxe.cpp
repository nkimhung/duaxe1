#include<iostream>
#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
#define consoleWidth 80
#define consoleHeight 25
#define ROAD 40
enum TrangThai{up,down,left,right};
void khoitao1(char a[25][41]){
	int i,j;
	fflush(stdin);
	for(i=0;i<24;i++)
		for(j=0;j<41;j++)
			{if(j==0||j==39) a[i][j]=179;
				else
				if(j==40) a[i][j]='\n';
				else
				a[i][j]=32;
			}
	for(i=0;i<=39;i++)
	if(i==0||i==39) a[24][i]=179;
	else a[24][i]=32;
	}
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
void ShowCur(bool CursorVisibility)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor = {1, CursorVisibility};
    SetConsoleCursorInfo(handle, &cursor);
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
    int run=0;
};
struct vc
{
    toado td;
};
void khoitao(xe &xe,vc &vc){
    int i;
 xe.td.y=consoleHeight-3;
 xe.td.x=ROAD/2;
 xe.hd.a[0][1]='^';
 xe.hd.a[0][0]='0';
 xe.hd.a[0][2]='0';
 xe.hd.a[2][0]='0';
 xe.hd.a[2][2]='0';
 xe.hd.a[1][0]='|';
 xe.hd.a[1][1]='X';
 xe.hd.a[2][1]='-';
 xe.hd.a[1][2]='|';
 /*for(i=0;i<=2;i++)
 {*/
 vc.td.x=3+rand()%36;
 vc.td.y=-2;
 /*}*/
 }
void hienthi(const xe &xe,const vc &vc,char a[25][41]){
	int kdong,kcot,x,y,i;

	for(kdong=-1;kdong<=1;kdong++)
        for(kcot=-1;kcot<=1;kcot++){
            x=kcot+xe.td.x;
            y=kdong+xe.td.y;
            a[y-1][x-1]=xe.hd.a[kdong+1][kcot+1];
			}

    	for(kdong=-1;kdong<=1;kdong++)
        	{
            	x=vc.td.x-1;
            	y=kdong+vc.td.y;
                if(y>0&&y<26){
            		a[y-1][x-1]=33;
            		a[y-1][x]=33;
            		a[y-1][x+1]=33;}
			}
    gotoXY(0,0);
    cout<<a[0];
    gotoXY(40,22);
    cout<<"              ";

}

void dieukhien(xe &xe){
    if(kbhit()){
    char key =_getch();
    if(key=='j'&&xe.td.x>3)
       {xe.td.x--;
       xe.run=1;}
    else
        if(key=='l'&&xe.td.x<ROAD-2)
            {xe.td.x++;
            xe.run=3;}
        else
            if(key=='i'&&xe.td.y>2)
                {xe.td.y--;
                xe.run=5;}
            else
                if(key=='k'&&xe.td.y<=consoleHeight-2)
                {xe.td.y++;
                xe.run=2;}
    }
}

void xoa( const xe &xe,const vc&vc,char a[25][41]){

    if(vc.td.y>=3 && vc.td.y<28)
    {
    a[vc.td.y-3][vc.td.x-2]=32;
    a[vc.td.y-3][vc.td.x-1]=32;
    a[vc.td.y-3][vc.td.x]=32;
    }
switch(xe.run){
case 3:
    a[xe.td.y-2][xe.td.x-3]=32;
    a[xe.td.y-1][xe.td.x-3]=32;
    a[xe.td.y][xe.td.x-3]=32;
    break;
case 1:
    a[xe.td.y-2][xe.td.x+1]=32;
    a[xe.td.y-1][xe.td.x+1]=32;
    a[xe.td.y][xe.td.x+1]=32;
    break;
case 5:
   	a[xe.td.y+1][xe.td.x-2]=32;
    a[xe.td.y+1][xe.td.x-1]=32;
    a[xe.td.y+1][xe.td.x]=32;
    break;
case 2:
    a[xe.td.y-3][xe.td.x-2]=32;
    a[xe.td.y-3][xe.td.x-1]=32;
    a[xe.td.y-3][xe.td.x]=32;
    break;

}
}
void xl(vc &vc){
vc.td.y++;
if(vc.td.y>27) {
vc.td.x=3+rand()%36;
 vc.td.y=-2;}
}
int main(){
    xe xe;
    vc vc;
    char a[25][41];
    khoitao1(a);
    srand(time(NULL));
    ShowCur(false);
    khoitao(xe,vc);
    while (1){
		gotoXY(0,0);
        hienthi(xe,vc,a);

        dieukhien(xe);
        xl(vc);
        xoa(xe,vc,a);

        Sleep(200);
    }

}
