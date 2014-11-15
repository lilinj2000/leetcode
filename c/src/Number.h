#include <vector>

class Number
{
public:
  bool isPalindrome(int);

  int reverse(int);

  std::vector<std::vector<int> > genPascalTriangle(int numRows);

  std::vector<int> getRowPascalTriangle(int rowIndex);
};
