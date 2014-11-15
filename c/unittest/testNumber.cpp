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


}

