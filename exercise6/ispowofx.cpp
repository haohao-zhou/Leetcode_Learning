//https://mp.weixin.qq.com/s?__biz=MzIzODMwOTgzNA==&mid=2247484694&idx=1&sn=b8d94270ea6c9c7f1f0a85547f9cd398&chksm=e93a1db3de4d94a566c322b4660f9100a80b0d690c7f92d9e06f86bd767f24d714f92ebfee39&cur_album_id=1448265767816151040&scene=190#rd
#include<iostream>
#include<vector>
using namespace std;
//判断一个数是否是2^m
bool ispowof2(int num) {
    int temp = num&(num - 1);
    if(!(num&(num - 1))) {//注意这里不能直接判断(num&(num - 1)==0或者false),因为这个结果是bool，可以通过！运算符控制
        return true;
    } else {
        return false;
    }
}
//判断是否为3的整数次幂：因为3是质数，可以先找出32位正整数中3的n次幂的最大值3486784401 ，然后，思路就很自然了，如下：
bool ispowof3(int num) {
    long long temp = 3486784401 ;  //注意这里保存数据需要long long型，int型范围不够
    if((temp % num) == 0) return true;
    else return false;
}
//判断是否为4的整数次幂：4的n次幂，首先必须是2的n次幂，且有4^n = (3+1)^n, 根据二项式定理可知：4^n % 3 = 1,
bool ispowof4(int num) {
    if(num & (num - 1)) {//首先要求为2的整数次幂
        return false;
    }
    if(num % 3 == 1) { //对3取余应该等于1
        return true;
    } else {
        return false;
    }
}
//判断是否为5的整数次幂，笨办法通过循环遍历实现
bool ispowof5(int num) {
    if(num == 1) 
        return true;
    while(num >= 5) {
        if(num % 5 != 0) {
            return false;
        } else {
            num /= 5;
        }
    }
    return true;
}
int main() {
    int num = 25;  //注意，1是任何数的0次幂，判断返回true；正确
    if(ispowof5(num)) {
        cout<<"Yes, it's the pow of 5"<<endl;
        }
    else {
        cout<<"No,  it isn't the pow of 5"<<endl;
        }
    system("pause");
    return 0;
}
