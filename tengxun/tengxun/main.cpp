//
//  main.cpp
//  tengxun
//
//  Created by LinghaoPu on 16/9/10.
//  Copyright © 2016年 pulinghao. All rights reserved.
//

#include <iostream>
#include <list>
using namespace std;

#pragma pack(2)

struct A
{
    int a;
    char b;
    short c;
};


#pragma pack()

#pragma pack(4)
struct B
{
    char b;
    int a;
    short c;
};

#pragma pack()

int main(int argc, const char * argv[]) {
    // insert code here...

    

}
