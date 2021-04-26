//����Դ���廪��ѧ����������÷��ʦ���ʵ����ݽṹC����ʵ�֣������������Ѿ��ж�����Ȼ�������
#include<iostream>
using namespace std;

#define MaxSize 100
//�������ڵ�ṹ�嶨��
typedef char DataType;
typedef struct BiNode {
    DataType data;
    struct BiNode* lChild;
    struct BiNode* rChild;
}BiNode;
//����������ݹ飩
void PreOrder(BiNode* root) {
    if(root == NULL) 
        return;
    else {
        printf("%c ", root->data);
        PreOrder(root->lChild);
        PreOrder(root->rChild);
    }
}
//��������ǵݹ�
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
//����������ݹ飩
void InOrder(BiNode* root) {
    if(root == NULL) 
        return;
    else {
        InOrder(root->lChild);
        printf("%c ", root->data);
        InOrder(root->rChild);
    }
}
//��������ǵݹ�
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
//��������
void PostOrder(BiNode* root) {
    if(root == NULL) 
        return;
    else {
        PostOrder(root->lChild);
        PostOrder(root->rChild);
        printf("%c ", root->data);
    }
}
//����һ�Ŷ�����
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
//����һ�Ŷ�����
void DestroyBiTree(BiNode* root) {
    if(root == NULL) {
        return;
    } else {
        DestroyBiTree(root->lChild);
        DestroyBiTree(root->rChild);
        free(root);
    }
}

//������
int main() {
    BiNode* root = NULL;
    root = CreateBiTree(root);
    printf("�ö������ĸ��ڵ��ǣ�%c\n", root->data);
    printf("ǰ��������Ϊ��\n");
    PreOrder(root);
    printf("����������Ϊ��\n");
    InOrder(root);
    printf("�����������Ϊ��\n");
    PostOrder(root);
    DestroyBiTree(root);
    system("pause");
    return 0;
}
