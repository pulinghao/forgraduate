//
//  main.m
//  wangyiyi
//
//  Created by LinghaoPu on 16/9/12.
//  Copyright © 2016年 pulinghao. All rights reserved.
//

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        
        NSMutableDictionary* d = [NSMutableDictionary dictionaryWithObjectsAndKeys:@"1",@"2",@"3",@"4",@"5",@"6", nil];
        
        [d removeObjectForKey:@"1"];
//        [d removeObjectForKey:@]
        [d removeAllObjects];
        NSLog(@"Hello, World!");
    }
    return 0;
}
