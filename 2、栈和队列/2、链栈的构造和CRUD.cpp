#include <stdio.h>
#include <stdlib.h> 

typedef struct LinkNode{  // 构造一个单链表
  int data;
  struct LinkNode *next;
}LiStack, *LinkNode;

bool InitListack(LinkNode &L){  // 初始化
  L = (LiStack *)malloc(sizeof(LiStack));
  if (L == NULL) return false;
  L->next = NULL;
  return true;
}

bool Empty(LinkNode L){  // 判空
  if (L->next == NULL) return true;
  return false;
}

bool Push(LinkNode &L, int e){  // 进栈，L代表需要Push的栈（头节点）
  LiStack *x = (LiStack *)malloc(sizeof(LiStack));
  if (x == NULL) return false;
  x->data = e;
  x->next = L->next;  // 永远是在头节点后插入
  L->next = x;
  return true;
}

bool Pull(LinkNode &L, int &e){  // 出栈
  if (L->next == NULL) return false;  
  LiStack *p = L->next;
  e = p->data;
  L->next = p->next;
  free(p);
  return true;
}

bool GetTop(LinkNode L, int &e){  // 读栈顶元素
  if (L->next == NULL) return false;  
  e = L->next->data;
  return true;
}
