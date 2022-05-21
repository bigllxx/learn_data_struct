#include <stdio.h>
#include <stdlib.h> 
#include "1、顺序串的构造和CRUD.cpp"

int Index(SString S, SString T){  //朴素模式匹配
  int i=1,j=1;
  while(i<S.length && j<T.length){
    if(S.ch[i]==T.ch[j]){
      ++i;
      ++j;
    }else{
      i=i-j+2;
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
  next[1]=0;
  while(i<T.length){
    if(j==0 || T.ch[i]==T.ch[j]){
      ++i;++j;
      next[i]=j;
    }else{
      j=next[j];
    }
  }
}

int IndexKMP(SString S, SString T){  // KMP算法
  int i=1,j=1;
  int next[T.length+1];
  getNext(T, next);
  while(i<=S.length && j<=T.length){
    if(j==0 || s.ch[i]==T.ch[i]){
      ++i;++j;
    }else{
      j=next[j];
    }
  }
  if(j>T.length) return i-T.length;
  else return 0;
}