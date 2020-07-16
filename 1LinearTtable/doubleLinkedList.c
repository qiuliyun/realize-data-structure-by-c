#include<stdio.h>
#include<stdlib.h>

//双链表定义和基本操作
typedef struct DNode{
    int data;
    struct DNode *prior,*next;
}DNode;

//尾插法建立双链表
DNode *initdoubleList(){
    DNode *L,*s,*r; //r指向尾节点
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    L = (DNode *)malloc(sizeof(DNode));
    L->prior = NULL;
    L->next = NULL;
    r = L;
    for(int i = 0;i < 10;i++){
        s = (DNode *)malloc(sizeof(DNode));
        s->data = a[i];
        r->next = s;
        s->prior = r;
        r = s;
    }
    r->next = NULL;
    return L;

}

//查找第i个元素的值
DNode *getElem(DNode *L,int i){
    if(i < 1)
        return NULL;
    DNode *p = L->next;
    for(int j = 1;p && j < i;j++){
        p = p->next;
    }
    return p;
}

//在第i个位置插入元素值为e
void insert(DNode *L,int i,int e){
    DNode *p = getElem(L,i);    //查找第i个元素的指针
    DNode *s = (DNode *)malloc(sizeof(DNode));  //建立新节点
    s->data = e;
    p->prior->next = s;
    s->prior = p->prior;
    p->prior = s;
    s->next = p;
}

//删除操作,删除第i个元素
void del(DNode *L,int i){
    DNode *p = getElem(L,i);    //查找第i个元素的指针
    p->next->prior = p->prior;
    p->prior->next = p->next;
    free(p);
}

//输出双链表
void printdolist(DNode *L){
    DNode *p = L->next;
    while(p){
        printf("===[%d]===",p->data);
        p = p->next;
    }
    printf("\n");
}

int main(){
    DNode *initdoubleList();
    DNode *getElem(DNode *L,int i);
    void insert(DNode *L,int i,int e);
    void del(DNode *L,int i);
    void printdolist(DNode *L);

    DNode *q = initdoubleList();
    printdolist(q);
    insert(q,4,233);
    printdolist(q);
    del(q,3);
    printdolist(q);
    return 0;
}