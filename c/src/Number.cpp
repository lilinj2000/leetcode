#include <iostream>
#include <limits>
#include "Number.h"

#define log(x) std::cerr <<"[Number] " <<x <<std::endl;

bool Number::isPalindrome(int x)
{
  if( x<0 )
    return false;

  int div = 1;
  while( x/div>=10 )
  {
    div *= 10;
  }

  while( x!=0 )
  {
    int l = x/div;
    int r = x%10;

    if( l!=r )
      return false;

    x = (x%div)/10;

    div /= 100;
  }
  
  return true;
}

int Number::reverse(int x)
{
  int int_max = std::numeric_limits<int>::max();
  int int_min = std::numeric_limits<int>::min();
  
  int result = 0;
  while( x!=0 )
  {
    if( result<int_min/10
        || int_max/10<result )
      return 0;
    
    result = result*10 + x%10;
    x = x/10;
  }

  return result;
}

std::vector<std::vector<int> > Number::genPascalTriangle(int numRows)
{
  std::vector<std::vector<int> > result;

  if( numRows<=0 )
    return result;

  std::vector<int> first;
  first.push_back(1);
  result.push_back(first);

  for(int i=1; i<numRows; i++)
  {
    std::vector<int> cur;
    cur.push_back(1);
    
    for(unsigned j=1; j<result[i-1].size(); j++)
    {
      cur.push_back(result[i-1][j-1] + result[i-1][j]);
    }
    cur.push_back(1);

    result.push_back(cur);
  }

  return result;
}

std::vector<int> Number::getRowPascalTriangle(int rowIndex)
{
  std::vector<int> result;

  if( rowIndex<0 )
    return result;

  result.push_back(1);

  for(int i=1; i<rowIndex+1; i++)
  {
    std::vector<int> cur;
    cur.push_back(1);
    
    for(unsigned j=1; j<result.size(); j++)
    {
      cur.push_back(result[j-1] + result[j]);
    }
    cur.push_back(1);
    
    result = cur;
  }

  return result;
}
