#ifndef _KIEUDULIEUMOI
#define _KIEUDULIEUMOI
#define consoleHeight 25
#define ROAD 41

//tao kieu toa do
struct  coordinate{

    int column,row;
};

//tao kieu hinh dang
struct shape{
    char a[3][3];
};

//tao kieu vat can
struct hindrance{
        coordinate td;
};

//tao kieu xe dua
class Race_Car{
    public:
        //setM :cai dat gia tri M
        //addM : cong them vao M mot gia tri
        //getM: lay gia tri M
        void setCoordinate(int,int);
        void addCoordinate(int,int);
        coordinate getCoordinate();

        void setShape();
        shape getShape();

        void setDan(int);
        void addDan(int);
        int getDan();

        void setSovcqua(int);
        void addSovcqua(int);
        int getSovcqua();

        void setLife(int);
        void addLife(int);
        int getLife();

        void setDem_CK_Dan(int );
        void addDem_CK_Dan(int);
        int getDem_CK_Dan();

        void setSovcquaMax(int);
        int getSovcquaMax();

        void setDem_CK_Life(int);
        void addDem_CK_Life(int);
        int getDem_CK_Life();

        void setTocDo(int);
        void addTocDo(int);
        int getTocDo();

        void setBan(bool);
        bool getBan();

        void setLoss(bool);
        bool getLoss();

        void setAff(bool,int);
        bool getAff(int);

        void setStop(bool);
        bool getStop();


    private:
        coordinate td;
        shape hd;

        int dan=0,sovcqua=0,life=0,dem_CK_Dan=0,sovcquamax=0,dem_CK_Life=0,tocdo=50;
        // bien xac nhan viec ban dan
        bool ban=false;

        //bien xac nhan viec game over
        bool loss=false;

        //bien xac nhan viec thay doi gia tri cac bien dan,sovcqua,life
        bool affirmation[3]={true,true,true};

        //bien xac nhan viec tam dung cho troi
        bool stop=false;


};

//tao kieu ban ve
class drawing_table{
    public:
        void Update(Race_Car &,const hindrance*,const hindrance &,char (*)[ROAD+1]);
        void Delete(Race_Car &, const hindrance*,const hindrance &,char(*)[ROAD+1] );

};

#endif // _KIEUDULIEUMOI




