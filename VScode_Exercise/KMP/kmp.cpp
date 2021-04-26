/*
KMP 模板匹配问题，用于求解字符串匹配问题
*/
#include<stdio.h>
#include<iostream>
#include<string>
using namespace std ;
const int maxn = 1e6+5;
int main()
{
	string str1, str2;
	cin >> str1 >> str2; //输入两个字符串，在str1中寻找str2字符串所在位置，标号从0开始
	int len1 = str1.size(), 
        len2 = str2.size();
	int i = 0, j = 0;
	while(i < len1)
	{
		if(j == -1 || str1[i] == str2[j]) {
			i++;
            j++;
		}
		else j = -1;
		if(j == len2){
			cout << i - len2 + 1 << endl; //输出str2首字母在str1的第几个字母重合
			break;
		}
	}

	cout << -1 << endl;
    system("pause");
	return 0;
}