#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swapValues(int* arr,int ind1,int ind2){
	int temp=arr[ind1];
	arr[ind1]=arr[ind2];
	arr[ind2]=temp;
}

int getValidChild(int* arr,int rootInd,int d,int length){
	int bestChild=-1;
	for(int i=0;i<d;i++){
		if(rootInd*d+(i+1)>=length)
			break;
		if(bestChild==-1){
			bestChild=rootInd*d+(i+1);
			continue;
		}
		if(arr[rootInd*d+(i+1)]>arr[bestChild])
			bestChild=rootInd*d+(i+1);
	}
	if(bestChild==-1)
		return -1;
	if(arr[bestChild]>arr[rootInd])
		return bestChild;
	return -1;
}
void siftDown(int* arr,int rootInd,int d,int length){
	if(rootInd>=length)
		return;
	int childInd=getValidChild(arr,rootInd,d,length);
	if(childInd==-1){	// No appropriate Child found. Root need not be sifted
		return;
	}
	swapValues(arr,rootInd,childInd);
	siftDown(arr,childInd,d,length);
}
void heapify(int* arr,int rootInd,int d,int length){
	if(rootInd>=length)
		return;
	for(int i=0;i<d;i++)
		heapify(arr,rootInd*d+(i+1),d,length);
	siftDown(arr,rootInd,d,length);

}
void printHeap(int* arr,int length){
	for(int i=0;i<length;i++)
		printf("%d ",arr[i]);
	printf("\n");
}
int main(){
	int length=12;
	int* arr=(int*)malloc(sizeof(int)*length);
	arr[0]=12;
	arr[1]=20;
	arr[2]=55;
	arr[3]=33;
	arr[4]=24;
	arr[5]=10;
	arr[6]=1;
	arr[7]=8;
	arr[8]=33;
	arr[9]=27;
	arr[10]=17;
	arr[11]=9;
	heapify(arr,0,1,12);	// pointer, rootInd, d, length
	printHeap(arr,12);
}
