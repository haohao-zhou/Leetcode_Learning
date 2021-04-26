//代码源自清华大学出版社王红梅老师主笔的数据结构C语言实现，代码适用于已经有二叉树然后遍历它
#include<iostream>
using namespace std;

#define MaxSize 100
//二叉树节点结构体定义
typedef char DataType;
typedef struct BiNode {
    DataType data;
    struct BiNode* lChild;
    struct BiNode* rChild;
}BiNode;
//先序遍历（递归）
void PreOrder(BiNode* root) {
    if(root == NULL) 
        return;
    else {
        printf("%c ", root->data);
        PreOrder(root->lChild);
        PreOrder(root->rChild);
    }
}
//先序遍历非递归
void PreOrder02(BiNode* root) {
    BiNode* S[MaxSize], *bt = root;
    int top = -1;
    while (bt != NULL || top != -1) {
        while(bt != NULL) {
            printf("%c ", bt->data);
            S[++top] = bt;
            bt = bt->lChild;
        }
        if(top != -1) {
            bt = S[top--];
            bt = bt->rChild;
        }
    }
}
//中序遍历（递归）
void InOrder(BiNode* root) {
    if(root == NULL) 
        return;
    else {
        InOrder(root->lChild);
        printf("%c ", root->data);
        InOrder(root->rChild);
    }
}
//中序遍历非递归
void InOrder02(BiNode* root) {
    BiNode* S[MaxSize], *bt = root;
    int top = -1;
    while (bt != NULL || top != -1) {
        while(bt != NULL) {
            S[++top] = bt;
            bt = bt->lChild;
        }
        if(top != -1) {
            bt = S[top--];
            printf("%c ", bt->data);
            bt = bt->rChild;
        }
    }
}
//后续遍历
void PostOrder(BiNode* root) {
    if(root == NULL) 
        return;
    else {
        PostOrder(root->lChild);
        PostOrder(root->rChild);
        printf("%c ", root->data);
    }
}
//建立一颗二叉树
BiNode* CreateBiTree(BiNode* root) {
    char ch;
    cin>>ch;
    if(ch == '# ')
        root = NULL;
    else {
        root = (BiNode*)malloc(sizeof(BiNode));
        root->data = ch;
        root->lChild = CreateBiTree(root->lChild);
        root->rChild = CreateBiTree(root->rChild);
    }
    return root;
}
//销毁一颗二叉树
void DestroyBiTree(BiNode* root) {
    if(root == NULL) {
        return;
    } else {
        DestroyBiTree(root->lChild);
        DestroyBiTree(root->rChild);
        free(root);
    }
}

//主函数
int main() {
    BiNode* root = NULL;
    root = CreateBiTree(root);
    printf("该二叉树的根节点是：%c\n", root->data);
    printf("前序遍历结果为：\n");
    PreOrder(root);
    printf("中序遍历结果为：\n");
    InOrder(root);
    printf("后续遍历结果为：\n");
    PostOrder(root);
    DestroyBiTree(root);
    system("pause");
    return 0;
}
