//N_Queen
#include<iostream>
using namespace std;
#define N 100       //定义最多求解100皇后问题
int x[N];           //存放N皇后问题的解
//判断皇后K放在x[k]列是否冲突
int Place(int k) {
    for(int i = 0; i < k; i++) {
        if(x[i] == x[k] || abs(i - k) == abs(x[i] - x[k]))  //违反约束条件
            return 1;       //冲突，返回1
    }
    return 0;           //不冲突，返回0
}
//打印N皇后问题的一个解
void PrintQueen(int n) {
    for(int i = 0; i < n; i++) {
        printf("%5d", x[i] + 1);    //数组下标从0开始，打印要求序号从1开始
    }
    printf("\n");
}
//回溯法求解
void Queen(int n) {
    int k = 0, num = 0; //num存储解的个数
    while (k >= 0)      //摆放皇后k，注意0<=k<n
    {
        x[k]++;         //在下一列摆放皇后k
        while (x[k] < n && Place(k) == 1 ) {    //发生冲突
            x[k]++;                 //皇后K试探下一列
        }
        if(x[k] < n && k == n - 1) {    //得到一个解，输出
            printf("第%d个解是：", ++num);
            PrintQueen(n);
        } else if (x[k] < n && k < n - 1) { //尚有皇后未摆放
            k = k + 1;                      //准备摆放下一个皇后
        } else {
            x[k--] = -1;                    //重置x[k],回溯，重新摆放下一个皇后k
        }        
    }
}
int main() {
    int i , n;
    printf("请输入皇后的个数：");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        x[i] = -1;
    }
    Queen(n);
    system("pause");
    return 0;
}
