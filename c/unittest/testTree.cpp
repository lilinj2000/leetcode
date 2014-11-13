#include <tut/tut.hpp>
#include "Tree.h"


namespace tut
{

struct tree_basic
{
    tree_basic() { }
    virtual ~tree_basic() { }

  Tree tree;
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
  Tree::TreeNode *p = NULL;
  Tree::TreeNode *q = NULL;
  
  ensure(tree.isSameTree(p, q));
}


}

