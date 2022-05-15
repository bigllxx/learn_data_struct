#include <stdio.h>   // 使用printf要这个包
#include <stdlib.h>  // 使用malloc要这个包


#define InitSize 10

typedef struct  // 构造顺序表
{
  int *data;
  int MaxSize;  // 最大长度
  int length;  // 当前长度
} SeqList; // 定义一个顺序表，名为 SeqList，顺序表一般用动态顺序表

void InitList(SeqList &L) // 初始化顺序表，申请储存空间
{
  L.data = (int *)malloc(InitSize * sizeof(int));
  L.length = 0;
  L.MaxSize = InitSize;
}

void IncreaseSize(SeqList L, int len)
{                                                          // 增加顺序表长度
  int *p = L.data;                                         // 将L中的数据拷贝给p
  L.data = (int *)malloc((L.MaxSize + len) * sizeof(int)); // L重新申请新的存储空间
  for (int i = 0; i < L.length; i++)
  {
    L.data[i] = p[i]; // 将p中的数据复制到新的L中
  }
  L.MaxSize = L.MaxSize + len;
  free(p); // 释放p
}

bool ListInsert(SeqList &L, int i, int e)
{ // 根据下标插入数据
  if (i < 0 || i > L.length)
  {
    return false;
  }
  if (L.length >= L.MaxSize)
  {
    return false;
  }
  for (int j = L.length; j > i; j--)
  {
    L.data[j] = L.data[j - 1];
  }
  L.data[i] = e;
  L.length++;
  return true;
}

bool ListDelete(SeqList &L, int i, int &e)
{ // 根据下标删除数据
  if (i < 0 || i >= L.length)
  {
    return false;
  }
  e = L.data[i]; // 将要删除的元素值赋值给e
  for (int j = i; j < L.length - 1; j++)
  {
    L.data[j] = L.data[j + 1];
  }
  L.length--;
  return true;
}

int GetElem(SeqList L, int i)
{ // 按下标查找，返回值
  return L.data[i];
}

int LocateElem(SeqList L, int e)
{ // 按值查找，返回下标
  for (int i = 0; i < L.length; i++)
  {
    if (L.data[i] == e)
    {
      return i;
    }
  }
  return -1;
}

int main()
{
  SeqList L;
  InitList(L);
  ListInsert(L, 0, 0);
  ListInsert(L, 1, 1);
  ListInsert(L, 2, 2);
  ListInsert(L, 3, 3);
  ListInsert(L, 4, 4);
  int e = -1;
  ListDelete(L, 2, e);
  for (int i = 0; i < L.length; i++)
  {
    printf("%d ", L.data[i]);
  }

  return 0;
}
