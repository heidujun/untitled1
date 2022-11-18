//
// Created by hyh25 on 2022/10/4.
//
#include <malloc.h>
#include <stdio.h>
#define MaxSize 30
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int front;//��ͷλ��
    int rear;//��βλ��
}SqQueue;
//��ʼ������
static void InitQueue(SqQueue *&q){
    q=(SqQueue *) malloc(sizeof(SqQueue));
    q->front=q->rear=0;
}
//���
static bool enQueue(SqQueue *&q,ElemType e){
    if((q->rear+1)%MaxSize==q->front)
        return false;
    q->rear=(q->rear+1)%MaxSize;
    q->data[q->rear]=e;
    return true;
}
//����
static bool pop(SqQueue *&q,ElemType &e){
    if(q->rear==q->front)
        return false;//�ж��Ƿ�Ϊ�ն���
    q->front=(q->front+1)%MaxSize,e=q->data[q->front];
    return true;
}
//��ӡ��������
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
    //�Ӽ����ϻ�ȡn
    int n,out;
    scanf_s("%d",&n);
    //��������
    SqQueue *a;
    InitQueue(a);
    for(int i=1;i<=n;i++){
        enQueue(a,i);
    }
    //��ʼѭ������
    while(1){
        //�ñ���Ϊ1���˳���
        pop(a,out);
        printf("%d ",out);
        //�ñ���Ϊ2���˵���βȥ
          //���ж϶����Ƿ�Ϊ�ն���,���Ϊ�ն��У�ֱ�ӽ���ѭ��
        if(a->rear==a->front)
            break;
        else{
            pop(a,out);
            enQueue(a,out);
        }
    }
}
