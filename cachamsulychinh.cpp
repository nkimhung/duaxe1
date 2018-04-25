#include"cachamsulychinh.h"
#include"hamtienich.h"
#include"cackieudulieumoi.h"
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
#define consoleHeight 25
#define ROAD 41
void Update(xedua &xe,const vatcan vc[3],char a[consoleHeight][ROAD+1]){
    int kdong,kcot,x,y,i;
    //gan hinh dang va vi tri xe vao mang
	for(kdong=-1;kdong<=1;kdong++)
        for(kcot=-1;kcot<=1;kcot++){
            x=kcot+xe.td.column;
            y=kdong+xe.td.line;
            a[y-1][x-1]=xe.hd.a[kdong+1][kcot+1];
			}
    //kt viec nhan phim ban dan
    if(xe.ban==1){
    x=xe.td.column-1;
    y=xe.td.line-3;

    //kt xem con dan trong xe khong
    if(xe.dan>0){
        //gan duong dan vao mang
        while(y>=0){
            a[y][x]=177;
            y--;
                }
        //giam so vien dan di
        xe.dan--;
        xe.affirmation[0]=true;//xac nhan su thay doi cua dan
                    }
    xe.ban=0;
    }

    for(i=0;i<=2;i++)
    for(kdong=-1;kdong<=1;kdong++)
    {
        x=vc[i].td.column-1;
        y=kdong+vc[i].td.line;
        if(y>0&&y<26){
            a[y-1][x-1]=219;
            a[y-1][x]=219;
            a[y-1][x+1]=219;}
    }
    //gan vi tri hinh dang life vao mang
    y=vc[1].td2.line-1;
    x=vc[1].td2.column-1;
    if(y>0&&y<25)
        {
            a[y][x-2]='+';
            a[y][x-1]='L';
            a[y][x]='I';
            a[y][x+1]='F';
            a[y][x+2]='E';
        }



}
void Delete(xedua &xe, const vatcan vc[3],char a[consoleHeight][ROAD+1]){
    int kdong,kcot,x,y,i;
    //xoa xe
    for(kdong=-1;kdong<=1;kdong++)
        for(kcot=-1;kcot<=1;kcot++){
            x=kcot+xe.td.column;
            y=kdong+xe.td.line;
            a[y-1][x-1]=32;
			}

    x=xe.td.column-1;//vi tri cot cua duong dan trong mang
    y=xe.td.line-3;//vi tri dong cua duong dan trong mang
    //xoa duong dan
    while(y>=0){
        a[y][x]=32;
        y--;
                }
    //xoa cac vat can
    for(i=0;i<=2;i++)
    	for(kdong=-1;kdong<=1;kdong++)
        	{
            	x=vc[i].td.column-1;
            	y=kdong+vc[i].td.line;
                if(y>0&&y<=consoleHeight){
            		a[y-1][x-1]=32;
            		a[y-1][x]=32;
            		a[y-1][x+1]=32;}
			}

    //xoa phep bo tro life
    y=vc[1].td2.line-1;
    x=vc[1].td2.column-1;
    if(y>0&&y<consoleHeight)
        {
            a[y][x-2]=32;
            a[y][x-1]=32;
            a[y][x]=32;
            a[y][x+1]=32;
            a[y][x+2]=32;
        }


}
void Display( xedua &xe,const vatcan vc[3],char a[consoleHeight][ROAD+1]){


    TextColor(70);
    gotoXY(0,0);
    //hien thi tro choi
    cout<<a[0];

    //hien thi so dan
    if(xe.affirmation[0])
    {   gotoXY(65,12);
        cout<<xe.dan<<"      ";
        xe.affirmation[0]=false;}

    //hien thi so vat can qua
    if(xe.affirmation[1]){
        gotoXY(75,13);
        cout<<xe.sovcqua;
        xe.affirmation[1]=false;}

    //hien thi so mang
    if(xe.affirmation[2]){
        gotoXY(70,14);
        cout<<xe.life<<"       ";
        xe.affirmation[2]=false;}


}

void Control(xedua &xe){
    int i;
    i=inputKey();
    if(key_Up==i&&xe.td.line>=3)
        xe.td.line--;
    else
        if(key_Down==i&&xe.td.line<=consoleHeight-2)
            xe.td.line++;
        else
            if(key_Left==i&&xe.td.column>=6)
                xe.td.column-=3;
            else
                if(key_Right==i&& xe.td.column<=ROAD-5)
                    xe.td.column+=3;
                else
                    if(i==32)
                        xe.ban=1;
                    else
                        if(i=='s'||i=='S')
                            xe.stop=true;
}

