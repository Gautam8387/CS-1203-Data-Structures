/*

[10 points] Given an array with n unique integers, produce a Reverse BST. Here, the left child
is always larger and the right child is always smaller (opposite of a normal BST). Then, print
the elements in prefix order (root, left child, right child).
    NodeAddress arrayToReverseBST(int *a , int n)
    {
        // Your code goes here
        return root;
    }
    void prefixPrint(NodeAddress root)
    {
        // Your code goes here
    }
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct NodeAddress{
    int val;
    struct NodeAddress *left;
    struct NodeAddress *right;
};
typedef struct NodeAddress * NodeAddress;

NodeAddress createNode(int val){
    NodeAddress node = malloc(sizeof(struct NodeAddress));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Inserting an element in a tree
// The place where you want to insert 8 is where you would expect 8 to be (similar to search) 
NodeAddress insertValue(NodeAddress root, int val){
	// Possibility, it is the very first element
	// If root is NULL (it is the first element) you want to insert an element now
    if (root == NULL) {
        return createNode(val);
    }
	// first check if right actually exists
    // Using my own code form github. source: https://github.com/Gautam8387/CS-1203-Data-Structures
    // If the value is less than the root, then it should be on the right side
	if(val < root->val){
		if(root->right){
			return insertValue(root->right, val);
		}
		else{
			root->right = createNode(val);
			return root->right;
		}
	}
    // If the value is greater than the root, then it should be on the left side
	if(val > root->val){
		if(root->left){
			return insertValue(root->left, val);
		}
		else{
			root->left = createNode(val);
			return root->left;
		}
	}
	return root;
	// Post inserting, it will return the root (the parent) to which the child is inserted 
}

// Converting array to BST of decding order. That is right child is always smaller than root and left child is always larger than root
NodeAddress arrayToReverseBST(int *a , int n){
    NodeAddress root = NULL;
    // special case for root
    if(n>0){
        root = createNode(a[0]);
    }
    // general case for inserting all values in BST
    for (int i = 1; i < n; i++)
    {
        insertValue(root, a[i]);
    }
    return root;    
}

// A utility function to do inorder traversal of BST, modified to print in prefix order
// Printing in order root-left-right
void prefixPrint(NodeAddress root){
    if(root == NULL) return;
    printf("%d ", root->val);
    prefixPrint(root->left);
    prefixPrint(root->right);
}

int main(){
    int a[10] = {12, 14, 23456, 23, 24, 29, 43, 56, 576, 4356};
    int n = 10;
    NodeAddress root = arrayToReverseBST(a,n);
    prefixPrint(root);
    return 0;
}
