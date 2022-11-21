/**
 
[5 points] Given an integer k, print the next largest element (successor) in the Reverse BST.
If k does not exist in this BST, print "Pudding" and if k’s successor does not exist in this BST,
print "Hamburger".
    void successorReverseBST(NodeAddress root, int k)
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
// Printing in order left-root-right
void prefixPrint(NodeAddress root){
    if(root == NULL) return;
    // printf("%d ", root->val);
    prefixPrint(root->left);
    printf("%d ", root->val);
    prefixPrint(root->right);
}

NodeAddress search(NodeAddress root, int val){
    // if the element has no further element, return NULL
    if(root == NULL) return NULL;
    // Move my attention to left subtree, if my val is lesser than the value at the node
    if(root->val == val) return root;
    // Move my attention to right subtree, if my val is greater than the value at the node
    if(val < root->val) return search(root->right, val);
    // if the value if equal to, that is found element, return root
    if(val > root->val) return search(root->left, val);   
}

// To find the parent, we recursively call the function until, the child matched the value
// Reference: https://www.geeksforgeeks.org/find-the-parent-of-a-node-in-the-given-binary-tree/#:~:text=Approach%3A%20Write%20a%20recursive%20function,current%20node%20as%20the%20parent. 
NodeAddress findParent(NodeAddress root, NodeAddress child, NodeAddress *parent){
    if(root == NULL) return root; // if the root is NULL, return NULL
    if(root->left == child || root->right == child){
        return root;
    }
    // Send the value of current root to recursively find the parent node 
    findParent(root->left, child, parent);
    findParent(root->right, child, parent);
}

void successorReverseBST(NodeAddress root, int k){
    // Your code goes here
    NodeAddress temp = search(root, k);
    if(temp == NULL){
        printf("Pudding");
    }
    else{
        // Hamburger will print of the successor is not found, that is k is the biggest element 
        if(temp == root){
            printf("Hamburger");
        }
        // print the parent of the child element if the left child doesnot exist, as it will be the successor
        else if(temp->left == NULL){
            // Find the parent of the child element, pass the root, current address and starting of root
            NodeAddress parent = findParent(root, temp, NULL);
            printf("%d", parent->val);
        }
        else{
            printf("%d", temp->left->val);
        }        
    }
}

int main(){
    int a[7] = {10, 7, 14, 20, 1, 5, 8};
    int n = 7;
    NodeAddress root = arrayToReverseBST(a,n);
    printf("Prefix Print: ");
    prefixPrint(root);
    printf("\n");
    // given integer k
    int k = 1;
    successorReverseBST(root, k);
    return 0;
}
