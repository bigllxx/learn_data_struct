// 双向链表

#include <iostream>
#include <stdio.h>
typedef int ElemType;
enum Status{Ok, Error};
using namespace std;

// 定义
typedef struct DuLNode{
    ElemType data;  // 数据域
    struct DuLNode *prior;  // 指针，指向 前驱
    struct DuLNode *next;  // 指针，指向 后继
}DuLNode, *DuLinkList;

// 插入，插在i-1后面
Status ListInsert(DuLinkList &L, int i, ElemType e){
    // 拿到第i-1个结点的内存地址p
    DuLinkList p = L; int j = 0;                  // 假设链表长度为10，i=4
    while(p && j<i-1){  // 寻找第i-1个结点          // j=0,p=p0(头结点); 0<3,j=1,p=p1; 1<3,j=2,p=p2; 2<3,j=3,p=p3; 3!<3, j=3,p=p3;
        p = p->next;
        j++;
    }
    if(!p || j>i-1) return Error;  // i大于表长时，p为null；i小于1时，j>i-1;  都是越界

    // 插入操作
    DuLinkList s = new DuLNode;  // 新建一个结点s，准备插入到链表中[插在p(i-1)的后面]
    s->data = e;  // 给s赋值
    s->next = p->next;  // s结点的后继指针指向 p结点的后继结点(第i个结点）
    p->next->prior = s;  // p结点的后继结点(第i个结点)的前驱指针 指向s结点
    p->next = s;  //p结点的后继指针指向s结点
    s->prior = p;  // s结点的前驱指针指向p结点
    return Ok;
}

// 删除
Status ListDelete_Dul(DuLinkList &L, int i,ElemType &e){
    // 拿到第i个结点的内存地址p
    DuLinkList p = L; int j =0;
    while(p && j<i){  // 寻找第i个结点
        p = p->next;
        j++;
    }
    if(!p || j>i) return Error;

    e = p->data;  // 将p的数据域给e
    p->prior->next = p->next;  // p上一个结点的后继指针 指向p的下一个结点    这里有个问题：p如果是链表的最后一个元素，是否会报错
    p->next->prior = p->prior;  // p下一个结点的前驱指针 指向p的上一个结点
    delete p;  // 释放p结点的内容空间
    return Ok;
}

// p08