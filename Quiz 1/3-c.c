/*

[5 points] Given any two integers x and y in the Reverse BST, find the distance between the
two in sorted order. That is, count how many numbers lie in between these two integers x and
y. If x, y or both x and y don’t exist in the BST, return -1. 
    int sortedDistance(NodeAddress root, int x, int y)
        {
            // Your code goes here
            return distance;
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

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Inserting an element in a tree. The place where you want to insert 8 is where you would expect 8 to be (similar to search)
NodeAddress insertValue(NodeAddress root, int val){
	if (root == NULL) {
        return createNode(val);
    }
	if(val < root->val){
		if(root->right){
			return insertValue(root->right, val);
		}
		else{
			root->right = createNode(val);
			return root->right;
		}
	}
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
// Given a root convert the binary seach tree to a sorted array
void BSTtoArray(NodeAddress root, int *a, int *i){
    if(root == NULL) return;
    BSTtoArray(root->left, a, i);
    a = realloc(a, sizeof(int));
    a[*i] = root->val;
    *i = *i + 1;
    BSTtoArray(root->right, a, i);
}

int sortedDistance(NodeAddress root, int x, int y){
    // Your code goes here
    NodeAddress xNode = search(root, x);
    NodeAddress yNode = search(root, y);
    if(xNode == NULL || yNode == NULL){ 
        return -1;
    }
    if(x==y){
        return 0;
    }
    // Since the BST is in reverse order, the first integer should be greater than the second
    if(x<y){
        swap(&x, &y);
    }
    // Convert the BST to a sorted array
    int n = 0;
    int *a = malloc(sizeof(int));
    BSTtoArray(root, a, &n);
    int i = 0;
    int j = 0;
    // Find the index of the first integer
    for (i = 0; i < n; i++)
    {
        if(a[i] == x){
            break;
        }
    }
    // Find the index of the second integer
    for (j = 0; j < n; j++)
    {
        if(a[j] == y){
            break;
        }
    }
    // Return the distance between the two integers
    return j-i-1;

}

int main(){
    int a[10] = {12, 14, 23456, 23, 24, 29, 43, 56, 576, 4356};
    int n = 10;
    NodeAddress root = arrayToReverseBST(a,n);
    prefixPrint(root);
    int x, y;
    printf("\nInput x: ");
    scanf("%d", &x);
    printf("Input y: ");
    scanf("%d", &y);
    int distance = sortedDistance(root, x, y);
    printf("Distance (excluding) between %d and %d is %d", x, y, distance);
    return 0;
}
