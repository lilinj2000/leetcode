/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <cstddef>
#include <vector>
#include "List.h"

#ifndef TREE_H
#define TREE_H

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  
 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeLinkNode {
  TreeLinkNode *left;
  TreeLinkNode *right;
  TreeLinkNode *next;

 TreeLinkNode(): left(NULL), right(NULL), next(NULL)
  {
  }
};
  
class Tree
{
public:
  
  bool isSameTree(TreeNode *p, TreeNode *q);

  bool hasPathSum(TreeNode *root, int sum);

  int minDepth(TreeNode *root);

  int maxDepth(TreeNode *root);

  bool isBalanced(TreeNode *root);

  std::vector<std::vector<int> > levelOrder(TreeNode *root);
  
  std::vector<std::vector<int> > levelOrderBottom(TreeNode *root);

  void flatten(TreeNode *root);

  void connect(TreeLinkNode* root);

  std::vector<std::vector<int> > pathSum(TreeNode *root, int sum);

  TreeNode* sortedListToBST(ListNode* head);
  
private:

  int depth(TreeNode *root);

  void pathSum(TreeNode *root, int sum, std::vector<int>& path, std::vector<std::vector<int> >& res);

  TreeNode* sortedListToBST(std::vector<int>& data, int start, int end);
};

#endif
