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
bool isSameTree(TreeNode *p, TreeNode *q) {

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
