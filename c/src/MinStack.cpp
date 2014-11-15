#include "MinStack.h"

void MinStack::push(int x)
{
  stack_.push(x);

  if( min_stack_.empty() || x<=min_stack_.top() )
  {
    min_stack_.push(x);
  }
}

void MinStack::pop()
{
  int val = stack_.top();

  if( val==min_stack_.top() )
  {
    min_stack_.pop();
  }
  
  stack_.pop();
}

int MinStack::top()
{
  return stack_.top();
}

int MinStack::getMinValue()
{
  return min_stack_.top();
}
