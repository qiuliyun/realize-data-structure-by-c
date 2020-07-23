#include<stdio.h>
#include<stdlib.h>

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

//先序遍历
//若二叉树为空，什么也不做，否则。1、访问跟节点，2、先序遍历左子树，3、先序遍历右子树
void preOrder(Bitree *T){
    if(T != NULL){
        printf("[%d]  ",T->data);
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
}

//中序遍历
//若二叉树为空，什么也不做，否则。1、中序遍历左子树，2、访问跟节点，3、中序遍历右子树
void inOrder(Bitree *T){
    if(T != NULL){
        inOrder(T->lchild);
        printf("[%d]  ",T->data);
        inOrder(T->rchild);
    }
    
}

//后序遍历
//若二叉树为空，什么也不做，否则。1、后序遍历左子树，2、后序遍历右子树，3、访问跟节点
void postOrder(Bitree *T){
    if(T != NULL){
        postOrder(T->lchild);
        postOrder(T->rchild);
        printf("[%d]  ",T->data);
    }
}


int main(){
    Bitree *p =inittree();
    //preOrder(p);
    //inOrder(p);
    postOrder(p);
    return 0;
}
