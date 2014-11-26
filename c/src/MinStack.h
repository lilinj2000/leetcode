#include <stack>

#ifndef MIN_STACK_H
#define MIN_STACK_H

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

#endif
