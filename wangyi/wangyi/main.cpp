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
#include <set>
#include <algorithm>

#include <numeric>
#include <map>
using namespace std;

string findzixulie(string a, string b);

void f(int *p,int *q)
{
    (*p)++;
    *q = *q+1;
}

//
//class B0//基类BO声明
//{
//public://外部接口
//    virtual void display()//虚成员函数
//    {
//    cout<<"B0::display0"<<endl;}
//};
//class B1:public B0//公有派生
//{
//public:
//    void display() { cout<<"B1::display0"<<endl; }
//};
//class D1: public B1//公有派生
//{
//public:
//    void display(){ cout<<"D1::display0"<<endl; }
//};
//void fun(B0 ptr)//普通函数
//{
//    ptr.display();
//}

//class A
//{
//public:
//    A(){
//        cout<<"constuct"<<endl;
//    };
//    ~A(){
//        cout<<"destruct"<<endl;
//    };
//};

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

char* getMem(void) {
    char p[] = "hello world";
    p[5] = 0x0;
    
    return p;
}
void test(void) {
    char *s = 0x0;
    s = getMem();
    printf("%s\n",s);
}


string getString()
{
    string r = "123";
    return r;
}

int * getInt()
{
    int i = 4;
    int *p;
    p = &i;
    return p;
}


#define MMAX 1000
#define NMAX 1000



int minTotal(vector<int> price_array,set<string> set_str)
{
    int result;
    
    
    
    
    
    return result;
}



//消除重复单词
void elimDups(vector<string> &words)
{
    //按字典排序
    sort(words.begin(),words.end());
    //unique重排输入范围，使得每个单词只出现一次
    auto end_unique = unique(words.begin(), words.end());
    
    //使用向量操作，删除重复单词
    words.erase(end_unique,words.end());
}


//谓词
bool isShorter(const string& s1,const string& s2)
{
    //短的在前，长的在后
    return s1.size() < s2.size();
    //sort(words.begin(),words.end(),isShoter)
}



void quickSort(int s[], int l, int r)
{
    if (l< r)
    {
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while(i < j && s[j]>= x) // 从右向左找第一个小于x的数
                j--;
            if(i < j)
                s[i++] = s[j];
            while(i < j && s[i]< x) // 从左向右找第一个大于等于x的数
                i++;
            if(i < j)
                s[j--] = s[i];
        }
        s[i] = x;
        
        for (int k = 0; k <= r; k++) {
            cout<<s[k]<<" ";
        }
//        quickSort(s, l, i - 1); // 递归调用
//        quickSort(s, i + 1, r);
    }
}

//struct A
//{
//    bool b;
//    int arr[2];
//    int i;
//    int j;
//};





//int main()
//{
//    A a;
//    a.b =false;
//    a.arr[]
//    vector<string> vec;
//    string a;
//    cout<<"请输入由数字字符和非数字字符组成的字符串：";
//    while(cin>>a)
//    {
//        vec.push_back(a);
//    }
//    for(vector<string>::size_type i=0;i!=vec.size();i++)
//    {
//        for(size_t t=0;t!=vec[i].size();t++)
//        {
//            if((vec[i][t]<='9') && (vec[i][t]>='0'))
//            {
//                cout<<vec[i][t];
//            }
//            
//        }
//    }
//}
//
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

//class Point{
//public:
//    Point(int a,int b)
//    {
//        x = a;
//        y = b;
//    }
//    
//    int calTime()
//    {
//        int result = 0;
//        result = (x - 1) + (y - 1);
//        return result;
//    }
//
//    int x;
//    int y;
//};
//
//int main()
//{
//    int track_num;
//    
//    vector<Point> vec;
//    vector<int> x_vec;
//    vector<int> y_vec;
//    
//    cin>>track_num;
//    if (track_num > 1000) {
//        return 0;
//    }
//    
//    for (int i = 0; i < track_num; i++) {
//        int px;
//        cin>>px;
//        x_vec.push_back(px);
//    }
//    
//    for (int i = 0; i < track_num; i++) {
//        int py;
//        cin>>py;
//        y_vec.push_back(py);
//    }
//    
//    int minTime = 2000;
//    for (int i = 0; i < track_num; i++) {
//        Point p(x_vec[i],y_vec[i]);
//        vec.push_back(p);
//        
//        if(p.calTime()<minTime){
//            minTime = p.calTime();
//        }
//    }
//    
//    cout<<minTime;
//    
//    return 0;
//    
//}



//变为斐波那契数
//返回最近的比n小的斐波那契数
int lessThanN(int n)
{
    int result = 0;
    
    int f1 = 1; //左边那个数
    int f2 = 1; //右边那个数
    int f3 = 1;
    while (result < n) {
        result = f1 + f2;
        f3 = f1;
        f1 = f2;
        f2 = result;
    }
    return  result - f3;
}


int moreThanN(int n)
{
    int result = 0;
    
    int f1 = 1; //左边那个数
    int f2 = 1; //右边那个数
    while (result < n) {
        result = f1 + f2;
        f1 = f2;
        f2 = result;
    }
    return  result;
}

