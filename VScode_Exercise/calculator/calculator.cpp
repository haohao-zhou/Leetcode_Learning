#include<iostream>
#include "stack.h"
#include<math.h>
#include<string.h>
using namespace std;
#define STACKSIZE 20
#define ITEMSIZE 20
#define POSTFIXSIZE 200
//判断表达式中是否有非法字符（合法字符包括0~9 . + - * / ^ )
bool IsLegal(char *postfix) {
    int i;
    char c;
    for(i = 0; i < strlen(postfix); i++) {
        c = postfix[i];
        if(!((c >= '0' && c <= '9') || c == '.' || c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == ' '))
            return false;
    }
    return true;
}
//从表达式当前位置curPos获取元素，完成后移动到下一元素首字符位置
//操作数返回0，操作符返回1，异常返回-1
int GetItem(char *postfix, int *curPos, char *item) {
    int i = 0, k = *curPos, flag;
    if(postfix[k] == '.') { //元素首字符不能是小数点
        flag = -1;
    } else if(postfix[k] >= '0' && postfix[k] <= '9') {     //元素首字符是数字，是正确的操作数
        while ((postfix[k] >= '0' && postfix[k] <= '9') || postfix[k] == '.') {
            item[i++] = postfix[k++];
        }
        item[i] = '\0';     //将数字截取为字符串形式保存
        flag = 0;
    } else {        //该元素为操作符
        item[0] = postfix[k++];
        item[1] = '\0';
        flag = 1;
    }
    while(postfix[k] == ' ') {  //跳过当前元素后面的空格，在下一次趣元素的起始位置为非空格字符
        k++;
    }
    *curPos = k;
    return flag;
}
//根据操作符执行计算，包括两个操作数和一个操作符（例如a+b, a左操作数，+操作符，b右操作数）
void DoOperator(Stack *S, char oper) {
    double oper1, oper2;
    if(!Top(S, &oper1)) {   //从栈中弹出右操作数
        printf("异常：后缀表达式格式出错，存在多余操作符\n");
        exit(0);
    }
    Pop(S);
    if(!Top(S, &oper2)) {   //从栈中弹出左操作数
        printf("异常：后缀表达式格式出错，存在多余操作符\n");
        exit(0);
    }
    Pop(S);
    switch (oper)   //根据操作符执行相应运算
    {
    case '+' :
        Push(S, oper2 + oper1);
        break;
    case '-' :
        Push(S, oper2 - oper1);
        break;
    case '*' :
        Push(S, oper2 * oper1);
        break;
    case '/' :
        if(fabs(oper1) < 1e-6) {    //判断分母是否为0
            printf("异常：除数不可以为0！\n");
            exit(0);
        } else {
            Push(S, oper2 / oper1);
        }
        break;
    case '^' :
        Push(S, pow(oper2, oper1));
        break;
    }
}
//对后缀表达式postfix求值
double Calculating(char *postfix) {
    Stack S;
    char item[ITEMSIZE];    //储存后缀表达式中的元素
    double data;
    int flag = -1;          //标记当前扫描元素的类型，1表示操作数，0表示操作符，-1表示异常
    int curPos = 0;         //记录当前扫描元素首字符下标位置
    while(postfix[curPos] == ' ')   //过滤postfix前面所有空格
        curPos++;
    Create(&S, STACKSIZE);  //创建栈，申请内存
    while (curPos < strlen(postfix))
    {
        flag = GetItem(postfix, &curPos, item);     //获取当前扫描的表达式的元素
        if(flag == -1) {
            printf("异常：后缀表达式元素不合法！\n");
            exit(0);
        } else if(flag == 1) {  //执行相应的操作符运算
            switch (item[0])
            {
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                DoOperator(&S, item[0]);
                break;
            }
        } else {            //操作数进栈
            data = atof(item);  //将字符串转换为浮点数输出
            Push(&S, data);
        }
    }
    if(S.top == 0) {    //如果栈中只剩下唯一元素，则栈顶元素即为计算结果
        Top(&S, &data);
    } else {
        printf("异常：后缀表达式格式出错，存在多余操作数\n");
        exit(0);
    }
    Destroy(&S);    //释放空间
    return data;
}
int main() {
    char postfix[POSTFIXSIZE];      //存储表达式中的扫描元素
    printf("请输入后缀表达式格式（连续操作数之间用空格隔开）：\n");
    gets(postfix);                  //输入流读取后缀表达式，cmd输入计算表达式（后缀表达式形式）
    if(!IsLegal(postfix)) {
        printf("异常：中缀表达式存在非法字符\n");
    } else 
        printf("%s = %.2f\n", postfix, Calculating(postfix));   //输出计算结果，保留两位小数1
    system("pause");
    return 0;
}