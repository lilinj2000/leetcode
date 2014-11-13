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

class Tree
{
public:
  struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
  
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
  
  bool isSameTree(TreeNode *p, TreeNode *q);
};
