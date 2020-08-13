#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#define LIST_SIZE  20
//基于线性表的查找法(顺序查找法、折半查找法、分块查找法)


//数据类型定义
typedef struct{     //每个节点的数据类型
    int key;
    int other;
}RecordType;

typedef struct{     //数据列表
    RecordType r[LIST_SIZE+1];
    int length;
}RecordList;

//初始化
RecordList init(RecordList l){
    for(int i=1;i< LIST_SIZE+1;i++){
        l.r[i].key = i+10;
        l.length++;
    }
    return l;
}

//设置检查哨的顺序查找算法
//平均查找长度：ASL=1/2(n+1)[成功时]，不成功时ASL为n+1
//时间复杂度为O(n)
int seqSearch(RecordList l,int k){
    l.r[0].key = 0;
    int i = l.length;
    while(l.r[i].key != k){
        i--;
    }
    return i;
}


//折半查找法(二分查找法)
//要求：必须是顺序存储，关键字必须按大小有序排列
//ASL=log₂(n+1)-1
//时间复杂度为O(nlog₂n)
int BinSearch(RecordList l,int k){
    int low = 1,high = l.length,mid;    //初始化区间左右
    while(low <= high){
        mid = (low+high)/2;     //取区间中心位置
        if(k == l.r[mid].key)
            return mid;
        else if(k < l.r[mid].key)
            high = mid-1;
        else low = mid+1;
    }
    return 0;

}

int main(){
    RecordList L;
    L = init(L);
    
    for(int i=1;i< LIST_SIZE+1;i++){
        printf("[%d]  ",L.r[i].key);
    }
    printf("\n");
    printf("length:[%d]\n",L.length);

    //printf("查找值是19元素是第[%d]个",seqSearch(L,19));
    printf("查找值是19元素是第[%d]个",BinSearch(L,19));
}

