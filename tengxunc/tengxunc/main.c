//
//  main.c
//  tengxunc
//
//  Created by LinghaoPu on 16/9/10.
//  Copyright © 2016年 pulinghao. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


#define Mul(x,y) ++x*++y

union X
{
    
};
int main(int argc, const char * argv[]) {
    // insert code here...
    int a = 1;
    int b = 2;
    int c = 3;
    printf("%d",Mul(a+b, b+c));
}