#include <vector>

#ifndef ALGO_H
#define ALGO_H

class Algo
{
public:
  int climbStairs(int n);

  bool isValidSudoku(std::vector<std::vector<char> > &board);

  std::vector<std::vector<int> > subsets(std::vector<int> &s);
  
  std::vector<std::vector<int> > twoSum(std::vector<int> &num, int target);
  
  std::vector<std::vector<int> > twoSum(std::vector<int> &num, int len, int target);

  std::vector<std::vector<int> > threeSum(std::vector<int> &num, int target);

  std::vector<std::vector<int> > threeSum(std::vector<int> &num, int len, int target);

  std::vector<std::vector<int> > fourSum(std::vector<int> &num, int target);

  int maxProfit(std::vector<int> &prices);

  int maxProfitII(std::vector<int> &prices);

  int minimumTotal(std::vector<std::vector<int> > &triangle);

  int threeSumClosest(std::vector<int> &num, int target);

  bool find(std::vector<std::vector<char> > &board, int i, int j, std::string & word, int idx);

  /**
   * word search
   */
  bool exist(std::vector<std::vector<char> > &board, std::string word);

};

#endif
