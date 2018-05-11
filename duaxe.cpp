#include<time.h>
#include"hamtienich.h"
#include"kieudulieumoi.h"
#include"cachamxulyxechinh.h"
#include"khoitao.h"

int main()
{
    string help;
    help=Help();
    while(true)
    {
        clrscr();
        cout <<help;
        string key;
        cin >>key;
        if(key=="A" ||key=="a")
            break;
    }
    clrscr();
    Race_Car car;
    hindrance dike[3],life;
    char racetrack[consoleHeight][ROAD+1];
    drawing_table drawing_table;

    //tao bo sinh so ngau nhien
    srand(time(NULL));

    //an con tro tren man hinh
    ShowCur(false);

    //tao duong dua
    initialize_racetrack(racetrack);

    //tao hinh dang,vi tri cac vat
    initialize_location(car,dike,life);

    while (true)
    {
        car.addDem_CK_Dan(1);
        car.addDem_CK_Life(1);

        if(car.getDem_CK_Dan()>100)  //kiem tra xem da du thoi gian nap dan chua
        {
            car.addDan(1);
            car.setAff(true,0);
            car.setDem_CK_Dan(0);
        }
        if(car.getDem_CK_Life()>200&&car.getTocDo()>=25)
        {
            car.addTocDo(-5);
            car.setDem_CK_Life(0);
        }

        //update lai vi tri,hinh dang cac vat tren duong dua
        drawing_table.Update(car,dike,life,racetrack);

        //hien thi tro choi
        Display_game(car,racetrack);

        //xoa cac vat tren duong dua
        drawing_table.Delete(car,dike,life,racetrack);

        //choi game
        Control_car(car);

        //tam dung tro choi khi co lenh
        pause_game(car);

        //xu ly game
        handle_car(car,dike,life);

        //xy ly lua chon cua nguoi choi khi thua cuoc
        Solve_The_Selection(car,dike,life);

        Sleep(car.getTocDo());
    }

}






