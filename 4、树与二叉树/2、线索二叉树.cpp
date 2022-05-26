 #include <stdio.h>
#include <stdlib.h>

#define ElemType int

typedef struct ThreadNode  // 线索二叉树
{
  int data;
  struct ThreadNode *lchild, *rchild;  // 左右指针，分别指向左右孩子
  int ltag, rtag;  // 左右线索，0表示否（指针指向孩子），1表示是（指针指向前驱/后继）
} ThreadNode, *ThreadTree;

ThreadNode * pre = NULL;  // 全局变量，所有方法共享。指向当前遍历的前一个结点

void visit(ThreadTree &q){  // 3、业务代码，q是遍历送过来的节点
  if(q->lchild==NULL){  // 如果q左指针指向NULL
    q->lchild = pre;  // 将q的左指针指向前驱，第一次pre为NULL（因为第一个元素没有前驱）
    q->ltag = 1;  // 更新标志位
  }
  if(pre!=NULL && pre->rchild==NULL){  // 如果pre不等于NULL，且pre的右指针指向NULL
    pre->rchild=q;  // 此时pre就是q的前驱，将pre的右指针指向q
    pre->rtag=1;
  }
  pre=q; // 这里是关键，将pre指向q，即中序遍历的前一个结点（前驱）
}

void InThread(ThreadTree T){  // 2、中序遍历 左中右
  if(T !=NULL){
    InThread(T->lchild);
    visit(T);
    InThread(T->rchild);
  }
}

void PreThread(ThreadTree T){  // 先序遍历  中左右
  if(T !=NULL){
    visit(T); 
    if(T->ltag==0) PreThread(T->lchild);  // 在执行visit(T)后，T本来应该指向NULL的左指针会在线索化之后指向它的前驱 如果不加判断，PreThread(T->lchild)会无限循环
    PreThread(T->rchild); 
  }
}

void PostThread(ThreadTree T){  // 后序遍历 左右中
    if(T !=NULL){
    PostThread(T->lchild);
    PostThread(T->rchild);
    visit(T); 
  }
}


void CreateInThread(ThreadTree T){  // 1、构造中序线索二叉树，入口方法
  pre = NULL;
  if(T != NULL){ 
    InThread(T);  // 中序线索化
    // PreThread(T);  // 先序线索化
    // PostThread(T);  // 后序线索化
    if(pre->rchild == NULL) pre->rtag=1;  // 最后一个节点也要线索化（指向NULL、更新标志位）
  }
}



ThreadTree FirestNode(ThreadNode *p){  // 找到p的最左下的节点（就是中序遍历的第一个节点）
  while(p->ltag==0) p=p->lchild;
  return p;
}

ThreadTree NextNode(ThreadNode *p){  // 找p的后继节点
  if(p->rtag==0) return FirestNode(p->rchild);  // 找到p右子树的最左边节点（就是p的后继节点，好好想想是不是 左中右）
  else return p->rchild;  // 如果右指针有线索，那右指针就指向后继节点
}

void Inorder(ThreadNode *T){  // 中序线索二叉树的遍历（不用递归了）
  for(ThreadNode *p = FirestNode(T); p!=NULL; p=NextNode(p)){  // p等于FirestNode(T)，就是中序遍历的第一个节点；p=NextNode(p)就是p的后继节点
    printf("%d", p->data);
  }
}