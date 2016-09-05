//
//  tengxun.cpp
//  wangyi
//
//  Created by LinghaoPu on 16/8/31.
//  Copyright © 2016年 pulinghao. All rights reserved.
//

#include "tengxun.hpp"

string putFirstCharToEnd(string str);
string putIndxeCharToEnd(string str, int index);

string Tengxun::revertChars(string str)
{
    for (int i = 0;i < str.length();i++) {
        if (isupper(str[i])) {
            str = putIndxeCharToEnd(str,i);
            i--;
        }
    }
    
    vector<int> arra;
    for (auto it = arra.begin(); it != arra.end(); it++) {
        
    }
    
    return str;
}


string putFirstCharToEnd(string str)
{
    char c = str[0];
    unsigned long length = str.size();
    for(int i = 0 ; i < str.size() - 1;i++)
    {
        str[i] = str[i+1];
    }
    str[length - 1] = c;
    
    return str;
}

string putIndxeCharToEnd(string str, int index)
{
    char c = str[index];
    unsigned long length = str.size();
    for (int i = index; i < length - 1; i++) {
        str[i] = str[i+1];
    }
    str[length - 1] = c;
    return str;
}