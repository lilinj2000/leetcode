#include <tut/tut.hpp>
#include "MinStack.h"


namespace tut
{

struct minstack_basic
{
    minstack_basic() { }
    virtual ~minstack_basic() { }

  MinStack minstack_;
};

typedef test_group<minstack_basic> factory;
typedef factory::object object;
}

namespace
{

tut::factory tf("minstack basic operations");

}

namespace tut
{
/**
 * Checks 
 */
template<>
template<>
void object::test<1>()
{
  minstack_.push(1);
  ensure( 1==minstack_.top() );
  ensure( 1==minstack_.getMinValue() );
  
  minstack_.push(2);
  ensure( 2==minstack_.top() );
  ensure( 1==minstack_.getMinValue() );
  
  minstack_.push(3);
  ensure( 3==minstack_.top() );
  ensure( 1==minstack_.getMinValue() );

  minstack_.pop();
  ensure( 1==minstack_.getMinValue() );

  minstack_.push( -1 );
  ensure( -1==minstack_.top() );
  ensure( -1==minstack_.getMinValue() );

  minstack_.pop();
  ensure( 2==minstack_.top() );
  ensure( 1==minstack_.getMinValue() );

  
  
}


}

