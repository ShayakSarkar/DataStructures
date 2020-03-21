#include <stdio.h>
#include <stdlib.h>
int main(){
	int** arr=(int**)malloc(sizeof(int*)*2);
	for(int i=0;i<2;i++){
		arr[i]=(int*)malloc(sizeof(int));
	}
	int ctr=10;
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			arr[i][j]=ctr++;

	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++)
			printf("%d ",arr[i][j]);
		printf("\n");
	}
}
