#include<iostream>
#include<stdio.h>
#include<time.h>
#include"hamtienich.h"
#include"cackieudulieumoi.h"
#include"cachamsulygamechinh.h"
#include"khoitao.h"
using namespace std;
#define consoleHeight 25
#define ROAD 41

int main(){
    xedua xe;
    vatcan vc[3];
    char a[25][42];
    //tao bo sinh so ngau nhien
    srand(time(NULL));

    //an con tro tren man hinh
    ShowCur(false);

    //tao duong dua
    khoitao1(a);

    //tao hinh dang,vi tri cac vat
    khoitao(xe,vc);

    //hien thi thong tin tro choi
    gotoXY(55,12);
    cout<<" Dan:      0";
    gotoXY(55,13);
    cout<<" SO VAT CAN QUA:    0";
    gotoXY(55,14);
    cout<<" MANG SONG:      0";


    while (1){
        xe.tem++;

        if(xe.tem>100) {//kiem tra xem da du thoi gian nap dan chua
            xe.dan++;
            xe.affirmation[0]=true;
            xe.tem=0;
                        }
        //update lai vi tri,hinh dang cac vat tren duong dua
        Update(xe,vc,a);

        //hien thi tro choi
        Display(xe,vc,a);

        //xoa cac vat tren duong dua
        Delete(xe,vc,a);

        //choi game
        Control(xe);

        //tam dung tro choi khi co lenh
        dungtrochoi(xe);

        //xu ly game
        xuly(vc,xe,a);

        //xy ly lua chon cua nguoi choi khi thua cuoc
        xulyluachon(xe,vc);
        Sleep(50);
    }

}




