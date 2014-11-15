#include <stack>

class MinStack
{
public:
  void push(int x);

  void pop();

  int top();

  int getMinValue();

private:
  int min_value_;

  std::stack<int> stack_;
};
