#include <stdio.h>

int main() {
	int a;
	int *aPtr;
	
	a=7;
	aPtr=&a;
	
	printf("a adresi:%p"
			"\n*aPtr degiskeninin degeri:%p",&a,aPtr);
	printf("\n\na degeri:%d"
			"\n*aPtr  degeri:%d",a,*aPtr);
    printf("\n\n* ve & birbirlerinin eslenigidir:"
			"\n&*aPtr=%p."
			"\n*&aPtr=%p \n",&*aPtr,*&aPtr);
}
