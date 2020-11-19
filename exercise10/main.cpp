#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;
bool isValid(string s) {
	if (s == "") return false;
	stack<char>result;//C++ 栈调用top()函数时栈不能为空
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ')') {
			if (!result.empty() && result.top() == '(') result.pop();
			else return false;
		}
		else if (s[i] == ']') {
			if (!result.empty() && result.top() == '[') 
                result.pop();
			else return false;
		}
		else if (s[i] == '}') {
			if (!result.empty() && result.top() == '{') result.pop();
			else return false;
		}
		else result.push(s[i]);
	}
	if (result.empty()) return true;
	else return false;
}
int main() {
	string s = "[]{}";
	cout << isValid(s) << endl;
	system("pause");
	return 0;
}