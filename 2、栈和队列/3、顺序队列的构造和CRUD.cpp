#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10

typedef struct{  // 构造一个顺序栈
  int data[MaxSize];
  int front, rear;
  // int size;  // 储存当前队列长度，用于判满
  // int tag;  // 储存上一次操作是 插入0 还是 删除1，用于判满
}SqQueue;

bool Empty(SqQueue Q){
  if(Q.front == Q.rear) return true;  // 每次先入队，后rear+1，这样rear永远指向没有数据的下标
  return false;
}

bool Full(SqQueue Q){
  if((Q.rear + 1)%MaxSize == Q.front) return true;
  // if (Q.size == MaxSize) return true;  // 两个可能会考的判满操作
  // if (Q.front == Q.rear && Q.tag==0) return true;
  return false;
}

bool EnQueue(SqQueue &Q, int x){  // 入队操作
  if (Full(Q)) return false;
  Q.data[Q.rear] = x;
  Q.rear = (Q.rear+1)%MaxSize;  // 当rear=10的时候，这种操作可以让rear重新回到1，实现循环队列
  return true;
}

bool deQueue(SqQueue &Q, int &x){  // 出队操作
  if (Empty(Q)) return false;
  x = Q.data[Q.front];
  Q.front = (Q.front+1)%MaxSize;
  return true;
}


void InitQueue(SqQueue &Q){
  Q.front = Q.rear = 0;
}