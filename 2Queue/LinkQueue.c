#include<stdio.h>
#include<stdlib.h>

//带头结点的链队

typedef struct LinkNode{    //链队中的节点
    int data;   //存放数据
    struct LinkNode *next;
}LinkNode;

typedef struct LinkQueue{   //队头、队尾指针定义
    LinkNode *front,*rear;  //队头、队尾指针,队头指针指向头结点，队尾指针指向最后一个元素
}LinkQueue;

//初始化
LinkQueue init(){
    LinkQueue q;
    q.front = q.rear = (LinkNode *)malloc(sizeof(LinkNode));    //建立头结点
    q.front->next =NULL;    //头结点的next指针赋值为NULL
    return q;
}

//判空
int isEmpty(LinkQueue q){
    if(q.front == q.rear)
        return 1;
    else return 0;
}

//入队
void Enqueue(LinkQueue *Q,int x){
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode)); //建立新节点存放x
    s->data = x;
    s->next = NULL;
    Q->rear->next = s;      //把x节点入队到队尾指针下一个位置
    Q->rear = s;        //队尾指针设为x节点
}

//出队
int DeQueue(LinkQueue *Q){
    int x;
    if(Q->front == Q->rear)     //队空
        return 0;
    LinkNode *p = Q->front->next;   //p指向第队头节点
    x = p->data;
    Q->front->next = p->next;
    if(p == Q->rear)
        Q->rear = Q->front;     //若p指向的是队尾，则出队后尾指针也指向头结点
    free(p);
    return x;
}

int main(){
    LinkQueue init();
    int isEmpty(LinkQueue q);
    void Enqueue(LinkQueue *Q,int x);
    int DeQueue(LinkQueue *Q);
    int m,n;
    LinkQueue p = init();
    n = isEmpty(p);
    if(n == 1)
        printf("链队为空\n");
    
    //入队【2,4,6,8】
    Enqueue(&p,2);
    Enqueue(&p,4);
    Enqueue(&p,6);
    Enqueue(&p,8);
    printf("入队2,4,6,8，队列尾部是：%d\n",p.rear->data);

    //出队
    for(int i=0;i<4;i++){
        m = DeQueue(&p);
        printf("出队的元素是：%d\n",m);
    }
    printf("队列尾部是：%d\n",p.rear->data);
    return 0;
}

