#include <tut/tut.hpp>
#include "Tree.h"


namespace tut
{

struct tree_basic
{
  tree_basic():root(2), node1(3),
               node2(4), node3(50),
               node4(10), node5(20),
               node6(100), node7(200)
  {
    // root -> node1, node2
    // node1 -> node3
    // node2 -> node4, node5
    // node4 -> node6
    // node6 -> node7
    root.left = &node1;
    root.right = &node2;
    node1.left = &node3;
    node2.left = &node4;
    node2.right = &node5;

    node4.left = &node6;
    node6.right = &node7;
  }
  
  virtual ~tree_basic() { }

  Tree tree;

  Tree::TreeNode root;
  Tree::TreeNode node1;
  Tree::TreeNode node2;
  Tree::TreeNode node3;
  Tree::TreeNode node4;
  Tree::TreeNode node5;
  Tree::TreeNode node6;
  Tree::TreeNode node7;
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

/**
 * Checks hasPathSum
 */
template<>
template<>
void object::test<2>()
{
  ensure(!tree.hasPathSum(NULL, 16));
  
  // root -> node2 -> node5
  ensure(tree.hasPathSum(&root, 26));

  // root -> node1 -> node3
  ensure(tree.hasPathSum(&root, 55));

  ensure(!tree.hasPathSum(&root, 3000));

}

/**
 * Checks minDepth
 */
template<>
template<>
void object::test<3>()
{
  ensure( 0==tree.minDepth(NULL) );

  ensure(3==tree.minDepth(&root));

  // node1 -> node3
  ensure(2==tree.minDepth(&node1));

}

/**
 * Checks isBalanced
 */
template<>
template<>
void object::test<4>()
{
  ensure( tree.isBalanced(NULL) );
  
  ensure( !tree.isBalanced(&root));

  // node1 -> node3
  ensure( tree.isBalanced(&node1));

  // node2 -> node4, node5
  // node4 -> node6
  // node6 -> node7
  ensure( !tree.isBalanced(&node2));
}



}

