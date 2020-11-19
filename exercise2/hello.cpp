#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    string str;
    while(cin>>str) {
        int n = str.size();
        string temp;
        for(int i = 0; i < n; i++) {
            if(temp.find(str[i]) == temp.npos) temp = temp + str[i];
        }
        int left = 0, right = n - 1;
        //foo(str, temp, left, right);
        cout<<str<<' '<<temp<<endl;
        cout<<left<<' ' <<right - left + 1<<endl;
    }return 0;
}