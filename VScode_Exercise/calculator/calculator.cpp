#include<iostream>
#include "stack.h"
#include<math.h>
#include<string.h>
using namespace std;
#define STACKSIZE 20
#define ITEMSIZE 20
#define POSTFIXSIZE 200
//�жϱ��ʽ���Ƿ��зǷ��ַ����Ϸ��ַ�����0~9 . + - * / ^ )
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
//�ӱ��ʽ��ǰλ��curPos��ȡԪ�أ���ɺ��ƶ�����һԪ�����ַ�λ��
//����������0������������1���쳣����-1
int GetItem(char *postfix, int *curPos, char *item) {
    int i = 0, k = *curPos, flag;
    if(postfix[k] == '.') { //Ԫ�����ַ�������С����
        flag = -1;
    } else if(postfix[k] >= '0' && postfix[k] <= '9') {     //Ԫ�����ַ������֣�����ȷ�Ĳ�����
        while ((postfix[k] >= '0' && postfix[k] <= '9') || postfix[k] == '.') {
            item[i++] = postfix[k++];
        }
        item[i] = '\0';     //�����ֽ�ȡΪ�ַ�����ʽ����
        flag = 0;
    } else {        //��Ԫ��Ϊ������
        item[0] = postfix[k++];
        item[1] = '\0';
        flag = 1;
    }
    while(postfix[k] == ' ') {  //������ǰԪ�غ���Ŀո�����һ��ȤԪ�ص���ʼλ��Ϊ�ǿո��ַ�
        k++;
    }
    *curPos = k;
    return flag;
}
//���ݲ�����ִ�м��㣬����������������һ��������������a+b, a���������+��������b�Ҳ�������
void DoOperator(Stack *S, char oper) {
    double oper1, oper2;
    if(!Top(S, &oper1)) {   //��ջ�е����Ҳ�����
        printf("�쳣����׺���ʽ��ʽ�������ڶ��������\n");
        exit(0);
    }
    Pop(S);
    if(!Top(S, &oper2)) {   //��ջ�е����������
        printf("�쳣����׺���ʽ��ʽ�������ڶ��������\n");
        exit(0);
    }
    Pop(S);
    switch (oper)   //���ݲ�����ִ����Ӧ����
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
        if(fabs(oper1) < 1e-6) {    //�жϷ�ĸ�Ƿ�Ϊ0
            printf("�쳣������������Ϊ0��\n");
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
//�Ժ�׺���ʽpostfix��ֵ
double Calculating(char *postfix) {
    Stack S;
    char item[ITEMSIZE];    //�����׺���ʽ�е�Ԫ��
    double data;
    int flag = -1;          //��ǵ�ǰɨ��Ԫ�ص����ͣ�1��ʾ��������0��ʾ��������-1��ʾ�쳣
    int curPos = 0;         //��¼��ǰɨ��Ԫ�����ַ��±�λ��
    while(postfix[curPos] == ' ')   //����postfixǰ�����пո�
        curPos++;
    Create(&S, STACKSIZE);  //����ջ�������ڴ�
    while (curPos < strlen(postfix))
    {
        flag = GetItem(postfix, &curPos, item);     //��ȡ��ǰɨ��ı��ʽ��Ԫ��
        if(flag == -1) {
            printf("�쳣����׺���ʽԪ�ز��Ϸ���\n");
            exit(0);
        } else if(flag == 1) {  //ִ����Ӧ�Ĳ���������
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
        } else {            //��������ջ
            data = atof(item);  //���ַ���ת��Ϊ���������
            Push(&S, data);
        }
    }
    if(S.top == 0) {    //���ջ��ֻʣ��ΨһԪ�أ���ջ��Ԫ�ؼ�Ϊ������
        Top(&S, &data);
    } else {
        printf("�쳣����׺���ʽ��ʽ�������ڶ��������\n");
        exit(0);
    }
    Destroy(&S);    //�ͷſռ�
    return data;
}
int main() {
    char postfix[POSTFIXSIZE];      //�洢���ʽ�е�ɨ��Ԫ��
    printf("�������׺���ʽ��ʽ������������֮���ÿո��������\n");
    gets(postfix);                  //��������ȡ��׺���ʽ��cmd���������ʽ����׺���ʽ��ʽ��
    if(!IsLegal(postfix)) {
        printf("�쳣����׺���ʽ���ڷǷ��ַ�\n");
    } else 
        printf("%s = %.2f\n", postfix, Calculating(postfix));   //�����������������λС��1
    system("pause");
    return 0;
}