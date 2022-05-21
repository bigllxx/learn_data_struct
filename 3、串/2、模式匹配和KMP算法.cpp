#include <stdio.h>
#include <stdlib.h> 
#include "1、顺序串的构造和CRUD.cpp"

int Index(SString S, SString T){  //朴素模式匹配
  int i=1,j=1;
  while(i<=S.length && j<=T.length){
    if(S.ch[i]==T.ch[j]){
      ++i;
      ++j;
    }else{
      i=i-j+2;  // 让i指向S数组的下一个位置，这里不理解的话，可以自动定义一个新的变量t，指向S的下一个位置
      j=1;
    }
  }
  if(j>T.length){
    return i-T.length;  // 匹配成功
  }else{
    return 0;  // 匹配失败
  }
}

void getNext(SString T, int next[]){  // 求next数组
  int i=1,j=0;
  next[1]=0;  // 这里的next数组从1开始，0不存数据
  while(i<T.length){
    if(j==0 || T.ch[i]==T.ch[j]){  // 0 ，1 ， 
      ++i;++j;
      next[i]=j;
    }else{
      j=next[j];
    }
  }
}

int IndexKMP(SString S, SString T){  // KMP算法
  int i=1,j=1,n=T.length+1;
  int next[n];
  getNext(T, next);
  while(i<=S.length && j<=T.length){
    if(j==0 || S.ch[i]==T.ch[i]){
      ++i;++j;
    }else{
      j=next[j];
    }
  }
  if(j>T.length) return i-T.length;
  else return 0;
}