#include<stdio.h>
#include<stdlib.h>

//中序线索二叉树，即利用二叉树的节点，在二叉树节点指向左孩子指针为空时，左指针指向二叉树中序遍历时该节点的前驱节点
//在二叉树节点指向右孩子指针为空时，右指针指向二叉树中序遍历时该节点的后继节点

//二叉树的遍历
//构造二叉树如下：
//                         [5]
//                     /        \
//                  [2]           [3]
//                 /   \         /   \
//              [7]    [8]     [9]    [4]
//              /
//            [1]

//构建线索二叉树节点
typedef struct threadTree{
    int data;      //数据域
    struct threadTree *lchild,*rchild;    //左孩子、右孩子节点
    int ltag;       //ltag为0，则该节点的*lchild指针指向节点左孩子。ltag为1，则该节点的*lchild指向节点的前驱
    int rtag;       //ltag为0，则该节点的*rchild指针指向节点右孩子。ltag为1，则该节点的*lchild指向节点的后继
}threadTree;

//构造此二叉树
 threadTree *inittree(){
    threadTree *p = (threadTree *)malloc(sizeof(threadTree));
    p->data = 5;    //构造跟节点
    p->lchild = (threadTree *)malloc(sizeof(threadTree));
    p->lchild->data = 2;
    p->rchild = (threadTree *)malloc(sizeof(threadTree));
    p->rchild->data = 3;
    p->lchild->lchild = (threadTree *)malloc(sizeof(threadTree));
    p->lchild->lchild->data = 7;
    p->lchild->lchild->rchild = NULL;
    p->lchild->rchild = (threadTree *)malloc(sizeof(threadTree));;
    p->lchild->rchild->data = 8;
    p->lchild->rchild->lchild = NULL;
    p->lchild->rchild->rchild = NULL;
    p->lchild->lchild->lchild = (threadTree *)malloc(sizeof(threadTree));
    p->lchild->lchild->lchild->data = 1;
    p->lchild->lchild->lchild->lchild = NULL;
    p->lchild->lchild->lchild->rchild = NULL;
    p->rchild->lchild = (threadTree *)malloc(sizeof(threadTree));
    p->rchild->lchild->data = 9;
    p->rchild->lchild->lchild = NULL;
    p->rchild->lchild->rchild = NULL;
    p->rchild->rchild = (threadTree *)malloc(sizeof(threadTree));
    p->rchild->rchild->data = 4;
    p->rchild->rchild->lchild = NULL;
    p->rchild->rchild->rchild = NULL;
    return p;
 }

 //中序遍历二叉树，赋值二叉树的所有ltag和rtag为0
 void inorder(threadTree *T){
     if(T!=NULL){
         inorder(T->lchild);
         printf("[%d]  ",T->data);
         T->ltag = 0;
         T->rtag = 0;
         inorder(T->rchild);
     }
 }

 //中序遍历对二叉树线索数化
 threadTree  *InThread(threadTree *p,threadTree *pre){      //pre指向刚访问过的节点，初始为NULL
     if(p){
         pre = InThread(p->lchild,pre);   //递归线索化左子树
         if(p->lchild == NULL){     //如果左子树为空
             p->lchild = pre;
             p->ltag = 1;               //左指针域作为前驱线索
         }
         if(pre!=NULL && pre->rchild == NULL){      //pre的右指针域为空，则右指针域作为后继线索
             pre->rchild = p;
             pre->rtag =1;
         }
         pre = p;           //把刚访问过的p赋值给pre
         pre = InThread(p->rchild,pre);       //递归线索化右子树
     }
     return pre;
 }

 //通过中序遍历建立中序线索二叉树
 void createInThreadTree(threadTree *p){
     threadTree *pre = NULL;
     if(p){
         pre = InThread(p,pre);
         pre->rchild = NULL;
         pre->rtag = 1;
     }
 }

 //中序线索二叉树遍历

 //求中序线索二叉树中序序列的第一个节点
 threadTree *First(threadTree *p){
     while(p->ltag == 0)    //当前节点有左孩子，则一直向左孩子走
        p = p->lchild;
    return p;
 }

 //求中序线索二叉树中节点p在中序序列下的后继
 threadTree *NextNode(threadTree *p){
     if(p->rtag == 0)           //rtag为1表示的是p节点的rchild指针域指向的是它的右孩子节点
        return First(p->rchild);            //返回p的右子树的中序序列的第一个节点
    else return p->rchild;          //rtag为1，则p无右孩子，rchild指针域存储的是后继线索，指向它的后继节点
 }

 //遍历算法
 void InOrder(threadTree *T){
     for(threadTree *p=First(T);p!=NULL;p=NextNode(p))
        printf("[%d]  ",p->data);
 }

 int main(){
     threadTree *T = inittree();
    inorder(T);
    createInThreadTree(T);
    printf("\n");
    InOrder(T);
     return 0;
 }