#include "Algo.h"

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
