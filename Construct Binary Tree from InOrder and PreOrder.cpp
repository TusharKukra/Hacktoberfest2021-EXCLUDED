/*Given preorder and inorder traversal of a tree, construct the binary tree.

Note: You may assume that duplicates do not exist in the tree.*/

/*
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
  
TreeNode* util(vector<int>& preorder, vector<int>& inorder, int l, int h, int& idx,unordered_map<int,int>& mp){
    
  if(l>h) return NULL;
  
  TreeNode* root=new TreeNode(preorder[idx]);
  int index=mp[preorder[idx]];
  idx++;
  
  root->left=util(preorder,inorder,l,index-1,idx,mp);
  root->right=util(preorder,inorder,index+1,h,idx,mp);
  
  return root;
    
}
    
  
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    
  int n=A.size(), idx=0;
  unordered_map<int,int> mp;

  for(int i=0;i<A.size();i++) mp[B[i]]=i;
  
  TreeNode* root=util(A,B,0,n-1,idx,mp);
  
  return root;
}
