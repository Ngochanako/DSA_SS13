#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
//tinh so la
void calLeaf(Node* root,int* cnt){
	if (root->left == NULL&&root->right==NULL){
		(*cnt)++;
		return;
		
	} 
    calLeaf(root->left,cnt);
    calLeaf(root->right,cnt);
}
//tim kiem trong cay nhi phan tim kiem
bool search(Node* root,int n){
	if(root==NULL){
		return false;
	}
	if(root->data==n){
		return true;
	}
	if(root->data<n){
		if(search(root->right,n)){
		   return true;
	   }
	}else{
	    if(search(root->left,n)){
		   return true;
	    }	
	}	
	return false;
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
    int searchValue1 = 10;
    int searchValue2 = 80;
    printf("Tim kiem %d: %s\n", searchValue1, search(root, searchValue1) ? "Tim thay" : "Khong tim thay");
    printf("Tim kiem %d: %s\n", searchValue2, search(root, searchValue2) ? "Tim thay" : "Khong tim thay");
}

