#include <tut/tut.hpp>
#include <string.h>
#include <limits>
#include "Number.h"


namespace tut
{

struct number_basic
{
    number_basic() { }
    virtual ~number_basic() { }

  Number mNumber;
};

typedef test_group<number_basic> factory;
typedef factory::object object;
}

namespace
{

tut::factory tf("number basic operations");

}

namespace tut
{
/**
 * Checks isPalindrome
 */
template<>
template<>
void object::test<1>()
{
  int x = -1;
  ensure( false==mNumber.isPalindrome(x) );

  x = 1;
  ensure( true==mNumber.isPalindrome(x) );

  x = 191;
  ensure( true==mNumber.isPalindrome(x) );

  x = 313;
  ensure( true==mNumber.isPalindrome(x) );

  x = 5885;
  ensure( true==mNumber.isPalindrome(x) );

  x = 19993;
  ensure( false==mNumber.isPalindrome(x) );

}

/**
 * Checks integer reverse
 */
template<>
template<>
void object::test<2>()
{
  int x = -1;
  ensure( -1==mNumber.reverse(x) );

  x = 1;
  ensure( 1==mNumber.reverse(x) );

  x = 1234;
  ensure( 4321==mNumber.reverse(x) );

  x = -1234;
  ensure( -4321==mNumber.reverse(x) );

  x = std::numeric_limits<int>::max();
  ensure( 0==mNumber.reverse(x) );

  x = std::numeric_limits<int>::min();
  ensure( 0==mNumber.reverse(x) );
}

/**
 * Checks pascal triangle genarate
 */
template<>
template<>
void object::test<3>()
{
  int numRows = 0;
  std::vector<std::vector<int> > result;

  result = mNumber.genPascalTriangle(numRows);
  ensure( result.empty() );

  numRows = 1;
  result = mNumber.genPascalTriangle(numRows);
  ensure( 1==result.size() );
  
  std::vector<int> row1;
  row1.push_back(1);
  ensure( row1==result[0] );

  numRows = 2;
  result = mNumber.genPascalTriangle(numRows);
  std::vector<int> row2;
  row2.push_back(1);
  row2.push_back(1);
  ensure( 2==result.size() );
  ensure( row1==result[0] );
  ensure( row2==result[1] );

  numRows = 3;
  result = mNumber.genPascalTriangle(numRows);
  std::vector<int> row3;
  row3.push_back(1);
  row3.push_back(2);
  row3.push_back(1);
  ensure( 3==result.size() );
  ensure( row1==result[0] );
  ensure( row2==result[1] );
  ensure( row3==result[2] );

  numRows = 4;
  result = mNumber.genPascalTriangle(numRows);
  std::vector<int> row4;
  row4.push_back(1);
  row4.push_back(3);
  row4.push_back(3);
  row4.push_back(1);
  ensure( 4==result.size() );
  ensure( row1==result[0] );
  ensure( row2==result[1] );
  ensure( row3==result[2] );
  ensure( row4==result[3] );

}

/**
 * Checks pascal triangle get row
 */
template<>
template<>
void object::test<4>()
{
  int rowIndex = -1;
  std::vector<int> result;
  result = mNumber.getRowPascalTriangle(rowIndex);
  ensure( result.empty() );

  rowIndex = 0;
  result = mNumber.getRowPascalTriangle(rowIndex);
  std::vector<int> row1;
  row1.push_back(1);
  ensure( 1==result.size() );
  ensure( row1==result );

  rowIndex = 1;
  result = mNumber.getRowPascalTriangle(rowIndex);
  std::vector<int> row2;
  row2.push_back(1);
  row2.push_back(1);
  ensure( row2==result );

  rowIndex = 2;
  result = mNumber.getRowPascalTriangle(rowIndex);
  std::vector<int> row3;
  row3.push_back(1);
  row3.push_back(2);
  row3.push_back(1);
  ensure( row3==result );

  rowIndex = 3;
  result = mNumber.getRowPascalTriangle(rowIndex);
  std::vector<int> row4;
  row4.push_back(1);
  row4.push_back(3);
  row4.push_back(3);
  row4.push_back(1);
  ensure( row4==result );

}


}

