#include <stdio.h>

struct Node{
	int value;
	int height;
	struct Node* left;
	struct Node* right;
};
bool leftLeft(struct Node* key){
	if(key->left==NULL)
		return false;
	if(key->right==NULL){
		if(key->left->height>2)

void balance(struct Node* key){
	if(leftLeft(key)){
		balanceLeftLeft(key);
	}
	else if(leftRight(key)){
		adjustLeftRight(key);
		balanceLeftLeft(key);
	}
	else if(rightRight(key)){
		balanceRightRight(key);
	}
	else{
		adjustRightLeft(key);
		balanceRightRight(key);
	}
}	

struct Node* avl_insert(struct Node* key,int value,int parent_height){
	if(key==NULL){
		struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
		newNode->value=value;
		newNode->left=NULL;
		newNode->right=NULL;
		(parent_height==0)?newNode->height=0:newNode->height=parent_height-1;
		return newNode;
	}
	if(value<=key->value){
		struct Node* newNode=avl_insert(key->left,value,key->height);
		key->left=newNode;
		if(key->left!=NULL)
			key->height=key->left->height+1
		balance(key);
	}
	else{
		struct Node* newNode=avl_insert(key->right,value,key->height);
		key->right=newNode;
		if(key->right!=NULL)
			key->height=key->right->height-1;
		balance(key);
	}
	return key;
}




