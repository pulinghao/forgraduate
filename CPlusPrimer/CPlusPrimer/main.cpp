//
//  main.cpp
//  CPlusPrimer
//
//  Created by 浦灵昊 on 16/9/3.
//  Copyright © 2016年 浦灵昊. All rights reserved.
//

#include <iostream>

#include "Screen.hpp"
using namespace std;



//typedef string Type;
//
//Type initVal();
//class Exercise
//{
//public:
//    typedef double  Type;
//    Type setVal(Type);
//    Type initVal();
//private:
//    int val;
//};
//
//Exercise::Type Exercise::setVal(Type param)
//{
//    val = param + Exercise::initVal();
//    return val;
//}

class base{
public:
    string name(){return  basename;}
    
    virtual void print(ostream &os){os << basename;}
private:
    string basename = "adf";
};

class derived:public base {
public:
    void print(ostream &os){base::print(os);os<< " "<<i;}
private:
    int i = 2;
};
int main(int argc, const char * argv[]) {
    // insert code here...

        return 0;
}
