#define MaxSize 30
#include <malloc.h>
#include<cstring>
#include <cstdio>

typedef char ElemType;

typedef struct {
    ElemType data[MaxSize];
    int top;
}SqStack;

//初始化栈//
static void InitStack(SqStack *&s){
    s=(SqStack *) malloc(sizeof(SqStack));
    s->top=-1;
}

//进栈//
static bool push(SqStack *&s,ElemType e){
    if(s->top==MaxSize-1)
        return false;//栈满，添加失败
    s->top+=1;
    s->data[s->top]=e;
    return true;//添加成功
}

//出栈//
static bool pop(SqStack *&s,ElemType &e){
    if(s->top==-1)
        return false;//空栈，无法出栈
    e=s->data[s->top];
    s->top=s->top-1;
    return true;//出栈成功
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