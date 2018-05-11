#ifndef _KHOITAO
#define _KHOITAO
#include"kieudulieumoi.h"
#include<iostream>
#include<stdlib.h>
using namespace std;
//huong dan dau game
string Help();

//tao hinh dang duong dua
void initialize_racetrack(char (*)[ROAD+1] );

//tao hinh dang ,vi tri cac vat tren duong dua
void initialize_location(Race_Car &,hindrance*,hindrance &);

#endif // _KHOITAO


