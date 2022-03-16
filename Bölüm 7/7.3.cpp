#include <stdio.h>
#define BOYUT 10

int main() {
	
	float sayilar[BOYUT]={0.0,1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9};
	float *nPtr;
	
	for(int i=0;i<BOYUT;i++)
		printf("%4.1f\n",sayilar[i]);
	nPtr=sayilar;
	nPtr=&sayilar[0];
		
	printf("\n");
		
	for(int offset=0;offset<BOYUT;offset++)
		printf("*(sayilar+%d):%0.1f\n",offset,*(sayilar+offset));
	
	printf("\n");
	
	for(int offset=0;offset<BOYUT;offset++)
		printf("*(nPtr+%d):%0.1f\n",offset,*(nPtr+offset));
	
	printf("\n");
	
	for(int i=0;i<BOYUT;i++)
		printf("nPtr[%d]:%0.1f\n",i,nPtr[i]);
		
	printf("\n");	
	
	printf("%p\n",nPtr);
	printf("%d\n",*nPtr);
}
