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

void Sort::merge(int A[], int m, int B[], int n)
{
  int iA = m-1;
  int iB = n-1;
  int iCur = m+n-1;

  while( iA>=0 && iB>=0 )
  {
    A[iCur--] = A[iA]>B[iB]?A[iA--]:B[iB--];
  }

  while(iB>=0)
  {
    A[iCur--] = B[iB--];
  }
  
}
