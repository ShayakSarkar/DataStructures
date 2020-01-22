#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Node{
	int value;
	struct Node* right;
	struct Node* left;
};

struct Node* bt_insert(struct Node* key,int value){
	if(key==NULL){
		struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
		newNode->value=value;
		newNode->left=NULL;
		newNode->right=NULL;
		return newNode;
	}
	else if(value<key->value){
		key->left=bt_insert(key->left,value);
		return key;
	}
	else{
		key->right=bt_insert(key->right,value);
		return key;
	}
	printf("Encountered an error");
	return NULL;

}

struct Node* findMaxAndDelete(struct Node* key,int value){		
	struct Node* parent=key;
	struct Node* child=parent->right;	//called only in the third case, therefore, right child is guaranteed
	while(child!=NULL){
		child=child->right;
		parent=parent->right;
	}
	//child is the largest value currently as it is the rightmost
	
	parent->right=child->left;
	return child;
}

struct Node* bt_delete(struct Node* key,int value){
	if(value<key->value){
		key->left=bt_delete(key->left,value);
		return key;
	}
	else if(value>key->value){
		key->right=bt_delete(key->right,value);
		return key;
	}
	else{
		if(key->left==NULL)
			return key->right;
		else if(key->right=NULL)
			return key->left;
		else{
			struct Node* node=findMaxAndDelete(key->left,value);
			key->value=node->value;
			return key;
		}
	}
}
void printTree(struct Node* key){
	if(key==NULL)
		return;
	printTree(key->left);
	printf(" %d ",key->value);
	printTree(key->right);
}
		
int main(){
	struct Node* root=(struct Node*)malloc(sizeof(struct Node));
	root->value=15;
	bt_insert(root,5);
	bt_insert(root,11);
	bt_insert(root,20);
	bt_insert(root,12);
	bt_insert(root,2);
	bt_delete(root,2);
	printTree(root);
}

		



	


			

