#include <tut/tut.hpp>
#include "Algo.h"


namespace tut
{

struct algo_basic
{
    algo_basic() { }
    virtual ~algo_basic() { }

  Algo algo_;
};

typedef test_group<algo_basic> factory;
typedef factory::object object;
}

namespace
{

tut::factory tf("algo basic operations");

}

namespace tut
{
/**
 * Check searchInsert
 */
template<>
template<>
void object::test<1>()
{
  ensure( 1==algo_.climbStairs(1) );

  ensure( 2==algo_.climbStairs(2) );

  ensure( 3==algo_.climbStairs(3) );

  ensure( 5==algo_.climbStairs(4) );

  ensure( 8==algo_.climbStairs(5) );
  
}

/**
 * Check isValidSudoku
 */
template<>
template<>
void object::test<2>()
{
  std::vector<std::vector<char> > sudoku;
  ensure( !algo_.isValidSudoku(sudoku) );

  // std::vector<char> row;
  // char A[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
  // int n = 9;
  
}

/**
 * Check subsets
 */
template<>
template<>
void object::test<3>()
{
  std::vector<std::vector<int> > res;
  std::vector<int> s;

  res = algo_.subsets(s);
  ensure( 1==res.size() );

  s.push_back(1);
  res = algo_.subsets(s);
  ensure( 2==res.size() );

  s.push_back(2);
  res = algo_.subsets(s);
  ensure( 4==res.size() );

  s.push_back(3);
  res = algo_.subsets(s);
  ensure( 8==res.size() );
}

/**
 * Check twosum
 */
template<>
template<>
void object::test<4>()
{
  std::vector<std::vector<int> > res;
  std::vector<int> s;

  res = algo_.twosum(s, 0, 0);
  ensure( res.empty() );

  s.push_back(-1);
  s.push_back(-4);
  s.push_back(-5);
  s.push_back(-4);
  s.push_back(-1);
  s.push_back(0);

  res = algo_.twosum(s, s.size(), -5);
  ensure( 2==res.size() );

}

/**
 * Check threesum
 */
template<>
template<>
void object::test<5>()
{
  std::vector<std::vector<int> > res;
  std::vector<int> s;

  res = algo_.threesum(s, 0);
  ensure( res.empty() );

  s.push_back(-1);
  s.push_back(-4);
  s.push_back(-5);
  s.push_back(-4);
  s.push_back(-1);
  s.push_back(0);
  s.push_back(-6);
  s.push_back(1);

  res = algo_.threesum(s, -5);
  // std::cerr <<"res size is " <<res.size() <<std::endl;
  // for( unsigned i=0; i<res.size(); i++)
  // {
  //   std::copy(res[i].begin(), res[i].end(), std::ostream_iterator<int>(std::cerr, " "));
  //   std::cerr <<"\n";
  // }
  ensure( 3==res.size() );

  s.clear();
  s.push_back(0);
  s.push_back(0);
  s.push_back(0);
  res = algo_.threesum(s, 0);
  ensure( 1==res.size() );

}


/**
 * Check max profit
 */
template<>
template<>
void object::test<6>()
{
  std::vector<int> prices;

  ensure( 0==algo_.maxProfit(prices) );

  prices.push_back(2);
  ensure( 0==algo_.maxProfit(prices) );
  
  prices.push_back(1);
  ensure( 0==algo_.maxProfit(prices) );


  prices.push_back(5);
  ensure( 4==algo_.maxProfit(prices) );
}

/**
 * Check max profit II
 */
template<>
template<>
void object::test<7>()
{
  std::vector<int> prices;

  ensure( 0==algo_.maxProfitII(prices) );

  prices.push_back(2);
  ensure( 0==algo_.maxProfitII(prices) );
  
  prices.push_back(1);
  ensure( 0==algo_.maxProfitII(prices) );

  prices.push_back(5);
  ensure( 4==algo_.maxProfitII(prices) );

  prices.push_back(8);
  ensure( 7==algo_.maxProfitII(prices) );

  prices.push_back(7);
  ensure( 7==algo_.maxProfitII(prices) );

  prices.push_back(8);
  ensure( 8==algo_.maxProfitII(prices) );
}

/**
 * Check minimumTotal
 */
template<>
template<>
void object::test<8>()
{
  std::vector<std::vector<int> > triangle;
  triangle.resize(4);

  triangle[0].push_back(2);
  triangle[1].push_back(3);
  triangle[1].push_back(4);
  triangle[2].push_back(6);
  triangle[2].push_back(5);
  triangle[2].push_back(7);
  triangle[3].push_back(4);
  triangle[3].push_back(1);
  triangle[3].push_back(8);
  triangle[3].push_back(3);

  ensure( 11==algo_.minimumTotal(triangle) );
}

/**
 * Check three sum closest
 */
template<>
template<>
void object::test<9>()
{
  std::vector<int> s;

  int ret = algo_.threeSumClosest(s, 100);
  ensure( 0==ret );

  s.push_back(-1);
  ret = algo_.threeSumClosest(s, 100);
  ensure( 0==ret);

  int A[] = { 3, 4, 5, 6, 7, 8, 2, 3, 5 };
  int n = sizeof(A)/sizeof(int);
  s.resize(n);
  std::copy(A, A+n, s.begin());
  
  ret = algo_.threeSumClosest(s, 18);
  ensure( 18==ret );

  ret = algo_.threeSumClosest(s, 25);
  ensure( 21==ret );

  int B[] = {1,2,4,8,16,32,64,128};
  int m = 8;
  s.resize(8);
  std::copy(B, B+m, s.begin());

  ret = algo_.threeSumClosest(s, 82);
  ensure( 82==ret );
  

}



}

