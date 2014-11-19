#include <algorithm>
#include <cassert>
#include <iostream>

#include "Algo.h"

#define log(x) std::cerr <<"[Alog] " <<x <<std::endl;
int Algo::climbStairs(int n)
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

bool Algo::isValidSudoku(std::vector<std::vector<char> > &board)
{
  if( board.size()!=9 )
    return false;

  for(unsigned i=0; i<board.size(); i++)
  {
    if( board[i].size()!=9 )
      return false;
  }
  
  std::vector<std::vector<bool> > rows(9, std::vector<bool>(9, false));
  std::vector<std::vector<bool> > cols(9, std::vector<bool>(9, false));
  std::vector<std::vector<bool> > blocks(9, std::vector<bool>(9, false));

  for(int i=0; i<9; i++)
  {
    for(int j=0; j<9; j++)
    {
      if( board[i][j]=='.' )
        continue;

      int c = board[i][j]-'1';
      if( rows[i][c] || cols[j][c] || blocks[i-i%3 + j/3][c] )
        return false;

      rows[i][c] = cols[j][c] = blocks[i-i%3+j/3][c] = true;
    }
  }

  return true;
}

std::vector<std::vector<int> > Algo::subsets(std::vector<int> &s)
{
  std::vector<std::vector<int> > res;
  res.push_back( std::vector<int>() );

  std::sort(s.begin(), s.end());
  
  for(unsigned i=0; i<s.size(); i++)
  {
    unsigned len = res.size();
    for(unsigned j=0; j<len; j++)
    {
      std::vector<int> subset = res[j];
      subset.push_back(s[i]);

      res.push_back(subset);
    }
  }

  return res;
}

std::vector<std::vector<int> > Algo::twosum(std::vector<int> &num, int len, int target)
{
  assert( len<=num.size() );

  std::sort(num.begin(), num.begin()+len);
  
  std::vector<std::vector<int> > res;

  if( len<2 )
    return res;

  
  int begin = 0;
  int end = len - 1;

  while( begin<end )
  {
    int sum = num[begin] + num[end];
    if( sum==target )
    {
      std::vector<int> item;
      item.push_back(num[begin]);
      item.push_back(num[end]);
      res.push_back(item);
      
      begin++;
      end--;

      while(begin<end && num[begin]==num[begin-1])
        begin++;

      while(begin<end && num[end]==num[end+1])
        end--;
    }
    else if( sum>target )
    {
      end--;
    }
    else
    {
      begin++;
    }
  }

  return res;
}

std::vector<std::vector<int> > Algo::threesum(std::vector<int> &num, int target)
{
  std::vector<std::vector<int> > res;

  if( num.size()<3 )
    return res;

  std::sort(num.begin(), num.end());

  for(unsigned i=num.size()-1; i>=2; i--)
  {

    if( i<num.size()-1 && num[i]==num[i+1] )
      continue;
           
    int twoTarget = target - num[i];

    std::vector<std::vector<int> > twoRes = twosum(num, i, twoTarget);

    for(unsigned j=0; j<twoRes.size(); j++)
    {
      twoRes[j].push_back(num[i]);

      res.push_back(twoRes[j]);
    }
  }

  return res;
}
