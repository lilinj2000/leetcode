#include <string.h>
#include <iostream>
#include <stdio.h>
#include "String.h"

// isMatch("aa","a") → false
// isMatch("aa","aa") → true
// isMatch("aaa","aa") → false
// isMatch("aa", "a*") → true
// isMatch("aa", ".*") → true
// isMatch("ab", ".*") → true
// isMatch("aab", "c*a*b") → true

// wildcard match for string
// isMatch("aa","a") → false
// isMatch("aa","aa") → true
// isMatch("aaa","aa") → false
// isMatch("aa", "*") → true
// isMatch("aa", "a*") → true
// isMatch("ab", "?*") → true
// isMatch("aab", "c*a*b") → false
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
  for(; i<strlen(str); i++)
  {
    // 3. check the digit data '0-9' or the other
    if( !isdigit(str[i]) )
      break;
    int d = str[i] - '0';
    
    result = result * 10 + d;
  }

  result *= sign;

  // 4. check oute of range int_max or the int_min
  int int_max = 2147483647;
  int int_min = -2147483648;

  if( result>int_max)
    result = int_max;
  else if( result<int_min )
    result = int_min;
  
  return result;
}
