#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

struct Heap{
	int* arr;
	int insertion_point;	//index at which value should be inserted
	int capacity;
};

//initHeap: initialises the required fields for the heap data structure
//---------------------------------------------------------------------
struct Heap* initHeap(int length){		
	struct Heap* h=(struct Heap*)malloc(sizeof(struct Heap));
	h->arr=(int*)malloc(2*sizeof(int)*length);
	h->insertion_point=0;
	h->capacity=length*2;	//Minimum size of the heap should be twice the number of nodes
	return h;
}

//helper function to swap two numbers. 
//This can be modified to accomodate different data types in the heap
//--------------------------------------------------------------------------------------------------------
void swap(int* a,int* b){
	int t=*a;
	*a=*b;
	*b=t;
}

//helper function to allow the inserted number to percolate upwards and find its location
//---------------------------------------------------------------------------------------
void siftUp(struct Heap* h,int index){
	if(index<0)
		return;
	int parent_ind=(index%2!=0)?(index-1)/2 : (index-2)/2;
	if(parent_ind<0)
		return;
	if(h->arr[index]<h->arr[parent_ind]){
		int t=h->arr[index];
		h->arr[index]=h->arr[parent_ind];
		h->arr[parent_ind]=t;
		siftUp(h,parent_ind);
	}
}

//function to insert an integer into the heap
//-------------------------------------------
void hp_insert(struct Heap* h,int value){
	if(h->insertion_point>=h->capacity){
		printf("Sorry heap memory limit exceeded");
		return;
	}
	h->arr[h->insertion_point]=value;
	siftUp(h,h->insertion_point);
	h->insertion_point++;
}

//function to percolate an integer downwards in the heap into its correct location
//--------------------------------------------------------------------------------
void siftDown(struct Heap* h,int index){
	int left_child=index*2+1;
	int right_child=index*2+2;
	
	if(left_child<h->insertion_point){
		if(right_child<h->insertion_point){
			if(h->arr[index]>h->arr[left_child] && h->arr[index]>h->arr[right_child]){
				int next_ind=(h->arr[left_child]>h->arr[right_child])?right_child:left_child;
				swap(h->arr+next_ind,h->arr+index);
				siftDown(h,next_ind);
			}
			else if(h->arr[index]>h->arr[left_child]){
				swap(h->arr+index,h->arr+left_child);
				siftDown(h,left_child);
			}
			else{
				swap(h->arr+right_child,h->arr+index);	
				siftDown(h,right_child);
			}
		}
		if(h->arr[index]>h->arr[left_child]){
			swap(h->arr+left_child,h->arr+index);
			siftDown(h,h->arr[left_child]);
		}
	}
}

//function to poll the value with the highest priority in the heap 
//implementing the priority queue
//----------------------------------------------------------------
int hp_poll(struct Heap* h){
	if(h->insertion_point==0){
		printf("Heap underflow");
		return INT_MIN;
	}
	int ret_val=h->arr[0];
	h->arr[0]=h->arr[h->insertion_point-1];
	h->insertion_point--;
	siftDown(h,0);
	return ret_val;
}

//function to print the priority queue internal array
//----------------------------------------------------
void hp_print(struct Heap* h){
	for(int i=0;i<h->insertion_point;i++)
		printf("%d ",h->arr[i]);
	printf("\n\n");
}

int main(){
	struct Heap* h=initHeap(10);
	hp_insert(h,5);
	hp_insert(h,3);
	hp_insert(h,4);
	hp_insert(h,1);
	hp_insert(h,2);
	printf("Priority queue internal array: ");
	hp_print(h);
	printf("%d polled\n",hp_poll(h));
	printf("%d polled\n",hp_poll(h));
	printf("%d polled\n",hp_poll(h));
	printf("%d polled\n",hp_poll(h));
	printf("%d polled\n",hp_poll(h));
	printf("%d polled\n",hp_poll(h));
}
