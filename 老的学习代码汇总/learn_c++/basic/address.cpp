# include <iostream>
using namespace std;

int main(){
    int var = 3;
    cout << &var << '\n';  // 输出 var 的内容地址

    int *p;  // 声明一个指针类型的变量，int是该指针指向的数据类型
    p = &var;  // 将 var 的内容地址传给p
    cout << *p << '\n';  // 输出 var 的值，相当于 *&var

    *p = 5;  // 将 var 内容地址指向的值，改为 5 
    cout << var;

    return 0;
}