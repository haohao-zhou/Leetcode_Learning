//N_Queen
#include<iostream>
using namespace std;
#define N 100       //����������100�ʺ�����
int x[N];           //���N�ʺ�����Ľ�
//�жϻʺ�K����x[k]���Ƿ��ͻ
int Place(int k) {
    for(int i = 0; i < k; i++) {
        if(x[i] == x[k] || abs(i - k) == abs(x[i] - x[k]))  //Υ��Լ������
            return 1;       //��ͻ������1
    }
    return 0;           //����ͻ������0
}
//��ӡN�ʺ������һ����
void PrintQueen(int n) {
    for(int i = 0; i < n; i++) {
        printf("%5d", x[i] + 1);    //�����±��0��ʼ����ӡҪ����Ŵ�1��ʼ
    }
    printf("\n");
}
//���ݷ����
void Queen(int n) {
    int k = 0, num = 0; //num�洢��ĸ���
    while (k >= 0)      //�ڷŻʺ�k��ע��0<=k<n
    {
        x[k]++;         //����һ�аڷŻʺ�k
        while (x[k] < n && Place(k) == 1 ) {    //������ͻ
            x[k]++;                 //�ʺ�K��̽��һ��
        }
        if(x[k] < n && k == n - 1) {    //�õ�һ���⣬���
            printf("��%d�����ǣ�", ++num);
            PrintQueen(n);
        } else if (x[k] < n && k < n - 1) { //���лʺ�δ�ڷ�
            k = k + 1;                      //׼���ڷ���һ���ʺ�
        } else {
            x[k--] = -1;                    //����x[k],���ݣ����°ڷ���һ���ʺ�k
        }        
    }
}
int main() {
    int i , n;
    printf("������ʺ�ĸ�����");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        x[i] = -1;
    }
    Queen(n);
    system("pause");
    return 0;
}
