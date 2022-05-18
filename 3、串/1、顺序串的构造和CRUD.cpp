#include <stdio.h>
#include <stdlib.h> 
#define MAXLEN 255
#define ElemType char

typedef struct{  // 构造一个顺序串
  ElemType ch[MAXLEN];
  int length;
}SString;

bool SubString(SString &Sub, SString S, int pos, int len){  // 求字串，将S中第pos个元素开始，长为len的字串拷贝到Sub中
  if(pos+len-1>S.length) return false;
  for(int i=pos;i<pos+len; i++){
    Sub.ch[i-pos+1] = S.ch[i];
  }
  Sub.length = len;
  return true;
}

int StrCompare(SString S, SString T){  // 比较
  for(int i=1; i<S.length && i<T.length; i++){
    if(S.ch[i] != T.ch[i]) return S.ch[i]-T.ch[i];  // 如果不相等，返回二者之差（Ascii码）
  }
  return S.length-T.length;  // 匹配到最后，二者长度不一致
}

int Index(SString S, SString T){  // 若T是S的字串，返回T在S中的位置
  int i=1, n=S.length, m=T.length;
  SString sub;
  while(i<n-m+1){
    SubString(sub,S,i,m);  // 将主串S中第(i,i+m)个元素复制给sub
    if(StrCompare(sub, T)!=0) ++i;  // 如果sub和T不相等，继续循环
    else return i;  // 如果相等，返回下标i
  }
  return 0;  // 不是字串，返回0
}