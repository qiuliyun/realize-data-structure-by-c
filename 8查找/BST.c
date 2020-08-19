#include<stdio.h>
#include<stdlib.h>

//二叉排序树创建与查找

//二叉排序树查找：
//①最好情况，即平衡二叉树。ASL=log₂n
//②最坏情况，即由有序表创建的二叉排序树，是一颗单叉树（单链表），ASL=(n+1)/2

//数据类型定义
typedef struct Node{
    int k;
    struct Node *lchild,*rchild;
}BSTNode,*BSTree;

//二叉排序树插入节点递归算法
void insertBst(BSTree *bst,int k){          //bst是指针的指针,因为算法改变的是指针的值，且没有返回值，只能通过指针的指针改变
    BSTree s;       //新节点
    if(*bst == NULL){                       //当前节点指针为空，构建新的节点作为新节点
        s = (BSTree)malloc(sizeof(BSTNode));
        s->k = k;
        s->lchild = NULL;
        s->rchild = NULL;
        *bst = s;
    }else if(k < (*bst)->k){                //k的值小于当前节点的k，则递归调用函数，指针指向当前节点左孩子
        insertBst(&(*bst)->lchild,k);
    }else if(k > (*bst)->k){                //k的值大于当前节点的k，则递归调用函数，指针指向当前节点右孩子
        insertBst(&(*bst)->rchild,k);
    }

}
//创建二叉排序树。时间复杂度为0(nlog₂n)，每个节点插入时间复杂度为0(log₂n)
void createBSTree(BSTree *bst){
    int k[10] = {1,4,2,6,7,12,5,3,33,9};
    *bst = NULL;                            //置空跟节点指针
    int i = 0;
    while(i<10){
        insertBst(bst,k[i++]);
    }
}

//二叉排序树中序遍历（递归），创建时输入序列不同，则构造出的二叉树不同，但中序遍历相同，都是从小到大的顺序排列
void preorder(BSTree bst){
    if(bst){
        preorder(bst->lchild);
        printf("[%d]  ",bst->k);
        preorder(bst->rchild);
    }
}


//二叉排序树查找（递归）
BSTree search1(BSTree bst,int k){           //查找k所在节点
    if(!bst)
        return NULL;
    else if(k == bst->k)                    //k正好是当前节点的值，则返回当前节点
        return bst;
    else if(k < bst->k)
        return search1(bst->lchild,k);     //k小于当前节点的值，递归比较当前节点左孩子的值
    else 
        return search1(bst->rchild,k);
}

//二叉排序树查找（非递归）
BSTree search2(BSTree bst,int k){
    BSTree q = bst;
    while(q){
        if(k == q->k)
            return q;
        else if(k < q->k)
            q = q->lchild;
        else q = q->rchild;
    }
    return NULL;                        //查找失败
}


int main(){
    BSTree b;
    createBSTree(&b);
    preorder(b);
    printf("\n[%d]\n",search1(b,12)->k);
    return 0;
}




