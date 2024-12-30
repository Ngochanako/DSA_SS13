#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Tao nut moi
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// chen vao cay nhi phan tim kiem
Node* insertNodeBST(Node* root, int data) {
    if (root == NULL) {
        return createNode(data); 
    }

    if (data < root->data) {
        root->left=insertNodeBST(root->left, data); 
    } else if (data > root->data) {
        root->right= insertNodeBST(root->right, data); 
    }

    return root; 
}
// Chen nut vao cay nhi phan thuong
void insertNodeBinaryTree(Node** root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
        return;
    }

    if ((*root)->left == NULL) {
        insertNodeBinaryTree(&(*root)->left, data);
    } else if ((*root)->right == NULL) {
        insertNodeBinaryTree(&(*root)->right, data);
    } else {
        insertNodeBinaryTree(&(*root)->left, data);
    }
}
// Duyet giua
void inorderTraversal(Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}
// Duyet truoc
void preOrderTraversal(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// Duyet sau
void postOrderTraversal(Node* root) {
    if (root == NULL) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->data);
}
int main() {
    Node* root = NULL;

    root = insertNodeBST(root, 50);
    root = insertNodeBST(root, 30);
    root = insertNodeBST(root, 70);
    root = insertNodeBST(root, 20);
    root = insertNodeBST(root, 40);
    root = insertNodeBST(root, 60);
    root = insertNodeBST(root, 80);

    printf("Duyet truoc: ");
    preOrderTraversal(root);
     printf("Duyet giua: ");
    inorderTraversal(root);
     printf("Duyet sau: ");
    postOrderTraversal(root);
}

