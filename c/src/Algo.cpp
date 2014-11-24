#include <algorithm>
#include <iostream>
#include <cassert>
#include <climits>

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

std::vector<std::vector<int> > Algo::twoSum(std::vector<int> &num, int target)
{
  std::vector<std::vector<int> > res;

  if( num.size()<2 )
    return res;

  std::sort(num.begin(), num.end());

  res = twoSum(num, num.size(), target);

  return res;
}

std::vector<std::vector<int> > Algo::twoSum(std::vector<int> &num, int len, int target)
{
  assert( len<=num.size() );

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


std::vector<std::vector<int> > Algo::threeSum(std::vector<int> &num, int target)
{
  std::vector<std::vector<int> > res;

  if( num.size()<3 )
    return res;

  std::sort(num.begin(), num.end());

  res = threeSum(num, num.size(), target);

  return res;
}

std::vector<std::vector<int> > Algo::threeSum(std::vector<int> &num, int len, int target)
{
  std::vector<std::vector<int> > res;
  
  assert( len<=num.size() );

  if( len<3 )
    return res;
  
  for(unsigned i=len-1; i>=2; i--)
  {

    if( i<len-1 && num[i]==num[i+1] )
      continue;
           
    int twoTarget = target - num[i];

    std::vector<std::vector<int> > twoRes = twoSum(num, i, twoTarget);

    for(unsigned j=0; j<twoRes.size(); j++)
    {
      twoRes[j].push_back(num[i]);

      res.push_back(twoRes[j]);
    }
  }

  return res;
}

std::vector<std::vector<int> > Algo::fourSum(std::vector<int> &num, int target)
{
  std::vector<std::vector<int> > res;

  if( num.size()<4 )
    return res;

  std::sort(num.begin(), num.end());

  for(unsigned i=num.size()-1; i>=3; i--)
  {

    if( i<num.size()-1 && num[i]==num[i+1] )
      continue;
           
    int threeTarget = target - num[i];

    std::vector<std::vector<int> > threeRes = threeSum(num, i, threeTarget);

    for(unsigned j=0; j<threeRes.size(); j++)
    {
      threeRes[j].push_back(num[i]);

      res.push_back(threeRes[j]);
    }
  }

  return res;

}

int Algo::maxProfit(std::vector<int> &prices)
{
  int max_profit = 0;
  int lowest_price = INT_MAX;

  for(unsigned i=0; i<prices.size(); i++)
  {
    if( prices[i]<lowest_price )
    {
      lowest_price = prices[i];
    }
    else
    {
      max_profit = std::max(max_profit, prices[i]-lowest_price);
    }
  }

  return max_profit;
}

int Algo::maxProfitII(std::vector<int> &prices)
{
  if( prices.size()<2 )
    return 0;
  
  int max_profit = 0;
  for(unsigned i=1; i<prices.size(); i++)
  {
    int profit = prices[i]-prices[i-1];

    if( profit>0 )
    {
      max_profit += profit;
    }
  }

  return max_profit;
}

int Algo::minimumTotal(std::vector<std::vector<int> > &triangle)
{
  if( triangle.empty() )
    return 0;
  
  std::vector<int> buf;
  buf.resize(triangle.size());

  for(int i=triangle.size()-1; i>=0; i--)
  {
    assert( i+1==triangle[i].size() );
    
    for(int j=0; j<triangle[i].size(); j++)
    {
      if( i==triangle.size()-1 )
      {
        buf[j] = triangle[i][j];
      }
      else
      {
        buf[j] = std::min(buf[j], buf[j+1]) +triangle[i][j];
      }
    }
  }

  return buf[0];
}

int Algo::threeSumClosest(std::vector<int> &num, int target)
{
  if( num.size()<3 )
    return 0;

  std::sort(num.begin(), num.end());

  int closest = INT_MAX;

  for( int n = num.size()-1; n>=2; n--)
  {
    int closeTarget = target - num[n];

    int i = 0;
    int j = n-1;

    while( i<j )
    {
      int twoSum = num[i] + num[j];
    
      if( twoSum == closeTarget )
        return target;

      int diff = twoSum - closeTarget;
      if( std::abs(diff)<std::abs(closest) )
      {
        closest = diff;
      }
      
      if( twoSum<closeTarget )
      {
        i++;
      }
      else
      {
        j--;
      }
    }
  }

  return target+closest;
}

bool Algo::find(std::vector<std::vector<char> > board, int i, int j, std::string & word, int idx)
{
  if( idx==word.size() )
    return true;

  if( 0<=i && i<board.size()
      && 0<=j && j<board[i].size()
      && board[i][j]==word[idx] )
  {
    // log( "[" <<i <<"," <<j <<"] " <<board[i][j]);
    board[i][j] = '#';
    idx++;

    return find(board, i+1, j, word, idx)
        || find(board, i-1, j, word, idx)
        || find(board, i, j+1, word, idx)
        || find(board, i, j-1, word, idx) ;
  }

  return false;
}

bool Algo::exist(std::vector<std::vector<char> > &board, std::string word)
{
  if( word.empty() || board.empty() )
    return false;

  for(unsigned i=0; i<board.size(); i++)
  {
    for(unsigned j=0; j<board[i].size(); j++)
    {
      if( board[i][j]==word[0] )
      {
        std::vector<std::vector<char> > tmpBoard(board);
        if( find(tmpBoard, i, j, word, 0) )
        {
          return true;
        }
      }
    }
  }

  return false;
}
