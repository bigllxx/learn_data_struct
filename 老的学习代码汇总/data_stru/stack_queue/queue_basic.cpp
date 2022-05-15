// 队列，队尾入，队头出，先进先出
// 栈和队列是一种特殊（运算受限）的线性表
# define MaxSize 100
# include <iostream>
using namespace std;
typedef int QElemType;


// 队列的定义，顺序队
typedef struct{
    QElemType *base;  // 数据域
    int front;  // 头指针
    int rear;  // 尾指针
}SqQueue;

// 循环队列初始化
bool InitQueue(SqQueue &q){
    q.base = new QElemType[MaxSize];  // new一个队列
    if(!q.base) return false;
    q.front = q.rear = 0;  // 空队列
    return true;
}

// 求长度
int QueueLength(SqQueue q){
    return (q.rear - q.front + MaxSize) % MaxSize;
}

// 入队
bool EnQueue(SqQueue &q, QElemType e){
    if( (q.rear+1) % MaxSize == q.front ) return false;
    q.base[q.rear] = e;
    q.rear = (q.rear+1) % MaxSize;
    return true;
}

// 出队
bool DeQueue(SqQueue &q, QElemType e){
    if( q.rear == q.front) return false;
    e = q.base[q.front];
    q.rear = (q.front+1) % MaxSize;
    return true;
}

// 队列的定义 单链
typedef struct LinkNode{
    int data;
    LinkNode *front, *rear;
}LinkQueue