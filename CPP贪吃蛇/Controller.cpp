//
//  Controller.cpp
//  CPP贪吃蛇
//
//  Created by BppleMan‘s Mac on 16/4/12.
//  Copyright © 2016年 BppleMan‘s Mac. All rights reserved.
//

#include "Controller.hpp"

Controller::Controller()
{
    WIDTH = 15;
    HEIGHT = 15;
    myMap = new MapView(WIDTH,HEIGHT);
    mySnake = new SnakeData();
    direct = Down;
    initView();
}

void Controller::initView()
{
    myMap->setSnakedata(mySnake);
    myMap->CreatFood();
    myMap->displayMap();
}

bool Controller::snakeMove()
{
    Point *food = myMap->getFood();
    Point *temp = mySnake->getRear();
    Point *rear = new Point(temp);
    temp = NULL;
    switch (direct)
    {
        case Up:
            rear->setY(rear->getY() - 1);
            break;
        case Down:
            rear->setY(rear->getY() + 1);
            break;
        case Left:
            rear->setX(rear->getX() - 1);
            break;
        case Right:
            rear->setX(rear->getX() + 1);
            break;
    }
    if (!isFail(rear))
        return false;
    if (food && rear->isEqual(food))
    {
        mySnake->pushSnake(rear);
        delete food;
        food = NULL;
        myMap->CreatFood();
    }
    else
    {
        mySnake->popSnake();
        mySnake->pushSnake(rear);
    }
    myMap->displayMap();
    return true;
}

void Controller::setDirect(char ch)
{
    if (ch == 'w' && direct != Down)
        direct = Up;
    else if (ch == 's' && direct != Up)
        direct = Down;
    else if (ch == 'a' && direct != Right)
        direct = Left;
    else if (ch == 'd' && direct != Left)
        direct = Right;
}

bool Controller::isFail(Point *point)
{
    int x = point->getX();
    int y = point->getY();
    if (x < 0 || x >= WIDTH)
        return false;
    if (y < 0 || y >= HEIGHT)
        return false;
    if (mySnake->isHave(point))
        return false;
    else return true;
}
