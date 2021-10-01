#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
  int val;
  TreeNode *right;
  TreeNode *left;
};

TreeNode* newnode(int data){
    TreeNode* node=new TreeNode();
    node->val=data;
    node->right=NULL;
    node->left=NULL;
    return node;
}

TreeNode* insert(TreeNode* ptr,int data){
   if(ptr==NULL)ptr=newnode(data);

   if(data>ptr->val)ptr->right=insert(ptr->right,data);
   else ptr->left=insert(ptr->left,data);
   return ptr;

}

TreeNode* find(TreeNode* ptr,int b){
    if(ptr->val==b)return ptr;
    if(ptr->val<b)find(ptr->right,b);
    else find(ptr->left,b);
    return NULL;
}

TreeNode* findAncestor(TreeNode* root, TreeNode*ptr, int b){
      TreeNode *successor = NULL;
        TreeNode *ancestor = root;
        while(ancestor != ptr){
            if(ptr->val < ancestor->val){
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else ancestor = ancestor->right;
        }
        return successor;
}


int main(){
    TreeNode* root=NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        root=insert(root,k);
    }
    int b;
    cin>>b;
    TreeNode* current=NULL;
    current=find(root,b);

    if(current->right!=NULL){
        current=current->right;
        while(current->left!=NULL){
            current=current->left;
        }
    }

    else{
       TreeNode* successor= findAncestor(root,current,b);
    }

}