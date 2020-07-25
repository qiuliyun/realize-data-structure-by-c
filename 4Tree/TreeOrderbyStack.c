#include<stdio.h>
#include<stdlib.h>

//递归算法与非递归算法的转换
//即借助栈实现遍历，而不是递归

//二叉树的遍历
//构造二叉树如下：
//                         [5]
//                     /        \
//                  [2]           [3]
//                 /   \         /   \
//              [7]    [8]     [9]    [4]
//              /
//            [1]

//构建二叉树节点
typedef struct Bitree{
    int data;      //数据域
    struct Bitree *lchild,*rchild;    //左孩子、右孩子节点
}Bitree;

//顺序栈
typedef struct sqStack{
    Bitree b[8];
    int top;
}sqStack;

//初始化栈
void initStack(sqStack *s){
    s->top = -1;
}
//入栈
int push(sqStack *s,Bitree b){
    if(s->top == 7)
        return 0;
    s->b[++(s->top)] = b;
    return 1;
}
//出栈
Bitree *pop(sqStack *s){
    Bitree *bi;
    if(s->top == -1)
        return 0;
    bi = &(s->b[(s->top)--]);
    return bi;
}

// //构造此二叉树
 Bitree *inittree(){
    Bitree *p = (Bitree *)malloc(sizeof(Bitree));
    p->data = 5;    //构造跟节点
    p->lchild = (Bitree *)malloc(sizeof(Bitree));
    p->lchild->data = 2;
    p->rchild = (Bitree *)malloc(sizeof(Bitree));
    p->rchild->data = 3;
    p->lchild->lchild = (Bitree *)malloc(sizeof(Bitree));
    p->lchild->lchild->data = 7;
    p->lchild->lchild->rchild = NULL;
    p->lchild->rchild = (Bitree *)malloc(sizeof(Bitree));;
    p->lchild->rchild->data = 8;
    p->lchild->rchild->lchild = NULL;
    p->lchild->rchild->rchild = NULL;
    p->lchild->lchild->lchild = (Bitree *)malloc(sizeof(Bitree));
    p->lchild->lchild->lchild->data = 1;
    p->lchild->lchild->lchild->lchild = NULL;
    p->lchild->lchild->lchild->rchild = NULL;
    p->rchild->lchild = (Bitree *)malloc(sizeof(Bitree));
    p->rchild->lchild->data = 9;
    p->rchild->lchild->lchild = NULL;
    p->rchild->lchild->rchild = NULL;
    p->rchild->rchild = (Bitree *)malloc(sizeof(Bitree));
    p->rchild->rchild->data = 4;
    p->rchild->rchild->lchild = NULL;
    p->rchild->rchild->rchild = NULL;
     return p;
 }

 //中序遍历非递归算法
 //1、初始依次扫描跟节点的所有左侧节点并依次进栈。2、出栈一个节点，并访问
 //3、扫描该节点的右孩子，并将其进栈。4、依次扫描右孩子节点的所有左侧节点并一一进栈。
 //5、反复该过程直至栈空
void inOrder2(Bitree *T){
    Bitree *p = T;
    sqStack s;
    initStack(&s);
    while(p||s.top!=-1){    //栈不空或者树的跟节点不空
        if(p){              //树的跟节点不空
            push(&s,*p);        //入栈
            p = p->lchild;      //向左孩子走
        }else{
            p = pop(&s);        //若p为空则出栈，且p指向出栈节点
            printf("[%d]  ",p->data);       
            p = p->rchild;       //p指向p的右孩子
        }
    }
}

//先序遍历非递归算法
//若根不为空，访问当前根节点，并入栈，然后一直向左孩子走
//若根节点为空，出栈，并转向出栈元素的右孩子
//循环以上过程
void preOrder2(Bitree *T){
    Bitree *p = T;
    sqStack s;
    initStack(&s);
    while(p || s.top != -1){    //栈不空或者当前子树根节点不空
        if(p){
            printf("[%d]  ",p->data);   //访问当前子树根节点
            push(&s,*p);    
            p = p->lchild;  //p进栈，向左孩子走
        }else{
            p = pop(&s);
            p = p->rchild;
        }
        


    }
}

int main(){
    void initStack(sqStack *s);
    int push(sqStack *s,Bitree b);
    Bitree *pop(sqStack *s);
    Bitree *inittree();
    void inOrder2(Bitree *T);

    Bitree *t = inittree();
    preOrder2(t);
    return 0;
}