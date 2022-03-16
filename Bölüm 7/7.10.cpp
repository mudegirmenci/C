#include <stdio.h>
/*

7.10

*/


int main(){
	long deger1=200000,deger2;
	
	long *lPtr;
	lPtr=&deger1;
	
	printf("%ld\n",*lPtr);
	
	deger2=*lPtr;
	printf("%ld\n",deger2);
	printf("%p\n",&deger1);
	printf("%p\n",lPtr);
	
	
}
