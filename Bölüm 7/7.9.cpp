#include <stdio.h>
/*

7.9

*/

#define BOYUT 5

int main(){
	unsigned int degerler[BOYUT]={2,4,6,8,10};
	unsigned int *vPtr;
	
	vPtr=degerler;			//vPtr deðiþkenine iki farklý þekilde deðerleri ata
	vPtr=&degerler[4];

	printf("vPtr:%d\n",*(vPtr+3));
	printf("vPtr:%d\n",vPtr+3);
	printf("*(vPtr-=4):%d\n",*(vPtr-=4));
	
	for(int i=0;i<BOYUT;i++)
		printf("degerler[%d]:%d\n",i,degerler[i]);	//deðerleri normal  yazdýr.
		
		
	for(int i=0;i<BOYUT;i++)
		printf("*(degerler+%d):%d\n",i,*(degerler+i));	//gösterici-offset yöntemi ile deðerleri yazdýr.
	
	for(int i=0;i<BOYUT;i++)
		printf("*(vPtr+%d):%d\n",i,*(vPtr+i));	//gösterici-offset yöntemi ile deðerleri yazdýr.
		
		for(int i=0;i<BOYUT;i++)
		printf("vPt[+%d]:%d\n",i,vPtr[i]);	//gösterici-belirtec yöntemi ile deðerleri yazdýr.
}
