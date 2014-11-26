#include <tut/tut.hpp>
#include <string.h>

#include "String.h"


namespace tut
{

struct string_basic
{
    string_basic() { }
    virtual ~string_basic() { }

  String string_;
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
  std::string s = "ppp";
  std::string p = s;
  ensure( string_.isWildMatch(s.data(), p.data()) );

  // s = "aa";
  // p = "a";
  // ensure( !string_.isWildMatch(s, p) );

  // s = "aa";
  // p = strdup(s);
  // ensure( string_.isWildMatch(s, p) );

  // s = "aaa";
  // p = "aa";
  // ensure( !string_.isWildMatch(s, p) );

  
  // s = "aa";
  // p = "*";
  // ensure( string_.isWildMatch(s, p) );

  // s = "aa";
  // p = "a*";
  // ensure( string_.isWildMatch(s, p) );

  // s = "ab";
  // p = "?*";
  // ensure( string_.isWildMatch(s, p) );

  // s = "aab";
  // p = "c*a*b";
  // ensure( !string_.isWildMatch(s, p) );

  // s = "hi";
  // p = "*?";
  // ensure( string_.isWildMatch(s, p) );

  // s = "aa";
  // p = "*a";
  // ensure( string_.isWildMatch(s, p) );

}

/**
 * Checks countAndSay
 */
template<>
template<>
void object::test<2>()
{
  int n = 1;
  std::string result = string_.countAndSay(n);
  std::string expected = "1";
  ensure( expected==result );

  n = 2;
  result = string_.countAndSay(n);
  expected = "11";
  ensure( expected==result );

  
  n = 3;
  result = string_.countAndSay(n);
  expected = "21";
  ensure( expected==result );

  n = 4;
  result = string_.countAndSay(n);
  expected = "1211";
  ensure( expected==result );

  n = 5;
  result = string_.countAndSay(n);
  expected = "111221";
  ensure( expected==result );

  n = 6;
  result = string_.countAndSay(n);
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
  ensure( 560 == string_.atoi(str.data()) );
  
  str = "-100";
  ensure( -100 == string_.atoi(str.data()) );

  // support whitespace on the left or the right
  str = "    100   ";
  ensure( 100 == string_.atoi(str.data()) );

  // support the addional characters and ignore it.
  str = "100abc345";
  ensure( 100 == string_.atoi(str.data()) );
  
  // return zero in case the first non-whitespace is not a valid integral data
  str = "a1000";
  ensure( 0 == string_.atoi(str.data()) );

  // return zero in case empty string or the only whitespace
  str = "";
  ensure( 0 == string_.atoi(str.data()) );
  
  str = "    ";
  ensure( 0 == string_.atoi(str.data()) );
  
  // return INT_MAX in case out of range INT_MAX(2147483647)
  str = "2147483647";
  ensure( 2147483647 == string_.atoi(str.data()) );
  
  str = "2147483648";
  ensure( 2147483647 == string_.atoi(str.data()) );

  // return INT_MIN in case out of range INT_MIN(-2147483648)
  str = "-2147483648";
  ensure( -2147483648 == string_.atoi(str.data()) );
  
  str = "-2147483649";
  ensure( -2147483648 == string_.atoi(str.data()) );
}

/**
 * Checks isPalindrome
 */
template<>
template<>
void object::test<4>()
{
  std::string str;

  str= "A man, a plan, a canal: Panama";
  ensure( string_.isPalindrome(str) );
  
  str = "race a car";
  ensure( !string_.isPalindrome(str) );

  str = "r123321r";
  ensure( string_.isPalindrome(str) );

  str = "";
  ensure( string_.isPalindrome(str) );
}

/**
 * Checks romanToInt
 */
template<>
template<>
void object::test<5>()
{
  std::string str;

  str= "III";
  ensure( 3==string_.romanToInt(str) );
  
  str = "IV";
  ensure( 4==string_.romanToInt(str) );

  str = "MMMCMXCIX";
  ensure( 3999==string_.romanToInt(str) );

  str = "";
  ensure( 0==string_.romanToInt(str) );
}

/**
 * Checks common prefix
 */
template<>
template<>
void object::test<6>()
{
  std::vector<std::string> strs;

  ensure( ""==string_.longestCommonPrefix(strs) );

  strs.push_back("");
  ensure( ""==string_.longestCommonPrefix(strs) );

  strs.clear();
  std::string str1 = "abcdefghijk";
  std::string str2 = "abcdefg";
  strs.push_back(str1);
  strs.push_back(str2);
  ensure( str2==string_.longestCommonPrefix(strs) );

  std::string str3 = "abcd";
  strs.push_back(str3);
  ensure( str3==string_.longestCommonPrefix(strs) );

  std::string str4 = "";
  strs.push_back(str4);
  ensure( str4==string_.longestCommonPrefix(strs) );

  strs.clear();
  strs.push_back("abab");
  strs.push_back("aba");
  strs.push_back("abc");
  ensure( "ab"==string_.longestCommonPrefix(strs) );
}

/**
 * Check convert ZigZag
 */
template<>
template<>
void object::test<7>()
{
  std::string s;

  ensure( s==string_.convertZigZag(s, 5) );

  s = "PAYPALISHIRING";
  ensure( s==string_.convertZigZag(s, 0) );
  ensure( s==string_.convertZigZag(s, 1) );

  std::string result = "PAHNAPLSIIGYIR";
  ensure( result==string_.convertZigZag(s, 3) );

  result = "PINALSIGYAHRPI";
  ensure( result==string_.convertZigZag(s, 4) );

  result = "PHASIYIRPLIGAN";
  ensure( result==string_.convertZigZag(s, 5) );
}

/**
 * Check isValid string for (), [], {}
 */
template<>
template<>
void object::test<8>()
{
  std::string s;

  ensure( string_.isValid(s) );

  s = "asdfasdf{asfasdfsdf(fasfasdf(fadfsd)asdfasd)afasdf}adf";
  ensure( string_.isValid(s) );

  s = "{{{{{fadafsdf(((())))}}}}";
  ensure( !string_.isValid(s) );

  s = "fasdd[[[[[[]]]]]]{{{{{{(((((())))))}}}}}}";
  ensure( string_.isValid(s) );

  s = "}}}}}}}}{{{{{{{";
  ensure( !string_.isValid(s) );
}

/**
 * Check strStr
 */
template<>
template<>
void object::test<9>()
{
  std::string s = "as789asfa789dfd";
  std::string p = "789";

  ensure( -1==string_.strStr(s.data(), NULL) );
  ensure( -1==string_.strStr(NULL, p.data()) );

  ensure( 2==string_.strStr(s.data(), p.data()) );

  ensure( -1==string_.strStr(p.data(), s.data()) );

  ensure( 0==string_.strStr("", "") );

  ensure( 0==string_.strStr(s.data(), "") );

  ensure( 0==string_.strStr(s.data(), s.data()) );
}

/**
 * Check addBinary
 */
template<>
template<>
void object::test<10>()
{
  std::string a = "11";
  std::string b = "1";

  std::string res = "100";
  ensure( res==string_.addBinary(a, b) );

  a = "100001";
  b = "11";

  res = "100100";
  ensure( res==string_.addBinary(a, b) );

  b = "";
  res = a;
  ensure( res==string_.addBinary(a, b) );

  a = "";
  res = "";
  ensure( res==string_.addBinary(a, b) );
  
}

/**
 * Check lengthOfLastWord
 */
template<>
template<>
void object::test<11>()
{
  std::string a = "Hello World";
  ensure( 5==string_.lengthOfLastWord(a.data()) );

  a = "Hello World      ";
  ensure( 5==string_.lengthOfLastWord(a.data()) );

  a = "";
  ensure( 0==string_.lengthOfLastWord(a.data()) );

  ensure( 0==string_.lengthOfLastWord(NULL) );
}

/**
 * Check longestPalindrome
 */
template<>
template<>
void object::test<12>()
{
  std::string s = "aaaaaaaaa";
  ensure( s==string_.longestPalindrome(s) );

  s = "cabcbabcbabcba";
  std::string p = "abcbabcbabcba";
  ensure( p==string_.longestPalindrome(s) );


}

}

