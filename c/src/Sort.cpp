#include <iostream>
#include "Sort.h"

#define log(x) std::cerr <<"[Sort] " <<x <<std::endl;

int Sort::searchInsert(int A[], int n, int target)
{
  if( 0==n )
    return 0;
  
  int start = 0;
  int end = n-1;

  while( start<end )
  {
    int mid = (start + end)/2;

    if( A[mid]==target )
      return mid;

    if( A[mid]<target )
    {
      start = mid + 1;
    }
    else
    {
      end = mid - 1;
    }
  }
  
  if( A[start]<target )
    return start+1 ;
  else
    return start;
}
