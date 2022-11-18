#include <malloc.h>
#include <stdio.h>
#pragma once
typedef int ElemType;

struct LinkNode{
    ElemType value;
    LinkNode *next;
};


//初始化单链表L，建立一个带头结点的单链表
static void Initlist(LinkNode *&L){
    L=(LinkNode *) malloc(sizeof(LinkNode));
    L->next=NULL;
}

//返回单链表L的长度
static int ListLength(LinkNode *L){
    int i=0;
    while (L->next!=NULL)
        L=L->next,i++;
    return i;
}

//在单链表L的第i个位置上插入元素e
static void ListInsert(LinkNode *&L,int i,ElemType e){
    LinkNode *hand=(LinkNode *) malloc(sizeof(LinkNode));
    hand=L;
    for(;i!=1;i--)
        L=L->next;
    LinkNode *net=(LinkNode *) malloc(sizeof(LinkNode));
    net->value=e;
    net->next=L->next;
    L->next=net;
    L=hand;
}
//删除单链表L的第i个元素
static void ListDelete(LinkNode *&L,int i){
    LinkNode *hand=(LinkNode *) malloc(sizeof(LinkNode));
    hand=L;
    while(i!=1)
        L=L->next,i--;
    L->next=L->next->next;
    L=hand;
}
//头插法建表L
static void CreateListT(LinkNode *&L,ElemType A[],int n){
    for(int i=0;i<n;i++){
        LinkNode *net=(LinkNode *) malloc(sizeof(LinkNode));
        net->next=L->next;
        net->value=A[i];
        L->next=net;
    }
}

static void DispList(LinkNode *L){
    while (L->next!=NULL){
        L=L->next;
        printf(" %d ",L->value);
    }
}//输出单链表L

//删除单链表中元素值最大的结点
static void DelMaxNode(LinkNode *&L){
    int num=0;
    LinkNode *hand=(LinkNode *)malloc(sizeof(LinkNode));
    hand=L;
    LinkNode *maxnet=(LinkNode *)malloc(sizeof(LinkNode));
    while(L->next!=NULL){
        if(L->next->value>num)
            num=L->next->value,maxnet=L;
        L=L->next;
    }
    maxnet->next=maxnet->next->next;
    L=hand;
}


