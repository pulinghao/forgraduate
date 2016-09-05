//
//  Screen.hpp
//  CPlusPrimer
//
//  Created by 浦灵昊 on 16/9/3.
//  Copyright © 2016年 浦灵昊. All rights reserved.
//

#ifndef Screen_hpp
#define Screen_hpp

#include <stdio.h>
#include <string>
//#incldue "Window_mgr.hpp"
#endif /* Screen_hpp */

using namespace std;
//void Window_mgr::clear(ScreenIndex);

class Screen {
    friend class Window_mgr;
//   friend void Window_mgr::clear(ScreenIndex);
public:
    typedef string::size_type pos;
    
    Screen() = default;
    
    Screen(pos ht, pos wd, char c):height(c),width(wd),contents(ht*wd,c){}
    char get() const{return contents[cursor];}
    inline char get(pos ht, pos wd) const;
    void some_member() const;
    
    
//    Screen set(char);
    Screen &move(pos r, pos c);

    Screen &set(char);
    Screen &set(pos,pos,char);
    
    Screen display(ostream &os){
        do_display(os);
        return *this;
    }
    
    const Screen display(ostream &os) const
    {
        do_display(os);
        return *this;
    }
    
    
    
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;
    
    mutable size_t access_ctr;
    
    void do_display(ostream &os) const {os << contents;}
};

//void Window_mgr::clear(ScreenIndex);

inline Screen& Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

inline Screen& Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline Screen& Screen::set(pos r, pos col, char ch)
{
    contents[r*width + col] = ch;
    return *this;
}