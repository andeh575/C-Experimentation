/*	Author:		Andrew Graham
/	Date: 		19 August 2015
/	Purpose:	A simple example of binary search tree data structures
/
/	Definition:	A binary tree is either empty (NULL Pointer), or is made of a single node
/				where the left and right pointers each point to a binary tree. A binary search
/				tree is an ordered version of the binary tree - it allows fast insertion and 
/				lookup. 
*/

#include <stdio.h>
#include <stdlib.h> 	// Needed for malloc() and free()
#include <stdbool.h>	// Requires C99: Needed for boolean values

// Typical construction of a binary tree
struct node {
	int val;
	struct node* left;	// Pointer to left subtree
	struct node* right;	// Pointer to right subtree
};

struct node* newNode(int data);
struct node* insert(struct node* node, int data);
bool lookup(struct node* node, int target);
struct node* build123v1(void);	// Build tree using three pointer variables
struct node* build123v2(void); 	// Build tree using only one pointer variable
struct node* build123v3(void);	// Build tree by calling insert() three times and passing it root
int size(struct node* node);	// Returns the number of nodes in a given binary tree
int maxDepth(struct node* node);// Returns the maximum depth of a given binary tree

int main(void) {

	return 0;
}

/*	Helper function that allocates a new node in memory with the given data and NULL left
/	and right pointers.
*/
struct node* newNode(int data) {
	struct node* node = malloc(sizeof(struct node));
	node->val = data;
	node->left = NULL;
	node->right = NULL;
	
	return(node);
}

/* 	Given a binary tree and data, insert a new node with the given number in the correct
/	place in the tree. Return the new root pointer which the caller should then use -
/	this technique avoids reference pointers (ie: **).
/
/	If nodes are inserted in increasing order (1, 2, 3, 4) then the tree nodes  grow to the right,
/	leading to a linked list tree shape, where the left pointers are NULL. If nodes are inserted 
/	in decreasing order (4, 3, 2, 1) then the tree nodes grow to the left, resulting in a similar
/	structure - this defeats lg(N) performance. Balancing is required in order to maintain a good
/	tree structure.
*/
struct node* insert(struct node* node, int data) {
	// Base Case: Tree is empty (NULL)
	if(node == NULL)
		return(newNode(data));
	else {
		// It wasn't empty so we need to recurse down the next subtree
		if(data <= node->val)
			node->left = insert(node->left, data);
		else 
			node->right = insert(node->right, data);
			
		return(node); // Return the (unchanged) node pointer
	}
}

/* 	Given a binary tree, return true if a node with the target data is found in the tree.
/	Recurse down the tree, choose the left or right branch by comparing the rarget to each
/	node
*/
bool lookup(struct node* node, int target) {
	// Base Case: Tree is empty (NULL)
	if(node == NULL)
		return false;
	// Test to see if this is the correct node?
	else {
		if(node->val == target)
			return true;
		// It wasn't so recurse down to the next subtree
		else {
			if(target < node->val)
				return(lookup(node->left, target));
			else
				return(lookup(node->right, target));
		}
	}
}

//	Builds a small binary tree by calling newNode() three times, using three pointer variables
struct node* build123v1(void) {
	struct node* root = newNode(2);
	struct node* lChild = newNode(1);
	struct node* rChild = newNode(3);
	
	root->left = lChild;
	root->right = rChild;
	
	return(root);
}

// Builds a small binary tree by calling newNode() three times, using one pointer variable
struct node* build123v2(void) {
	struct node* root = newNode(2);
	
	root->left = newNode(1);
	root->right = newNode(3);
	
	return(root);
}

// Builds a small binary tree by calling insert() three times by passing it the root pointer
struct node* build123v3(void) {
	struct node* root = NULL;
	
	root = insert(root, 2);
	root = insert(root, 1);
	root = insert(root, 3);
	
	return(root);
}

// Given a binary tree, count the number of nodes in the tree
int size(struct node* node) {
	if(node == NULL)
		return(0); // If node is empty then we add nothing to the total size
	else
		return(size(node->left) + 1 + size(node->right)); // Counts this node, recurse to subtrees
}

/*  Given a binary tree, count the number of nodes along the longest path from the root node down
/	to the farthest leaf node. An empty tree as a maxDepth of 0. 
*/
int maxDepth(struct node* node) {
	if(node == NULL)
		return(0); // If node is empty then we add nothing to the depth
	// Recurse to subtrees calculating the depth of the farthest leaf
	else {
		int leftDepth = maxDepth(node->left);
		int rightDepth = maxDepth(node->right);
		
		// Use the large depth
		if(leftDepth > rightDepth)
			return(leftDepth + 1);
		else
			return(rightDepth + 1); 
	}
}