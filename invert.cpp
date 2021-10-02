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
    node->left=NULL;
    node->right=NULL;
    return node;
}

TreeNode* insert(TreeNode* root, int data){
    if(root==NULL)root=newnode(data);
    if(data>root->val)root->right=insert(root->right,data);
    else root->left=insert(root->left,data);
    return root;
}
void invert(TreeNode* root){
    if(root!=NULL){
    TreeNode* temp=root->left;
    root->left=root->right;
    root->right=temp;
    }
    invert(root->left);
    invert(root->right);

}

int main(){
    int n;
    cin>>n;
    TreeNode* root=NULL;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        root=insert(root,k);
    }
    invert(root);
}