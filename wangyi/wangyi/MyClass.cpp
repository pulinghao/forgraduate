//
//  MyClass.cpp
//  wangyi
//
//  Created by LinghaoPu on 16/8/18.
//  Copyright © 2016年 pulinghao. All rights reserved.
//

#include "MyClass.hpp"
#include <stdio.h>
#include <iostream>
using namespace std;

MyClass::MyClass()
{
    cout<<"my class construct"<<endl;
}

MyClass::~MyClass()
{
    cout<<"my class destruct";
}