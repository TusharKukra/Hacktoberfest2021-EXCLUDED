/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  TreeNode* invertTree(TreeNode* root) {
    f(root);
    return root;
  }
  void f(TreeNode* root) {
    if(root == NULL) return;
    TreeNode* tmp = root->right;
    root->right = root->left;
    root->left = tmp;
    f(root->left);
    f(root->right);
  }
};
