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
//tim duong di den node co gia tri n
void findPath(Node* root,int n,int* l,int path[],bool* check){
	if(root->data==n){
		path[(*l)++]=n;
		(*check)=true;
		for(int i=0;i<*l;i++){
			printf("%d ",path[i]);
		}
		return;
	}
	path[(*l)++]=root->data;
	if(root->left!=NULL){
		findPath(root->left,n,l,path,check);
	}
	if(root->right!=NULL){
		findPath(root->right,n,l,path,check);
	
	}
	(*l)--; 
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
    int path[100];
    bool check=false;
    int l=0;
	findPath(root1,80,&l,path,&check);    
	if(!check){
		printf("Khong tim thay");
	}
}

