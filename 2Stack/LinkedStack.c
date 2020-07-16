#include<stdio.h>
#include<stdlib.h>

//链栈的定义和基本操作，只能在链表头进行插入删除操作
typedef struct LinkedStack{
    int data;
    struct LinkedStack *next;
}LinkedStack;

//初始化
LinkedStack *init(){
    LinkedStack *L;
    return L;
}

//判断空
int Empty(LinkedStack *L){
    if(L == NULL)
        return 0;
    else return 1;
}

//进栈
void push(LinkedStack *L,int x){
    LinkedStack *p = (LinkedStack *)malloc(sizeof(LinkedStack));    //创造一个节点，存储x
    p->data = x;
    p->next = NULL;     //给节点赋值
    if(!L){
        L = p;
    }else{
        p->next = L;
        L = p;      //头插法插入节点
    }   
}

//出栈
int pop(LinkedStack *L){
    LinkedStack *q;
    int x;
    if(!L)
        return 0;
    q = L;
    L = q->next;
    x = q->data;
    free(q);
    return x;
}

//返回栈顶元素
int gettop(LinkedStack *L){
    return L->data;
}