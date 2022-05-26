#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode  // 构造一个队列，实际就是一个链表
{
  int data;
  struct LinkNode *next;
}LinkNode;

typedef struct{  // 构造队列的头、尾指针
  LinkNode *front, *rear;
}LinkQueue;


void InitQueue(LinkQueue &Q){  // 初始化
  Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
  Q.front->next = NULL;
}

bool Empty(LinkQueue Q){  // 判空
  if(Q.front==Q.rear) return true;
  return false;
}

void EnQueue(LinkQueue &Q, int x){  // 入队
  LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
  s->data = x;
  s->next=NULL;
  Q.rear->next = s;  // 尾指针所在节点指向s
  Q.rear = s;  // 尾指针指向s
}

bool DeQueue(LinkQueue &Q, int &x){  // 出队
  if(Q.front=Q.rear) return false;
  LinkNode *p = Q.front->next;
  x = p->data;
  Q.front->next = p->next;
  if(Q.rear==p) Q.rear=Q.front;
  free(p);
  return true;
}