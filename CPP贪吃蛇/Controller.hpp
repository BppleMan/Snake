//
//  Controller.hpp
//  CPP贪吃蛇
//
//  Created by BppleMan‘s Mac on 16/4/12.
//  Copyright © 2016年 BppleMan‘s Mac. All rights reserved.
//

#ifndef Controller_hpp
#define Controller_hpp

#include "Header.h"
#include "MapView.hpp"
#include "SnakeData.hpp"
#include "Point.hpp"

class Controller
{
private:
    int WIDTH;
    int HEIGHT;
    MapView *myMap;
    SnakeData *mySnake;
    Direction direct;
public:
    Controller();
    void initView();
    void setDirect(char ch);
    bool snakeMove();
    bool isFail(Point *point);
};

#endif /* Controller_hpp */