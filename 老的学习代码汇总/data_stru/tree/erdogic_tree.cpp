// 树  链式存储
typedef struct BiTNode{
    char data; // 数据域
    struct BiTNode *lchild, *rchild;  // 左右孩子指针
}BiTNode, *BiTree;


//  队列 链式存储
typedef struct LinkNode{
    BiTNode *data;
    struct LinkNode *next;
}LinkNode;
typedef struct{
    LinkNode *front, *rear;  // 指针
}LinkQueue;

// 初始化一个辅助队列 -> 根结点入队 -> 若对列为空，则头节点出队，访问该节点，并将其左右孩子插入队尾 -> 重复 -> 直至对列为空
void LevelOrder(BiTree T){
    LinkQueue Q;
    InitQueue(Q);
    BiTree p;
    EnQueue(Q, T);
    while (!IsEmpty(Q))
    {
        DeQueue(Q, p);
        visit(p);
        if (p->lchild != NULL) EnQueue(Q, p->lchild);
        if (p->rchild != NULL) EnQueue(Q, p->rchild);
    }
    
}