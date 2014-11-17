#include <tut/tut.hpp>
#include "Sort.h"


namespace tut
{

struct sort_basic
{
    sort_basic() { }
    virtual ~sort_basic() { }

  Sort sort_;
};

typedef test_group<sort_basic> factory;
typedef factory::object object;
}

namespace
{

tut::factory tf("sort basic operations");

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
  int A[] = {1, 3, 5, 6};
  int n = 4;
  int target = 5;
  ensure( 2==sort_.searchInsert(A, n, target) );

  target = 2;
  ensure( 1==sort_.searchInsert(A, n, target) );

  target = 7;
  ensure( 4==sort_.searchInsert(A, n, target) );

  target = 0;
  ensure( 0==sort_.searchInsert(A, n, target) );

  
}


}

