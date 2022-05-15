#include "sequence_form_base.cpp"  // 导包
#include <iostream>
using namespace std;

// 如果if else while for 这些判断或循环语句后面的执行语句只有一条，就可以省略大括号。

// 取值，用e返回L中第i个数据元素的值  O(1)
int GetElem(SqList L, int i, ElemType &e){
	if(i > L.length || i < 1) return Error;
	e = L.elem[i-1];
	printf("第%d个值为：%d\n", i, e);
	return Ok;
}

// 查找，查找线性表中值为e的元素的位置 O(n)
int LocateElem(SqList L, ElemType e){
    for(int i=0; i<L.length; i++) 
        if(L.elem[i]==e) return i+1;
    return Error;
}

// 插入，将元素 e 插在第 i 个节点之前 O(n)
int SeqListInsert(SqList &L, int i, ElemType e){
	if((i < 1) || (i > L.length + 1)) return Error;  // i位置不合法
	if(L.length == MaxSize) return Error;  // 顺序表已满
		
	// 将位置i及后面的元素向后移一位
	for(int j=L.length-1; j>=i-1; j--) 
        L.elem[j+1] = L.elem[j];

	L.elem[i-1] = e;  // 元素放在i位置
	L.length++;  // 顺序表长度+1
	return Ok;
}

// 删除，删除第 i 个节点 O(n)
int SeqListDelete(SqList &L, int i){
	if(i<1||i>L.length){  // i位置不合法
		return Error;
	}
	for(int j=i; j<L.length; j++){  // i后的元素向前移动一位
		L.elem[j-1] = L.elem[j];
	}
	L.length--;  // 顺序表长度+1
	return Ok;
}