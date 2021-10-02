// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
/*
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
*/


#include <bits/stdc++.h>
using namespace std;

class node
{
	public:
	int data;
	node* left, *right;
};

node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = Node->right = NULL;
	return(Node);
}


node *lca(node* root, int n1, int n2)
{
	if (root == NULL) return NULL;

	// If both n1 and n2 are smaller
	// than root, then LCA lies in left
	if (root->data > n1 && root->data > n2)
		return lca(root->left, n1, n2);

	// If both n1 and n2 are greater than
	// root, then LCA lies in right
	if (root->data < n1 && root->data < n2)
		return lca(root->right, n1, n2);

	return root;
}


int main()
{
	node *root = newNode(20);
	root->left = newNode(8);
	root->right = newNode(22);
	root->left->left = newNode(4);
	root->left->right = newNode(12);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(14);

	int n1 = 10, n2 = 14;
	node *t = lca(root, n1, n2);
	cout << "LCA of " << n1 << " and " << n2 << " is " << t->data<<endl;

	n1 = 14, n2 = 8;
	t = lca(root, n1, n2);
	cout<<"LCA of " << n1 << " and " << n2 << " is " << t->data << endl;

	n1 = 10, n2 = 22;
	t = lca(root, n1, n2);
	cout << "LCA of " << n1 << " and " << n2 << " is " << t->data << endl;
	return 0;
}

// This code is contributed by rathbhupendra
