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

  bool hasPathSum(TreeNode *root, int sum);

  int minDepth(TreeNode *root);

  int maxDepth(TreeNode *root);

  bool isBalanced(TreeNode *root);

  std::vector<std::vector<int> > levelOrder(TreeNode *root);
  
  std::vector<std::vector<int> > levelOrderBottom(TreeNode *root);
private:

  int depth(TreeNode *root);
};
