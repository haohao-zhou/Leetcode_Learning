
#include<iostream>
using namespace std;        //下面的反斜杠\叫做行连接，增加代码可读性
int log_flag = 1;           //控制是否打印日志的开关
//args...表示printf的参数列表，##args表示连接args参数列表
#define LOG(frm, args...) do{\  
    if(log_flag == 0) break;\
    printf("[%s : %s : %d] ", __FILE__, __func__, __LINE__);\
    printf(frm, ##args);\
    printf("\n");\
}while(0);
int main()
{
    LOG("helloC")
    printf("\n");
    cout<<"helloC"<<endl;

    system("pause");
    return 0;
}