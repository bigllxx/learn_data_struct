#include <stdio.h> 
#include <stdlib.h>

typedef struct DNode
{
  int data;
  struct DNode *prior, *next;  // 一个前指针，一个后指针
} DNode, *DLinkList;  // D double简写

bool InitDLinkList(DLinkList &L){  // 初始化
  L = (DNode *)malloc(sizeof(DNode));  // L理解为头节点，给头节点申请内存空间
  if(L == NULL) return false;  // 如果没有申请成功（可能内存满了）
  L->prior = NULL;  // 头节点的前驱指针永远指向NULL
  L->next = NULL;  // 防止脏数据
  return true;
}

bool Empty(DLinkList L){  // 判空
  return L->next == NULL;
}

bool InsertNextDNode(DNode *p, DNode *s){  // 插入操作，在p节点后插入s节点
  if(p==NULL || s==NULL) return false;
  s->next = p->next;
  if(p->next != NULL) p->next->prior = s;  // 如果p有后继节点，将后继节点的前驱指向s
  s->prior = p;
  p->next = s;
  return true;
}

bool DeleteNextDNode(DNode *p){  // 删除p节点的后一个节点
  if(p==NULL || p->next == NULL) return false;
  DNode *q = p->next; // 新建一个节点q，指向p后面一个节点（q就是要删除的节点）
  p->next = q->next;  // p的后继指针指向q节点的后一个节点
  if(q->next != NULL) q->next->prior = p;  // 如果q不是最后一个节点，将q后继节点的前驱指向p
  free(q);
  return true;
}

void DestoryList(DLinkList &L){  // 清空链表
  while(L->next != NULL){
    DeleteNextDNode(L);
  }
  free(L);  // 释放头节点的内存空间，注意这里只是释放了L指向的头节点的堆内存，但L这个变量还在栈内存里面，是个指针
  L=NULL;  // 使头节点指向NULL
}


int main(){
  DLinkList L;
  InitDLinkList(L);
}