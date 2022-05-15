// 为了克服顺序表：1、插入、删除元素[O(n)]时需要移动大量元素；2、浪费存储空间；3、静态存储，数据元素无法自由扩充
// 引入：链表
// 特点：结点在逻辑上相邻，在物理上不一定相邻；由数据(存放数值)和指针(存放后继节点的内存地址)构成
// 结点：数据元素的存储映像。由数据域和指针域组成，对应“记录”
// 分类：单链表(一个指针)、双链表(两个指针)、循环链表（一个指针且最后一个结点的指针指向第一个结点)、循环双链表（两个指针且最后一个结点的指针指向第一个结点)
// 有头节点：头指针指向头节点，头节点后指针指向第一个节点，链表为空时 头节点后的指针为空。头节点可存放线性表长度等附加信息，不计入链表长度；
// 无头节点：头指针直接指向第一个节点，链表为空时，头指针为空；
// 定义链表变量时，内存只记录变量名和头指针，所以访问链表必须从头指针进入，并依次往后查找，称之为顺序存储（顺序访问）
// 顺序表知道数据类型，知道该数据类型所占用的内容空间，即可以计算出第i个元素的内存地址，直接从该内容地址拿数据就好了，称为随机存储
// 链表是随机存放，各个元素的内容地址不能通过计算得出，只能依次通过一个一个元素指针来查找，称为顺序存储

#include <iostream>
#include <stdio.h>
#define MaxSize 10
using namespace std;  // std::cout<<"xxx"<< std::endl;  可以去掉std::
enum Status{Ok, Error};  // 宏，自定义返回值
typedef int ElemType;

typedef struct LNode{
    ElemType data;  // 数据域
    struct LNode *next;  // 指针域，指向后继
}LNode, *LinkList;  // 定义一个变量p：LinkList p       那么： p 表示结点地址，*p 表示结点内容值 
// 若p->data = a1 ， 则 p->next->data = a2 
// 初始化、取值、查找、插入、删除

// 初始化：构造一个空链表。步骤：1、生成新结点作为头结点；2、用头指针L指向头节点；3、头结点的指针域置空
Status InitList_L(LinkList &L){
    L = new LNode;  // 申请一个结点L
    L->next = NULL;  // 将结点L 的指针域置为空
    return Ok;
}

// 销毁链表，头结点也销毁
Status DestroyList_L(LinkList &L){
    LinkList p;
    while (L){  // 相当于 L != NULL
        p = L;  // L 是传过来的引用类型实参（链表），同时也是链表的第一个结点路径
        L = L->next;
        delete p;
    }
    return Ok;
}

// 请空链表，头结点还在
Status ClearList(LinkList &L){
    LinkList p,q;
    p = L->next;  // p 指向第一个结点
    while (p){
        q = p->next;
        delete p;
        p = q;
    }
    L->next = NULL;  // 头结点指针域为空
    return Ok;  
}

// 求表长 从第1个元素开始数，数到最后一个指针域为空的结点
int ListLength_L(LinkList L){
    LinkList p;
    p = L->next;
    int i = 0;
    while(p){  // p 不为空，i自增1，p再指向下一个结点；p 为空，结束循环
        i++;
        p = p->next;
    }
    return i;
}

// 判断是否是空表
Status ListEmpty(LinkList L){
    if(L->next) return Ok;
    else return Error;
}

// 取值，根据位置获取数值。从链表的头指针开始，顺着链域next逐个结点往下搜索，直到搜索到第i个元素，return
Status GetElem_L(LinkList L, int i, ElemType &e){
    LinkList p = L->next; 
    int j = 1;
    while(p && j<i){
        p = p->next;
        j++;
    }
    if(!p || j>i) return Error;
    e = p->data;
    return Ok;
}

// 查找，根据数值获取内存地址。
LNode *locateElem_L(LinkList L, ElemType e){
    LinkList p = L->next;
    while(p && p->data !=e) p = p->next;
    return p;
}

// 查找，根据数值返回位置序号
int LocateElem_L(LinkList L, ElemType e){
    LinkList p = L->next;
    int j = 1;
    while(p && p->data != e){
        p = p->next;
        j++;
    }
    if(p) return j;
    else return Error;
}

// 插入（插在第i-1后面）； 将值为x的新节点插入到列表的第i个结点的位置上，即插在i-1 和i 之间
Status ListInsert_L(LinkList &L, int i, ElemType e){  // 链表头结点内存地址，要插入的位置序号，要插入的值
    LinkList p = L; int j = 0;
    while(p && j<i-1){  // 寻找第i-1个结点
        p = p->next;
        j++;
    }
    if(!p || j>i-1) return Error;  // i大于表长时，p为null；i小于1时，j>i-1; 
    LinkList s= new LNode;  // 生成新的结点s
    s->data = e;  // 将结点s的数据域置为e（给s赋值）
    s->next = p->next;  // 将结点s插入L中，指向p指向的结点
    p->next = s;  // 再将p 指向s
    return Ok;
}

// 删除，删除第i个结点
Status ListDelete_L(LinkList &L, int i, ElemType &e){
    LinkList p = L; int j = 0;
    while (p->next && j<i-1){  //寻找第i个结点，p指向其前驱
        p = p->next;
        j++;
    }
    if(!(p->next) || j>i-1) return Error;  // 删除位置不合理
    LinkList q = p->next;  // 临时保存将要删除的绩点
    p->next = q->next;  // 改变被删除结点前驱的指针域（指向被删除结点的后一个结点），相当于p->next = p->next->next，那原先的q=p->next就被跨过去了
    e = q->data;  // 保存删除结点的数据域
    delete q;  // 释放删除结点的空间
    return Ok;
}

// 07
// 单链表的创建（前插法/栈式）
// 新建一个空表开始，重复读入数据； 将读入的数据存放到新节点的数据域中； 将该新节点插入到链表的前端
void CreateList_F(LinkList &L, int n){
    L = new LNode; L->next = NULL;  // 建立一个带头结点的单链表，并初始化
    for(int i=n; i>0; --i){  
        LinkList p = new LNode;  // 生成新结点
        cin >> p->data;  // 输入元素值
        p->next = L->next;  // 插入到表头
        L->next = p;
    }
}

// 尾插法
void CreateList_L(LinkList &L, int n){
    L = new LNode; L->next = NULL;  // 建立一个带头结点的单链表，并初始化
    LinkList r = L;  // 定义r，使r指向的内存地址和L一致，这时L、r都是该链表的头结点，也是尾结点（因为现在只有这一个结点）
    for(int i=0; i<n; ++i){
        LinkList p = new LNode;  // 新建一个结点p
        cin >> p->data;  // 给结点p的数据域赋值
        p->next = NULL; // 初始化p，使p的指针域指向null
        r->next = p;  // r的指针指向p，这样p就称为了L链表的尾结点
        r = p;  // 使也r成为L的尾结点，使上条语句逻辑正确
    }
}