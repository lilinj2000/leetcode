#include <cassert>
#include "MinStack.h"

void MinStack::push(int x)
{
  if( stack_.empty() )
  {
    min_value_ = x;
  }
  else if( x<min_value_ )
  {
    int val = 2*x - min_value_;

    min_value_ = x;

    x = val;

    assert( x<min_value_ );
  }

  stack_.push(x);
}

void MinStack::pop()
{
  int val = stack_.top();

  if( val<min_value_ )
  {
    min_value_ = 2*min_value_ - val;
  }

  stack_.pop();
}

int MinStack::top()
{
  int val = stack_.top();

  if( val<min_value_ )
  {
    val = min_value_;
  }
  return val;
}

int MinStack::getMinValue()
{
  return min_value_;
}
