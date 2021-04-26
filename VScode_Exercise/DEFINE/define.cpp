//本工程目的是验证C语言自带系统宏定义
//__DATE__, TIME, LINE, FILE, func, FUNC, PRETTY_FUNCTION
#include<iostream>
using namespace std;
int main() {
    printf("__DATE__ = %s\n", __DATE__);
    printf("__TIME__ = %s\n", __TIME__);
    printf("__LINE__ = %d\n", __LINE__);
    printf("__FILE__ = %s\n", __FILE__);
    printf("__func__ = %s\n", __func__);
    printf("__PRETTY_FUNCTION__ = %s\n", __PRETTY_FUNCTION__);
    system("pause");
    return 0;
}