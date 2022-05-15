#include <stdio.h>  // 使用printf要这个包
#include <stdlib.h> // 使用malloc要这个包

typedef struct LNode
{
  int data;
  struct LNode *next;
} LNode, *LinkList; // 给链表设置别名，用 LNode 声明指针要加 * ，用 LinkList 不用加 *。
// 一般认为LNode代表某个节点，LinkList代表整个链表

bool InitList(LinkList &L)
{                                     // 初始化单链表   如果不加 & ，就是复制传来的参数，加了 & 就是在传过来的参数上做操作
  L = (LNode *)malloc(sizeof(LNode)); // 分配一个头节点
  if (L == NULL)
  {
    return false;
  }
  L->next = NULL;
  return true;
}

bool Empty(LinkList L)
{                           // 判空
  return (L->next == NULL); // 空 则返回true
}

bool ListInsert(LinkList &L, int i, int e)
{ // 插入新节点，按位序插入
  if (i < 1)
    return false;
  LNode *p = GetElem(L, i);
  // LNode *p;
  // p = L;  // p 指向链表头节点
  // int j = 0;
  // while(p != NULL && j<i-1){
  //   p = p->next;
  //   j++;
  // }
  // if(p == NULL) return false;
  // LNode *s = (LNode *)malloc(sizeof(LNode));
  // s->data = e;
  // s->next = p->next;
  // p->next = s;
  // return true;
  return InsertNextNode(p, e);
}

bool InsertNextNode(LNode *p, int e)
{ // 插入新节点，在p后面
  if (p == NULL)
    return false;
  LNode *s = (LNode *)malloc(sizeof(LNode));
  if (s == NULL)
    return false;
  s->data = e;
  s->next = p->next;
  p->next = s;
  return true;
}

bool InsertProirNode(LNode *p, int e)
{ // 插入新节点，在p前面
  if (p == NULL)
    return false;
  LNode *s = (LNode *)malloc(sizeof(LNode));
  if (s == NULL)
    return false;
  s->data = p->data;
  p->data = e;
  s->next = p->next;
  p->next = s;
  return true;
}

bool ListDelete(LinkList &L, int i, int &e)
{ // 删除节点，按位序
  if (i < 1)
    return false;
  LNode *p = GetElem(L, i);
  // LNode *p;
  // p = L;  // p 指向链表头节点
  // int j = 0;
  // while(p != NULL && j<i-1){
  //   p = p->next;
  //   j++;
  // }
  // if(p == NULL || p->next == NULL) return false;
  // LNode *q = p->next;
  // e = q->data;
  // p->next = q->next;
  // free(q);
  return DeleteNode(p);
}

bool DeleteNode(LNode *p)
{ // 删除指定结点
  if (p == NULL)
    return false;
  LNode *q = p->next;
  p->data = q->data;
  p->next = q->next;
  free(q);
  return true;
}

LNode *GetElem(LinkList L, int i)
{ // 按位查找
  if (i < 0)
    return NULL;
  LNode *p;
  int j = 0;
  p = L;
  while (p != NULL && j < i)
  {
    p = p->next;
    j++;
  }
  return p;
}

LNode *LocateElem(LinkList L, int e)
{ // 按值查找
  LNode *p = L->next;
  while (p != NULL && p->data != e)
  {
    p = p->next;
  }
  return p;
}

int Length(LinkList L)
{ // 求表长
  int len = 0;
  LNode *p = L;
  while (p->next != NULL)
  {
    p = p->next;
    len++;
  }
  return len;
}

LinkList ListTailInsert(LinkList &L)
{ // 尾插法建立单链表
  int x;
  L = (LinkList)malloc(sizeof(LNode));
  L->next = NULL;
  LNode *s, *r = L;
  scanf("%d", &x);
  while (x != 999999)
  {
    s = (LNode *)malloc(sizeof(LNode));
    s->data = x;
    r->next = s;
    r = s;
    scanf("%d", &x);
  }
  r->next = NULL;
  return L;
}

LinkList ListHeadInsert(LinkList &L)
{ // 头插法建立单链表
  int x;
  LNode *s;
  L = (LinkList)malloc(sizeof(LNode));
  L->next = NULL;
  scanf("%d", &x);
  while (x != 999999)
  {
    s = (LNode *)malloc(sizeof(LNode));
    s->data = x;
    s->next = L->next;
    L->next = s;
    scanf("%d", &x);
  }
  return L;
}

int main()
{
  // LNode *L;  // 因为 LNode 不是指针类型，所以L前要加 * ，  效果和 LinkList L 效果一样，不过后者可读性更好
  LinkList L; // 因为 LinkList 本身就是指针类型了，所以L前不用加 *
  InitList(L);
  bool a = Empty(L);
  printf("%d", a);
  return 0;
}