#include<iostream>
#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
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
    int run=0,vacham=0,sovcqua=0,life=0;
};
struct vc
{
    toado td,td2,td3;


};
void khoitao(xe &xe,vc vc[3]){
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
 for(i=0;i<=2;i++)
 {vc[i].td.x=3+rand()%36;
 vc[i].td.y=-2-i*7;
 }
 /*}*/
 vc[1].td2.x=4+rand()%34;
 vc[1].td2.y=-50;
 }
void hienthi(const xe &xe,const vc vc[3],char a[25][41]){
	int kdong,kcot,x,y,i;

	for(kdong=-1;kdong<=1;kdong++)
        for(kcot=-1;kcot<=1;kcot++){
            x=kcot+xe.td.x;
            y=kdong+xe.td.y;
            a[y-1][x-1]=xe.hd.a[kdong+1][kcot+1];
			}

        for(i=0;i<=2;i++)
    	for(kdong=-1;kdong<=1;kdong++)
        	{
            	x=vc[i].td.x-1;
            	y=kdong+vc[i].td.y;
                if(y>0&&y<26){
            		a[y-1][x-1]=33;
            		a[y-1][x]=33;
            		a[y-1][x+1]=33;}
			}

    y=vc[1].td2.y-1;
    x=vc[1].td2.x-1;
    if(y>0&&y<25)
        {
            a[y][x-2]='+';
            a[y][x-1]='L';
            a[y][x]='I';
            a[y][x+1]='F';
            a[y][x+2]='E';
        }



    gotoXY(0,0);
    TextColor(70);
    cout<<a[0];
    gotoXY(55,12);
    cout<<" SO VA CHAM: "<<xe.vacham;
    gotoXY(55,13);
    cout<<" SO VAT CAN QUA: "<<xe.sovcqua;
    gotoXY(55,14);
    cout<<" MANG SONG: "<<xe.life;

    /*gotoXY(40,24);
    cout<<"              ";*/

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

void xoa( const xe &xe,const vc vc[3],char a[25][41]){
int i;
for(i=0;i<=2;i++)
        if(vc[i].td.y>=3 && vc[i].td.y<28)
        {
            a[vc[i].td.y-3][vc[i].td.x-2]=32;
            a[vc[i].td.y-3][vc[i].td.x-1]=32;
            a[vc[i].td.y-3][vc[i].td.x]=32;
        }

if(vc[1].td2.y>=2&&vc[1].td2.y<=26)
    {
    a[vc[1].td2.y-2][vc[1].td2.x-3]=32;
    a[vc[1].td2.y-2][vc[1].td2.x-2]=32;
    a[vc[1].td2.y-2][vc[1].td2.x-1]=32;
    a[vc[1].td2.y-2][vc[1].td2.x]=32;
    a[vc[1].td2.y-2][vc[1].td2.x+1]=32;
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
void xl(vc vc[3],xe &xe,char a[25][41]){
int i,dx,dy,kdong,x,y;

vc[0].td.y++;
vc[1].td.y++;
vc[2].td.y++;
vc[1].td2.y++;

for(i=0;i<=2;i++) {
    dx=xe.td.x-vc[i].td.x;
    dy=xe.td.y-vc[i].td.y;
    if(abs(dx)<=2&&abs(dy)<=2)
    {   xe.vacham++;
        for(kdong=-1;kdong<=1;kdong++)
        	{
            	x=vc[i].td.x-1;
            	y=kdong+vc[i].td.y;
                if(y>=2&&y<26){
            		a[y-2][x-1]=32;
            		a[y-2][x]=32;
            		a[y-2][x+1]=32;}
			}
        vc[i].td.x=3+rand()%36;
        vc[i].td.y=-2;
    }
    if(vc[i].td.y>27) {
        vc[i].td.x=3+rand()%36;
        vc[i].td.y=-2;
        xe.sovcqua++;
                        }
}
dx=xe.td.x-vc[1].td2.x;
dy=xe.td.y-vc[1].td2.y;
if(abs(dx)<=3&&abs(dy)<=1){
    xe.life++;
    if(vc[1].td2.y>=2&&vc[1].td2.y<=26){
    a[vc[1].td2.y-2][vc[1].td2.x-3]=32;
    a[vc[1].td2.y-2][vc[1].td2.x-2]=32;
    a[vc[1].td2.y-2][vc[1].td2.x-1]=32;
    a[vc[1].td2.y-2][vc[1].td2.x]=32;
    a[vc[1].td2.y-2][vc[1].td2.x+1]=32;}
    vc[1].td2.x=4+rand()%34;
    vc[1].td2.y=-50;

}

if(vc[1].td2.y>26)
    {
    vc[1].td2.x=4+rand()%34;
    vc[1].td2.y=-50;
    }

}
int main(){
    xe xe;
    vc vc[3];
    char a[25][41];
    khoitao1(a);
    srand(time(NULL));
    ShowCur(false);
    khoitao(xe,vc);
    while (1){
        hienthi(xe,vc,a);

        dieukhien(xe);
        xl(vc,xe,a);
        xoa(xe,vc,a);

        Sleep(100);
    }

}
