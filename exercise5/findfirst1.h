#include<iostream>
using namespace std;

unsigned int FindFirstBitIs1(int num)
{
      int indexBit = 0;
      while (((num & 1) == 0) && (indexBit < 32))
      {
            num = num >> 1;
            ++ indexBit;
      }
 
      return indexBit;
}