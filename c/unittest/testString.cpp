#include <tut/tut.hpp>
#include <string.h>
#include "String.h"


namespace tut
{

struct string_basic
{
    string_basic() { }
    virtual ~string_basic() { }

  String mString;
};

typedef test_group<string_basic> factory;
typedef factory::object object;
}

namespace
{

tut::factory tf("string basic operations");

}

namespace tut
{
/**
 * Checks isWildMatch
 */
template<>
template<>
void object::test<1>()
{
  char* s = "ppp";
  char* p = s;
  ensure( mString.isWildMatch(s, p) );

  // s = "aa";
  // p = "a";
  // ensure( !mString.isWildMatch(s, p) );

  // s = "aa";
  // p = strdup(s);
  // ensure( mString.isWildMatch(s, p) );

  // s = "aaa";
  // p = "aa";
  // ensure( !mString.isWildMatch(s, p) );

  
  // s = "aa";
  // p = "*";
  // ensure( mString.isWildMatch(s, p) );

  // s = "aa";
  // p = "a*";
  // ensure( mString.isWildMatch(s, p) );

  // s = "ab";
  // p = "?*";
  // ensure( mString.isWildMatch(s, p) );

  // s = "aab";
  // p = "c*a*b";
  // ensure( !mString.isWildMatch(s, p) );

  // s = "hi";
  // p = "*?";
  // ensure( mString.isWildMatch(s, p) );

  // s = "aa";
  // p = "*a";
  // ensure( mString.isWildMatch(s, p) );

}

/**
 * Checks countAndSay
 */
template<>
template<>
void object::test<2>()
{
  int n = 1;
  std::string result = mString.countAndSay(n);
  std::string expected = "1";
  ensure( expected==result );

  n = 2;
  result = mString.countAndSay(n);
  expected = "11";
  ensure( expected==result );

  
  n = 3;
  result = mString.countAndSay(n);
  expected = "21";
  ensure( expected==result );

  n = 4;
  result = mString.countAndSay(n);
  expected = "1211";
  ensure( expected==result );

  n = 5;
  result = mString.countAndSay(n);
  expected = "111221";
  ensure( expected==result );

  n = 6;
  result = mString.countAndSay(n);
  expected = "312211";
  ensure( expected==result );

}

/**
 * Checks atoi
 */
template<>
template<>
void object::test<3>()
{
  std::string str;

  // support integer with sign
  str= "+560";
  ensure( 560 == mString.atoi(str.data()) );
  
  str = "-100";
  ensure( -100 == mString.atoi(str.data()) );

  // support whitespace on the left or the right
  str = "    100   ";
  ensure( 100 == mString.atoi(str.data()) );

  // support the addional characters and ignore it.
  str = "100abc345";
  ensure( 100 == mString.atoi(str.data()) );
  
  // return zero in case the first non-whitespace is not a valid integral data
  str = "a1000";
  ensure( 0 == mString.atoi(str.data()) );

  // return zero in case empty string or the only whitespace
  str = "";
  ensure( 0 == mString.atoi(str.data()) );
  
  str = "    ";
  ensure( 0 == mString.atoi(str.data()) );
  
  // return INT_MAX in case out of range INT_MAX(2147483647)
  str = "2147483647";
  ensure( 2147483647 == mString.atoi(str.data()) );
  
  str = "2147483648";
  ensure( 2147483647 == mString.atoi(str.data()) );

  // return INT_MIN in case out of range INT_MIN(-2147483648)
  str = "-2147483648";
  ensure( -2147483648 == mString.atoi(str.data()) );
  
  str = "-2147483649";
  ensure( -2147483648 == mString.atoi(str.data()) );
}

}

