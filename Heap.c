#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct Heap{
	int* arr;
	int insertion_point;	//index at which value should be inserted
	int capacity;
};

struct Heap* initHeap(int length){
	struct Heap* h=(struct Heap*)malloc(sizeof(struct Heap));
	h->arr=(int*)malloc(2*sizeof(int)*length);
	h->insertion_point=0;
	h->capacity=length*2;	//Minimum size of the heap should be twice the number of nodes
	return h;
}

void siftUp(struct Heap* h,int index){
	if(index<=0)
		return;
	int parent_ind=(index%2!=0)?(index-1)/2 : (index-2)/2;

	if(h->arr[index]>h->arr[parent_ind]){
		int t=h->arr[index];
		h->arr[index]=h->arr[parent_ind];
		h->arr[parent_ind]=t;
		siftUp(h,parent_ind);
	}
}

void hp_insert(struct Heap* h,int value){
	h->arr[h->insertion_point]=value;
	siftUp(h,h->insertion_point);
	h->
}
void siftDown(struct Heap* h,int index){
	int left_child=index*2+1;
	int right_child=index*2+2;
	
	if(left_child<h->insertion_point){
		if(right_child<insertion_point){
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

int hp_poll(struct Heap* h){
	int ret_val=h->arr[0];
	h->arr[0]=h->arr[h->insertion_point-1];
	h->insertion_point--;
	siftDown(h,0);
	return ret_val;
}

int main(){

}
