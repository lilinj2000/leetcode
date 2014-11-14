#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cctype>
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
