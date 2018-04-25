#include"khoitao.h"
#include"cackieudulieumoi.h"
#include"time.h"
#include<stdlib.h>
#define consoleHeight 25
#define ROAD 41
void khoitao1(char a[consoleHeight][ROAD+1]){
	int i,j;
	for(i=0;i<consoleHeight;i++)
        for(j=1;j<ROAD-1;j++)
            a[i][j]=32;
    for(i=0;i<consoleHeight;i++){
        a[i][0]=179;
        a[i][ROAD-1]=179;
        a[i][ROAD]='\n';
    }
    a[24][ROAD]='\0';
	}

void khoitao(xedua &xe,vatcan vc[3]){
    int i;
    //vi tri ban dau cua xe
    xe.td.line=consoleHeight-3;
    xe.td.column=ROAD/2+1;

    //hinh dang xe
    xe.hd.a[0][1]='^';
    xe.hd.a[0][0]='0';
    xe.hd.a[0][2]='0';
    xe.hd.a[2][0]='0';
    xe.hd.a[2][2]='0';
    xe.hd.a[1][0]='|';
    xe.hd.a[1][1]='X';
    xe.hd.a[2][1]='-';
    xe.hd.a[1][2]='|';

    //vi tri ban dau cua cac vat can
    for(i=0;i<=2;i++)
    {
        vc[i].td.column=3+rand()%(ROAD-4);
        ;
        vc[i].td.line=-2-i*7;
    }

    //vi tri ban dau cua phep bo tro life
    vc[1].td2.column=4+rand()%(ROAD-6);
    vc[1].td2.line=-50;
 }


