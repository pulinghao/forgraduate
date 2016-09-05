//
//  main.cpp
//  wangyi
//
//  Created by LinghaoPu on 16/8/2.
//  Copyright © 2016年 pulinghao. All rights reserved.
//


//  x.nowcoder.com
//  ooo
#include <iostream>
#include "MyClass.hpp"
#include "tengxun.hpp"
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

string findzixulie(string a, string b);

void f(int *p,int *q)
{
    (*p)++;
    *q = *q+1;
}


class B0//基类BO声明
{
public://外部接口
    virtual void display()//虚成员函数
    {
    cout<<"B0::display0"<<endl;}
};
class B1:public B0//公有派生
{
public:
    void display() { cout<<"B1::display0"<<endl; }
};
class D1: public B1//公有派生
{
public:
    void display(){ cout<<"D1::display0"<<endl; }
};
void fun(B0 ptr)//普通函数
{
    ptr.display();
}

class A
{
public:
    A(){
        cout<<"constuct"<<endl;
    };
    ~A(){
        cout<<"destruct"<<endl;
    };
};

int funXXX(unsigned int x)
{
    int n=0;
    while((x+1))
    {
        n++;
        x=x|(x+1);
    }
    return n;
}

class XA
{
public:
    int _a;
    XA()
    {
        _a = 1;
    }
    void print()
    {
        printf("%d\n", _a);
    }
};
class XB: public XA
{
public:
    int _a;
    XB()
    {
        _a = 2;
    }
};

int iii = 42;

bool isNext(char* prev,char* next);



int isArrangeWord(char** arr, int num)
{
    for (int i = 0; i < num; i++) {
        char* checkstr = arr[i];
        
        stack<string> leftStack;
        vector<string> rightStack;
        
        for (int j = 0; j < num; j++) {
            if (i == j) {
                continue;
            }
            
            char* teststr = arr[j];
            
            if (isNext(checkstr,teststr)) {
                
            }
            
            
        }
        
        
        
        
        
    }
    

    
    return 0;
}

bool isNext(char* prev,char* next)
{
    unsigned long length = strlen(prev) - 1;
    
    char p_last = *(prev+length);
    char n_firt = *next;
    if (p_last == n_firt) {
        return 1;
    } else{
        return 0;
    }
}


char getLastChar(char* str)
{
    if (str == NULL) {
        return NULL;
    }
    unsigned long length = strlen(str) - 1;
    char last = *(str+length);
    return last;
}



int mgetTheTopNumer(int number)
{
    int result = 0;
    
    if (number == 0) {
        return 0;
    }
    
    while (number/10 != 0) {
//        int temp  = number / 10;
//        if (temp == 0) {
//            result = number%10;
//            break;
//        } else {
//            number = number/10;
//        }
        number = number/10;
    }
    
    result = number;
    return result;
}



string reverseString(string str)
{
    string result;
    vector<string> temp;
    
    string ts;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != ' ') {
            if (str[i+1] == '\0') {
                ts.push_back(str[i]);
                temp.push_back(ts);
                ts = "";
            }
            ts.push_back(str[i]);
        } else {
            temp.push_back(ts);
            ts = "";
            
        }
    }
    
//    temp.push_back(ts);
    
    for (auto it = temp.end() - 1; it >= temp.begin(); it --) {
        result.append(*it);
        if (it != temp.begin()) {
            result.append(" ");
        }
    }
    
    return result;
}

int main()
{
    
    string testStr;
    getline(cin,testStr);
    cout<<reverseString(testStr)<<endl;
    return 0;
}



//int main()
//{
//    const double pi = 3.14;
//    const double *cptr = &pi;
//    double dval = 3.12;
//    cptr = &dval;
//    return 0;
//}


//int main()//主函数
//{
//    B0 b0;//声明基类对象和指针
//    B1 b1;//声明派生类对象
//    D1 d1;//声明派生类对象
//    fun(b0);//调用基类B0函数成员
//    fun(b1);//调用派生类B1函数成员
//    fun(d1);//调用派生类D1函数成员
//}

#pragma mark - 系统Main函数
//int main(int argc, const char * argv[]) {
////    // insert code here...
////    int m = 1,n = 2,*r = &m;
////    f(r,&n);
////    cout<<m<<","<<n<<endl;
//    MyClass c1;
//    MyClass *c2;
//    MyClass *c3=new MyClass;
//    MyClass &c4=c1;
//    return 0;
//}

