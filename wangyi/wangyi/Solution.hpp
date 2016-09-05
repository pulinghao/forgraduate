//
//  Solution.hpp
//  wangyi
//
//  Created by LinghaoPu on 16/8/23.
//  Copyright © 2016年 pulinghao. All rights reserved.
//

#ifndef Solution_hpp
#define Solution_hpp

#include <stdio.h>

#include <vector>
#include <string>
#include <sstream>
#endif /* Solution_hpp */

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
    val(x), left(NULL), right(NULL) {
    }
};

class Solution
{

public:
    
    char* Serialize(TreeNode *root);
    
    TreeNode* Deserialize(char *str);
    
    vector<string> Permutation(string str);

    string PrintMinuNumber(vector<int> numbers);

};