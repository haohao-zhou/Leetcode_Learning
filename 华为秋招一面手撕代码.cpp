#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int>num(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	int signal1, signal2;
	bool sign1 = false;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (num[j] > num[i]) {
				signal1 = j;
				sign1 = true;
				break;
			}
			else {
				continue;
			}
		}
		if (sign1) {
			break;
		}
	}
	bool sign2 = false;
	//从后往前找，如果找到点后面的比前面小，则后面的小的数为右边界
	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j > i; j--) {
			if (num[j] < num[i]) {
				signal2 = j;
				sign2 = true;
				break;
			} 
			else {
				continue;
			}
		}
		if (sign2) {
			break;
		}
	}
	cout << signal1 << endl << signal2 << endl;
	cout << signal2 - signal1 + 1 << endl;
	system("pause");
	return 0;
}//周昊昊