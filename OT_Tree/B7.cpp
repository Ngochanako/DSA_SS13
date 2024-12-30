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
//tim gia tri lon nhat
int findMax1(Node* root,int max){
	if(root==NULL){
		return max;
	}
	if(root->data>max){
		max=root->data;
	}
    if(max<	findMax1(root->left,max)){
    	max=findMax1(root->left,max);
	}
	if(max<	findMax1(root->right,max)){
    	max=findMax1(root->right,max);
	}
	return max;
}
void findMax2(Node* root,int* max){
	if(root==NULL){
		return;
	}
	if(root->data>* max){
		(*max)=root->data;
	}
	findMax2(root->left,max);	
	findMax2(root->right,max);
}
//dem so node trong cay lon hon n
void countNode(Node* root,int n,int* cnt){
	if(root==NULL){
		return;
	}
	if(root->data>n){
		(*cnt)++;
	}
	countNode(root->left,n,cnt);
	countNode(root->right,n,cnt);
}
//ham so sanh 2 cay 
bool areIdentical(Node* root1, Node* root2) {
    if (root1 == NULL && root2 == NULL) {
        return true;
    }
    if (root1 == NULL || root2 == NULL) {
        return false;
    }
    return (root1->data == root2->data) &&
           areIdentical(root1->left, root2->left) &&
           areIdentical(root1->right, root2->right);
}

int main() {
    Node* root1 = NULL;

    root1 = insertNodeBST(root1, 50);
    root1 = insertNodeBST(root1, 30);
    root1 = insertNodeBST(root1, 70);
    root1 = insertNodeBST(root1, 20);
    root1 = insertNodeBST(root1, 40);
    root1 = insertNodeBST(root1, 60);
    root1 = insertNodeBST(root1, 80);
    
    Node* root2 = NULL;

    root2 = insertNodeBST(root2, 50);
    root2 = insertNodeBST(root2, 30);
    root2 = insertNodeBST(root2, 70);
    root2 = insertNodeBST(root2, 20);
    root2 = insertNodeBST(root2, 40);
    root2 = insertNodeBST(root2, 60);
    root2 = insertNodeBST(root2, 80);
    
    if(areIdentical(root1,root2)){
    	printf("YES");
	}else{
		printf("NO");
	}
}

