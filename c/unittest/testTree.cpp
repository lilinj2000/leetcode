#include <tut/tut.hpp>
#include "Tree.h"


namespace tut
{

struct tree_basic
{
    tree_basic() { }
    virtual ~tree_basic() { }
};

typedef test_group<tree_basic> factory;
typedef factory::object object;
}

namespace
{

tut::factory tf("tree basic operations");

}

namespace tut
{
/**
 * Checks isSameTree
 */
template<>
template<>
void object::test<1>()
{
  TreeNode *p = NULL;
  TreeNode *q = NULL;
  
  ensure(isSameTree(p, q));
}

/**
 * Checks clear operation
 */
template<>
template<>
void object::test<2>()
{
    s.clear();
    ensure_equals("size is 0", s.size(), 0U);
    ensure("empty", s.empty());

    // imitate failure of container implementation
    ensure("s.end() == s.begin()", s.end() != s.begin());
}

}

