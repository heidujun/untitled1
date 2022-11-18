//
// Created by hyh25 on 2022/11/1.
//
#include<cstdio>
#include <cstdlib>
#define Maxsize 50
typedef char Elemtype;

typedef struct node{
    Elemtype data;
    node *rchild,*lchild;
}BTNode;


//��ʼ�������
static void create_root(BTNode *&r){
    r=(BTNode *) malloc(sizeof(BTNode));
    r->data='#';//��ʼ�������
}

//����������
static void create_tree(BTNode *&r,Elemtype str[]){
    BTNode *p,*st[Maxsize];
    char ch=str[0];
    int top=0,i=0,k=0;
    while(ch!='\0'){
        switch (ch) {
            case '(': i++,top++,st[top]=p,k=1;
                break;//����������
            case ',': i++,k=2;
                break;//����������
            case ')': i++,top--,k=0;//���˵���һ�����
                break;
            default:
                ch=str[i];
                p=(BTNode *) malloc(sizeof(BTNode));//����һ�����
                if(r==nullptr){//��û�и��ڵ㣬�ͽ�data����������
                    p->data=ch,st[top]=p,r=p;
                }
                else
                    switch (k) {
                        case 1: p->data=ch,st[top]->lchild=p;//��Ϊ��������ӵ����ڵ�
                            break;
                        case 2: p->data=ch,st[top]->rchild=p;//��Ϊ��������ӵ����ڵ�
                            break;
                        case 0:
                            top--;
                    }
        }
        i++,ch=str[i];
    }
}

//���������
static void disptree(BTNode *&r){
    if(r!=nullptr){
        printf("%c",r->data);
        if(r->lchild!=nullptr || r->rchild!=nullptr){
            printf("(");
            disptree(r->lchild);
            if(r->rchild!=nullptr)
                printf(",");
            disptree(r->rchild);
            printf(")");
        }
    }
}

//ǰ�����������
static void before_display(BTNode *r){
    if(r!=nullptr){
        printf("%c",r->data);
        before_display(r->lchild);
        before_display(r->lchild);
    }
}

//�������
static void Inorder(BTNode *r){
    if(r!=nullptr){
        Inorder(r->lchild);
        printf("%c",r->data);
        Inorder(r->rchild);
    }
}

//�������
static void PostOrder(BTNode *b){
    if(b!= nullptr){
        PostOrder(b->lchild);
        PostOrder(b->rchild);
        printf("%c",b->data);
    }
}

//����������Ľڵ���
static int count_node(BTNode *r){
    if(r->rchild== nullptr&& r->lchild== nullptr)
        return 1;//Ҷ�ڵ㷵��
    else
        return count_node(r->rchild)+ count_node(r->lchild)+1;//�ݹ���ڵ���
}

//�������������Ҷ�ӽ����
static int count_leaf(BTNode *&r){
    if(r->lchild== nullptr&&r->rchild== nullptr)
        return 1;
    else
        return count_leaf(r->rchild)+ count_leaf(r->lchild);
}

//��������������
static int count_deep(BTNode *&r){
    if(r->rchild!= nullptr||r->rchild!= nullptr){
        int num1=0,num2=0;
        num1+= count_deep(r->rchild);
        num2+= count_deep(r->lchild);
        if(num1>num2)
            return num1+1;
        else
            return num2+1;
    }
    else//ɨ�赽Ҷ�ڵ�
        return 1;
}


//������������
typedef struct {
    Elemtype data;
    double weight;
    int parent,lchild,rchild;
    char cd[Maxsize];
}HTNode;

//�Զ���������
static void autohuffman(HTNode *ht,int num){
    HTNode *p;
    int top=0,max=num;
    double min1,min2;
    for(int i=0;i<num;i++){//����Ȩ�ش�С��������
        for(int j=i;j<num;j++)
            if(ht[i].weight>ht[j].weight)
                p=&ht[i],ht[j]=ht[i],ht[i]=*p;//�������
    }
    //connect
    ht[max].rchild=0,ht[max].weight+=ht[0].weight,ht[0].parent=max;
    top++;
    while(top<num){
        if(ht[max].lchild!=0)
            max++,ht[max].rchild=max-1,ht[max].weight+=ht[max-1].weight,ht[max-1].parent=max;//�������ڵ�
        ht[max].lchild=top,ht[max].weight+=ht[top].weight,ht[top].parent=max;//�����Ҷ��
        top++;
    }
    //����
    int level=0;
    while(max>top){
        if(level>0){//�̳�����
            for(int i=0;i<level;i++){
                ht[ht[max].lchild].cd[i]=ht[max].cd[i];
                ht[ht[max].rchild].cd[i]=ht[max].cd[i];
            }
        }
        ht[ht[max].lchild].cd[level]='0';
        ht[ht[max].rchild].cd[level]='1';
        level++;
        max--;
    }
}