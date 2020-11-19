#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int minDistance(string a, string b) {
	int lenA = a.size();
	int lenB = b.size();
	
	vector<vector<int>>dp(lenA + 1, vector<int>(lenB + 1, 0));
	for(int i = 0; i < lenA + 1; i++)
		dp[i][0] = i;
	for(int j = 0; j < lenB + 1; j++)
		dp[0][j] = j;
	for(int i = 1; i < lenA + 1; i++) {
		for(int j = 1; j < lenB + 1; j++) {
			if(a[i] == b[j]) 
				dp[i][j] = dp[i - 1][j - 1];
			else {
				dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
			}
		}
	}
	return dp[lenA][lenB];
}
int main() {
	string a = "helloc", b = "hallob";
	cout<<minDistance(a, b)<<endl;
	system("pause");
	return 0;
}