#ifndef _cachamxulygamechinh
#define _cachamxulygamechinh
#include"cackieudulieumoi.h"
#define ROAD 41
//update lai vi tri cac vat tren duong dua
void Update(xedua &,const vatcan*,char (*)[ROAD+1] );

//xoa cac vat tren duong dua
void Delete(xedua &, const vatcan*,char(*)[ROAD+1] );

//hien thi tro choi
void Display( xedua &,const vatcan*,char(*)[ROAD+1] );

//dieu khien xe di chuyen
void Control(xedua &);

//tao su di chuyen cac vat,kiem tra su dung do,game over
void xuly(vatcan* ,xedua &,char(*)[ROAD+1] );

// xu ly lua chon khi thua cuoc
void xulyluachon(xedua&,vatcan*);

//tam dung tro choi
void dungtrochoi(xedua&);
#endif // _cachamxulygamechinh


