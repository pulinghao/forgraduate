//
//  main.cpp
//  CPlusLanguage
//
//  Created by LinghaoPu on 16/9/2.
//  Copyright © 2016年 pulinghao. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int i = 2;
class BaseCls{
public:
    BaseCls():m_nSec(i++),m_nFir(i++){
        
    }
    
    virtual int getResult()
    {
        return m_nFir+m_nSec;
    }
protected:
    int m_nFir;
    int m_nSec;
};


class MyCls:public BaseCls
{
public:
    MyCls():m_nFor(m_nThd),m_nThd(i++)
    {
        m_nThd = i;
    }
    
    int getResult(){
        return m_nFir + m_nSec + m_nThd + m_nFor;
    }
    
private:
    int m_nThd;
    int& m_nFor;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    BaseCls* instance = new MyCls();
    cout<<instance->getResult()<<endl;
    
    string s1 = "adfasdf";
    string s2 = "adad";
    
    cout<<s1.compare(s2);
    
    return 0;
}
