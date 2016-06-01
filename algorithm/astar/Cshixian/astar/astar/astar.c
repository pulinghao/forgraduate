//
//  astar.c
//  astar
//
//  Created by LinghaoPu on 16/6/1.
//  Copyright © 2016年 pulinghao. All rights reserved.
//

#include "astar.h"

#include <math.h>
#include <stdio.h>


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


typedef struct mPoint
{
    signed char x,y;
}kPoint;

const kPoint dir[8] =
{
    {0, 1},   // East
    {1, 1},   // South_East
    {1, 0},   // South
    {1, -1},  // South_West
    {0, -1},  // West
    {-1, -1}, // North_West
    {-1, 0},  // North
    {-1, 1}   // North_East
};

unsigned char within(int x, int y)
{
    return (x>=0 && y>=0 && x < Height && y < Width);
}

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


typedef struct Open
{
    int length;
    kClose *Array[MaxLength];
}kOpen;

static kMapNode graph[Height][Width];
static int srcX,srcY,dstX,dstY;
static kClose cclose[Height][Width];

//优先队列的基本操作
void initOpen(kOpen *q)
{
    q->length = 0;  //初始化为0
}

void push(kOpen *q, kClose cls[Height][Width], int x, int y , float g)
{
    kClose *t;
    int i, mintag;
    cls[x][y].G = g;
    cls[x][y].F = cls[x][y].G + cls[x][y].H;
    
    q->Array[q->length++] = &(cls[x][y]);
    mintag = q->length - 1;
    
    for (i = 0; i < q ->length; i++) {
        if (q->Array[i]->F < q->Array[mintag]->F) {
            mintag = i;
        }
    }
    
    t = q->Array[q->length - 1];
    q->Array[q->length - 1] = q->Array[mintag];
    q->Array[mintag] = t;
    
}

kClose* shift(kOpen *q)
{
    return q->Array[--q->length];
}

//地图初始化操作

void initClose(kClose cls[Height][Width], int sx, int sy, int dx, int dy)
{
    //地图初始化配置
    int i,j;
    for (i = 0; i < Height; i++) {
        for (j = 0;  j < Width; j++) {
            cls[i][j].cur = &graph[i][j];
            cls[i][j].vis = !graph[i][j].reachable;
            cls[i][j].from = NULL;
            cls[i][j].G = cls[i][j].F = 0;
            cls[i][j].H = abs(dx - i) + abs(dy - j);
        }
    }
    
    //起始点评价初始值
    cls[sx][sy].F = cls[sx][sy].H;
    cls[dx][dy].G = Infinity;
}


void initGraph(const int map[Height][Width], int sx, int sy, int dx, int dy)
{
    int i,j;
    srcX = sx;
    srcY = sy;
    dstX = dx;
    dstY = dy;
    
    for (i = 0; i < Height; i++) {
        for (j = 0; j < Width; j++) {
            graph[i][j].x = i;
            graph[i][j].y = j;
            graph[i][j].value = map[i][j];
            graph[i][j].reachable = (graph[i][j].value == Reachable);
            graph[i][j].sur = 0;   //邻接节点个数
            if (!graph[i][j].reachable) {
                continue;
            }
            
            if (j>0) {
                if (graph[i][j-1].reachable) { //左节点可达
                    graph[i][j].sur |= West;
                    graph[i][j-1].sur |= East;
                }
                
                if (i>0) {
                    if (graph[i-1][j-1].reachable && graph[i-1][j].reachable && graph[i][j-1].reachable) {   //上左节点可达
                        graph[i][j].sur |= North_West;
                        graph[i-1][j-1].sur |= South_West;
                    }
                }
            }
            
            if (i > 0) {
                if (graph[i-1][j].reachable) {   //上节点可达
                    graph[i][j].sur |= North;
                    graph[i-1][j].sur |= South;
                }
                
                if (j<Width -1) {
                    if (graph[i-1][j+1].reachable && graph[i-1][j].reachable && map[i][j+1] == Reachable) {  //上右节点可达
                        graph[i][j].sur |= North_East;
                        graph[i-1][j+1].sur |= South_West;
                    }
                }
            }
        }
    }
}

int bfs()   //广度优先
{
    int times = 0;
    int i,curX,curY,surX,surY;
    unsigned char f = 0,r = 1;
    kClose *p;
    kClose *q[MaxLength] = { &cclose[srcX][srcY]};
    
    initClose(cclose, srcX, srcY, dstX, dstY);
    
    cclose[srcX][srcY].vis = 1;
    
    while (r != f) {
        p = q[f];
        f = (f+1)%MaxLength;
        curX = p->cur->x;
        curY = p->cur->y;
        for (i = 0; i < 8; i++) {
            if (!(p->cur->sur & ( 1 << i))) {
                continue;
            }
            surX = curX + dir[i].x;
            surY = curY + dir[i].y;
            
            if (! cclose[surX][surY].vis) {
                cclose[surX][surY].from = p;
                cclose[surX][surY].vis = 1;
                cclose[surX][surY].G = p->G + 1;
                q[r] = &cclose[surX][surY];
                r = (r + 1) % MaxLength;
            }
        }
        times++;
    }
    return times;
}

int astar()
{    // A*算法遍历
    //int times = 0;
    int i, curX, curY, surX, surY;
    float surG;
    kOpen q; //Open表
    kClose *p;
    
    initOpen(&q);
    initClose(cclose, srcX, srcY, dstX, dstY);
    cclose[srcX][srcY].vis = 1;
    push(&q, cclose, srcX, srcY, 0);
    
    while (q.length)
    {    //times++;
        p = shift(&q);
        curX = p->cur->x;
        curY = p->cur->y;
        if (!p->H)
        {
            return Sequential;
        }
        for (i = 0; i < 8; i++)
        {
            if (! (p->cur->sur & (1 << i)))
            {
                continue;
            }
            surX = curX + dir[i].x;
            surY = curY + dir[i].y;
            if (!cclose[surX][surY].vis)
            {
                cclose[surX][surY].vis = 1;
                cclose[surX][surY].from = p;
                surG = p->G + sqrt((curX - surX) * (curX - surX) + (curY - surY) * (curY - surY));
                push(&q, cclose, surX, surY, surG);
            }
        }
    }
    //printf("times: %d\n", times);
    return NoSolution; //无结果
}

const int map[Height][Width] = {
    {0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,1},
    {0,0,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
    {0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,0,0,0,0,1},
    {0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,1},
    {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0},
    {0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,1,0,0,0,1},
    {0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0}
};

void printMap()
{
    int i, j;
    for (i = 0; i < Height; i++)
    {
        for (j = 0; j < Width; j++)
        {
            printf("%s", Symbol[graph[i][j].value]);
        }
        puts("");
    }
    puts("");
}