void xuly(vatcan vc[3],xedua &xe,char a[consoleHeight][ROAD+1]){
    int i,dx,dy,kdong,x,y;

    vc[0].td.line++;
    vc[1].td.line++;
    vc[2].td.line++;
    vc[1].td2.line++;

    //xu ly cac tinh huong xay ra voi vat can
    for(i=0;i<=2;i++) {
        dx=xe.td.column-vc[i].td.column;//khoang cach cot giua xe voi vat can
        dy=xe.td.line-vc[i].td.line;//khoang cach dong giua xe voi vat can
        if(abs(dx)<=2&&abs(dy)<=2) //kiem tra su vat cham giua xe voi vat can
        {
            if(xe.life>0){
                xe.life--;
                xe.affirmation[2]=1;
                vc[i].td.column=3+rand()%(ROAD-4);
                vc[i].td.line=-2;
                        }
            else
                xe.loss=true;
        }

    //kiem tra neu dan co ban vao vat can thi khoi tao lai toa do vat can
        if(xe.ban==1&&abs(dx)<=2&&xe.dan>0){
            vc[i].td.column=3+rand()%(ROAD-4);
            vc[i].td.line=-2;
                                            }

    //kiem tra neu vat can di het duong dua thi update lai thong tin
        if(vc[i].td.line>27) {
            vc[i].td.column=3+rand()%(ROAD-4);
            vc[i].td.line=-2;
            xe.sovcqua++;
            xe.affirmation[1]=true;
                        }
        }

    //xu ly cac tinh huong voi phep bo tro life
    dx=xe.td.column-vc[1].td2.column;//khoang cach cot giua xe voi phep bo tro mang song
    dy=xe.td.line-vc[1].td2.line;//khoang cach dong giua xe voi phep bo tro mang song
    if(abs(dx)<=3&&abs(dy)<=1){//kiem tra su an phep bo tro cua xe
        xe.life++;
        xe.affirmation[2]=true;
        //update lai toa do
        vc[1].td2.column=4+rand()%(ROAD-6);
        vc[1].td2.line=-50;
                            }
    if(xe.ban==1&&abs(dx)<=3&&xe.dan>0){//kiem tra xem dan co ban vao phep bo tro khong
        vc[1].td2.column=4+rand()%(ROAD-6);
        vc[1].td2.line=-50;
                                        }
    if(vc[1].td2.line>26)//kiem tra xem phep bo tro mang song da di het duong dua chua
    {
        vc[1].td2.column=4+rand()%(ROAD-6);
        vc[1].td2.line=-50;
    }

}
void xulyluachon(xedua &xe,vatcan vc[3]){
while(xe.loss) {

                clrscr();
                cout<<" nhap a de tiep tuc x the thoat"<<endl;
                string key;
                cin>>key;
                if(key=="a"||key=="A") {
                    int i;

                    //update lai vi tri ban dau cua xe
                    xe.td.line=consoleHeight-3;
                    xe.td.column=ROAD/2+1;

                    //update lai vi tri ban dau cua vat can
                    for(i=0;i<=2;i++)
                    {
                        vc[i].td.column=3+rand()%37;
                        vc[i].td.line=-2-i*7;
                    }
                    //update lai vi tri ban dau cua phep bo tro láº¡i life
                    vc[1].td2.column=4+rand()%35;
                    vc[1].td2.line=-50;

                    //in ra thong tin ban dau game
                    if(xe.sovcqua>xe.sovcquamax) xe.sovcquamax=xe.sovcqua;
                    gotoXY(47,11);
                    cout<<"SO VAT CAN QUA NHIEU NHAT:"<<xe.sovcquamax;
                    gotoXY(55,12);
                    cout<<" DAN:      0";
                    gotoXY(55,13);
                    cout<<" SO VAT CAN QUA:    0";
                    gotoXY(55,14);
                    cout<<" MANG SONG:      0";
                    gotoXY(0,0);
                    xe.dan=0;
                    xe.life=0;
                    xe.sovcqua=0;
                    xe.tem=0;


                    xe.loss=false;
                }
                else
                    if(key=="x"||key=="X")
                        exit(0);

            }
}
void dungtrochoi(xedua &xe){
    while(xe.stop) {
                clrscr();
                cout<<"Nhap a de tiep tuc choi x the thoat"<<endl;
                string key;
                cin>>key;
                if(key=="a"||key=="A") {

                    //in ra thong hien tai cua game
                    gotoXY(47,11);
                    cout<<"SO VAT CAN QUA NHIEU NHAT:"<<xe.sovcquamax;
                    gotoXY(55,12);
                    cout<<" Dan:      0";
                    gotoXY(55,13);
                    cout<<" SO VAT CAN QUA:    0";
                    gotoXY(55,14);
                    cout<<" MANG SONG:      0";
                    gotoXY(0,0);
                    xe.affirmation[0]=true;
                    xe.affirmation[1]=true;
                    xe.affirmation[2]=true;


                    xe.stop=false;
                                        }
                else
                    if(key=="x"||key=="X")
                        exit(0);
            }

}

