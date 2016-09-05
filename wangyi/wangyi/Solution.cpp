//
//  Solution.cpp
//  wangyi
//
//  Created by LinghaoPu on 16/8/23.
//  Copyright © 2016年 pulinghao. All rights reserved.
//

#include "Solution.hpp"
#include <algorithm>


typedef TreeNode node;
typedef TreeNode* pnode;
typedef int* pint;

vector<int> buf;

void PermutationHelp(vector<string> &array, string str,int begin);


//一个数的最高位数
int getTheTopNumer(int number);

void dfs(pnode p)
{
    if (!p) {
        buf.push_back(0x23333);
    } else {
        buf.push_back(p->val);
        dfs(p->left);
        dfs(p->right);
    }
}

pnode dfs2(pint& p)
{
    if (*p == 0x23333) {
        p++;
        return NULL;
    }
    
    pnode res = new node(*p);
    ++p;
    res -> left = dfs2(p);
    res -> right = dfs2(p);
    return res;
}



char* Solution::Serialize(TreeNode *root)
{

    
    if (root == NULL) {
        return NULL;
    }
    
    buf.clear();
    dfs(root);
    int* res = new int[buf.size()];
    for (unsigned int i = 0; i < buf.size(); i++) {
        res[i] = buf[i];
    }
    return (char*)res;
    

    
}

vector<string> Solution::Permutation(string str)
{
    //方法一，使用algorithm的全排列算法
    vector<string> answer;
    if(str.empty())
        return answer;
    sort(str.begin(),str.end());
    do{
        answer.push_back(str);
    }
    while(next_permutation(str.begin(),str.end()));
//    return answer;
    
    //方法二，递归
    vector<string> array;
    if (str.size() == 0) {
        return array;
    }
    
    PermutationHelp(array,str,0);
    sort(array.begin(), array.end());
    return array;
    

}

void PermutationHelp(vector<string> &array, string str,int begin)
{
    if (begin == str.size() - 1) {
        //只有一个字符的时候
        array.push_back(str);
    }
    
    for (int i = begin; i <= str.size() - 1; i++) {
        if (i!=begin && str[i] == str[begin]) {
            continue;
        }
        
        swap(str[i], str[begin]);
        
        PermutationHelp(array,str, begin + 1);
        
        swap(str[i],str[begin]);
    }
}


TreeNode* Solution::Deserialize(char *str)
{
    int *p = (int*)str;
    return dfs2(p);
}

bool IsPopOrader(vector<int> pushV, vector<int> popV)
{
    if (pushV.size() == 0) {
        return false;
    }
    
    vector<int> stack;
    for (int i = 0, j = 0; i < pushV.size();) {
        stack.push_back(pushV[i++]);
        while (j < popV.size() && stack.back() == popV[j]) {
            stack.pop_back();
            j++;
        }
    }
    return stack.empty();
}

#pragma mark - 把数组排成最小数
//采用字符串的流处理
static int compare(const string& st1,const string& st2)
{
    string s1 = st1+st2;
    string s2 = st2+st1;
    return s1<s2;
}
string Solution::PrintMinuNumber(vector<int> numbers)
{
    string result;
    
    
    if (numbers.size()<=0) {
        return 0;
    }
    
    vector<string> vec;
    
    for (unsigned int i = 0; i < numbers.size(); i++) {
        stringstream ss;
        ss<<numbers[i];
        string s = ss.str();
        vec.push_back(s);
    }
    
    sort(vec.begin(), vec.end(), compare);
    
    for (unsigned int i = 0; i < vec.size(); i++) {
        result.append(vec[i]);
    }
    return result;
    
    
}

//求一个数的最高位数字
int getTheTopNumer(int number)
{
    int result = 0;
    
    if (number == 0) {
        return 0;
    }
    
    while (number/10 != 0) {
        number = number/10;
    }
    return result;
}











