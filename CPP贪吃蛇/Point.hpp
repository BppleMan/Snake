//
//  Point.hpp
//  CPP贪吃蛇
//
//  Created by BppleMan‘s Mac on 16/4/12.
//  Copyright © 2016年 BppleMan‘s Mac. All rights reserved.
//

#ifndef Point_hpp
#define Point_hpp
#include "Header.h"
class Point
{
private:
    int x;
    int y;
    Point *next;
public:
    Point(){x = 0;y = 0;}
    Point(int x,int y);
    Point(Point *point);
    ~Point();
    
    //setter
    void setX(int x);
    void setY(int y);
    void setPoint(int x,int y);
    void setPoint(Point *p);
    void setNext(Point *point);
    
    //getter
    int getX();
    int getY();
    Point *getNext();
    Point* getPoint();
    
    //judge
    bool isEqual(Point *point);
    bool isEqual(int x,int y);
};

#endif /* Point_hpp */