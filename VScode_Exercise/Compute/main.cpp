//输入逆波兰式表达式
#include<iostream>
#include<string.h>
using namespace std;
//函数表达式比较str1和str2优先级：return 1表示str1优先级高；return 0表示优先级相等；return -1表示str2优先级高
int Compare(char str1, char str2) {     
    switch (str1)
    {
    case '+':
    case '-':
        if(str2 == '(' || str2 == '#') return 1;
        else return -1;
        break;
    case '*':
    case '/':
        if(str2 == '*' || str2 == '/') return -1;
        else return 1;
        break;
    case '(':
        return 1;
        break;
    case ')':
        if(str2 == '(') return 0;
        else return -1;
        break;
    case '#':
        if(str2 == '#') return 0;
        else return -1;
        break;
    default:
        break;
    }
}
int Compute(char *str) {
    char OPND[100], OPTR[100];                  //定义两个顺序栈
    OPTR[0] = '#';                              //栈OPTR初始化为定界符
    int top1 = -1, top2 = 0;                    //初始化OPTR和OPND栈顶指针
    int i, k, x, y, z, op;
    for(i = 0; str[i] != '\0'; i++) {
        if(str[i] >= 48 && str[i] <= 57)        //0~9之间ASCII码
            OPND[++top1] = str[i++] - 48;       //将字符转换为数字压栈
        else {
            k = Compare(str[i], OPTR[top2]);
            if(k == 1) OPTR[++top2] = str[i++]; //str[i]优先级较高哈
            else if(k == -1) {                  //str[i]优先级较低
                y = OPND[top1--];               //运算元素出栈
                x = OPND[top1--];
                op = OPTR[top2--];              //运算符号出栈
                switch (op)
                {
                case '+': z = x + y; break;
                case '-': z = x - y; break;
                case '*': z = x * y; break;
                case '/': z = x / y; break;
                default: break;
                }
                OPND[++top1] = z;               //运算结果入栈
            } else                              //str[i]与运算符栈的栈顶元素优先级相同
            {
                top2--;                         //匹配str[i]，扫描下一个字符
                i++;
            }
        }
    }
    return OPND[top1];                          //最后的栈顶元素即为运算结果
}
int main() {
    char str[100];
    int result;
    printf("please input an Arithmetic expression:\t");
    scanf("%s", str);
    strcat(str, "#");
    result = Compute(str);
    printf("the result of your Arithmetic expression is : %d\n", result);
    system("pause");
    return 0;
}