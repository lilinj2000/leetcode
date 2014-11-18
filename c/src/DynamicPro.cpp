#include "DynamicPro.h"

int DynamicPro::climbStairs(int n)
{
  int f1 = 1;
  int f2 = 2;

  if( 1==n ) return f1;
  if( 2==n ) return f2;
  
  for(int i=3; i<=n; i++)
  {
    int f3 = f1 + f2;
    f1 = f2;
    f2 = f3;
  }

  return f2;
}
