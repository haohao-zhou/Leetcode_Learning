//题目背景：https://mp.weixin.qq.com/s?__biz=MzIzODMwOTgzNA==&mid=2247484551&idx=1&sn=a033805b5bb1113d9f2763515f4319b2&chksm=e93a1c22de4d95348badc6d334590b90f8fa13f2ada0a31dc954a5072493d452e10f316f6fb9&scene=178&cur_album_id=1448265767816151040#rd
//求解两个集合中相同的元素,可能是腾讯的题，两个集合可能是亿级大小
#include<iostream>
#include<vector>
#include "bitmap.h"
using namespace std;

//方法一：暴力求解，for循环;时间复杂度 O(MN)
void find(vector<int>& a, vector<int>& b) {
    for(int i = 0; i < a.size(); i++) 
        for(int j = 0; j < b.size(); j++)
            if(a[i] == b[j]) cout<<a[i]<<endl;
    return;
}
//方法二：用哈希表进行改进，hash[x]=x, 即在下标x处存x的值; 时间复杂度 O(M),M是M,N中最大的数
void hashmap(vector<int>& a, vector<int>& b) {
    int hash[10] = {0};
    for(int i = 0; i < a.size(); i++)
        hash[a[i]] = a[i];
    for(int i = 0; i < b.size(); i++) 
        if(hash[b[i]] == b[i]) 
            cout<<b[i]<<endl;
    return;
}
//方法三：flag表(类似于hashmap); 时间复杂度 O(M)，M是M,N中最大的数
void flagmap(vector<int>& a, vector<int>& b) {
    int hash[10] = {0};
    for(int i = 0; i < a.size(); i++)
        hash[a[i]]++;
    for(int i = 0; i < b.size(); i++) 
        if(hash[b[i]]) 
            cout<<b[i]<<endl;
    return ;
}
//方法四：见bitmap.h

int main() {
    vector<int>a = {0,1,2,3,4};
    vector<int>b = {0,1,3,4,5};
    //find(a, b);
    //hashmap(a, b);
    //flagmap(a, b);
    createArr();
    setAllZero();
 
  // a.txt: 4 5 7 2 9 2 4 8 0 11   (a.txt中可以有40亿个无符号整数)
  // b.txt: 6 11 0 2 3             (b.txt中可以有40万个无符号整数)
 
    setStateFromFile();
    printCommonNumber(); // 交集是：11 0 2
    deleteArr();

    system("pause");
    return 0;
}
