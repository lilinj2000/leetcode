#include <iostream>
#include "Array.h"

#define log(x) std::cerr <<"[Array] " <<x <<std::endl;

int Array::searchInsert(int A[], int n, int target)
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

void Array::merge(int A[], int m, int B[], int n)
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

int Array::removeDuplicates(int A[], int n)
{
  if( !A || 0==n )
    return 0;
  
  int iPre = 0;
  int iPost = iPre + 1;

  while( iPost<n )
  {
    if( A[iPre]==A[iPost] )
    {
      iPost++;
    }
    else
    {
      iPre++;
      A[iPre] = A[iPost];
      
      iPost++;
    }
  }

  return iPre+1;
}

int Array::removeElement(int A[], int n, int elem)
{
  if( !A || 0==n )
    return 0;

  int iPre = -1;
  int iPost = 0;

  while( iPost<n )
  {
    if( A[iPost]==elem )
      iPost++;
    else
    {
      iPre++;
      A[iPre] = A[iPost++];
    }
  }

  return iPre+1;
}

std::vector<int> Array::plusOne(std::vector<int> &digits)
{
  if( digits.empty() )
    return digits;

  int one = 1;
  for(int i=digits.size()-1; i>=0; i--)
  {
    int digit = (digits[i]+one)%10;
    one = (digits[i]+one)/10;

    digits[i] = digit;
    if( !one )
      return digits;
  }

  digits.push_back(0);
  digits[0] = 1;

  return digits;
}