#include<iostream>
#include "stack.h"
#include<math.h>
#include<string.h>
using namespace std;
#define STACKSIZE 20    //����ջ��������С
#define ITEMSIZE 20     //���ʽ��Ԫ����󳤶�
#define EXPSIZE 200     //���ʽ��󳤶�
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
//��ȡ��������ջ�����ȼ�
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
        printf("%c!\n", c); //��׺���ʽ��֧�ֲ�����
        exit(-1);
    }
}
//��ȡ��������ջ�����ȼ�
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
        printf("��׺���ʽ��֧�ֲ�����%c!\n", c);   //��׺���ʽ��֧�ֲ�����
        exit(-1);
    }
}
//����׺���ʽinfixת��Ϊ��׺���ʽpostfix����׺���ʽ�е�����Ԫ�أ�����������������ÿո�ֿ�
void InfixToPostfix(char *infix, char *postfix) {
    Stack S;
    char item[ITEMSIZE];    //�洢��׺���ʽ��Ԫ�أ�ͨ���ַ�������ʽ��C++�п���ͨ��String���ͣ���ͬ����
    int flag = -1;          //��ǵ�ǰɨ��Ԫ�����ͣ�1��������0��������-1�쳣
    int curPos = 0;         //��¼��ǰɨ��Ԫ�����ַ��±�λ��
    int k = 0, i;
    char ch, curOP;
    while(infix[curPos] == ' ')     //����infixǰ�����пո�
        curPos++;
    Create(&S, STACKSIZE);          //����ջ�������ڴ�ռ�
    Push(&S, '#');
    while(curPos < strlen(infix)) {
        flag = GetItem(infix, &curPos, item);   //��ȡ��ǰɨ����ʽ��Ԫ��
        if(flag == -1) {
            printf("�쳣����׺���ʽԪ�ز��Ϸ���\n");   //�쳣����׺���ʽԪ�ز��Ϸ���
            exit(-1);
        } else if(flag == 1) {      //��ǰԪ��Ϊ����������
            curOP = item[0];        //curOP�ǵ�ǰ��������ֻ��һ���ַ���ʾ�͹���
            if(curOP == ')') {      //ɨ�赽�����ŵ�ʱ����г�ջ������ʵ�����űպϣ�ֱ������������
                do {
                    Top(&S, &ch);
                    Pop(&S);
                    if(ch == '#') {
                        printf("�쳣����׺���ʽԪ�ز��Ϸ���\n");   //�쳣����׺���ʽԪ�ز��Ϸ���
                        exit(-1);
                    }
                    if(ch != '(') {         //�����Ų����
                        postfix[k++] = ch;
                        postfix[k++] = ' '; //����Ԫ���ÿո�ֿ�
                    }
                } while (ch != '(');
            } else {                        //ɨ�赽����������ʱ��Ĵ���
                Top(&S, &ch);               //��ȡ��ǰջ��������
                while (ICP(curOP) <= ISP(ch))
                {
                    Pop(&S);
                    postfix[k++] = ch;
                    postfix[k++] = ' ';     //����Ԫ�ؿո�ֿ�
                    Top(&S, &ch);
                }
                Push(&S, curOP);            //��ǰɨ�赽�Ĳ�������ջ
            }
        } else {                            //��ǰɨ�赽���ǲ���������������ֱ�����
            for(i = 0; i < strlen(item); i++, k++) {
                postfix[k] = item[i];
            }
            postfix[k++] = ' ';             //����Ԫ�ؿո�ֿ�
        }
    }
    while (!IsEmpty(&S))                    //���ջ��ʣ�������
    {
        Top(&S, &ch);
        Pop(&S);
        if(ch != '#') {
            postfix[k++] = ch;
            postfix[k++] = ' ';
        }
    }
    postfix[--k] = '\0';                    //ȥ��������ո�
}
int main() {
    char infix[EXPSIZE];                    //�洢��׺���ʽ
    char postfix[EXPSIZE];                  //�洢��׺���ʽ
    printf("��������׺���ʽ��%s\n", infix);  //��������׺���ʽ��
    gets(infix);
    if(!IsLegal(infix)) {
        printf("�쳣����׺���ʽ���ڷǷ��ַ�\n");      //�쳣����׺���ʽ���ڷǷ��ַ�
        return -1;
    } else {
        InfixToPostfix(infix, postfix);
        printf("%s ===> %s\n", infix, postfix);     //���ת����ĺ�׺���ʽ
    }
    system("pause");
    return 0;
}