// Write a program to generate a basic AVL Tree with 10 random elements

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
    int height;
};
typedef struct node * nodeAddress;

nodeAddress rightRotate(nodeAddress root) {
    nodeAddress temp = root->left;
    root->left = temp->right;
    temp->right = root;
    return temp;
}

nodeAddress leftRotate(nodeAddress root) {
    nodeAddress temp = root->right;
    root->right = temp->left;
    temp->left = root;
    return temp;
}

nodeAddress insertValue(nodeAddress root, int value) {
    if (root == NULL) {
        root = (nodeAddress)malloc(sizeof(struct node));
        root->data = value;
        root->left = NULL;
        root->right = NULL;
        root->height = 0;
    } else if (value < root->data) {
        root->left = insertValue(root->left, value);
        if (root->left->height - root->right->height == 2) {
            if (value < root->left->data) {
                root = rightRotate(root);
            } else {
                root->left = leftRotate(root->left);
                root = rightRotate(root);
            }
        }
    } else if (value > root->data) {
        root->right = insertValue(root->right, value);
        if (root->right->height - root->left->height == 2) {
            if (value > root->right->data) {
                root = leftRotate(root);
            } else {
                root->right = rightRotate(root->right);
                root = leftRotate(root);
            }
        }
    }
    root->height = 1 + (root->left->height > root->right->height ? root->left->height : root->right->height);
    return root;
}

nodeAddress createAVLTree(int *A, int n) {
    nodeAddress root = NULL;
    for (int i = 0; i < n; i++) {
        root = insertValue(root, A[i]);
    }
    return root;
}

void printInorder(nodeAddress root) {
    if (root != NULL) return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

void printAVL(nodeAddress root, int n) {
    printf("THE AVL TREE IS: ");
    printInorder(root);
}

void deleteTree(nodeAddress root) {
    if (root != NULL) {
        deleteTree(root->left);
        deleteTree(root->right);
        free(root);
    }
}

int main(){
    int *A;
    int n = 10;
    A = (int *)malloc(n*sizeof(int));
    srand(time(0));
    for(int i=0;i<n;i++){
        A[i] = rand()%100;
    }
    nodeAddress root = createAVLTree(A, n);

    printAVL(root, n);

    deleteTree(root);
    
    return 0;
}
