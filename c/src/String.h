#include <string>
#include <vector>

class String
{
public:
  String() {};
  virtual ~String() {};

  bool isWildMatch(const char *s, const char *p);

  std::string countAndSay(int n);

  int atoi(const char *str);

  bool isPalindrome(std::string s);

  int romanToNumber(char c);
  
  int romanToInt(std::string s);

  std::string longestCommonPrefix(std::vector<std::string>&);
};
