#include"cachamxulyxechinh.h"

//Hien thi tro choi
void Display_game( Race_Car &car,char racetrack[consoleHeight][ROAD+1])
{

    TextColor(30);
    gotoXY(0,0);
    cout<<racetrack[0];
    //Hien thi so dan
    if(car.getAff(0))
    {
        gotoXY(55,12);
        cout<<" DAN:      "<<car.getDan()<<" ";
        car.setAff(false,0);
    }

    //Hien thi so vat can qua
    if(car.getAff(1))
    {
        gotoXY(55,13);
        cout<<" SO VAT CAN QUA:    "<<car.getSovcqua();
        car.setAff(false,1);
    }

    //Hien thi so mang
    if(car.getAff(2))
    {
        gotoXY(55,14);
        cout<<" MANG SONG:      "<<car.getLife()<<" ";
        car.setAff(false,2);
    }


}

//Dieu khien xe
void Control_car(Race_Car &car)
{
    int i;
    coordinate Td;
    Td=car.getCoordinate();
    i=inputKey();
    if(key_Up==i&&Td.row>=3)//xe di xuong
        car.addCoordinate(0,-1);
    else if(key_Down==i&&Td.row<=consoleHeight-2) //xe di len
        car.addCoordinate(0,1);
    else if(key_Left==i&&Td.column>=6) //xe sang trai
        car.addCoordinate(-3,0);
    else if(key_Right==i&& Td.column<=ROAD-5) //xe sang phai
        car.addCoordinate(3,0);
    else if(i==32) //ban dan
        car.setBan(true);
    else if(i=='s'||i=='S') //tam dung
        car.setStop(true);
}

//Xu ly cac truong hop voi xe
void handle_car(Race_Car &car,hindrance dike[3],hindrance &life)
{
    int i,dx,dy,kdong,x,y;

    dike[0].td.row++;
    dike[1].td.row++;
    dike[2].td.row++;
    life.td.row++;

    //Xu ly cac tinh huong xay ra voi vat can

    coordinate Td;
    Td=car.getCoordinate();

    for(i=0; i<=2; i++)
    {
        dx=Td.column-dike[i].td.column;//khoang cach cot giua xe voi vat can
        dy=Td.row-dike[i].td.row;//khoang cach hang giua xe voi vat can
        if(abs(dx)<=2&&abs(dy)<=2) //kiem tra su vat cham giua xe voi vat can
        {
            if(car.getLife()>0)
            {
                car.addLife(-1);
                car.setAff(true,2);
                dike[i].td.column=3+rand()%(ROAD-4);
                dike[i].td.row=-2;
            }
            else
                car.setLoss(true);
        }

        //Kiem tra neu dan co ban vao vat can thi khoi tao lai toa do vat can
        if(car.getBan()&&abs(dx)<=2&&car.getDan()>0)
        {
            dike[i].td.column=3+rand()%(ROAD-4);
            dike[i].td.row=-2;
        }

        //Kiem tra neu vat can di het duong dua thi update lai thong tin
        if(dike[i].td.row>27)
        {
            dike[i].td.column=3+rand()%(ROAD-4);
            dike[i].td.row=-2;
            car.addSovcqua(1);
            car.setAff(true,1);

        }
    }

    //Xu ly cac tinh huong voi phep bo tro life
    dx=Td.column-life.td.column;//khoang cach cot giua xe voi phep bo tro mang song
    dy=Td.row-life.td.row;//khoang cach hang giua xe voi phep bo tro mang song
    if(abs(dx)<=3&&abs(dy)<=1) //kiem tra viec an phep bo tro cua xe
    {
        car.addLife(1);
        car.setAff(true,2);

        //update lai toa do
        life.td.column=4+rand()%(ROAD-6);
        life.td.row=-50;
    }
    if(car.getBan()&&abs(dx)<=3&&car.getDan()>0) //kiem tra xem dan co ban vao phep bo tro khong
    {
        life.td.column=4+rand()%(ROAD-6);
        life.td.row=-50;
    }
    if(life.td.row>26)//kiem tra xem phep bo tro mang song da di het duong dua chua
    {
        life.td.column=4+rand()%(ROAD-6);
        life.td.row=-50;
    }

}

//Xu ly lua chon nguoi choi khi thua cuoc
void Solve_The_Selection(Race_Car &car,hindrance dike[3],hindrance &life)
{
    while(car.getLoss())
    {

        clrscr();
        cout<<" Nhan phim \"A\" de choi lai \"X\" de thoat \n\n Nhan phim Enter de xac nhan"<<endl;
        string key;
        fflush(stdin);
        cin>>key;
        if(key=="a"||key=="A")
        {
            int i;

            //update lai vi tri ban dau cua xe
            car.setCoordinate(ROAD/2+1,consoleHeight-3);

            //update lai vi tri ban dau cua vat can
            for(i=0; i<=2; i++)
            {
                dike[i].td.column=3+rand()%37;
                dike[i].td.row=-2-i*7;
            }
            //update lai vi tri ban dau cua phep bo tro life
            life.td.column=4+rand()%35;
            life.td.row=-50;
            //cap nhap diem cao nhat
            if(car.getSovcqua()>car.getSovcquaMax())
                car.setSovcquaMax(car.getSovcqua());

            //in ra them diem cao nhat
            gotoXY(47,11);
            cout<<"SO VAT CAN QUA NHIEU NHAT:"<<car.getSovcquaMax();

            //thiet lap trang thai dau game
            car.setAff( true,0);
            car.setAff(true,1);
            car.setAff(true,2);
            car.setDan(0);
            car.setLife(0);
            car.setSovcqua(0);
            car.setDem_CK_Dan(0);
            car.setDem_CK_Life(0);
            car.setTocDo(50);
            car.setLoss(false);
        }
        else if(key=="x"||key=="X")
        {
            TextColor(10);
            cout<<"\nGAME OVER!"<<endl;
            exit(0);
        }
    }
}

//tam dung tro choi
void pause_game(Race_Car &car)
{
    while(car.getStop())
    {
        clrscr();
        cout<<"Nhan phim\"A\"de tiep tuc phim \"X\" de thoat\n\n Nhan Enter de xac nhan"<<endl;
        string key;
        fflush(stdin);
        cin>>key;
        if(key=="a"||key=="A")
        {
            //in ra thong tin hight neu co
            if(car.getSovcquaMax()!=0)
            {
                gotoXY(47,11);
                cout<<"SO VAT CAN QUA NHIEU NHAT:"<<car.getSovcquaMax();
            }
            //Xac nhan viec thay doi gia tri de in ra man hinh
            car.setAff( true,0);
            car.setAff(true,1);
            car.setAff(true,2);
            //ket thuc viec tam dung chuong trinh
            car.setStop(false);
        }
        else if(key=="x"||key=="X")
        {
            TextColor(10);
            cout<<"\nGAME OVER!"<<endl;
            exit(0);
        }
    }
}


