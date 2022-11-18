#define MaxSize 30
#include <malloc.h>
#include<cstring>
#include <cstdio>

typedef char ElemType;

typedef struct {
    ElemType data[MaxSize];
    int top;
}SqStack;

//��ʼ��ջ//
static void InitStack(SqStack *&s){
    s=(SqStack *) malloc(sizeof(SqStack));
    s->top=-1;
}

//��ջ//
static bool push(SqStack *&s,ElemType e){
    if(s->top==MaxSize-1)
        return false;//ջ�������ʧ��
    s->top+=1;
    s->data[s->top]=e;
    return true;//��ӳɹ�
}

//��ջ//
static bool pop(SqStack *&s,ElemType &e){
    if(s->top==-1)
        return false;//��ջ���޷���ջ
    e=s->data[s->top];
    s->top=s->top-1;
    return true;//��ջ�ɹ�
}

static void Ismatch(){
    int num;
    SqStack *q;
    InitStack(q);
    ElemType A[MaxSize];
    ElemType lie[]="{}[]()",e;
    gets_s(A);
    num=strlen(A);
    for(int i=0;i<num;i++){
        for(int j=0;j<6;j++){
            if(A[i]==lie[j]){
                if(q->top!=-1&&j%2!=0){
                    if(q->data[q->top]==lie[j-1])
                        pop(q,e);
                    else
                        push(q,A[i]);
                }
                else
                    push(q,A[i]);
            }

        }
    }

    if(q->top==-1)
        printf("1");
    else
        printf("0");
}