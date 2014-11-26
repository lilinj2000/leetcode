#include <tut/tut.hpp>

#include "Tree.h"
#include "utility.h"

namespace tut
{

struct tree_basic
{
  tree_basic():root(2), node1(3),
               node2(4), node3(50),
               node4(10), node5(20),
               node6(100), node7(200)
  {
     //         2(root)
     //     3(1)     4(2)
     // 50(3)      10(4)      20(5)
     //       100(6)
     //     200(7)
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

  Tree tree_;

  TreeNode root;
  TreeNode node1;
  TreeNode node2;
  TreeNode node3;
  TreeNode node4;
  TreeNode node5;
  TreeNode node6;
  TreeNode node7;

  
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
  
  ensure(tree_.isSameTree(p, q));
}

/**
 * Checks hasPathSum
 */
template<>
template<>
void object::test<2>()
{
  ensure(!tree_.hasPathSum(NULL, 16));
  
  // root -> node2 -> node5
  ensure(tree_.hasPathSum(&root, 26));

  // root -> node1 -> node3
  ensure(tree_.hasPathSum(&root, 55));

  ensure(!tree_.hasPathSum(&root, 3000));

}

/**
 * Checks minDepth
 */
template<>
template<>
void object::test<3>()
{
  ensure( 0==tree_.minDepth(NULL) );

  ensure(3==tree_.minDepth(&root));

  // node1 -> node3
  ensure(2==tree_.minDepth(&node1));

}

/**
 * Checks isBalanced
 */
template<>
template<>
void object::test<4>()
{
  ensure( tree_.isBalanced(NULL) );
  
  ensure( !tree_.isBalanced(&root));

  // node1 -> node3
  ensure( tree_.isBalanced(&node1));

  // node2 -> node4, node5
  // node4 -> node6
  // node6 -> node7
  ensure( !tree_.isBalanced(&node2));
}

/**
 * Check levelOrder
 */
template<>
template<>
void object::test<5>()
{
  std::vector<std::vector<int> > result;
  result = tree_.levelOrder(NULL);
  ensure( result.empty() );

  // root -> node1, node2
  // node1 -> node3
  // node2 -> node4, node5
  // node4 -> node6
  // node6 -> node7

  result = tree_.levelOrder(&root);
  ensure( 5==result.size() );
  int level = 1;
  ensure( 1==result[level-1].size()
          && 2==result[level-1][0] );  // root = 2

  level = 2;
  ensure( 2==result[level-1].size() 
          && 3==result[level-1][0]  // node1 = 3
          && 4==result[level-1][1] );// node2 = 4

  level = 3;
  ensure( 3==result[level-1].size() 
          && 50==result[level-1][0]  // node3 = 50
          && 10==result[level-1][1]  // node4 = 10
          && 20==result[level-1][2]);// node5 = 20

  level = 4;
  ensure( 1==result[level-1].size() 
          && 100==result[level-1][0]);  // node6 = 100

  level = 5;
  ensure( 1==result[level-1].size() 
          && 200==result[level-1][0]);  // node7 = 200

}

/**
 * Check levelOrderBottom
 */
template<>
template<>
void object::test<6>()
{
  std::vector<std::vector<int> > result;
  result = tree_.levelOrderBottom(NULL);
  ensure( result.empty() );

  // root -> node1, node2
  // node1 -> node3
  // node2 -> node4, node5
  // node4 -> node6
  // node6 -> node7

  result = tree_.levelOrderBottom(&root);
  ensure( 5==result.size() );
  
  int level = 1;
  ensure( 1==result[level-1].size() 
          && 200==result[level-1][0]);  // node7 = 200

  level = 2;
  ensure( 1==result[level-1].size() 
          && 100==result[level-1][0]);  // node6 = 100

  level = 3;
  ensure( 3==result[level-1].size() 
          && 50==result[level-1][0]  // node3 = 50
          && 10==result[level-1][1]  // node4 = 10
          && 20==result[level-1][2]);// node5 = 20

  level = 4;
  ensure( 2==result[level-1].size() 
          && 3==result[level-1][0]  // node1 = 3
          && 4==result[level-1][1] );// node2 = 4


  level = 5;
  ensure( 1==result[level-1].size()
          && 2==result[level-1][0] );  // root = 2

}

/**
 * Checks maxDepth
 */
template<>
template<>
void object::test<7>()
{
  ensure( 0==tree_.maxDepth(NULL) );

  ensure( 5==tree_.maxDepth(&root) );

  // node1 -> node3
  ensure( 2==tree_.maxDepth(&node1) );

  ensure( 4==tree_.maxDepth(&node2) );
}

/**
 * Checks TreeLinkNode connect
 */
template<>
template<>
void object::test<8>()
{
  TreeLinkNode root;
  TreeLinkNode node2;
  TreeLinkNode node3;
  TreeLinkNode node4;
  TreeLinkNode node5;
  TreeLinkNode node6;
  TreeLinkNode node7;

  root.left = &node2;
  root.right = &node3;
  node2.left = &node4;
  node2.right = &node5;
  node3.left = &node6;
  node3.right = &node7;

  tree_.connect(&root);

  ensure( NULL==root.next );
  ensure( &node3==node2.next );
  ensure( NULL==node3.next );
}


/**
 * Checks flatten
 */
template<>
template<>
void object::test<9>()
{

  tree_.flatten(&root);

  ensure( NULL==root.left );
  ensure( NULL==node1.left );
  ensure( NULL==node2.left );
  ensure( NULL==node3.left );
  ensure( NULL==node4.left );
  ensure( NULL==node5.left );
  ensure( NULL==node6.left );
  ensure( NULL==node7.left );

  // root -> node1, node2
  // node1 -> node3
  // node2 -> node4, node5
  // node4 -> node6
  // node6 -> node7

  ensure( &node1==root.right );
  ensure( &node3==node1.right );
  ensure( &node2==node3.right );
  ensure( &node4==node2.right );
  ensure( &node6==node4.right );
  ensure( &node7==node6.right );
  ensure( &node5==node7.right );
  ensure( NULL==node5.right );

}

/**
 * Checks pathSum II
 */
template<>
template<>
void object::test<10>()
{
  //         2(root)
  //     3(1)     4(2)
  // 50(3)      10(4)      20(5)
  //       100(6)
  //     200(7)
  // root -> node1, node2
  // node1 -> node3
  // node2 -> node4, node5
  // node4 -> node6
  // node6 -> node7

  std::vector<std::vector<int> > res;
  res = tree_.pathSum(&root, 316);
  ensure( 1==res.size() );
  int A[] = {2, 4, 10, 100, 200};
  std::vector<int> exp;
  exp.resize(5);
  std::copy(A, A+5, exp.begin());
  ensure( exp==res[0] );
}

/**
 * Checks sortedListToBST
 */
template<>
template<>
void object::test<11>()
{
  int A[] = { 1, 2, 3, 4, 5};
  ListNode* head = util->buildList(A, 5);

  TreeNode* root = tree_.sortedListToBST(head);
  ensure(3==root->val);
  ensure(1==root->left->val);
  ensure(2==root->left->right->val);
  ensure(4==root->right->val);
  ensure(5==root->right->right->val);
}


}

