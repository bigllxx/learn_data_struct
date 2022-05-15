// 串 数组 广义表
// 串：由零个或多个字符组成的有限序列
// 串的基本操作：赋值StrAssign、比较StrCompare、求长StrLength、字串StrString、拼接Concat  （这五个是基本）
//             连结Concat、定位Index、清空ClearString、销毁DestroyString、复制StrCopy、判空StrEmpty


# include <iostream>
# define MaxSize 100
using namespace std;

// 定义串
typedef struct{
    char *ch;  // 数据域
    int length;  // 实际长度
}SString;

//  初始化，new对象
bool InitSString(SString &S){ //L 引用类型
	S.ch = new char[MaxSize];  // 申请内存空间
	if(!S.ch){  // 判断是否申请成功
		return false;
	}
	S.length = 0;  //初始化长度为0
	cout << "引用初始化成功" << endl;
	return true;
}

// 模式匹配 BF算法 回溯算法 暴力但复杂 O(nm)，nm分别为主串和字串的长度
int Index_BF(SString S, SString T){
    int i = i, j=1;

    while(i<=S.length && j<=T.length){  
        if(S.ch[i]==T.ch[j]){
            ++i;
            ++j;
        }else{
            i=i-j+2;  // i和j同增，相当于不管i、j怎么变，在一次循环中，i(1)-j(1) = ... = i(n)-j(n) 是一个常数,
            j=1;      // 又因为 i(1)=i,j(1)=1, 那么i-j+1=i，i-j+2=i+1
        }
        if(j>T.length) return i-T.length;  // 返回字串在主串的位置 
        else return 0;
    }
    return 0;
}


// KMP算法，对BF算法的改进 最长前后缀 
// 求next数组
void get_next(SString T, int next[]){
    int j=1; int t=0; next[1]=0;

    while(j<T.length){
        if(t==0 || T.ch[j]==T.ch[t]){
            ++j; ++t;
            next[j]=t;
        }
        else
            t = next[t];
    }
}

// 入口
int Index_KMP(SString S, SString T, int next[]){  // 模式串的0位不存值
    int i = 1, j=1;

    while(i<=S.length && j<=T.length){
        if(j==0 || S.ch[i]==T.ch[j]){
            ++i; ++j;
        }else
            j=next[j];
    }

    if(j>T.length)
        return i-T.length;
    else 
        return 0;
}