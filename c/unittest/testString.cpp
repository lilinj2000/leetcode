#include <tut/tut.hpp>
#include <string.h>
#include "../String.h"


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

}

