#include<stdio.h>
#include<stdlib.h>

//层次遍历
//需要借助队列
//1、初始将根入队并访问，出队。2、若有左子树，将左子树根入队。3、若有右子树，将右子树根入队
//4、出队，访问出队节点。5、循环2、3、4

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

//构造辅助队列（顺序队列）
typedef struct sqQueue{
    Bitree b[8];
    int front,rear;
}sqQueue;

//队列初始化
void initQueue(sqQueue *s){
    s->front = 0;
    s->rear = 0;
}
//入队
int enQueue(sqQueue *s,Bitree bi){
    if((s->rear+1)%8 == s->front)   //队满
        return 0;
    s->b[s->rear] = bi;
    s->rear = (s->rear+1)%8;
    return 1;
}
//出队
Bitree *deQueue(sqQueue *s){
    Bitree *p;
    if(s->rear == s->front)     //队空
        return NULL;
    p = &(s->b[s->front]);
    s->front = (s->front+1)%8;
    return p;
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

//层次遍历
void levelOrder(Bitree *T){
    sqQueue sq;                
    initQueue(&sq);                     //初始化队列
    Bitree *p;
    enQueue(&sq,*T);                     //根节点进队
    while(sq.rear != sq.front){           //队列不为空
        p = deQueue(&sq);
        printf("[%d]  ",p->data);
        if(p->lchild != NULL)
            enQueue(&sq,*(p->lchild));       //左子树不为空，左子树跟节点进队
        if(p->rchild != NULL)
            enQueue(&sq,*(p->rchild));       //右子树不为空，右子树跟节点进队
    }
}

int main(){
    void initQueue(sqQueue *s);
    int enQueue(sqQueue *s,Bitree bi);
    Bitree *deQueue(sqQueue *s);
    void levelOrder(Bitree *T);
    Bitree *p =  inittree();
    levelOrder(p);


}