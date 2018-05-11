#include"khoitao.h"

//huong dan dau game
string Help()
{
    string chuthich[10],help;
    chuthich[0]="SU DUNG CAC PHIM DI CHUYEN TREN BAN PHIM DE DIEU KHIEN XE\n";
    chuthich[1]="\nHAY CO GANG VUOT QUA THAT NHIEU VAT CAN\n";
    chuthich[2]="\nAN THAT NHIEU PHEP BO TRO LIFE DE KHONG SO VA CHAM\n";
    chuthich[3]="\nMOI LAN VA CHAM MANG SONG GIAM DI 1\n";
    chuthich[4]="\nKHI MANG SONG NHO HON 0 THI BAN DA THUA\n";
    chuthich[5]="\nSAU MOT THOI GIAN XE SE TU DONG NAP DAN\n";
    chuthich[6]="\nKHI NGUY HIEM HAY NHAN PHIM CACH DE BAN DAN\n";
    chuthich[7]="\nNHAN PHIM \"S\" KHI MUON TAM DUNG TRO CHOI\n";
    chuthich[8]="\n  CHU Y: CHOI CANG LAU TOC DO CANG NHANH\n\n";
    chuthich[9]="\nNHAN PHIM \"A\" VA NHAN ERTER DE BAT DAU THUONG THUC GAME\n";
    int i;
    for(i=0; i<10; i++)
        help+=chuthich[i];
    return help;

}

//tao duong dua
void initialize_racetrack(char racetrack[consoleHeight][ROAD+1])
{
    int i,j;
    //tao khoang trong duong dua
    for(i=0; i<consoleHeight; i++)
        for(j=1; j<ROAD-1; j++)
            racetrack[i][j]=32;
    //tao duong bien
    for(i=0; i<consoleHeight; i++)
    {
        racetrack[i][0]=179;
        racetrack[i][ROAD-1]=179;
        racetrack[i][ROAD]='\n';
    }
    racetrack[24][ROAD]='\0';
}

//tao hinh dang vi tri cac vat
void initialize_location(Race_Car &car,hindrance dike[3],hindrance &life)
{
    int i;
    // tao vi tri ban dau cua xe
    car.setCoordinate(ROAD/2+1,consoleHeight-3);

    // tao hinh dang xe
    car.setShape();

    // tao vi tri ban dau cua cac vat can
    for(i=0; i<=2; i++)
    {
        dike[i].td.column=3+rand()%(ROAD-4);
        dike[i].td.row=-2-i*7;
    }

    // tao vi tri ban dau cua phep bo tro life
    life.td.column=4+rand()%(ROAD-6);
    life.td.row=-50;
}



