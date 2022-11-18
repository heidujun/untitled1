#include <malloc.h>
#include <stdio.h>
#pragma once
typedef int ElemType;

struct LinkNode{
    ElemType value;
    LinkNode *next;
};


//��ʼ��������L������һ����ͷ���ĵ�����
static void Initlist(LinkNode *&L){
    L=(LinkNode *) malloc(sizeof(LinkNode));
    L->next=NULL;
}

//���ص�����L�ĳ���
static int ListLength(LinkNode *L){
    int i=0;
    while (L->next!=NULL)
        L=L->next,i++;
    return i;
}

//�ڵ�����L�ĵ�i��λ���ϲ���Ԫ��e
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
//ɾ��������L�ĵ�i��Ԫ��
static void ListDelete(LinkNode *&L,int i){
    LinkNode *hand=(LinkNode *) malloc(sizeof(LinkNode));
    hand=L;
    while(i!=1)
        L=L->next,i--;
    L->next=L->next->next;
    L=hand;
}
//ͷ�巨����L
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
}//���������L

//ɾ����������Ԫ��ֵ���Ľ��
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


