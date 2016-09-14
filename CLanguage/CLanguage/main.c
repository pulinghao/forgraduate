//
//  main.c
//  CLanguage
//
//  Created by LinghaoPu on 16/8/17.
//  Copyright © 2016年 pulinghao. All rights reserved.
//

#include <stdio.h>


#include<stdint.h>
#include<stdio.h>
union X
{
    int32_t a;
    struct
    {
        int16_t b;
        int16_t c;
    };
};

struct st_task
{
    uint16_t id;
    uint32_t value;
    uint64_t timestamp;
};

void Func(char str_arg[100])
{
    printf("%lu\n",sizeof(str_arg));
}

void fool()
{
    struct st_task task = {};
    uint64_t a = 0x00010001;
    memcpy(&task, &a, sizeof(uint64_t));
    printf("%11u,%11u,%llu\n", task.id, task.value, task.timestamp);
}

int iii = 42;
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


int main(void)
{
    
    test();
}

//int main(){
//    union X x;
//    x.a=0x20150810;
//    printf("%x,%x\n",x.b,x.c);
//    return 0;
//}

//int main(int argc, const char * argv[]) {
//    // insert code here...
////    printf("Hello, World!\n");
//    int n=0;
//    char ch;
//    for(ch=getchar();ch!='\n';n++)
//        printf("%d",n);
//    return 0;
//}
