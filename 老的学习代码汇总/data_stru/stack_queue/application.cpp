#define MaxSize 10
typedef struct{
    char data[MaxSize];
    int top;
}SqStack;


bool bracketCheck(char str[], int length){
    SqStack S; 
    InitStack(S);  
    for (int i=0; i<length; i++){
        if (str[i]=='(' || str[i]=='[' || str[i]=='{'){
            Push(S, str[i])
        } else {
            if (StackEmptys(S)) return false;
            char topElem;
            Pop(S, topElem);
            if (str[i]==')' && topElem!='(') return false;
            if (str[i]==']' && topElem!='[') return false;
            if (str[i]=='}' && topElem!='{') return false;
        }
    }
}