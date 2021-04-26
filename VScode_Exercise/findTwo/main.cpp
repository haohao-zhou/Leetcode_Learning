#include<iostream>
using namespace std;
int count_cnt_v1(int x) {       //版本一，需要循环32次
    int cnt = 0;
    for(int i = 0; i < 32; i++) {
        if(x & (1 << i)) 
            cnt++;
    }
    return cnt;
}
int count_cnt_v2(int x) {       //版本二，最多运行32次，平均16次
    int cnt = 0;
    while (x)
    {
        x = x & (x - 1);
        cnt++;
    }
    return cnt;
}
int count_cnt_v3(int x) {       //版本三，分组统计法，运行8次
    int cnt = 0;
    //4位二进制0~15，开一个数组16大小，
    int arr_cnt[16] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};
    for(int i = 0; i < 8; i++) {
        cnt += arr_cnt[(x >> (i * 4)) & 0xf];
    }
    return cnt;
}
int count_cnt_v4(int x) {       //版本四，把数组转换为字符串
    int cnt = 0;
    for(int i = 0; i < 8; i++) {
        cnt += "\0\1\1\2\1\2\2\3\1\2\2\3\2\3\3\4"[(x >> (i * 4)) & 0xf];
    }
    return cnt;
}
int count_cnt_v5(int x) {       //二进制分组统计法
    int cnt = 0;
    x = (x & 0x55555555) + ((x & 0xAAAAAAAA) >> 1);
    x = (x & 0x33333333) + ((x & 0xCCCCCCCC) >> 2);
    x = (x & 0x0F0F0F0F) + ((x & 0xF0F0F0F0) >> 4);
    x = (x & 0x00FF00FF) + ((x & 0xFF00FF00) >> 8);
    x = (x & 0x0000FFFF) + ((x & 0xFFFF0000) >> 16);
    return x;
}
int main() {
    int n;
    cin>>n;
    cout<<count_cnt_v1(n)<<endl;
    cout<<count_cnt_v2(n)<<endl;
    cout<<count_cnt_v3(n)<<endl;
    cout<<count_cnt_v4(n)<<endl;
    cout<<count_cnt_v5(n)<<endl;
    system("pause");
    return 0;
}