#include<iostream>
#include<vector>
using namespace std;
int n, rows, cols;
void dfs(vector<vector<int>>&board, int i, int j) {
	if (i >= 0 && i < rows&&j >= 0 && j < cols&&board[i][j] == 0) {
		board[i][j] = 2;
		dfs(board, i - 1, j);
		dfs(board, i + 1, j);
		dfs(board, i, j - 1);
		dfs(board, i, j + 1);
	}
}
void solve(vector<vector<int>>&board) {
	if (board.size() == 0 || board[0].size() == 0) return;
	rows = board.size(), cols = board[0].size();
	for (int i = 0; i < rows; i++) {
		dfs(board, i, 0);
		dfs(board, i, cols - 1);
	}
	for (int j = 1; j < cols; j++) {
		dfs(board, 0, j);
		dfs(board, rows - 1, j);
	}
/*终于看明白了，这里的标志为2是表示边缘为0 的点，就是不算孤立群体的点，
所以函数一开始的两个for循环只在边界位置巡逻。
可能就是为了DFS过程中不用重复搜索递归*/
	for (int i = 0; i < rows; i++) 
		for (int j = 0; j < cols; j++) {
			if (board[i][j] == 2)
				board[i][j] = 0;
			else board[i][j] = 1;
		}
}
int main()
{
	cin >> n;
	vector<vector<int>>num(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> num[i][j];
	solve(num);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
 			cout << num[i][j]<<' ';
		cout << endl;
	}
	system("pause");
	return 0;
}