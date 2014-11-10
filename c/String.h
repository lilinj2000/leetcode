#include <string>

class String
{
public:
  String() {};
  virtual ~String() {};

  bool isWildMatch(const char *s, const char *p);

  std::string countAndSay(int n);
};
