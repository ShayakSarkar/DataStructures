#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Node{
	int value;
	struct Node* right;
	struct Node* left;
};

void bt_insert(struct Node* key,int value){
	if(key==NULL){
		printf("ROOT node invalid");
		return;
	}
	if(key->left==NULL && key->right==NULL){
		if(value <= key->value){
			struct Node newNode;
			newNode.left=NULL;
			newNode.right=NULL;
			newNode.value=value;
			key->left=&newNode;
			
		}
		else{
			struct Node newNode;
			newNode.left=NULL;
			newNode.right=NULL;
			newNode.value=value;
			key->right=&newNode;
		}
	}
	if(key->value<=value)
		bt_insert(key->left,value);
	else
		bt_insert(key->right,value);
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
int main(){
	printf("Hello World");
	struct Node* node=(struct Node*)malloc(sizeof(struct Node));

}

		



	


			

