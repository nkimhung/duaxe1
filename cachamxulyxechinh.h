#ifndef _CACHAMXULYXECHINH
#define _CACHAMXULYXECHINH

#include<iostream>
#include<string.h>
#include<stdlib.h>
#include"kieudulieumoi.h"
#include"hamtienich.h"
using namespace std;
//hien thi tro choi
void Display_game( Race_Car &,char(*)[ROAD+1] );

//dieu khien xe di chuyen
void Control_car(Race_Car &);

//tao su di chuyen cac vat,kiem tra su dung do,game over
void handle_car(Race_Car &,hindrance*,hindrance & );

// xu ly lua chon khi thua cuoc
void Solve_The_Selection(Race_Car &,hindrance*,hindrance &);

//tam dung tro choi
void pause_game(Race_Car &);
#endif // _CACHAMXULYXECHINH



