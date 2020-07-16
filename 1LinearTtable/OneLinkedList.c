#include<stdio.h>
#include<stdlib.h>

//单链表定义和基本操作
typedef struct LoNode{
    int data;   //数据
    struct LoNode *next;    //指针
}LoNode;

//头插法建立单链表
LoNode *ListHeadInsert(){
    LoNode *s;
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    LoNode *L;
    L = (LoNode *)malloc(sizeof(LoNode));   //创建头结点
    L->next = NULL;
    for(int i = 0;i < 10;i++){
        s = (LoNode *)malloc(sizeof(LoNode));   //s为新开辟节点
        s->data = a[i];
        s->next = L->next;
        L->next = s;
    }
    return L;
}

//尾插法建立单链表
LoNode *ListTailInsert(){
    LoNode *s,*r,*L;    //r为尾指针
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    L = (LoNode *)malloc(sizeof(LoNode));   //创建头结点
    L->next = NULL;
    r = L;
    for(int i=0;i < 10;i++){
        s = (LoNode *)malloc(sizeof(LoNode));
        s->data = a[i];
        r->next = s;
        r = s;
    }
    r->next =NULL;
    return L;

}

//按序号i查找节点值
LoNode *getElem(LoNode *L,int i){
    LoNode *p = L->next;
    if(i < 1)
        return 0;
    for(int j = 1;p && j < i;j++){
        p = p->next;
    }
    return p;
}

//插入节点操作,在第i个位置插入一个值为e的节点
LoNode *oneInsert(LoNode *L,int i,int e){
    LoNode *s = (LoNode *)malloc(sizeof(LoNode));
    s->data = e;
    LoNode *p = getElem(L,i-1); //找到i的前驱节点
    s->next = p->next;
    p->next = s;
    return L;
}

//删除第i个节点
LoNode *del(LoNode *L,int i){
    LoNode *p = getElem(L,i-1); //找到i的前驱节点
    LoNode *q = p->next;
    p->next = p->next->next;
    free(q);    //释放第i个节点
    return L;
}

//输出单链表的值
void printList(LoNode *L){
    LoNode *p = L->next;
    while(p){
        printf("~~~[%d]~~~",p->data);
        p = p->next;
    }
    printf("\n");
}

int main(){
    LoNode *ListHeadInsert();
    LoNode *ListTailInsert();
    LoNode *getElem(LoNode *L,int i);
    LoNode *oneInsert(LoNode *L,int i,int e);
    LoNode *del(LoNode *L,int i);
    void printList(LoNode *L);

    //头插法
    //LoNode *p = ListHeadInsert();

    //尾插法
    LoNode *p = ListTailInsert();
    printList(p);

    //查找第3个值
    LoNode *q = getElem(p,3);
    printf("~~[%d]~~~\n",q->data);

    //在第3个位置插入值为77
    oneInsert(p,3,77);
    printList(p);

    //删除第3个元素
    del(p,3);
    printList(p);

}
