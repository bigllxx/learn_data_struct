 #include <stdio.h>
#include <stdlib.h>

#define ElemType int

typedef struct ThreadNode  // 线索二叉树
{
  int data;
  struct ThreadNode *lchild, *rchild;  // 左右指针，分别指向左右孩子
  int ltag, rtag;  // 左右线索，0表示否（指针指向孩子），1表示是（指针指向前驱/后继）
} ThreadNode, *ThreadTree;

