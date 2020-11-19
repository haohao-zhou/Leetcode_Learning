//寻找数组中的“孤单数”或者出现“奇数次的数字”，
//题目来源https://mp.weixin.qq.com/s?__biz=MzIzODMwOTgzNA==&mid=2247484618&idx=1&sn=4a4a81b7185c9997ecf6991e48e7ebe1&chksm=e93a1c6fde4d95799b21b27b315449d76266a21a96dfa6fb166611d4222083765bf31caeacfd&cur_album_id=1448265767816151040&scene=189#rd
//这里面解释的更全一些：https://www.cnblogs.com/youxin/p/3349834.html
#include<iostream>
#include<vector>
#include "findfirst1.h"
using namespace std;
/* 可以看出，a和b异或的结果如下(异或符号是^)：（异或运算的性质）
      1. 当a不等于b, a^b不为0；
      2. 当a=b, a^b为0；
      3. 当b=0, a^b为a.
      4. a^b^b = a对一个数异或两次等于没有异或*/
//情景一：数组中只有一个数字出现一次，其他都出现偶数次:那么异或运算到最后就是只出现一次的数
void findone() {
    vector<int>num = {0,20,3,3,4,5,6,4,5,6};
    int temp = num[0];
    for(int i = 1; i < num.size(); i++) {
        temp ^= num[i];
    }
    cout<<"only once: "<<temp<<endl;
}
//情景二：有两个数字只出现一次，其他出现偶数次：那么异或运算结果不为0，结果转二进制，从低位寻找1，假设在第二位(1010),
//那么将原始数据按照第二位是1还是0划分为两组，分别异或，得到的两个结果就是只出现一次的两个数字
void findtwo() {
    vector<int>num = {10,20,3,3,4,5,6,4,5,6};
    int temp = num[0];
    for(int i = 1; i < num.size(); i++) {//计算异或结果
        temp ^= num[i];
    }
    int indexbit = FindFirstBitIs1(temp);
    cout<<"the first bit1 in temp is located in : "<<FindFirstBitIs1(temp)<<endl;
    int num1 = 0, num2 = 0;
    for(int i = 0; i < num.size(); i++) {
        if((num[i] >> indexbit) & 1) num1 ^= num[i];
        else num2 ^= num[i];
    }
    cout<<"the number only appeared once is: "<<num1<<' '<<num2<<endl;
}
int main() {
    
    //findone();
    findtwo();
    system("pause");
    return 0;
}



