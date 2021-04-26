//斐波那契数列，青蛙跳台问题，经典递归方法求解，但是在n==1000时求解非常困难，可以借助数学方法，推导通项公式，然后求解
//https://mp.weixin.qq.com/s?__biz=MzIzODMwOTgzNA==&mid=2247484865&idx=1&sn=b462b4d083ae4c129a1cbd9528c1f711&chksm=e93a1d64de4d9472607afb7cefe021fc8297100f60fc5453aa8de2f119e5445cb4318f38d958&cur_album_id=1448265767816151040&scene=189#rd
#include<iostream>
#include<vector>
using namespace std;
int func(int num) {
    if(num == 1 || num == 2) {
        return num;
    }
    return func(num - 1) + func(num - 2);
}
int main() {
    int num = 10;
    cout<<func(num)<<endl;
    system("pause");
    return 0;
}