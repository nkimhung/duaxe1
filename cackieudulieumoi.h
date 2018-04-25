#ifndef _cackieudulieumoi
#define _cackieudulieumoi

struct  toado{

    int column,line;
};

struct hinhdang {
    char a[3][3];
};
struct xedua{
        toado td;
        hinhdang hd;
        int dan=0,sovcqua=0,life=0,tem=0,ban=0,sovcquamax=0;

        //xac nhan viec game over
        bool loss=false;
        //xac nhan viec thay doi gia tri cac bien dan,sovcqua,life
        bool affirmation[3]={false};
        bool stop=false;
};
struct vatcan{
        toado td,td2;
};
#endif // _cackieudulieumoi



