#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <stack>

#include "String.h"


#define log(s) std::cerr <<"[String] " <<s <<std::endl;

bool String::isWildMatch(const char *s, const char*p)
{
  if( s==p )
    return true;

  if( !s || !p )
    return false;

  if ( *s=='\0' )
  {
    while(*p=='*') p++;

    return *p=='\0';
  }

  if( *p=='\0' )
    return false;
  
  int j = -1;
  bool star = false;
  char chP = '\0';
  char chS = '\0';
  int lenP = strlen(p);
  int lenS = strlen(s);

  for(int i=0; i<lenP; i++)
  {
    chP = *(p+i);
    if( chP=='?' )
    {
      j++;

      // if( star )
      //   star = false;

      if( j>=lenS )
        return false;

      continue;
    }

    if( chP=='*' )
    {
      star = true;
      continue;
    }

    if( star )
    {
      star = false;
      
      for(++j ; j<lenS; j++ )
      {
        chS = *(s+j);
        if( chS==chP )
          break;
      }

      if( j>=lenS )
        return false;
    }
    else
    {
      j++;
      chS = *(s+j);

      if( chP!=chS )
        return false;
    }
  }

  if( !star && j<lenS-1 )
    return false;
  
  return true;
}

std::string String::countAndSay(int n)
{
  std::string result;

  if( 1==n )
  {
    result = "1";
  }
  else
  {
    std::string preResult = countAndSay(n-1);

    char word = preResult[0];
    int count = 1;
    for(int i=1; i<preResult.length(); i++)
    {
      if( preResult[i]==word )
      {
        count++;
      }
      else
      {
        char tmpValue[256];
        snprintf(tmpValue, 255, "%d%c", count, word);
        result += tmpValue;
        
        word = preResult[i];
        count = 1;
      }
    }

    char tmpValue[256];
    snprintf(tmpValue, 255, "%d%c", count, word);
    result += tmpValue;
  }

  
  return result;
}

int String::atoi(const char *str)
{
  if( !str )
    return 0;

  // 1. check the whitespace
  int i=0;
  for(; i<strlen(str); i++)
  {
    if( !isspace(str[i]) )
        break;
  }

  // 2. check the sign '+' or '-'
  int sign = 1;
  switch( str[i] )
  {
    case '\0':
      return 0; //only the white-space
    case '+':
      sign = 1;
      i++;
      break;
      
    case '-':
      sign = -1;
      i++;
      break;
  };


  long long result = 0;
  int int_max = 2147483647;
  int int_min = -2147483648;
  for(; i<strlen(str); i++)
  {
    // 3. check the digit data '0-9' or the other
    if( !isdigit(str[i]) )
      break;
    int d = str[i] - '0';

    // 4. check out of range int_max or the int_min
    result = result * 10 + d;

    long long tmpResult = result*sign;
    if( tmpResult>=int_max)
    {
      return int_max;
    }
    else if( tmpResult<=int_min )
    {
      return int_min;
    }

  }

  result *= sign;

  return result;
}

bool String::isPalindrome(std::string s)
{
  if( s.empty() )
    return true;

  // ignore the none alphanumeric
  int j=0;
  for(int i=0; i<s.length(); i++)
  {
    if( isalnum(s[i]) )
      s[j++] = s[i];
  }
  s.erase(s.begin()+j, s.end());
  
  std::transform(s.begin(), s.end(), s.begin(), toupper);
  
  // reverse the string
  std::string r(s.rbegin(), s.rend());

  // compare the two strings
  return s==r;
}


int String::romanToNumber(char c)
{
  int num = 0;

  switch( c)
  {
    case 'I':
      num = 1;
      break;

    case 'V':
      num = 5;
      break;

    case 'X':
      num = 10;
      break;

    case 'L':
      num = 50;
      break;

    case 'C':
      num = 100;
      break;

    case 'D':
      num = 500;
      break;

    case 'M':
      num = 1000;
      break;
  };

  return num;
}

int String::romanToInt(std::string s)
{
  if( s.empty() )
  {
    return 0;
  }

  int number = romanToNumber(s[0]);
  for(unsigned i=1; i<s.length(); i++)
  {
    int pre_num = romanToNumber(s[i-1]);
    int post_num = romanToNumber(s[i]);

    if( pre_num<post_num )
    {
      number += post_num - 2*pre_num;
    }
    else
    {
      number += post_num;
    }
  }

  return number;
}

std::string String::longestCommonPrefix(std::vector<std::string>& strs)
{
  if( strs.empty() )
    return "";

  std::string prefix;
  unsigned i; //string column
  unsigned j; //number of strs
  for(i=0; i<strs[0].length(); i++)
  {
    for(j=0; j<strs.size(); j++)
    {
      if( !(i<strs[j].length() && strs[j][i]==strs[0][i]) )
        break;
    }

    if( j<strs.size() )
    {
      break;
    }
    
    prefix += strs[0][i];
  }

  return prefix;
}

std::string String::convertZigZag(std::string s, int nRows)
{
  if( s.empty() || nRows<2 )
    return s;

  std::string result;
  int size = 2*nRows - 2;

  for(int i=0; i<nRows; i++)
  {
    for(int j=i; j<s.length(); j+=size)
    {
      result += s[j];

      if( i!=0 && i!=nRows-1 && (j+size-2*i)<s.length() )
      {
        result += s[j+size-2*i];
      }
    }
  }

  return result;

}

bool String::isValid(std::string s)
{
  if( s.empty() )
    return true;

  std::stack<char> stackChar;
  for(unsigned i=0; i<s.size(); i++)
  {
    switch(s[i])
    {
      case '(':
      case '{':
      case '[':
        stackChar.push(s[i]);
        break;
        
      case ')':
        if( stackChar.empty() || stackChar.top()!='(' )
          return false;

        stackChar.pop();
        break;

      case '}':
        if( stackChar.empty() || stackChar.top()!='{' )
          return false;

        stackChar.pop();
        break;
        
      case ']':
        if( stackChar.empty() || stackChar.top()!='[' )
          return false;
        
        stackChar.pop();
        break;
    };
  }

  if( !stackChar.empty() )
    return false;
  else
    return true;
}

int String::strStr(const char *haystack, const char *needle)
{
  if( !haystack || !needle )
    return -1;
  
  int hLen = strlen(haystack);
  int nLen = strlen(needle);

  if( 0==nLen )
    return 0;

  for(int i=0; i<=hLen-nLen; i++)
  {
    int j = 0;
    for(; j<nLen; j++)
    {
      if( haystack[i+j]!=needle[j] )
        break;
    }

    if( j==nLen )
      return i;
  }

  return -1;
}

std::string String::addBinary(std::string a, std::string b)
{
  std::string res;

  int i = a.length() - 1;
  int j = b.length() - 1;

  int one = 0;
  while( i>=0 || j>=0 )
  {
    int aValue = 0;
    if( i>=0 )
      aValue = a[i--]-'0';
    
    int bValue = 0;
    if( j>=0 )
      bValue = b[j--]-'0';

    char digit = (aValue + bValue + one)%2 + '0';
    res.push_back(digit);

    one = (aValue + bValue + one)/2;
  }

  if( one )
    res.push_back('1');

  std::reverse(res.begin(), res.end());

  return res;
}

int String::lengthOfLastWord(const char *s)
{
  if( !s )
    return 0;

  int n = strlen(s) -1 ;
  // skip the last space
  for(; n>=0; n--)
  {
    if( !isspace(s[n]) )
      break;
  }

  int len = 0;
  for(; n>=0; n--)
  {
    if( !isspace(s[n]) )
      len++;
    else
      break;
  }

  return len;
}
