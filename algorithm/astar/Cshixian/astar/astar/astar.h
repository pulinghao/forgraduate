//
//  astar.h
//  astar
//
//  Created by LinghaoPu on 16/6/1.
//  Copyright © 2016年 pulinghao. All rights reserved.
//

#ifndef astar_h
#define astar_h

#include <stdio.h>
#include <stdlib.h>

#define MaxLength 100    //用于优先队列（Open表）的数组
#define Height     15    //地图高度
#define Width      20    //地图宽度

#define Reachable   0    //可以到达的结点
#define Bar         1    //障碍物
#define Pass        2    //需要走的步数
#define Source      3    //起点
#define Destination 4    //终点

#define Sequential  0    //顺序遍历
#define NoSolution  2    //无解决方案
#define Infinity    0xfffffff

#define East       (1 << 0)
#define South_East (1 << 1)
#define South      (1 << 2)
#define South_West (1 << 3)
#define West       (1 << 4)
#define North_West (1 << 5)
#define North      (1 << 6)
#define North_East (1 << 7)

#endif /* astar_h */

typedef struct MapNode
{
    int x,y;
    unsigned char reachable, sur, value;
}kMapNode;


typedef struct Close
{
    kMapNode *cur;
    char vis;
    struct Close *from;
    float F,G;
    int H;
}kClose;

void initGraph(const int map[Height][Width], int sx, int sy, int dx, int dy);

void printMap();

unsigned char within(int x, int y);

int printShortest();

void clearMap();

int bfs();