//
//  main.m
//  objectiveCPro
//
//  Created by LinghaoPu on 16/8/8.
//  Copyright © 2016年 pulinghao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <objc/objc.h>
#import "TestOne.h"

int func(int count);

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...

//        void (^blk)(void) = ^{printf("this is a block");};
//        blk();

        NSMutableString *testString = [NSMutableString stringWithFormat:@"123"];
        TestOne* one = [[TestOne alloc] init];
        one.string = testString;
        [testString appendString:@"456"];
        NSLog(@"%p,%p",testString,one.string);
        NSLog(@"%@,%@",testString,one.string);

        
        
    }
    return 0;
}



void fooMethod(id obj, SEL _cmd)
{
    NSLog(@"Doing foo");
}

int func(int count)
{
    return count + 1;
}