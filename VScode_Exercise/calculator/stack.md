#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef int Status;

typedef struct {
    int * base;
    int * top;
    int stacksize;
}Stack;

Status InitStack(Stack &S);
Status DestroyStack(Stack &S);
Status GetTop(Stack S, int &e);
Status Push(Stack &S, int e);
Status Pop(Stack &S, int &e);
Status StackEmpty(Stack &S);
Status ClearStack(Stack &S);

Status InitStack(Stack &S)
{
    S.base = (int *)malloc(STACK_INIT_SIZE * sizeof(int));
    if (! S.base)
        exit(OVERFLOW);
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

Status DestroyStack(Stack &S){
    //free(&S); 这里的结构体的变量，由于在定义初始化变量时已分配内存，所以不能用free释放，free只能针对malloc,relloc等操作
    //所以其只有数据有效和无效之分，没有空值之说，若是结构体内有指针，则判断同（1）。
    free(S.base);
    S.base=NULL;
    return OK;
}

Status GetTop(Stack S, int &e)
{
    if (S.top == S.base)
        return ERROR;
    e = * (S.top - 1);
    return OK;
}

Status Push(Stack &S, int e)
{
    if (S.top - S.base >= S.stacksize)
    {
        S.base = (int * )realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(int));
        if (! S.base)
            exit(OVERFLOW);
        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREMENT;
    }
    *S.top++ = e;
    return OK;
}

Status Pop(Stack &S, int &e)
{
    if (S.top == S.base)
        return ERROR;
    e = * --S.top;
    return OK;
}

int StackEmpty(Stack &S)
{
    if (S.top == S.base)
        return     TRUE;
    else
        return FALSE;
}

Status ClearStack(Stack &S)
{
    S.top = S.base;
    return OK;
}