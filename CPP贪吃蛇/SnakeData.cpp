//
//  SnakeData.cpp
//  CPP贪吃蛇
//
//  Created by BppleMan‘s Mac on 16/4/12.
//  Copyright © 2016年 BppleMan‘s Mac. All rights reserved.
//

#include "SnakeData.hpp"

SnakeData::SnakeData()
{
    
    int x[10];// = {5,5,5};
    int y[10];// = {0,1,2};
    for (int i = 0; i < 10;i++)
    {
        x[i] = 0;
        y[i] = i;
    }
    head = new Point(x[0],y[0]);
    size = 10;
    Point *p,*s;
    head->setNext(NULL);
    p = head;
    for (int i = 1;i < size;i++)
    {
        s = new Point(x[i],y[i]);
        s->setNext(p->getNext());
        p->setNext(s);
        p = s;
    }
    rear = p;
    p = s = NULL;
}

void SnakeData::popSnake()
{
    Point *temp = head;
    head = head->getNext();
    delete temp;
    temp = NULL;
    size--;
}

void SnakeData::pushSnake(Point *point)
{
    rear->setNext(point);
    rear = point;
}

Point* SnakeData::getHead()
{
    return head;
}

Point* SnakeData::getRear()
{
    return rear;
}

bool SnakeData::isHave(int x,int y)
{
    bool flag = 0;
    Point *p = head;
    while(p)
    {
        if (p->isEqual(x,y))
        {
            flag = 1;
            break;
        }
        p = p->getNext();
    }
    p = NULL;
    return flag;
}

bool SnakeData::isHave(Point *point)
{
    bool flag = 0;
    Point *p = head;
    while(p)
    {
        if (p->isEqual(point))
        {
            flag = 1;
            break;
        }
        p = p->getNext();
    }
    p = NULL;
    return flag;
}

SnakeData::~SnakeData()
{
    while (head)
    {
        Point *temp = head;
        head = head->getNext();
        delete temp;
        temp = NULL;
    }
    head = rear = NULL;
}