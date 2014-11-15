#include <stack>

class MinStack
{
public:
  void push(int x);

  void pop();

  int top();

  int getMinValue();

private:

  std::stack<int> stack_;
  std::stack<int> min_stack_;
};
