#include<iostream>
#include <bitset>
#define INT_SIZE sizeof(int)
#define INT_BITS INT_SIZE * 8 - 1
#include<cmath>
using namespace std;

unsigned left_rotate( unsigned u )
{
  constexpr unsigned Bits = sizeof(u) * 8;

  if ( u == 0) return u;

  unsigned mask = 1 << (Bits-1); // mask has only the MSB set


  while ( (mask & u) == 0) // find the leading '1'
    mask >>= 1;

  u ^= mask;  // remove leading one
  u <<= 1; // left shift
  u |= 1; // put the removed one as LSB

  return u;
}

int main(){
    int n;
    scanf("%d",&n);
    int r = left_rotate(n);
    cout<<"Person surviving: "<<r;
    return 0;
}

