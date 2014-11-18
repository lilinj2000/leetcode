#include <tut/tut.hpp>
#include "Algo.h"


namespace tut
{

struct algo_basic
{
    algo_basic() { }
    virtual ~algo_basic() { }

  Algo algo_;
};

typedef test_group<algo_basic> factory;
typedef factory::object object;
}

namespace
{

tut::factory tf("algo basic operations");

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
  ensure( 1==algo_.climbStairs(1) );

  ensure( 2==algo_.climbStairs(2) );

  ensure( 3==algo_.climbStairs(3) );

  ensure( 5==algo_.climbStairs(4) );

  ensure( 8==algo_.climbStairs(5) );
  
}



}

