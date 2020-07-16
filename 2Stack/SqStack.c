#include<stdio.h>

//顺序栈
#define MaxSize 100

typedef struct {
    int data[MaxSize];  //存放数据
    int top;    //栈顶指针
}SqStack;

//初始化
void initStack(SqStack *S){
    S->top = -1;
}

//判断空
int  StackEmpty(SqStack s){
    if(s.top == -1){
        return 0;
    }else return 1;
}

//进栈
int push(SqStack *S,int i){
    if(S->top == MaxSize-1) //判断栈是否满
        return 0;
    S->data[++S->top] = i;  //栈顶指针先加一，再进栈
    return 1;
}

//出栈,返回出栈元素
int pop(SqStack *S){
    int x;
    if(S->top == -1)    //判断栈是否为空
        return 0;
    x = S->data[S->top--];  //先出栈，栈顶指针再减一
    return x;
}

//读取栈顶元素,返回读取的值
int gettop(SqStack S){
    return S.data[S.top];
}

int main(){
    return 0;
}