/*

	1 -> 22 -> 333 -> 555 -> 999 -> NULL

*/

// Think of it as lift, and you go from floor 1 -> floor 22 -> floor 333
// Cannot skip from 1 to 333
// Suppose you have thousand of these numbers and someone asks if 77 is in the list
// Start at beginning and go one by one: first approach. This is stupid and slow
// There are mechnaism to do this searching: 1. Skip List, 2. Trees
// Both arise from the linked list 


// BINARY SEARCH TREES
// Instead of an item pointing to another item, it is useful to have an item which points to two item and then both point to two items each
// Linked List, there is a clear concept of order.
// Binary Trees have an invarint: Everything to left is smaller, everything to right is bigger.
// This reduces the search space, if I know the think I am searching is smaller than right, I donot have to go to right subtree to search.

#include<stdio.h>
#include<stdlib.h>
struct nodeType
{
	int val;
	// Every node has two branches (children)
	struct nodeType * left; 	// smaller
	struct nodeType * right;	// larger
};
// This in focused term, in terms of node, not as a whole tree

typedef struct nodeType * nodeAddress;

/*

	4, left: 2, right: 7
	2, left: 1, right: 3
	7, left: 5, right: 9
	1, 3, 5, 9 -> left: NULL, right: NULL
	The moment you follow left child, you'll only find smaller stuff. And the moment you follow right you'll only find the bigger stuff

*/
// If you find a value, return a node address, return NULL if element not found

nodeAddress search(nodeAddress root, int val){
	// Writing Recursive function is really elegant
	// if the element has no further element, return NULL
	if (root == NULL) {return NULL;}
	// Move my attention to left subtree, if my val is lesser than the value at the node
	if(val < root->val) {return search(root->left, val);} 
	// Move my attention to right subtree, if my val is greater than the value at the node
	else if (val > root->val) {return search(root->right, val);} 
	// if the value if equal to, that is found element, return root
	else {return root;}
}

// An idea is to have a single return statement
nodeAddress search2(nodeAddress root, int val){
	if (root) {
		// if root is a vlaid element and it exists, then only we check
	//  (val < root->val)?search(root->left, val):search(root->right, val);

		// where are we testing if it is exactly euqal or not
		return root?((val==root->val)?root:((val < root->val)?search(root->left, val):search(root->right, val))):NULL;
	}
}

// Inserting an element in a tree
// The place where you want to insert 8 is where you would expect 8 to be (similar to search) 
nodeAddress insert(nodeAddress root, int val){
	// Possibility, it is the very first element
	// If root is NULL (it is the first element) you want to insert an element now
	if (root == NULL) {return createNode(val);}
	
	// If it is not NUll?
	if(val < root->val) { root->left = insert(root->left, val);} 
	else if (val > root->val) {root->right = insert(root->right, val);} 
	// Post inserting, it will return the root (the parent) to which the child is inserted 
	return root;
}

nodeAddress insert2(nodeAddress root, int val){
	if (root == NULL) {return createNode(val);}
	// first check if left actually exists
	if(val < root->val){
		if(root->left){return insert(root->left, val);}
		else{root->left = createNode(val);
		return root->left;}
	}

	if(val > root->val){
		if(root->right){return insert(root->right, val);}
		else{root->right = createNode(val);
		return root->right;}
	}

	return root;
}

// How to delete stuff??
// If its the end nodes getting deleted, its trival. What if its somewhere in the middle
// In-order trivarsal, in order to delete
// Dont want a degenrate tree (it is just like a linked list)
// We need a well balanced tree
// Print order: Left-Root-Right 

void inOrder(nodeAddress root){
	// Print entrie thing in order: Left-Root_Right
	if(root->left){
		inOrder(root->left);
	}
	// check if root exist for printing
	if(root){
		printf("%d",root->val);
	}
	if(root->right){
		inOrder(root->right);
	}
}
