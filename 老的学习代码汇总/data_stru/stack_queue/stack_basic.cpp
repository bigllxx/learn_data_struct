# define MaxSize 5
typedef int Elemtype;
// 栈，先进后出
// 定义一个顺序栈
typedef struct{
    Elemtype data[MaxSize];  // 存放栈内元素,data为数组
    int top;  // 栈顶指针，假设data中有5个元素，那么top=4
}SqStack;  // 别名

// 初始化栈
void InitStack(SqStack &st){
    st.top = -1;  // 将栈顶指针指向-1，即完成初始化
}

// 判栈空
bool StackEmpty(SqStack st){
    if(st.top == -1) return true;  // top为-1，则栈空
    else return false;
}

// 进栈
bool Push(SqStack &st, Elemtype x){
    if(st.top == MaxSize-1) return false;  // 栈满 报错
    st.data[++st.top] = x;  //  指针top先自增1，再拿自增后top去赋值
    return true;
}

// 出栈
bool Pop(SqStack &st, Elemtype &x){
    if(st.top == -1) return false; // 栈空 报错
    x = st.data[st.top--];  // 先拿top出栈，top再自减1
    return true;
}

// 读栈顶元素
bool GetTop(SqStack st, Elemtype &x){
    if(st.top == -1) return false; // 栈空 报错
    x = st.data[st.top];
    return true;
}