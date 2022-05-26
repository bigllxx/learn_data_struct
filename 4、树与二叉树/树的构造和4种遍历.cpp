#include <stdio.h>
#include <stdlib.h>
#include "/Users/bigllxx/code/c/2、栈和队列/4、链队列的构造和CRUD.cpp"

#define ElemType int

typedef struct BiTNode  // 二叉树 链式存储
{
  int data;
  struct BiTNode *lchild, *rchild;  // 左右指针，分别指向左右孩子
} BiTNode, *BiTree;

bool InitBitNode(BiTree &B){  // 初始化
  B = (BiTNode *) malloc(sizeof(BiTNode));
  if(B==NULL) return false;
  B->lchild=NULL;
  B->rchild=NULL;
  B->data=NULL;
  return true;
}

bool InsertNode(BiTree &B, ElemType e){  // 插入一个节点
  BiTNode * p = (BiTNode *) malloc(sizeof(BiTNode));
  if(p==NULL) return false;
  p->data=e;
  p->lchild=NULL;
  p->rchild=NULL;
  B->lchild=p;
  return true;
}

void PreOrder(BiTree T){  // 先序遍历  中左右
  if(T !=NULL){
    printf("%d", T->data);  // 先访问根节点
    PreOrder(T->lchild);  // 递归遍历左子树
    PreOrder(T->rchild);  // 递归遍历右子树
  }
}

void InOrder(BiTree T){  // 中序遍历 左中右
    if(T !=NULL){
    PreOrder(T->lchild);
    printf("%d", T->data);
    PreOrder(T->rchild);
  }
}

void PostOrder(BiTree T){  // 后序遍历 左右中
    if(T !=NULL){
    PreOrder(T->lchild);
    PreOrder(T->rchild);
    printf("%d", T->data);
  }
}

/** 
void LevelOrder(BiTree T){  // 层序遍历
  LinkQueue Q;  // 声明并初始化一个队列
  InitQueue(Q);
  BiTree p = T;
  EnQueue(Q, T);  // 将根节点入队
  while(!Empty(Q)){  // 如果队列不为空
    DeQueue(Q, p);  // 将队头节点出队
    printf("%d", p->data);
    if(p->lchild != NULL) EnQueue(Q, p->lchild);
    if(p->rchild != NULL) EnQueue(Q, p->rchild);
  }
}
*/


int main(){
  BiTree root;
  InitBitNode(root);
  return 0;
}