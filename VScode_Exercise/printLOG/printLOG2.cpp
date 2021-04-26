
#include<iostream>
using namespace std;        //下面的反斜杠\叫做行连接，增加代码可读性
//通过条件编译控制知否打印日志信息，还可以通过命令行g++ -DDEBUG printLOG2.cpp确保
//执行的是DEBUG版本，即使下面一行#define DEBUG未进行宏定义也可以执行该版本
#define DEBUG
#ifdef DEBUG
//args...表示printf的参数列表，##args表示连接args参数列表
#define LOG(frm, args...) {\
    printf("[%s : %s : %d] ", __FILE__, __func__, __LINE__);\
    printf(frm, ##args);\
    printf("\n");\
};
#else

#define LOG(frm, args...)

#endif

int main()
{
    LOG("helloWorld")
    printf("\n");
    cout<<"helloC"<<endl;

    system("pause");
    return 0;
}