//
//  SnakeData.hpp
//  CPP贪吃蛇
//
//  Created by BppleMan‘s Mac on 16/4/12.
//  Copyright © 2016年 BppleMan‘s Mac. All rights reserved.
//

#ifndef SnakeData_hpp
#define SnakeData_hpp

#include "Header.h"
#include "Point.hpp"

class SnakeData
{
private:
    int size;
    Point *head;
    Point *rear;
public:
    SnakeData();
    ~SnakeData();
    
    void popSnake();
    void pushSnake(Point *point);
    
    //getter
    Point* getHead();
    Point* getRear();
    
    //judge
    bool isHave(Point *point);
    bool isHave(int x,int y);
};

#endif /* SnakeData_hpp */
