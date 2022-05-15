#include <iostream>
#include <stdio.h>

#define MaxSize 10
using namespace std;  // std::cout<<"xxx"<< std::endl;  可以去掉std::
enum Status{Ok, Error};  // 宏，自定义返回值


typedef int ElemType;
typedef struct{  // 顺序表的存储结构定义 
	ElemType *elem;  // 顺序表占用的数组空间，注意：顺序表是用“数组array”实现的
	int length;  // 手动创建用于记录目前此表的长度，每次CR之后都要手动修改
}SqList;

//初始化当前顺序表，引用
int InitSeqList(SqList &L){ //L 引用类型
	L.elem = new ElemType[MaxSize];  // 申请内存空间
	if(!L.elem){  // 判断是否申请成功
		return Error;
	}
	L.length = 0;  //初始化长度为0
	cout << "引用初始化成功" << endl;
	return Ok;
}

//初始化当前顺序表，指针
int InitList_1(SqList *L){      //L回传给实参，用指针类型
    L->elem = new ElemType[MaxSize];
		if(!L->elem){ //判断是否申请成功
		return Error;
	}
	L->length = 0;  //初始化长度为0
	cout << "指针初始化化成功" << endl;
	return Ok;		   
}

// 给顺序表添加10个值
int AddData(SqList &L){
	if(!L.elem){
		cout<<"线性表不存在"<<endl;
		return Error;
	}
	for(int i=0; i<10; i++){
		L.elem[i] = i;
		L.length ++;
	}
	cout<<"添加数据成功"<<endl;
	return Ok;
}

// 遍历打印顺序表
int PrintSqlist(SqList &L){
	if(!L.elem){
		cout<<"线性表不存在"<<endl;
		return Error;
	}
	printf("线性表遍历结果：");
	for(int i = 0; i<L.length; i++){
		printf("%d", L.elem[i]);
	}
	printf("\n");
	return Ok;
}


//销毁线性表
int DestroySeqList(SqList &L){
	if(!L.elem){
		cout<<"线性表不存在"<<endl;
		return Error;
	}
	free(L.elem);
	L.elem = NULL;
	cout<<"线性表已销毁"<<endl;
	return Ok;
}

//线性表的长度
int ListLength(SqList L){
	printf("线性表长度为%d\n", L.length);
	return L.length;
}

//线性表是否为空
int ListEmpty(SqList L){
	if(L.length == 0){
		cout << "线性表为空" << endl;
		return Ok;  //若为空表，则返回ok,否则返回error
	}
	cout << "线性表不为空" << endl;
	return Error;
}
