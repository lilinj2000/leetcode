#include <iostream>
#include <stack>
#include <cstdlib>
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

int Array::findMin(std::vector<int> &num)
{
  if( num.empty() )
    return 0;

  if( num.size()<2 )
    return num[0];

  int low = 0;
  int high = num.size()-1;

  while( low<high )
  {
    int mid = (low+high)/2;

    if( num[low]<=num[mid] && num[mid]<=num[high] )
      return num[low];

    if( low+1==high )
      return num[high];

    if( num[mid]<=num[high] )
    {
      high = mid;
    }
    else
    {
      low = mid;
    }
  }

  return 0;
}

int Array::evalRPN(std::vector<std::string> &tokens)
{
  
  std::stack<int> theStack;
  
  for(unsigned i=0; i<tokens.size(); i++)
  {
    if( tokens[i]=="+" || tokens[i]=="-"
        || tokens[i]=="*" || tokens[i]=="/" )
    {
      int rightValue = 0;
      if( !theStack.empty() )
      {
        rightValue = theStack.top();
        theStack.pop();
      }
    
      int leftValue = 0;
      if( !theStack.empty() )
      {
        leftValue = theStack.top();
        theStack.pop();
      }

      if( tokens[i]=="+" )
        theStack.push( leftValue + rightValue );
      else if( tokens[i]=="-" )
        theStack.push( leftValue - rightValue );
      else if( tokens[i]=="*" )
        theStack.push( leftValue * rightValue );
      else if( tokens[i]=="/" )
      {
        if( rightValue!=0 )
          theStack.push( leftValue / rightValue );
      }
    }
    else
    {
      theStack.push( std::atoi(tokens[i].data()) );
    }

    log( "the top value is " <<theStack.top() );
  }

  if( theStack.empty() )
    return 0;
  else
    return theStack.top();

}
