#include<iostream>
#include<string>
#include<stack>
using namespace std;

int tryGetOps(char c) {
		int code = 0;
		switch (c) {
		case '+':code = 1; break;
		case '-':code = 2; break;
		case '*':code = 3; break;
		case '/':code = 4; break;
		}
		return code;
	}
int calculate(string s) {
	stack<int>stack;
	int index = 0;
	while (index < s.length()) {
		while (index < s.length() && s[index] == ' ') ++index;
		if (index >= s.length()) break;
		int code = tryGetOps(s[index]);
		if (code != 0) {
			++index;
			while (index < s.length() && s[index] == ' ') ++index;
		}
		int num = 0;
		while (index < s.length() && s[index] >= '0' && s[index] <= '9') {
			num = num * 10 + (s[index] - '0');
			++index;
		}
		if (code == 3 || code == 4) {
			int prev = stack.top();
			stack.pop();
			if (code == 3) num = prev * num;
			else num = prev / num;
		}
		else if (code == 2) {
			num = -num;
		}
		stack.push(num);
	}
	int res = 0;
	while (!stack.empty()) {
		res += stack.top();
		stack.pop();
	}
	return res;
}
int main()
{
	string str;
	cin >> str; cout << endl;
	cout << calculate(str) << endl;
	system("pause");
	return 0;
}