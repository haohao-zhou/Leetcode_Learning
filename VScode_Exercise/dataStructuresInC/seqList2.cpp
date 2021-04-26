//线性表的链式存储结构
#include<iostream>
using namespace std;

#define ERROR 0
#define OK 1
#define Overflow 2      //表示上溢
#define Underflow 3     //表示下溢
#define NotPresent 4    //表示元素不存在
#define Duplicate 5     //表示有重复元素

typedef int Status;
typedef int ElemType;
typedef struct  node
{
    ElemType element;       //数据域
    struct node *link;      //指针域
}Node;
typedef struct singleList
{
    Node *first;            //头指针
    int n;                  //单链表元素个数
}SingleList;
//单链表的初始化
Status Init(SingleList* L) {
    L->first = NULL;
    L->n = 0;
    return OK;
}
//单链表的查找
Status Find(SingleList L, int i, ElemType* x) {
    Node *p;
    int j;
    if(i < 0 || i >L.n - 1)     //对i进行越界检查
        return ERROR;
    p = L.first;
    for(j = 0; j < i; j++) {    //从头结点开始查找ai
        p = p->link;
    }
    *x = p->element;            //通过x返回ai的值
    return OK;
}
//单链表的插入
Status Insert(SingleList *L, int i, ElemType x) {
    Node *p, *q;
    int j;
    if(i < -1 || i > L->n - 1)
        return ERROR;
    p = L->first;
    for(j = 0; j < i; j++) {    //从头结点查找ai
        p = p->link;
    }
    q = (Node *)malloc(sizeof(Node));   //生成新节点q
    q->element = x;             
    if(i > -1) {
        q->link = p->link;      //新节点插在p所指结点之后，即指针的更改实现插入
        p->link = q;            
    } else {
        q->link = L->first;     //新节点插在头结点之前，成为新的头结点
        L->first = q;
    }
    L->n++;
    return OK;
}
//单链表的删除
Status Delete(SingleList *L, int i) {
    int j;
    Node *p, *q;
    if(!L->n) 
        return ERROR;
    if(i < 0 || i > L->n - 1) 
        return ERROR;
    q = L->first;
    p = L->first;
    for(j = 0; j < i - 1; j++) {
        q = q->link;
    } 
    if(i == 0)                      //如果i==0,那么删除的是头结点
        L->first = L->first->link;
    else {
        p = p->link;                //p指向ai
        q->link = p->link;          //从单链表中删除p所指向的节点
    }
    free(p);                        //释放p所指结点的存储空间
    L->n--;
    return OK;
}
//单链表的输出
Status Output(SingleList *L) {
    Node *p;
    if(!L->n)                       //判断顺序表是否为空
        return ERROR;
    p = L->first;
    while(p) {
        printf("%d ", p->element);
        p = p->link;
    }
    return OK;
}
//单链表的销毁
void Destroy(SingleList *L) {
    Node *p;
    while(L->first) {
        p = L->first->link;     //保存后继节点地址，防止“断链”
        free(L->first);         //释放first所指存储空间
        L->first = p;
    }
}
int main() {
    int i;
    int x;
    SingleList list;
    Init(&list);                //初始化单链表
    for(i = 0; i < 10; i++) {   //插入元素
        Insert(&list, i - 1, i);
    }
    printf("the linklist is : \n");
    Output(&list);
    Delete(&list, 0);
    printf("\nthe linklist after delete is : \n");
    Output(&list);
    Find(list, 0, &x);
    printf("\nthe element in x is : %d \n", x);
    Destroy(&list);
    system("pause");
    return 0;
}
