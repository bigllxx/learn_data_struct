#include <stdio.h>   // 使用printf要这个包
#include <stdlib.h>

typedef struct LNode  // 构造单链表
{
  int data;
  struct LNode *next;
} LNode, *LinkList; // 给链表设置别名，用 LNode 声明指针要加 * ，用 LinkList 不用加 *。

typedef struct DNode  // 构造双链表
{
  int data;
  struct DNode *prior, *next;  // 一个前指针，一个后指针
} DNode, *DLinkList;  // D double简写

bool InitLinkList(LinkList &L){  // 初始化循环单链表
  L = (LNode *)malloc(sizeof(LNode));
  if (L==NULL) return false;
  L->next = L;  // L的后继指针指向本身
  return true;
}

bool InitDLinkList(DLinkList &L){  // 初始化循环双链表
  L = (DNode *)malloc(sizeof(DNode));
  if (L==NULL) return false;
  L->prior = L;  // L的两个指针都指向本身
  L->next = L;
  return true;
}

bool Empty(LinkList L){  // 判断循环链表是否为空，两种都是这样判断
  if (L->next == L) return true;
  return false;
}

bool isTail(LinkList L, LNode *p){  // 判断节点p是否是循环链表的最后一个节点，两种都是这样判断
  if(p->next==L) return true;
  return false;
}

bool InsertNextNode(DNode *p, DNode *s){  // 循环双链表的插入，将s插入到p的后面
  p->next->prior = s;
  s->next=p->next;
  p->next = s;
  s->prior = p;
  return true;
}

