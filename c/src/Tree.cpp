#include <algorithm>

#include "Tree.h"

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool Tree::isSameTree(TreeNode *p, TreeNode *q) {

  if ( p==q )
    return true;

  if ( !p || !q )
    return false;

  if ( p->val != q->val )
    return false;

  if ( isSameTree(p->left, q->left) )
    return isSameTree(p->right, q->right);
  else
    return false;

}

bool Tree::hasPathSum(TreeNode *root, int sum)
{
  if( !root )
    return false;

  if( NULL==root->left && NULL==root->right && root->val==sum )
    return true;

  int leftSum = sum - root->val;
  return hasPathSum(root->left, leftSum) || hasPathSum(root->right, leftSum);
}

int Tree::minDepth(TreeNode *root)
{
  if( !root )
    return 0;

  if( !root->left )
  {
    return minDepth(root->right)+1;
  }
  else if( !root->right )
  {
    return minDepth(root->left)+1;
  }
  else
  {
    return std::min(minDepth(root->left), minDepth(root->right))+1;
  }
    
}

bool Tree::isBalanced(TreeNode *root)
{
  if( !root )
    return true;

  int lDepth = depth(root->left);
  int rDepth = depth(root->right);

  if( std::abs(lDepth-rDepth)>1 )
    return false;

  return isBalanced(root->left) && isBalanced(root->right);
}

int Tree::depth(TreeNode *root)
{
  if( !root )
    return 0;

  return 1+std::max(depth(root->left), depth(root->right));
}
