#include <stdio.h>
#include <stdlib.h> 
#define MaxSize 10

typedef struct{  // 构造一个顺序栈
  int data[MaxSize];
  int top;
}SqStack;

void InitSqStack(SqStack &S){  // 初始化
  S.top = -1;
}

bool Empty(SqStack S){  // 判空
 if(S.top == -1) return true;
 return false;
}

bool Push(SqStack &S, int x){  // 进栈
  if(S.top == MaxSize - 1) return false;
  // S.top = S.top + 1;
  // S.data[S.top] = x;
  S.data[++S.top] = x;
  return true;
}

bool Pull(SqStack &S, int &x){  // 出栈
  if(S.top == -1) return false;
  // x = S.data[S.top];
  // S.top = S.top -1;
  x = S.data[S.top--];
  return true;
}

bool GetTop(SqStack &S, int &x){ // 读栈顶元素
  if(S.top == -1) return false;
  x = S.data[S.top];
  return true;
}

int main(){
  SqStack S;  // 声明一个顺序栈，同时开辟内存空间（因为是静态顺序表，所以声明时就开辟了内存空间）
}