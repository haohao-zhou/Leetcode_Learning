#include<iostream>
using namespace std;
void quick_sort_v1(int *arr, int l, int r) {
    if(l >= r) return;
    int x = l, y = r, z = arr[l];
    while (x < y)
    {
        while (x < y && arr[y] >= z) y--;
        if(x < y) arr[x++] = arr[y];
        while (x < y && arr[x] <= z) x++;
        if(x < y) arr[y--] = arr[x];
    }
    arr[x] = z;
    quick_sort_v1(arr, l, x - 1);
    quick_sort_v1(arr, x + 1, r);
    return;
}
void quick_sort_v2(int *arr, int l, int r) {    //单边递归法优化
    while(l < r) {
        int x = l, y = r, z = arr[l];
        while (x < y)
        {
            while (x < y && arr[y] >= z) y--;
            if(x < y) arr[x++] = arr[y];
            while (x < y && arr[x] <= z) x++;
            if(x < y) arr[y--] = arr[x];
        }
        arr[x] = z;
        quick_sort_v1(arr, l, x - 1);
        l = x + 1;
    }
    return;
}
#define swap(a, b) {\
    __typeof(a) __c = a;\
    a = b, b = __c;\
}
void insert_sort(int *arr, int l, int r) {
    for(int i = l + 1; i <= r; i++) {
        int j = i;
        while(j > l && arr[j] < arr[j - 1]) {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
    return;
}
void unguarded_insert_sort(int *arr, int l, int r) {
    int ind = l;
    for(int i = l + 1; i <= r; i++) {
        if(arr[ind] > arr[i]) 
            ind = i;
    }
    while(ind > l) {
        swap(arr[ind], arr[ind - 1]);
        ind--;
    }
    for(int i = l + 2; i <= r; i++) {
        int j = i;
        while(arr[j] < arr[j - 1]) {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
    return;
}
void quick_sort_v3(int *arr, int l, int r) {    //无监督？
    while(l < r) {
        int x = l, y = r, z = arr[l];
        do {
            while(arr[x] < z) x++;
            while(arr[y] > z) y++;
            if(x <= y) {
                swap(arr[x], arr[y]);
                x++;
                y--;
            }
        } while(x <= y);
        quick_sort_v3(arr, l, y);
        l = x;
    }
    return ;
}
 
int main() {
    return 0;
}