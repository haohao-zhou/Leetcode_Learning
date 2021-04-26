//线性表的顺序存储结构，通过数组的形式
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
typedef struct seqList {
    int n;              //顺序表当前长度
    int maxLength;      //最大允许长度
    ElemType *element;  //顺序表存储空间首地址
}SeqList;

//顺序表的初始化
Status Init(SeqList *L, int mSize) {
    L->maxLength = mSize;
    L->n = 0;
    L->element = (ElemType*)malloc(sizeof(ElemType) * mSize);    //动态生成一维数组空间，这里*是乘的意思不是指针
    if(!L->element) 
        return OK;
}
//顺序表的查找，在L中寻找下标为i的元素，通过指针返回
Status Find(SeqList L, int i, ElemType* x) {
    if(i < 0 || i > L.n - 1)        //判断元素下标i是否越界
        return ERROR;   
    *x = L.element[i];              //取出element[i]的值通过参数x返回
    return OK;
}
//顺序表的插入O(n)
Status Insert(SeqList* L, int i, ElemType x) {
    int j;
    if(i < -1 || i > L->n - 1)              //判断下标i是否越界
        return ERROR;
    if(L->n == L->maxLength)                //判断顺序表存储空间是否已满
        return ERROR;
    for(j = L->n - 1; j > i; j--) {         //从后往前逐个后移元素
        L->element[j + 1] = L->element[j];
    }
    L->element[i + 1] = x;                  //在i + 1 位置插入元素
    L->n = L->n + 1;                        
    return OK;
}
//顺序表的元素删除O(n)
Status Delete(SeqList *L, int i) {
    int j;
    if(i < 0 || i > L->n - 1)               //判断下标是否越界
        return ERROR;
    if(!L->n)                               //判断顺序表是否为空
        return ERROR;
    for(j = i + 1; j < L->n; j++) {         //从前往后逐个前移元素
        L->element[j - 1] = L->element[j];
    }
    L->n--;                                 //顺序表长度-1
    return OK;
}
//顺序表的输出
Status Output(SeqList *L) {
    int i;
    if(L->n == 0)                       //判断顺序表是否为空
        return ERROR;
    for(i = 0; i <= L->n - 1; i++) {    //从前往后逐个输出元素
        printf("%d ", L->element[i]);
    }
    printf("\n");
    return OK;
}
//顺序表的销毁
Status Destroy(SeqList *L) {
    L->n = 0; 
    L->maxLength = 0;
    free(L->element);
}
//主函数int main
int main() {
    int i;
    SeqList list;
    Init(&list, 10);
    for(i = 0; i < 10; i++) {       //将下标i赋予对应元素
        Insert(&list, i - 1, i);
    }
    Output(&list);
    Delete(&list, 5);
    Output(&list);
    Destroy(&list);
    system("pause");
    return 0;
}