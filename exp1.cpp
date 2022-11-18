#include "tree.cpp"
int main(){
//
    Elemtype str[Maxsize]="A(B(C,D),E(F(G,H),I))";
    BTNode *r;
    create_root(r);

    create_tree(r,str);

    disptree(r);

    before_display(r);

    Inorder(r);

    PostOrder(r);

    return 0;
}