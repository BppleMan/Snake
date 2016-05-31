//
//  Point.cpp
//  CPP贪吃蛇
//
//  Created by BppleMan‘s Mac on 16/4/12.
//  Copyright © 2016年 BppleMan‘s Mac. All rights reserved.
//

#include "Point.hpp"

Point::Point(int x,int y)
{
    this->x = x;
    this->y = y;
    next = NULL;
}

Point::Point(Point *point)
{
    this->x = point->x;
    this->y = point->y;
    next = NULL;
}

void Point::setPoint(int x,int y)
{
    this->x = x;
    this->y = y;
    next = NULL;
}

void Point::setX(int x)
{
    this->x = x;
}

int Point::getX()
{
    return x;
}

void Point::setY(int y)
{
    this->y = y;
}

int Point::getY()
{
    return y;
}

Point* Point::getPoint()
{
    return this;
}

void Point::setNext(Point *point)
{
    next = point;
}

Point* Point::getNext()
{
    return next;
}

bool Point::isEqual(int x,int y)
{
    if (this->x != x || this->y != y)
        return false;
    else return true;
}

bool Point::isEqual(Point *point)
{
    if (this->x != point->x || this->y != point->y)
        return false;
    else return true;
}

Point::~Point()
{
    next = NULL;
}