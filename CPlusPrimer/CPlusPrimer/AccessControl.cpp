//
//  AccessControl.cpp
//  CPlusPrimer
//
//  Created by 浦灵昊 on 16/9/4.
//  Copyright © 2016年 浦灵昊. All rights reserved.
//  访问控制

#include "AccessControl.hpp"

class Base
{
public:
    void pub_mem();
protected:
    int prot_mem;
private:
    char priv_mem;
};

struct Pub_Derv:public Base{
    int f() {return prot_mem;};
//    char g(){_DARWIN priv_mem;}; //wrong
};

struct Priv_Derv:private Base{
    int f1() const {return prot_mem;};
};