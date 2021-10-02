#include<bits/stdc++.h>
using namespace std;

struct Tree
{
  int key;
  struct Tree *left,*right;
};
//create Nodes
Tree *Node(int data)
{
  Tree * node=(Tree*)malloc(sizeof(Tree));
  node->key=data;
  node->left=node->right=NULL;
  return (node);
}

Tree* LevelOrder(int arr[],Tree* root,int i , int n)
{
  if(i<n)
  {
    Tree* tmp=Node(arr[i]);
    root=tmp;

    //left child
    root->left = LevelOrder(arr,root->left,2*i+1,n);

    //right child
    root->right=LevelOrder(arr,root->right,2*i+2,n);
  }

  return root;
}
int height(Tree* node)
{
    if (node == NULL)
        return 0;
    else
    {
        /* height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);

        if (lheight > rheight)
        {
            return(lheight + 1);
        }
        else {
          return(rheight + 1);
        }
    }
}

void printCurrentLevel(Tree* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->key << " ";
    else if (level > 1)
    {
        printCurrentLevel(root->left, level-1);
        printCurrentLevel(root->right, level-1);
    }
}

void printLevelOrder(Tree* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}

Tree* invertTree(Tree* root) {
        Tree* temp;
        if(root==NULL)
            return root;
        temp=root;

        temp=root->left;
        root->left=root->right;
        root->right=temp;
      invertTree(root->left);
        invertTree(root->right);
        return root;
    }
int main()
{

  int n,num;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)

  cin>>arr[i];
  Tree* root=LevelOrder(arr,root,0,n);
  invertTree(root);
  printLevelOrder(root);
  }

