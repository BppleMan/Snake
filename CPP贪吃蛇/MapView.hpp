//
//  MapView.hpp
//  CPP贪吃蛇
//
//  Created by BppleMan‘s Mac on 16/4/12.
//  Copyright © 2016年 BppleMan‘s Mac. All rights reserved.
//

#ifndef MapView_hpp
#define MapView_hpp

#include "Header.h"
#include "SnakeData.hpp"
#include "Point.hpp"

class MapView
{
private:
    int width;
    int height;
    SnakeData *snakeData;
    Point *food;
public:
    MapView(int width,int height);
    //fun
    void displayMap();
    void CreatFood();
    
    //set
    void setSnakedata(SnakeData *stack);
    void setFoodPoint(Point *p);
    
    //get
    int getWidth();
    int getHeight();
    Point* getFood();
};

#endif /* MapView_hpp */