#include<stdlib.h>
#include<stack>
typedef char ElemType;

typedef struct stack
{
    int top;    //表示栈顶元素标识
    int maxSize;
    ElemType *element;
}Stack;
//创建一个能容纳mSize和单元的空栈
void Create(Stack *S, int mSize) {
    S->maxSize = mSize;
    S->element = (ElemType*)malloc(sizeof(ElemType) * mSize);   //好像就是申请了一段double型的内存当数组用了
    S->top = -1;
}
//销毁栈，释放空间
void Destroy(Stack *S) {
    S->maxSize = -1;
    free(S->element);
    S->top = -1;
}
//清楚栈中元素，但不释放空间
void Clear(Stack *S) {
    S->top = -1;
}
//判断堆栈是否已满，若已满返回true，否则返回false
bool IsFull(Stack *S) {
    return S->top == S->maxSize - 1;
}
//判断堆栈是否为空，空返回true， 否则返回false
bool IsEmpty(Stack *S) {
    return S->top == -1;
}
//获取栈顶元素，通过指针x返回，操作成功返回true， 否则返回false
bool Top(Stack *S, ElemType *x) {
    if(IsEmpty(S)) 
        return false;
    *x = S->element[S->top];
    return true;
}
//栈顶位置插入元素x入栈
bool Push(Stack *S, ElemType x) {
    if(IsFull(S)) 
        return false;
    S->top++;
    S->element[S->top] = x;
    return true;
}
//出栈，删除栈顶元素
bool Pop(Stack *S) {
    if(IsEmpty(S)) 
        return false;
    S->top--;
    return true;
}