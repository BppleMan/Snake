//
//  kbhit.hpp
//  CPP贪吃蛇
//
//  Created by BppleMan‘s Mac on 16/4/13.
//  Copyright © 2016年 BppleMan‘s Mac. All rights reserved.
//

#ifndef kbhit_hpp
#define kbhit_hpp

#include "Header.h"

class Kbhit
{
private:
    int tty_set_flag;
    termios ori_attr, cur_attr;
public:
    Kbhit();
    ~Kbhit();
    
    int tty_set(void);
    
    int tty_reset(void);
    
    int kbhit(void);
};

#endif /* kbhit_hpp */
