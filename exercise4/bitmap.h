//bitmap的实质为把一个uint(还不是int，充分利用符号位)，存放的uint转二进制为32个01，那么1个uint可以通过不同位表达32种状态
#include <iostream>
#include <fstream>
#include<memory.h>
using namespace std;

#define BIT_INT 32   // 1个unsigned int可以标志32个QQ的存在与否
#define SHIFT 5  //原因是2^5=32
#define MASK 0x1f  //二进制为15+16=31=2^5-1
#define N 4294967296 // 2的32次方, 能覆盖到所有的QQ号码
 
unsigned int *a = NULL;

// 必须用堆 为什么？是因为栈不够大吗？
void createArr()
{  a = new unsigned int[1 + N / BIT_INT]; }
 
// 堆释放
void deleteArr()
{
  delete []a;
  a = NULL;
}
 
// 将所有位都初始化为0状态
void setAllZero()
{  memset(a, 0, (1 + N / BIT_INT) * sizeof(unsigned int)); }
 
// 设置第i位为1
void setOne(unsigned int i)
{  a[i >> SHIFT] |= (1 << (i & MASK)); }//实质为不断更新一个uint数，转二进制可以表达(4*8=)32种状态
 
// 设置第i位为0
void setZero(unsigned int i)
{  a[i >> SHIFT] &= ~(1 << (i & MASK)); }
 
// 获取第i位的值
int getState(unsigned int i)
{  return (a[i >> SHIFT] & (1 << (i & MASK))) && 1; }
 
// 用bitmap记录是否存在
void setStateFromFile()
{   //注意vscode好像需要全路径，不是VS中建立在一个工程就可以检索的那种
    ifstream cin("E:\\vscodeexercise\\exercise4\\a.txt");
    unsigned int n;
    while(cin >> n)  
    {
        setOne(n);
        //cout<<n<<endl;
    }  
}
 
// 交集
void printCommonNumber()
{
    ifstream cin("E:\\vscodeexercise\\exercise4\\b.txt");
    unsigned int n;
    while(cin >> n)  
    {
        if(1 == getState(n))
        {
          cout << n << " ";
        }
    }  
 
  cout << endl;
}
 
