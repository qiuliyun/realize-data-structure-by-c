#include<stdio.h>
#include<stdlib.h>

//顺序表定义和基本操作
#define MaxSize 50

//定义顺序表数据结构（静态数组）
typedef struct{
    int data[MaxSize];
    int length;
}Sqllist;

// typedef struct{
//     int *data;
//     int length;
// }Sqllist;

//初始化表（静态数组）
void InitList(Sqllist *L){
    L->length = 10;
    for(int i = 0;i < 10;i++){
        L->data[i] = i;
    }
    
}

//初始化表（动态数组）
// void InitList2(Sqllist *L){
//     L->length = 10;
//     L->data =(int *)malloc(sizeof(int)*10);
//     for(int i = 0;i < L->length;i++){
//         L->data[i] = i;
//     }
// }

//求表长
int length(Sqllist L){
    return L.length;
}

//按值查找操作，返回值e所在的位置序号
int locateElem(Sqllist L,int e){
    for(int i = 0;i<L.length;i++){
        if(L.data[i] == e){
            i++;
            return i;
        }
    }
}

//按位查找操作，返回第n位的值
int getElem(Sqllist L,int n){
    return L.data[n-1];
}

//插入操作,在第i个位置上插入e
int  ListInsert(Sqllist *L,int i,int e){
    if(i < 1 || i > L->length+1)
        return 0;
    if(L->length >= MaxSize)
        return 0;
    for(int j = L->length;j >= i;j--){
        L->data[j] = L->data[j-1];
    }
    L->data[i-1] = e;
    L->length++;
    return 1;
}

//删除第i个元素，并返回删除的元素的值
int ListDel(Sqllist *L,int i){
    if(i < 1 || i > L-> length)
        return 0;
    int e =L->data[i-1];
    for(int j = i;j < L->length;j++){
        L->data[j-1] = L->data[j];
    }
    L->length--;
    return e;
}

void print(Sqllist L){
    for(int i = 0;i < L.length;i++){
        printf("data[%d]=%d***",i,L.data[i]);
    }
    printf("\nlong=%d",L.length);
}

int main(){
    void InitList(Sqllist *);
    int length(Sqllist);
    int locateElem(Sqllist,int);
    int getElem(Sqllist,int);
    int ListInsert(Sqllist *,int,int);
    int ListDel(Sqllist *,int);
    void print(Sqllist);

    Sqllist l;
    int x;

    //初始化(动态数组)
    InitList(&l);

    //求表长
    //x=length(l);
    //printf("long=%d",x);

    //查询元素在第几个位置
    //x=locateElem(l,5);
    //printf("~5:%d\n",x);

    //查询第几个位置的值
    //x=getElem(l,7);
    //printf("~data[6]:%d\n",x);

    //在第i个位置插入e
    //ListInsert(&l,7,23);

    //删除第i个元素
    //x=ListDel(&l,4);
    //printf("del:%d",x);
    print(l);
    return 0;
}

