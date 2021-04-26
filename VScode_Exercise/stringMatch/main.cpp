#include<iostream>
using namespace std;
typedef struct btnode
{
    char element;
    struct btnode *lChild;
    struct btnode *rChild;
}BTNode;
typedef struct binarytree
{
    BTNode *root;
}BinaryTree;
//构造一棵空二叉树
void Create(BinaryTree *bt) {
    bt->root = NULL;
}
//创建一个新节点
BTNode *NewNode(char x, BTNode *ln, BTNode *rn) {
    BTNode *p = (BTNode *) malloc (sizeof(BTNode));
    p->element = x;
    p->lChild = ln;
    p->rChild = rn;
    return p;
}
//判断二叉树是否为空，非空通过指针x返回根节点的值
bool Root(BinaryTree *bt, char *x) {
    if(bt->root) {
        x = &bt->root->element;
        return true;
    } else {
        return false;
    }
}
//构造二叉树，根节点的值为e，left和right为左右子树
void MakeTree(BinaryTree *bt, char e, BinaryTree *left, BinaryTree *right) {
    if(bt->root || left == right) {
        return ;
    }
    bt->root = NewNode(e, left->root, right->root);
    left->root = NULL;
    right->root = NULL;
}
//
void PreOrder(BTNode *t) {
    if(!t) return;
    printf("\t%c\t\n", t->element);
    PreOrder(t->lChild);
    PreOrder(t->rChild);
}
//先序遍历二叉树
void PreOrderTree(BinaryTree *bt) {
    PreOrder(bt->root);
}
void Clear(BTNode *t) {
    if(!t) return;
    Clear(t->lChild);
    Clear(t->rChild);
    free(t);
}
void TreeClear(BinaryTree *bt) {
    Clear(bt->root);
}

int main() {
    BinaryTree a, b, x, y, z;
    //构造5个空节点
    Create(&a);
    Create(&b);
    Create(&x);
    Create(&y);
    Create(&z);
    //将节点连接为二叉树，注意节点a和b始终为空节点
    MakeTree(&y, 'E', &a, &b);
    MakeTree(&z, 'F', &a, &b);
    MakeTree(&x, 'C', &y, &z);
    MakeTree(&y, 'D', &a, &b);
    MakeTree(&z, 'B', &y, &x);
    printf("PreOrderTree: \n");
    PreOrderTree(&z);
    TreeClear(&z);
    system("pause");
    return 0;
}