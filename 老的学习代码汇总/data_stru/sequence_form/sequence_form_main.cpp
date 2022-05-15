#include "sequence_form_operate.cpp"  // 导包
#include <iostream>
using namespace std;

int main(){
    SqList L;
    int e;
    InitSeqList(L);
    AddData(L);
    PrintSqlist(L);
    ListEmpty(L);
    ListLength(L);
    GetElem(L, 3, e);
    DestroySeqList(L); // 销毁
}

// p5