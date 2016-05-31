//
//  MapView.cpp
//  CPP贪吃蛇
//
//  Created by BppleMan‘s Mac on 16/4/12.
//  Copyright © 2016年 BppleMan‘s Mac. All rights reserved.
//

#include "MapView.hpp"

MapView::MapView(int width,int height)
{
    this->width = width;
    this->height = height;
}

void MapView::displayMap()
{
    system("clear");
    int i,j;
    for (i = 0; i < height; i++)
    {
        cout<<"|";
        for (j = 0; j < width; j++)
        {
            if (snakeData->isHave(j, i))
                cout<<SNAKE;
            else if (food && food->isEqual(j, i))
                cout<<SNAKE;
            else
                cout<<Map;
        }
        cout<<"|";
        cout<<endl;
    }
}

void MapView::CreatFood()
{
    srand((unsigned)time(NULL));
    while (true)
    {
        int x = rand() % width;
        int y = rand() % height;
        if (!snakeData->isHave(x, y))
        {
            food = new Point(x,y);
            break;
        }
    }
}

Point* MapView::getFood()
{
    if (food)
        return food;
    else return NULL;
}

void MapView::setFoodPoint(Point *p)
{
    if (!p)
        food = NULL;
}

void MapView::setSnakedata(SnakeData *snake)
{
    snakeData = snake;
}
int MapView::getWidth()
{
    return width;
}
int MapView::getHeight()
{
    return height;
}