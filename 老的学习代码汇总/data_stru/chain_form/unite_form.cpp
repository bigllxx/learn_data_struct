#include <iostream>
#include <stdio.h>
#define MaxSize 10
using namespace std;  // std::cout<<"xxx"<< std::endl;  可以去掉std::


// 假设利用两个线性表La和Lb分别标识两个集合A和B，
// 现在求一个新的集合 A = A ∪ B
// 思路：一次取出Lb中的每个元素，在La中查找该元素，如果找不到就插在La后面
// 定义一个SqList，把它当成一种数据类型，它有相应的运算。描述如下：


// 线性表
typedef int ElemType;
typedef struct{
	ElemType *elem;
	int length;
}SqList;

//线性表的长度
int ListLength(SqList L){
	printf("线性表长度为%d\n", L.length);
	return L.length;
}

// 取值，用e返回L中第i个数据元素的值  O(1)
int GetElem(SqList L, int i, ElemType &e){
	return 0;
}

// 顺序表是否存在e元素
int LocateElem(SqList L, ElemType e){
    return 0;
}

// 插入尾部元素
int ListInsert(SqList &L, int i, ElemType e){
	return 0;
}

void unite_from(SqList &La, SqList&Lb){
    ElemType e;
    ElemType La_len = ListLength(La);
    ElemType Lb_len = ListLength(Lb);
    for(int i=1; i<=Lb_len; i++){
        GetElem(Lb, i, e);
        if(!LocateElem(La, e)) ListInsert(La, ++La_len, e);
    }

}



// 有序链表的合并
// 算法步骤、算法描述，复杂度分析
// 1、Lc 指向 La； 2、一次从La 或Lb 中“摘取”元素较小的结点插入到Lc的最后，直至其中一个表变空为止； 
// 3、继续将La或Lb其中一个表的剩余结点插入在Lc的最后；4、释放Lb表的头结点
typedef struct LNode {
    ElemType data;  // 数据域
    struct LNode *next;  // 指针域，指向后继
}LNode, *LinkList;

void MergeList(LinkList &La, LinkList &Lb, LinkList &Lc){
    LinkList pa = La->next; LinkList pb = Lb->next;
    LinkList pc = Lc = La; // 用La的头结点作为Lc的头结点
    while(pa && pb){
        if(pa->data <= pb->data){
            pc->next=pa;
            pc=pa;
            pa=pa->next;
        }else{
            pc->next=pb;
            pc=pb;
            pb=pb->next;
        }
    }
    pc->next=pa?pa:pb; // pa不为空则取pa，pa为空则取pb
    delete Lb;
}