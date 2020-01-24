#include <stdbool.h>
#include <limits.h>
#include <stdio.h>

int parentOf(int i){	//i is one based index, function should return 0 based index
	int prod=1;
	while(i%2==0){
		i/=2;
		prod*=2;
	}
	prod*=2;
	return (prod-1)+(i-1);	//0 based index
}

void ft_makeTree(int* arr,int length){
	for(int i=0;i<length;i++){	//Fenwick tree is 1 based.  
		int parent=parentOf(i+1);
		//printf("parent of %d is %d\n",(i+1),parent);
		if(parent<length)
			arr[parent]+=arr[i];
	}
}

void ft_update(int* arr,int length,int index,int delta){
	if(index<0 || index>=length){
		printf("index out of bounds");
		return;
	}
	while(index<length){
		arr[index]+=delta;
		index=parentOf(index+1);
	}
}

int next(int index){	//index is 0 based, gives the next independent index -- helper for range query
	index++;
	int prod=1;
	while(index%2==0){
		prod*=2;
		index/=2;
	}
	return index-prod-1;
}

int query(int* arr,int index){		
	int sum=0;
	while(index>=0){
		sum+=arr[index];
		index=next(index);	//returns the next independent index
	}
	return sum;
}

int ft_query(int* arr,int length,int l,int h){     // l,h are 0 based. gives summation [ l , h ) 
	if(l<0 || h>=length){
		printf("Sorry index out of bounds");
		return INT_MIN;
	}

	return query(arr,h-1)-query(arr,l-1);
}

void printArray(int* arr,int length){
	for(int i=0;i<length;i++)
		printf("%d ",arr[i]);
	printf("\n");
}

int main(){
	int arr[]={1,2,3,4,5};
	int length=5;
	ft_makeTree(arr,length);
	while(true){
		int l,h;
		scanf("%d",&l);
		scanf("%d",&h);
		printf("[ %d , %d ) = %d\n",l,h,ft_query(arr,length,l,h));
	}
}			

