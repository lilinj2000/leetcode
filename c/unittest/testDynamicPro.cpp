#include <tut/tut.hpp>
#include "DynamicPro.h"


namespace tut
{

struct dynamicpro_basic
{
    dynamicpro_basic() { }
    virtual ~dynamicpro_basic() { }

  DynamicPro dynamicpro_;
};

typedef test_group<dynamicpro_basic> factory;
typedef factory::object object;
}

namespace
{

tut::factory tf("dynamicpro basic operations");

}

namespace tut
{
/**
 * Check searchInsert
 */
template<>
template<>
void object::test<1>()
{
  ensure( 1==dynamicpro_.climbStairs(1) );

  ensure( 2==dynamicpro_.climbStairs(2) );

  ensure( 3==dynamicpro_.climbStairs(3) );

  ensure( 5==dynamicpro_.climbStairs(4) );

  ensure( 8==dynamicpro_.climbStairs(5) );
  
}



}

