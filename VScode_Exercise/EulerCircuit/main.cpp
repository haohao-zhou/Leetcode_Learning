
/*哥尼斯堡七桥问题转换为欧拉路径求解*/
#include<iostream>
using namespace std;
int EulerCircult(int mat[4][4], int n) {
    int i, j, degree, count = 0;            //count记录通往奇数桥顶点个数
    for(i = 0; i < n; i++) {
        degree = 0;
        for(j = 0; j < n; j++) {
            degree += mat[i][j];            //这里通过累加边数得出该顶点统共有多少桥连接
        }
        if(degree % 2 != 0)                 //判断是否为奇数桥
            count++;
     }
     return count;
}
int main() {
    int mat[4][4] = {{0, 1, 2, 2}, {1, 0, 1, 1}, {2, 1, 0, 0}, {2, 1, 0, 0}};
    int num = EulerCircult(mat, 4);
    if(num >= 2) 
        cout<<"有"<<num<<"个地方通奇数桥，不存在欧拉回路"<<endl;
    else 
        cout<<"存在欧拉回路，可以实现"<<endl;
    system("pause");
    return 0;
}