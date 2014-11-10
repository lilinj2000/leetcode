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
