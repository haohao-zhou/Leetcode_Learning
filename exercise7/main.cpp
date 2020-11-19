//这个问题较麻烦https://mp.weixin.qq.com/s?__biz=MzIzODMwOTgzNA==&mid=2247484732&idx=1&sn=aab6f58e2a9454b892a6235fffa4f156&chksm=e93a1d99de4d948fe05c7d666548520ff4972f6cd2af4503c902febfc29e376f3d734216d380&cur_album_id=1448265767816151040&scene=190#rd
//有时间看
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int multi(char a, char b)
{  return (a - '0') * (b - '0'); }
 
void strMulti(char *a, char *b, char *c)
{
  int lenA = strlen(a);
  int lenB = strlen(b);
  int maxLen = lenA + lenB;
  int *p = new int[maxLen];
  memset(p, 0, maxLen * sizeof(int)); 
  
  int i = 0;
  int j = 0;
  for(j = lenB - 1; j >= 0; j--)
  {
    for(i = lenA - 1; i >= 0; i--)
    {
      p[j + i + 1] += multi(b[j], a[i]);
    }
  }
 
  // 处理进位操作
  for(i = maxLen - 1; i >= 1; i--)
  {
    p[i - 1] += p[i] / 10;
    p[i] = p[i] % 10;
  }
 
  int *s = p;
 
  // m位正整数和n位正整数相乘，结果的位数必然是(m+n-1)位或者(m+n)位
  if(0 == p[0])
  {
    p++;
  }
  
  int *pTmp = NULL;
  for(pTmp = p; pTmp < s + maxLen; pTmp++)
  {
    *c++ = *pTmp + '0';
  }
 
  *c = '\0';
  delete s;
}
 
void factorial(int n, char *str)
{
  int i = 0;
  *str = '1';
  *(str + 1) = '\0';
  char b[5000] = {0};
  for(i = 1; i <= n; i++)
  {
    snprintf(b, sizeof(b), "%d", i);
    strMulti(str, b, str);
  }
}
 
int main()
{
  char str[5000] = {0};
  factorial(1000, str); 
  cout << str << endl << endl;
  return 0;
}