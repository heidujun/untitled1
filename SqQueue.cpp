//
// Created by hyh25 on 2022/10/4.
//
#include <malloc.h>
#include <stdio.h>
#define MaxSize 30
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int front;//队头位置
    int rear;//队尾位置
}SqQueue;
//初始化队列
static void InitQueue(SqQueue *&q){
    q=(SqQueue *) malloc(sizeof(SqQueue));
    q->front=q->rear=0;
}
//入队
static bool enQueue(SqQueue *&q,ElemType e){
    if((q->rear+1)%MaxSize==q->front)
        return false;
    q->rear=(q->rear+1)%MaxSize;
    q->data[q->rear]=e;
    return true;
}
//出队
static bool pop(SqQueue *&q,ElemType &e){
    if(q->rear==q->front)
        return false;//判断是否为空队列
    q->front=(q->front+1)%MaxSize,e=q->data[q->front];
    return true;
}
//打印整个队列
static void DisplaySqQueue(SqQueue *&q){
    int num=q->front;
    while (1){
        printf("%d",q->data[num]);
        num++;
        if(num==q->front)
            break;
    }
}

static void fun(){
    //从键盘上获取n
    int n,out;
    scanf_s("%d",&n);
    //创建队列
    SqQueue *a;
    InitQueue(a);
    for(int i=1;i<=n;i++){
        enQueue(a,i);
    }
    //开始循环报数
    while(1){
        //让报数为1的人出列
        pop(a,out);
        printf("%d ",out);
        //让报数为2的人到队尾去
          //先判断队列是否为空队列,如果为空队列，直接结束循环
        if(a->rear==a->front)
            break;
        else{
            pop(a,out);
            enQueue(a,out);
        }
    }
}
