#include<stdio.h>

//队列的顺序存储结构，循环队列
//牺牲队列的一个元素，即入队时少一个单元。使我们能通过头尾指针判断队空和队满

typedef struct{
    int  data[100]; //保存队列的元素
    int front,rear; //队头、队尾指针，对头指针指向队头元素，队尾指针指向队尾元素后一个元素。
}SqQueue;

//队列初始化
void initQueue(SqQueue *S){
    S->front = S->rear = 0;
}

//判空操作
int isEmpty(SqQueue s){
    if(s.front == s.rear)   //队列为空。因有入队限制（少一个入队单元），所以头尾指针相同时，即队空
        return 1;
    else return 0;
}

//入队操作
int EnQueue(SqQueue *Q,int x){
    if((Q->rear+1)%100 == Q->front) //队满，此时rear指针指向最后一个空单元，不能进行入队操作
        return 0;
    Q->data[Q->rear] = x;
    Q->rear = (Q->rear+1)%100;
    return 1;
}

//出队操作
int DeQueue(SqQueue *Q){
    int x;
    if(Q->rear == Q->front) //队空
        return 0;
    x = Q->data[Q->front];
    Q->front = (Q->front+1)%100;
    return x;
}

int main(){
    void initQueue(SqQueue *S);
    int isEmpty(SqQueue s);
    int EnQueue(SqQueue *Q,int x);
    int DeQueue(SqQueue *Q);
    SqQueue q;
    int m,n;
    initQueue(&q);
    n = isEmpty(q);
    if(n == 1)
        printf("队列为空！");
    
    //入队
    EnQueue(&q,10);
    EnQueue(&q,13);
    printf("队尾指针为：%d\n",q.rear);

    //出队
    m = DeQueue(&q);
    printf("出队元素为：%d，队头指针为:%d\n",m,q.front);
    m = DeQueue(&q);
    printf("出队元素为：%d，队头指针为:%d\n",m,q.front);
    return 0;
}