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


//初始化根结点
static void create_root(BTNode *&r){
    r=(BTNode *) malloc(sizeof(BTNode));
    r->data='#';//初始化根结点
}

//创建二叉树
static void create_tree(BTNode *&r,Elemtype str[]){
    BTNode *p,*st[Maxsize];
    char ch=str[0];
    int top=0,i=0,k=0;
    while(ch!='\0'){
        switch (ch) {
            case '(': i++,top++,st[top]=p,k=1;
                break;//处理左子树
            case ',': i++,k=2;
                break;//处理右子树
            case ')': i++,top--,k=0;//回退到上一级结点
                break;
            default:
                ch=str[i];
                p=(BTNode *) malloc(sizeof(BTNode));//创建一个结点
                if(r==nullptr){//若没有根节点，就将data加入根结点中
                    p->data=ch,st[top]=p,r=p;
                }
                else
                    switch (k) {
                        case 1: p->data=ch,st[top]->lchild=p;//作为左子树添加到父节点
                            break;
                        case 2: p->data=ch,st[top]->rchild=p;//作为右子树添加到父节点
                            break;
                        case 0:
                            top--;
                    }
        }
        i++,ch=str[i];
    }
}

//二叉树输出
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

//前序遍历整个树
static void before_display(BTNode *r){
    if(r!=nullptr){
        printf("%c",r->data);
        before_display(r->lchild);
        before_display(r->lchild);
    }
}

//中序遍历
static void Inorder(BTNode *r){
    if(r!=nullptr){
        Inorder(r->lchild);
        printf("%c",r->data);
        Inorder(r->rchild);
    }
}

//后序遍历
static void PostOrder(BTNode *b){
    if(b!= nullptr){
        PostOrder(b->lchild);
        PostOrder(b->rchild);
        printf("%c",b->data);
    }
}

//计算二叉树的节点数
static int count_node(BTNode *r){
    if(r->rchild== nullptr&& r->lchild== nullptr)
        return 1;//叶节点返回
    else
        return count_node(r->rchild)+ count_node(r->lchild)+1;//递归求节点数
}

//计算二叉树及的叶子结点数
static int count_leaf(BTNode *&r){
    if(r->lchild== nullptr&&r->rchild== nullptr)
        return 1;
    else
        return count_leaf(r->rchild)+ count_leaf(r->lchild);
}

//计算二叉树的深度
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
    else//扫描到叶节点
        return 1;
}


//定义哈夫曼结点
typedef struct {
    Elemtype data;
    double weight;
    int parent,lchild,rchild;
    char cd[Maxsize];
}HTNode;

//自动哈夫曼树
static void autohuffman(HTNode *ht,int num){
    HTNode *p;
    int top=0,max=num;
    double min1,min2;
    for(int i=0;i<num;i++){//按照权重从小到大排序
        for(int j=i;j<num;j++)
            if(ht[i].weight>ht[j].weight)
                p=&ht[i],ht[j]=ht[i],ht[i]=*p;//交换结点
    }
    //connect
    ht[max].rchild=0,ht[max].weight+=ht[0].weight,ht[0].parent=max;
    top++;
    while(top<num){
        if(ht[max].lchild!=0)
            max++,ht[max].rchild=max-1,ht[max].weight+=ht[max-1].weight,ht[max-1].parent=max;//创建父节点
        ht[max].lchild=top,ht[max].weight+=ht[top].weight,ht[top].parent=max;//添加左叶子
        top++;
    }
    //编码
    int level=0;
    while(max>top){
        if(level>0){//继承数据
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