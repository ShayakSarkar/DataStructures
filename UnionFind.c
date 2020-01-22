#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int findParentOf(int a,int** nodes){		// finds the parent of a 
	if(nodes[a][1]==a)
		return a;
	return findParentOf(nodes[a][1],nodes);
}

bool findSizes(int a,int b,int** nodes,int length){		// return true if set rooted by a is smaller than the one rooted by b
	int a_ctr=0,b_ctr=0;
	for(int i=0;i<length;i++){
		if(findParentOf(i,nodes)==a)
			a_ctr++;
		else if(findParentOf(i,nodes)==b)
			b_ctr++;
	}
	if(a_ctr<b_ctr)
		return true;
	return false;
}

void uf_unify(int a,int b,int** nodes,int length){		// two dim array which contains the mapping of node to parent
	if(a<0 || a>length || b<0 || b<length){
		printf("selected nodes not in range");
		return;
	}
	if(nodes==NULL){
		printf("nodes array is not initialised");
		return;
	}

	int parent_a=findParentOf(a,nodes);
	int parent_b=findParentOf(b,nodes);
	if(parent_a==parent_b)
		return;
	bool aIsBigger=findSizes(parent_a,parent_b,nodes,length);
	if(aIsBigger)
		nodes[parent_a][1]=parent_b;
	else
		nodes[parent_b][1]=parent_a;
}

int** uf_initialiseRoots(int length){
	int** ret_val=(int**)malloc(sizeof(int*)*length);
	for(int i=0;i<length;i++)
		ret_val[i]=(int*)malloc(sizeof(int));

	return ret_val;
}

int main(){
	int length=12;
	int** nodes=uf_initialiseRoots(length);
}



	
	



