//
//  kbhit.cpp
//  CPP贪吃蛇
//
//  Created by BppleMan‘s Mac on 16/4/13.
//  Copyright © 2016年 BppleMan‘s Mac. All rights reserved.
//

#include "kbhit.hpp"

Kbhit::Kbhit()
{
    tty_set_flag = tty_set();
}

int Kbhit::tty_set(void)
{
    
    if ( tcgetattr(STDIN_FILENO, &ori_attr) )
        return -1;
    memcpy(&cur_attr, &ori_attr, sizeof(cur_attr) );
    cur_attr.c_lflag &= ~ICANON;
    //        cur_attr.c_lflag |= ECHO;
    cur_attr.c_lflag &= ~ECHO;
    cur_attr.c_cc[VMIN] = 1;
    cur_attr.c_cc[VTIME] = 0;
    
    if (tcsetattr(STDIN_FILENO, TCSANOW, &cur_attr) != 0)
        return -1;
    return 0;
}

int Kbhit::tty_reset(void)
{
    if (tcsetattr(STDIN_FILENO, TCSANOW, &ori_attr) != 0)
        return -1;
    
    return 0;
}


int Kbhit::kbhit(void)
{
    
    fd_set rfds;
    struct timeval tv;
    int retval;
    
    /* Watch stdin (fd 0) to see when it has input. */
    FD_ZERO(&rfds);
    FD_SET(0, &rfds);
    /* Wait up to five seconds. */
    tv.tv_sec  = 0;
    tv.tv_usec = 0;
    
    retval = select(1, &rfds, NULL, NULL, &tv);
    /* Don't rely on the value of tv now! */
    
    if (retval == -1) {
        perror("select()");
        return 0;
    } else if (retval)
        return 1;
    /* FD_ISSET(0, &rfds) will be true. */
    else
        return 0;
    return 0;
}

Kbhit::~Kbhit()
{
    if (tty_set_flag == 0)
        tty_reset();
}