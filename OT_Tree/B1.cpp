#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node* left;
	struct Node* right;
}Node;

Node* createNode(int n){
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->data=n;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}

Node* insertNodeBST(Node* root,int n){
	if(root==NULL){
		return createNode(n);
	}
	if(root->data>n){
		root->left=insertNodeBST(root->left,n);
	}else{
		root->right=insertNodeBST(root->right,n);
	}
	return root;
}
int calHeightOfBST(Node* root){
	Node* queue[100];
	int levelSize;
	int height=-1;
	int front=0;
	int rear=0;
	queue[rear++]=root;
	while(front<rear){
		height++;
		levelSize=rear-front;
		for(int i=0;i<levelSize;i++){
			Node* tmp=queue[front++];
			if(tmp->left){
				queue[rear++]=tmp->left;
			}
			if(tmp->right){
				queue[rear++]=tmp->right;
			}
		}
	}
	return height;
}
int main(){
	Node* root=NULL;
	root=insertNodeBST(root,50);
	root=insertNodeBST(root, 30);
    root=insertNodeBST(root, 20);
    root=insertNodeBST(root, 40);
    root=insertNodeBST(root, 70);
    root=insertNodeBST(root, 60);
    root=insertNodeBST(root, 80);
    
    int h=calHeightOfBST(root);
    printf("%d",h);
}
