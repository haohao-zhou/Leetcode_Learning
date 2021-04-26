#include<iostream>
#include "stack.h"
#include<math.h>
#include<string.h>
using namespace std;
#define STACKSIZE 20    //定义栈的容量大小
#define ITEMSIZE 20     //表达式中元素最大长度
#define EXPSIZE 200     //表达式最大长度
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
//获取操作符的栈外优先级
int ICP(char c) {
    if(c == '#') {
        return 0;
    } else if(c == '(') {
        return 7;
    } else if(c == '*' || c == '/') {
        return 4;
    } else if(c == '+' || c == '-') {
        return 2;
    } else if(c == ')') {
        return 1;
    } else {
        printf("%c!\n", c); //后缀表达式不支持操作符
        exit(-1);
    }
}
//获取操作符的栈内优先级
int ISP(char c) {
    if(c == '#') {
        return 0;
    } else if(c == '(') {
        return 1;
    } else if(c == '*' || c == '/') {
        return 5;
    } else if(c == '+' || c == '-') {
        return 3;
    } else if(c == ')') {
        return 7;
    } else {
        printf("后缀表达式不支持操作符%c!\n", c);   //后缀表达式不支持操作符
        exit(-1);
    }
}
//将中缀表达式infix转换为后缀表达式postfix，后缀表达式中的相邻元素（操作符或操作数）用空格分开
void InfixToPostfix(char *infix, char *postfix) {
    Stack S;
    char item[ITEMSIZE];    //存储中缀表达式的元素，通过字符数组形式，C++中可以通过String类型，相同道理
    int flag = -1;          //标记当前扫描元素类型，1操作符，0操作数，-1异常
    int curPos = 0;         //记录当前扫描元素首字符下标位置
    int k = 0, i;
    char ch, curOP;
    while(infix[curPos] == ' ')     //过滤infix前面所有空格
        curPos++;
    Create(&S, STACKSIZE);          //创建栈，申请内存空间
    Push(&S, '#');
    while(curPos < strlen(infix)) {
        flag = GetItem(infix, &curPos, item);   //获取当前扫描表达式的元素
        if(flag == -1) {
            printf("异常：中缀表达式元素不合法！\n");   //异常：中缀表达式元素不合法！
            exit(-1);
        } else if(flag == 1) {      //当前元素为操作符或界符
            curOP = item[0];        //curOP是当前操作符，只有一个字符表示就够了
            if(curOP == ')') {      //扫描到右括号的时候进行出栈操作，实现括号闭合，直到遇到左括号
                do {
                    Top(&S, &ch);
                    Pop(&S);
                    if(ch == '#') {
                        printf("异常：中缀表达式元素不合法！\n");   //异常：中缀表达式元素不合法！
                        exit(-1);
                    }
                    if(ch != '(') {         //左括号不输出
                        postfix[k++] = ch;
                        postfix[k++] = ' '; //相邻元素用空格分开
                    }
                } while (ch != '(');
            } else {                        //扫描到其他操作符时候的处理
                Top(&S, &ch);               //获取当前栈顶操作符
                while (ICP(curOP) <= ISP(ch))
                {
                    Pop(&S);
                    postfix[k++] = ch;
                    postfix[k++] = ' ';     //相邻元素空格分开
                    Top(&S, &ch);
                }
                Push(&S, curOP);            //当前扫描到的操作符进栈
            }
        } else {                            //当前扫描到的是操作数，不做处理直接输出
            for(i = 0; i < strlen(item); i++, k++) {
                postfix[k] = item[i];
            }
            postfix[k++] = ' ';             //相邻元素空格分开
        }
    }
    while (!IsEmpty(&S))                    //输出栈中剩余操作符
    {
        Top(&S, &ch);
        Pop(&S);
        if(ch != '#') {
            postfix[k++] = ch;
            postfix[k++] = ' ';
        }
    }
    postfix[--k] = '\0';                    //去除最后多余空格
}
int main() {
    char infix[EXPSIZE];                    //存储中缀表达式
    char postfix[EXPSIZE];                  //存储后缀表达式
    printf("请输入中缀表达式：%s\n", infix);  //请输入中缀表达式：
    gets(infix);
    if(!IsLegal(infix)) {
        printf("异常：中缀表达式存在非法字符\n");      //异常：中缀表达式存在非法字符
        return -1;
    } else {
        InfixToPostfix(infix, postfix);
        printf("%s ===> %s\n", infix, postfix);     //输出转换后的后缀表达式
    }
    system("pause");
    return 0;
}