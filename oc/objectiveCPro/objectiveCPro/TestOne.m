//
//  TestOne.m
//  objectiveCPro
//
//  Created by LinghaoPu on 16/8/15.
//  Copyright © 2016年 pulinghao. All rights reserved.
//

#import "TestOne.h"
#import <objc/objc.h>
#import <objc/runtime.h>


@implementation TestOne

- (NSString *)nameWithInstance:(id)instance
{
    unsigned int numIvars = 0;
    NSString* key = nil;
    Ivar* ivars = class_copyIvarList([self class],&numIvars);
    for (int i = 0; i < numIvars; i++) {
        Ivar thisIvar = ivars[i];
        const char *type = ivar_getTypeEncoding(thisIvar);
        NSString* stringType = [NSString stringWithCString:type encoding:NSUTF8StringEncoding];
        if (![stringType hasPrefix:@"@"]) {
            continue;
        }
        
        if (object_getIvar(self, thisIvar) == instance) {
            key = [NSString stringWithUTF8String:ivar_getName(thisIvar)];
        }
    }
    
    free(ivars);
    
    return key;
}

- (void)runLoopTest
{
    CFRunLoopObserverRef observer = CFRunLoopObserverCreateWithHandler(CFAllocatorGetDefault(), kCFRunLoopAllActivities, YES, 0, ^(CFRunLoopObserverRef observer, CFRunLoopActivity activity) {
        NSLog(@"----监听到RunLoop状态发生改变---%zd", activity);
    });

    CFRunLoopAddObserver(CFRunLoopGetCurrent(), observer, kCFRunLoopDefaultMode);

    CFRelease(observer);
}


@end
