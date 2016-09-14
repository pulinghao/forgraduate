//
//  main.cpp
//  wangyiyiyi1
//
//  Created by LinghaoPu on 16/9/12.
//  Copyright © 2016年 pulinghao. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


int Rev(int x)
{
    int r = 0;
    
    while(x/10)
    {
        if (x%10) {
            r = (x%10) + r*10;
        }
        x = x/10;
    }
    
    if (x%10) {
        r = (x%10) + r*10;
    }
    return r;
}


long int recursiveP(long int m);

long int blackString(long int m)
{
    long int r = 0;
    
    //计算有多少个是纯洁字符串，然后减去即可
    
    if (m == 0) {
        return 0;
    }
    if(m < 3) return r = 9;
    
    r = recursiveP(m) - 6 * recursiveP(m - 3);
    
    return r;
}

long int recursiveP(long int m){
    long int result = 1;
    for (int i = 0; i < m; i++) {
        result = result*3;
    }
    return result;
}


int coutTime(vector<int> a)
{
    int r = 0;
    
    int count = 0;
    
    for(int i = 0;i<a.size();i++)
    {
        
    }
    return r;
}

//int main(int argc, const char * argv[]) {
//    // insert code here...
//    
//    int n;
//    cin>>n;
//    
//    vector<int> arr;
//    
//    for(int i = 0;i < n ;i++){
//        int temp;
//        cin>>temp;
//        arr.push_back(temp);
//    }
//    
//    
//    return 0;
//}
int main() {
    int n;
    int i, start, end, count;
    while (cin >> n) {
        vector<int> alldata(n);
        for (i = 0; i < n; i++) {
            cin >> alldata[i];
        }
        start = 0; end = n-1;
        count = 0;
        while (start <= end) {
            if (alldata[start] < alldata[end]) {
                alldata[start+1] += alldata[start];
                start++;
                count++;
            }
            else if (alldata[start] == alldata[end]) {
                start++;
                end--;
            }
            else {
                alldata[end-1] += alldata[end];
                end--;
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}