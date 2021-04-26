//小括号匹配
#include<iostream>
using namespace std;
int Match(char *str) {
    char s[100];                            //定义顺序栈，假定最长有效字符为100
    int top = -1;                           //初值指针-1
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == ')') {                 //判断当前字符是否为右括号
            if(top > -1) top--;             //出栈前判断栈是否为空
            else return -1;
        } else if(str[i] == '(')            //当前字符为左括号
            s[++top] = str[i];
    }
    if(top == -1) return 0;                 //正确匹配的情况应该是栈顶指针回到初始位置top = -1;
    else return 1;
}
int main() {
    char str[100];
    int k;
    printf("please input an Arithmetic expression:\t");
    scanf("%s", str);
    k = Match(str);
    if(k == 0) printf("Right Match!\n");
    else if(k == 1) printf("Excess '(' !\n");
    else printf("excess ')' !\n");
    system("pause");
    return 0;
}