//发纸牌
#include<iostream>
#include<string.h>
#include<time.h>
using namespace std;
char *str1[4] = {"梅花", "黑桃", "红桃", "方块"};   //全局变量存储花色和点数
char *str2[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
char *card[13];             //全局变量存储随机产生的纸牌，假设最多发13张纸牌
//发牌函数
void SendCards(int n) {
    int i, j, k, sign[4][13] = {0};     //初始化数组标志，所有牌均未发出
    srand(time(NULL));
    for(int k = 0; k < n;) {
        i = rand() % 4;         //随机产生花色，一共有4种
        j = rand() % 13;        //随机产生点数，一共有13种
        if(sign[i][j] == 1) {   //表示该牌已经发出
            continue;
        } else {
            card[k] = (char *) malloc(6);
            strcpy(card[k], str1[i]);   //字符串复制函数
            strcat(card[k], str2[j]);   //字符串连接函数
            sign[i][j] = 1;             //标记已经发出该牌
            k++;
        }
    }
}
//打印当前牌面
void PrintCards(int n) {
    for(int k = 0; k < n; k++) {
        printf("%-10s", card[k]);   //字符串控制符
    }
    printf("\n");
}
//主函数
int main() {
    int n;
    printf("Please Input the Number of Your Cards: ");
    scanf("%d", &n);
    SendCards(n);
    PrintCards(n);
    system("pause");
    return 0;
}