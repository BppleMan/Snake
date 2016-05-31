//
//  main.cpp
//  CPP贪吃蛇
//
//  Created by BppleMan‘s Mac on 16/4/6.
//  Copyright © 2016年 BppleMan‘s Mac. All rights reserved.
//

#include "Header.h"
#include "Controller.hpp"
#include "Kbhit.hpp"

int timer = 200000;

Controller myContrller;
Kbhit kbhit;

bool isThreadRun1;
bool isThreadRun2;

void showKO();
void getch();
void snakeMove();

int main(int argc, const char * argv[])
{
    getchar();
    thread t1(getch);
    thread t2(snakeMove);
    isThreadRun1 = true;
    isThreadRun2 = true;
    t1.join();
    t2.join();
    return 0;
}

void getch()
{
    Kbhit kbhit;
    while(isThreadRun1 && isThreadRun2)
    {
        if(kbhit.kbhit())
        {
            const int key = getchar();
            if(key == 'q')
            {
                cout<<"已退出!"<<endl;
                isThreadRun2 = false;
                break;
            }
            else if (key == '=')
                timer -= 50000;
            else if (key == '-')
                timer += 50000;
            else
                myContrller.setDirect(key);
        }
    }
}

void snakeMove()
{
    while (isThreadRun1 && isThreadRun2)
    {
        if (!myContrller.snakeMove())
        {
            putchar(7);
            showKO();
            isThreadRun1 = false;
            break;
        }
        usleep(timer);
    }
    
}

void showKO()
{
    system("clear");
    char KO[11][200] =
    {
        "    ****     ****                ********              ",
        "    ****    ****               ************            ",
        "    ****   ****               ****      ****           ",
        "    ****  ****                ****      ****           ",
        "    **** ****                 ****      ****           ",
        "    ********                  ****      ****           ",
        "    **** ****                 ****      ****           ",
        "    ****  ****                ****      ****           ",
        "    ****   ****               ****      ****           ",
        "    ****    ****      ***      ************     ***    ",
        "    ****     ****     ***       **********      ***    ",
    };
    cout<<"你输了!"<<endl;
    for (int i = 0;i < 11;i++)
    {
        puts(KO[i]);
        usleep(100000);
    }
}