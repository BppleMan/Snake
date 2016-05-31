//
//  Header.h
//  CPP贪吃蛇
//
//  Created by BppleMan‘s Mac on 16/4/12.
//  Copyright © 2016年 BppleMan‘s Mac. All rights reserved.
//

#ifndef Header_h
#define Header_h

//#define Map   "⬛️"
//#define SNAKE "⬜️"
#define Map   "   "
#define SNAKE " * "

#include <iostream>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <termios.h>
#include <thread>

using namespace std;

enum Direction
{
    Up,
    Down,
    Left,
    Right
};

#endif /* Header_h */

