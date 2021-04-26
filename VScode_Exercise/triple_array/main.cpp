//通过C语言中的结构体和动态数组，实现三维整形数组类型TripleArray及其运算
#include<iostream>
using namespace std;
typedef struct triplearray{
    int m1;
    int m2;
    int m3;
    int *array;
}TripleArray;
#define ERROR 0
#define OK 1
#define NotPresent 2
#define Duplicate 3
#define IllegalIndex 4
typedef int Status;
//创建矩阵，malloc动态申请内存，如果成功返回非0值，否则返回0
Status CreateArray(TripleArray *TripleArray, int m1, int m2, int m3) {
    TripleArray->m1 = m1;
    TripleArray->m2 = m2;
    TripleArray->m3 = m3;
    TripleArray->array = (int *)malloc(m1 * m2 * m3 * sizeof(int));
    if( !(TripleArray->array) ) 
        return ERROR;
    else 
        return OK;
}
//销毁矩阵，释放占用的内存空间
Status DestroyArray(TripleArray *TripleArray) {
    if(!(TripleArray->array)) 
        return ERROR;
    else {
        free(TripleArray->array);
    }
    free(TripleArray);
    return OK;
}
//数组元素查询与取值
Status RetrieveArray(TripleArray TripleArray, int i1, int i2, int i3, int *x) {
    if(!TripleArray.array) 
        return NotPresent;
    if(i1 < 0 || i2 < 0 || i3 < 0 || 
       i1 >= TripleArray.m1 || i2 >= TripleArray.m2 || i3 >= TripleArray.m3) 
        return IllegalIndex;
    *x = *(TripleArray.array + i1 * TripleArray.m2 * TripleArray.m3 + i2 * TripleArray.m3 + i3);
    return OK;
}
//矩阵中元素赋值操作
Status StoreArrayItem(TripleArray *TripleArray, int i1, int i2, int i3, int x) {
    if(!TripleArray->array) 
        return NotPresent;
    if(i1 < 0 || i2 < 0 || i3 < 0 ||
       i1 >= TripleArray->m1 || i2 >= TripleArray->m2 || i3 >= TripleArray->m3) 
        return IllegalIndex;
    *(TripleArray->array + i1 * TripleArray->m2 * TripleArray->m3 + i2 * TripleArray->m3 + i3) = x;
    return OK;
}
//遍历输出矩阵元素
void OutputArray(TripleArray TripleArray) {
    if(!TripleArray.array) 
        return ;
    for(int i = 0; i < TripleArray.m1; i++) {
        for(int j = 0; j < TripleArray.m2; j++) {
            for(int k = 0; k < TripleArray.m3; k++) {
                int value;
                RetrieveArray(TripleArray, i, j, k, &value);
                printf("Array[%d][%d][%d] = %d\n", i, j, k, value);
            }
        }
    }
    printf("\n");
}
//复制矩阵中所有元素到新的矩阵中去
Status CopyArray(TripleArray *TripleArrayA, TripleArray *TripleArrayB) {
    if(!(TripleArrayA->array || TripleArrayB->array))
        return NotPresent;
    if (TripleArrayA->array == TripleArrayB->array) 
        return Duplicate;
    if(TripleArrayA->m1 != TripleArrayB->m1 || 
       TripleArrayA->m2 != TripleArrayB->m2 ||
       TripleArrayA->m3 != TripleArrayB ->m3)
        return ERROR;
    for(int i = 0; i < TripleArrayA->m1; i++) {
        for(int j = 0; j < TripleArrayA ->m2; j++) {
            for(int k = 0; k < TripleArrayA->m3; k++) {
                int value;
                RetrieveArray(*TripleArrayA, i, j, k, &value);
                StoreArrayItem(TripleArrayB, i, j, k, value);
            }
        }
    }
    return OK;
}
int main() {
    TripleArray TripleArrayA, TripleArrayB;
    CreateArray(&TripleArrayA, 2, 2, 2);
    CreateArray(&TripleArrayB, 2, 2, 2);
    for(int i = 0; i < TripleArrayA.m1; i++) {
        for(int j = 0; j < TripleArrayA.m2; j++) {
            for(int k = 0; k < TripleArrayA.m3; k++) {
                StoreArrayItem(&TripleArrayA, i, j, k, 10);
                StoreArrayItem(&TripleArrayB, i, j, k, 20);
            }
        }
    }
    OutputArray(TripleArrayA); 
    OutputArray(TripleArrayB);
    //cout<<endl;
    CopyArray(&TripleArrayA, &TripleArrayB);
    OutputArray(TripleArrayA);
    OutputArray(TripleArrayB);
    system("pause");
    return 0;
}