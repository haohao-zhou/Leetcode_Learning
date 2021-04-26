//在有序表中插入元素，插入后数组依然有序
#include<iostream>
using namespace std;
int main() {
    int a[11] = {1,2,3,4,5,6,7,8,9,10};
    int insert = 0;
    scanf("%d", &insert);
    if(insert > a[9]) {
        a[10] = insert;
    } else {
        for(int i = 0; i < 11; i++) {
            if(insert > a[i]) 
            continue;
            else {      //将insert的值指向a[i]位置，i~10顺序后移
                int temp = a[i];
                for(int j = 10; j > i; j--) a[j] = a[j - 1];
                a[i] = insert;
                break;
            }
        }
    }
    for(int i = 0; i < 11; i++) cout<<a[i]<<endl;    
    system("pause");
    return 0;
}
