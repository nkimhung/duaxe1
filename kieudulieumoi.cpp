#include"kieudulieumoi.h"
//cac ham tien ich cho kieu td
void Race_Car::setCoordinate(int _column,int _row){
    td.column=_column;
    td.row=_row;
}
void Race_Car::addCoordinate(int _column,int _row){
    td.column+=_column;
    td.row+=_row;
}
coordinate Race_Car::getCoordinate(){
    return td;
}

//cac ham tien ich cho hd
void Race_Car::setShape(){
    hd.a[0][1]='^';
    hd.a[0][0]='0';
    hd.a[0][2]='0';
    hd.a[2][0]='0';
    hd.a[2][2]='0';
    hd.a[1][0]='|';
    hd.a[1][1]='X';
    hd.a[2][1]='-';
    hd.a[1][2]='|';
}
shape Race_Car::getShape(){
    return hd;
}

//cac ham tien tich cho dan
void Race_Car::setDan(int number){
    dan=number;
}
void Race_Car::addDan(int number){
    dan+=number;
}
int Race_Car::getDan(){
    return dan;
}

//cac ham hien ich cho life
void Race_Car::setLife(int number){
    life=number;
}
void Race_Car::addLife(int number){
    life+=number;
}
int Race_Car::getLife(){
    return life;
}

//cac ham tien ich cho sovcqua
void Race_Car::setSovcqua(int number){
    sovcqua=number;
}
void Race_Car::addSovcqua(int number){
    sovcqua+=number;
}
int Race_Car::getSovcqua(){
    return sovcqua;
}

//cac ham tien ich cho dem_CK_Dan
void Race_Car::setDem_CK_Dan(int number){
    dem_CK_Dan=number;
}
void Race_Car::addDem_CK_Dan(int number){
    dem_CK_Dan+=number;
}
int Race_Car::getDem_CK_Dan(){
    return dem_CK_Dan;
}

//cac ham tien ich cho dem_Ck_Life
void Race_Car::setDem_CK_Life(int number){
    dem_CK_Life=number;
}
void Race_Car::addDem_CK_Life(int number){
    dem_CK_Life+=number;
}
int Race_Car::getDem_CK_Life(){
    return dem_CK_Life;
}

//cac ham tien ich cho tocdo
void Race_Car::setTocDo(int number){
    tocdo=number;
}
void Race_Car::addTocDo(int number){
    tocdo+=number;
}
int Race_Car::getTocDo(){
    return tocdo;
}

//cac ham tien ich cho sovcMax
void Race_Car::setSovcquaMax(int number){
    sovcquamax=number;
}
int Race_Car::getSovcquaMax(){
    return sovcquamax;
}

//cac ham tien ich cho ban
void Race_Car::setBan(bool _ban){
    ban=_ban;
}
bool Race_Car::getBan(){
    return ban;
}

//cac ham tien ich cho loss
void Race_Car::setLoss(bool _loss){
    loss =_loss;
}
bool Race_Car::getLoss(){
    return loss;
}

//cac ham tien ich cho stop
void Race_Car::setStop(bool _stop){
    stop=_stop;
}
bool Race_Car::getStop(){
    return stop;
}

//cac ham tien ich cho affirmation
void Race_Car::setAff(bool _aff,int number){
    affirmation[number]=_aff;
}
bool Race_Car::getAff(int number){
    return affirmation[number];
}

//cap nhap vi tri cac vat len ban ve
void drawing_table::Update(Race_Car &car,const hindrance dike[3],const hindrance &life,char racetrack[consoleHeight][ROAD+1])
{
    int kdong,kcot,x,y,i;
    coordinate Td;
    shape Hd;

    //gan hinh dang va vi tri xe vao duong dua
    Hd=car.getShape();
    for(kdong=-1; kdong<=1; kdong++)
        for(kcot=-1; kcot<=1; kcot++)
        {
            Td=car.getCoordinate();
            Td.column+=kcot;
            Td.row+=kdong;
            racetrack[Td.row-1][Td.column-1]=Hd.a[kdong+1][kcot+1];

        }
    //kt viec nhan phim ban dan
    Td=car.getCoordinate();
    if(car.getBan())
    {

        x=Td.column-1;
        y=Td.row-3;

        //kt xem con dan trong xe khong
        if(car.getDan()>0)
        {
            //gan duong dan vao duong dua
            while(y>=0)
            {
                racetrack[y][x]=219;
                y--;
            }
            //giam so vien dan di
            car.addDan(-1);
            car.setAff(true,0);//xac nhan su thay doi cua dan
        }
        car.setBan(false);
    }
    //gan vat can vao duong dua
    for(i=0; i<=2; i++)
        for(kdong=-1; kdong<=1; kdong++)
        {
            x=dike[i].td.column-1;
            y=kdong+dike[i].td.row;
            if(y>0&&y<26)
            {
                racetrack[y-1][x-1]=219;
                racetrack[y-1][x]=219;
                racetrack[y-1][x+1]=219;
            }
        }

    //gan phep bo tro life vao duong dua
    y=life.td.row-1;
    x=life.td.column-1;
    if(y>0&&y<25)
    {
        racetrack[y][x-2]='+';
        racetrack[y][x-1]='L';
        racetrack[y][x]='I';
        racetrack[y][x+1]='F';
        racetrack[y][x+2]='E';
    }
}

//Xoa cac vat
void drawing_table::Delete( Race_Car &car, const hindrance dike[3],const hindrance &life,char racetrack[consoleHeight][ROAD+1])
{
    int kdong,kcot,x,y,i;
    coordinate Td;
    shape Hd;
    //xoa xe
    Hd=car.getShape();
    for(kdong=-1; kdong<=1; kdong++)
        for(kcot=-1; kcot<=1; kcot++)
        {
            Td=car.getCoordinate();
            Td.column+=kcot;
            Td.row+=kdong;
            racetrack[Td.row-1][Td.column-1]=32;
        }
    Td=car.getCoordinate();
    x=Td.column-1;//vi tri cot cua duong dan trong mang duong dua
    y=Td.row-3;//vi tri dong cua duong dan trong mang duong dua
    //xoa duong dan
    while(y>=0)
    {
        racetrack[y][x]=32;
        y--;
    }
    //xoa cac vat can
    for(i=0; i<=2; i++)
        for(kdong=-1; kdong<=1; kdong++)
        {
            x=dike[i].td.column-1;
            y=kdong+dike[i].td.row;
            if(y>0&&y<=consoleHeight)
            {
                racetrack[y-1][x-1]=32;
                racetrack[y-1][x]=32;
                racetrack[y-1][x+1]=32;
            }
        }

    //xoa phep bo tro life
    y=life.td.row-1;
    x=life.td.column-1;
    if(y>0&&y<consoleHeight)
    {
        racetrack[y][x-2]=32;
        racetrack[y][x-1]=32;
        racetrack[y][x]=32;
        racetrack[y][x+1]=32;
        racetrack[y][x+2]=32;
    }
}


