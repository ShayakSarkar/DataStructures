#include <stdio.h>

[[maybe_unused]] void print(){
	printf("kl");
}

int main(){
	#ifdef maxi
		#undef maxi
	#endif

	#define maxi(a,b,c) (a>b)?((a>c)?a:c):(b>c)?b:c

	printf("Hello World");
	//printf("%d",maxi(2,3,5));
	int a,b,c;
	a=3;
	b=2;
	c=1;
	printf("%d",maxi(a,b,c));
	//#undef maxi
	#ifdef maxi
		printf("Shayak Sarkar is my name\n");
	#endif	
	
}
