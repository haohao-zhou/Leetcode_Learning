//��ֽ��
#include<iostream>
#include<string.h>
#include<time.h>
using namespace std;
char *str1[4] = {"÷��", "����", "����", "����"};   //ȫ�ֱ����洢��ɫ�͵���
char *str2[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
char *card[13];             //ȫ�ֱ����洢���������ֽ�ƣ�������෢13��ֽ��
//���ƺ���
void SendCards(int n) {
    int i, j, k, sign[4][13] = {0};     //��ʼ�������־�������ƾ�δ����
    srand(time(NULL));
    for(int k = 0; k < n;) {
        i = rand() % 4;         //���������ɫ��һ����4��
        j = rand() % 13;        //�������������һ����13��
        if(sign[i][j] == 1) {   //��ʾ�����Ѿ�����
            continue;
        } else {
            card[k] = (char *) malloc(6);
            strcpy(card[k], str1[i]);   //�ַ������ƺ���
            strcat(card[k], str2[j]);   //�ַ������Ӻ���
            sign[i][j] = 1;             //����Ѿ���������
            k++;
        }
    }
}
//��ӡ��ǰ����
void PrintCards(int n) {
    for(int k = 0; k < n; k++) {
        printf("%-10s", card[k]);   //�ַ������Ʒ�
    }
    printf("\n");
}
//������
int main() {
    int n;
    printf("Please Input the Number of Your Cards: ");
    scanf("%d", &n);
    SendCards(n);
    PrintCards(n);
    system("pause");
    return 0;
}