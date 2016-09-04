//
//  Window_mgr.hpp
//  CPlusPrimer
//
//  Created by 浦灵昊 on 16/9/3.
//  Copyright © 2016年 浦灵昊. All rights reserved.
//

#ifndef Window_mgr_hpp
#define Window_mgr_hpp

#include <stdio.h>
#include <vector>
#include "Screen.hpp"

#endif /* Window_mgr_hpp */

using namespace std;

class Window_mgr
{

public:
    using ScreenIndex  = vector<Screen>::size_type;
    
    void clear(ScreenIndex);
private:
    vector<Screen> screens{Screen(24,80,' ')};  //初始化方法
};


void Window_mgr::clear(ScreenIndex i)
{
    Screen &s = screens[i];
    
    //
    s.contents = string(s.height * s.width , ' ');
}
