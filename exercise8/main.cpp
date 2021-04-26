//盛水最多的容器https://www.cnblogs.com/wmx24/p/9043447.html
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
//双指针实现，是最优解法
int maxArea(vector<int>height) {
    int maxA = -1;
    int left = 0, right = height.size() - 1;
    while(left < right) {
        int area = (height[left] < height[right] ? height[left] : height[right]) * (right - left);
        maxA = maxA > area ? maxA : area;
        //若移动较大的数字，则容器底长度会变小，而盛水的最大高度不变，所以盛水体积不会变更大。因此需要移动两数中较小的数字，
        //这样若中间出现特别大的数字，则有可能提高盛水体积。然后每次移动完更新此时的最大盛水体积，直到两指针相遇。
        if(height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return maxA;
}
int main() {
    vector<int>num = {1,2,6,3,6,3,5};
    int maxA = maxArea(num);
    cout<<maxA<<endl;
    system("pause");
    return 0;
}
