 #include "1、顺序栈的构造和CRUD.cpp"


bool bracketCheck(char str[], int length){  // 括号匹配
  SqStack S;  
  InitSqStack(S);  // 初始化栈
  for(int i=0; i<length; i++){
    if(str[i]=='(' || str[i]=='[' || str[i]=='{'){
      Push(S, str[i]);  // 如果是左括号，入栈
    }else{
      if(Empty(S)) return false;  // 如果是空栈，返回false
      char topElem;
      Pop(S, topElem);  // 先出栈
      if(str[i]==')' && topElem!='(') return false;  // 如果出栈的括号和和进栈的不对应，返回false
      if(str[i]==']' && topElem!='[') return false;
      if(str[i]=='}' && topElem!='{') return false;
    }
  }
  return Empty(S);  // 匹配结束后栈不空，返回false
}
 
 