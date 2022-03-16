#include <stdio.h>
#define BOYUT 10

int main() {
	float *fPtr;
	float sayi1=4,sayi2;
	
	fPtr=&sayi1;	
	sayi2=*fPtr;
	
	printf("%.1f\n",*fPtr);
	printf("%.1f\n",sayi2);
	printf("%p\n",&sayi1);
	printf("%p\n",&sayi2);
	printf("%p\n",fPtr);
}
