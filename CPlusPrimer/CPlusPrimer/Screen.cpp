//
//  Screen.cpp
//  CPlusPrimer
//
//  Created by 浦灵昊 on 16/9/3.
//  Copyright © 2016年 浦灵昊. All rights reserved.
//

#include "Screen.hpp"



void Screen::some_member() const
{
    ++ access_ctr;
}



char Screen::get(pos r, pos c) const{
    pos row = r * width;
    return  contents[row + c];
}

