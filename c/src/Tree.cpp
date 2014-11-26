#include <algorithm>
#include <queue>
#include <iostream>

#include "Tree.h"

#define log(x) std::cerr <<"[Tree] " <<x <<std::endl;
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

int Tree::maxDepth(TreeNode *root)
{
  if( !root )
    return 0;

  if( !root->left )
  {
    return maxDepth(root->right)+1;
  }
  else if( !root->right )
  {
    return maxDepth(root->left)+1;
  }
  else
  {
    return std::max(maxDepth(root->left), maxDepth(root->right))+1;
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

std::vector<std::vector<int> > Tree::levelOrder(TreeNode *root)
{
  std::vector<std::vector<int> > res;

  if( !root )
    return res;

  std::queue<TreeNode *> dataQueue;
  std::vector<int> level;
  
  // push the first level
  dataQueue.push(root);
  dataQueue.push(NULL);

  while( !dataQueue.empty() )
  {
    TreeNode *node = dataQueue.front();
    dataQueue.pop();

    if( node )
    {
      level.push_back(node->val);

      if( node->left )
        dataQueue.push(node->left);

      if( node->right )
        dataQueue.push(node->right);
    }
    else
    {
      res.push_back(level);
      level.clear();

      if( dataQueue.empty() )
        break;

      dataQueue.push(NULL);
    }
  }

  return res;
}

std::vector<std::vector<int> > Tree::levelOrderBottom(TreeNode *root)
{
  std::vector<std::vector<int> > res = levelOrder(root);

  std::reverse(res.begin(), res.end());

  return res;
}

void Tree::flatten(TreeNode *root)
{
  if( !root )
    return;

  if( root->left )
  {
    TreeNode* leftNode = root->left;
    TreeNode* rightNode = root->right;

    root->right = leftNode;
    root->left = NULL;

    TreeNode* p = leftNode;
    while( p->right )
      p = p->right;

    p->right = rightNode;
  }

  flatten(root->right);
}

void Tree::connect(TreeLinkNode* root)
{
  if( !root )
    return;

  if( root->left )
  {
    root->left->next = root->right;
  }

  if( root->right && root->next )
  {
    root->right->next = root->next->left;
  }

  connect(root->left);
  connect(root->right);
}

std::vector<std::vector<int> > Tree::pathSum(TreeNode *root, int sum)
{
  std::vector<std::vector<int> > res;
  if( !root )
    return res;

  std::vector<int> path;
  pathSum(root, sum, path, res);

  return res;
}

void Tree::pathSum(TreeNode *root, int sum, std::vector<int>& path, std::vector<std::vector<int> >& res)
{
  if( !root )
    return;

  path.push_back(root->val);
  if( root->left==NULL && root->right==NULL && root->val==sum)
  {
      res.push_back(path);
  }

  int leftSum = sum - root->val;

  if( root->left )
    pathSum(root->left, leftSum, path, res);

  if( root->right )
    pathSum(root->right, leftSum, path, res);

  path.pop_back();
}

TreeNode* Tree::sortedListToBST(ListNode* head)
{
  TreeNode* root = NULL;

  if( !head )
    return root;

  std::vector<int> vecData;
  for( ListNode* p=head; p; p=p->next )
    vecData.push_back(p->val);

  root = sortedListToBST(vecData, 0, vecData.size()-1);
}

TreeNode* Tree::sortedListToBST(std::vector<int>& data, int start, int end)
{
  if( start>end )
    return NULL;
  
  int mid = (start+end)/2;

  TreeNode* node = new TreeNode(data[mid]);

  node->left = sortedListToBST(data, start, mid-1);

  node->right = sortedListToBST(data, mid+1, end);

  return node;
}