bool equalToN(int n)
{
    int result = 0;
    
    int f1 = 1; //左边那个数
    int f2 = 1; //右边那个数
    while (result < n) {
        result = f1 + f2;
        f1 = f2;
        f2 = result;
        if (result == n) {
            cout<<"true";
            return true;
        }
    }
    cout<<"false2";
    return  false;
}

//struct A
//{
//    A(){}
//    ~A(){}
//    int m1;
//    int m2;
//};
//
//struct B:A
//{
//    B(){}
//    ~B(){}
//    int m1;
//    char m2;
//    static char m3;
//};
//
//struct C
//{
//    C(){};
//    virtual~C(){}
//    int m1;
//    short m2;
//};
//
//int main()
//{
//    cout<<sizeof(A)<<endl;
//    cout<<sizeof(B)<<endl;
//    cout<<sizeof(C);
//}
////int main()
////{
////    int num;
//    cin>>num;
//    
//    if(num > 1000000) cout<<"error";
//    
//    if(num == 0) cout<<0;
//
//    if (num == 1) {
//        cout<<0;
//    }
//    if (num == 2) {
//        cout<< 0;
//    }
//    
//    int toleft;
//    int toright;
//    toleft = num - lessThanN(num);
//    toright = moreThanN(num) - num;
//    
//    if (toleft >= toright) {
//        cout<<toright;
//    } else {
//        cout<<toleft;
//    }
//    
//}

//class A
//{
//public:
//    virtual void fun();
//    
//    void func(){cout<<"A::func()";}
//    
//    
//};
//
//class B:public A
//{
//public:
//    void fun(int){cout<<"B::f()";};
//    void func(){cout<<"B::func()";}
//    virtual void fund();
//};
//
//class C:public B
//{
//public:
//    void fun(int){cout<<"C::f()";}
//    void func(){cout<<"C::func()";}
//    void fund();
//};
//
//int main()
//{
//    A aa;
//    B bb;
//    C cc;
//    A* a = &aa;
//    B* b = &bb;
//    C* c = &cc;
//    
//    b->fund();
//    
//    return 0;
//}

//class Base
//{
//public:
//    virtual int fcn(){cout<<"Base::fcn";return 1;};
//};
//
//class D1:public Base
//{
//public:
//    int fcn(int){
//        cout<<"D1::fcn";
//        return 1;};
//    virtual void f2();
//    
//};
//
//class D2:public D1
//{
//public:
//    int fcn(int);
//    int fcn();
//    void f2();
//};
//
//int main()
//{
//    Base bobj;
//    D1 d1obj;
//    D2 d2obj;
//    
//    Base* bp1 = &bobj,*bp2 = &d1obj,*bp3=&d2obj;
//    
//    bp1->fcn();
//    bp2->fcn();
//    bp3->fcn();
//    
//    D1 *d1p = &d1obj;
//    D2 *d2p = &d2obj;
//    
////    bp2->f2();
//    d1p->f2();
//    d2p->f2();
//}

//void printVec(vector<vector<int>> v);
//
//
//vector<vector<int>> constructZengliang(int m,int row,int col)
//{
//    vector<vector<int>> midv;
//    vector<vector<int>> result;
//
//    
//    for (int i = 0; i < row; i++) {
//        vector<int> temp;
//        for (int j = 0; j < col; j++) {
//            int k = i*col + m + j;
//            temp.push_back(k);
//        }
//        midv.push_back(temp);
//    }
//    
//    printVec(midv);
//    
//    for (int i = 0; i < row; i++) {
//        vector<int> rt;
//        for (int j = 0; j < row; j++) {
//            //外层定结果的位置
//            vector<int> tv = midv[i];
//            
//                int sum = 0;
//                vector<int> kv = midv[j];
//                
//                for (int l = 0; l < col; l++) {
//                    sum = kv[l]*tv[l]+sum;
//                }
//                rt.push_back(sum);
//            
//        }
//        result.push_back(rt);
//    }
//        
//    
//    printVec(result);
//    return result;
//}
//
//
//
//void printVec(vector<vector<int>> v)
//{
//    for (int i = 0; i < v.size(); i++) {
//        vector<int> vi = v[i];
//        for (int j = 0; j < vi.size(); j++) {
//            cout<<vi[j]<<" ";
//        }
//        cout<<endl;
//    }
//    
//}
//vector<vector<int>> cal(vector<vector<int>> v)
//{
//    vector<vector<int>> result;
//    
//
//    
//    return result;
//}
//
//int main()
//{
//    vector<vector<int>> arr;
//    
//    int init;
//    int n;
//    int m;
//    cin>>init>>n>>m;
//    
//    
//    constructZengliang(init,n,m);
//    
//    return 0;
//}


int main()
{
    int a,b,c,d;
    int x,y,z;
    float fy;
    cin>>a>>b>>c>>d;
    
    if (b+d < 0) {
        cout<<"NO";
    } else {
        fy = (b+d)/2;
        
        if (fy == int(fy)) {
            y = int(fy);
            z = y - b;
            if (z<0) {
                cout<<"NO";
            } else {
                x = a + y;
                if (x<0) {
                    cout<<"NO";
                } else {
                    
                    if(x + y != c){
                        cout<<"NO";
                    } else {
                        cout<<x<<" "<<y<<" "<<z;
                    }
                }
            }
        } else {
            cout<<"NO";
        }
    }
    
    
    
    
}