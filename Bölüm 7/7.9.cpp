#include <stdio.h>
/*

7.9

*/

#define BOYUT 5

int main(){
	unsigned int degerler[BOYUT]={2,4,6,8,10};
	unsigned int *vPtr;
	
	vPtr=degerler;			//vPtr de�i�kenine iki farkl� �ekilde de�erleri ata
	vPtr=&degerler[4];

	printf("vPtr:%d\n",*(vPtr+3));
	printf("vPtr:%d\n",vPtr+3);
	printf("*(vPtr-=4):%d\n",*(vPtr-=4));
	
	for(int i=0;i<BOYUT;i++)
		printf("degerler[%d]:%d\n",i,degerler[i]);	//de�erleri normal  yazd�r.
		
		
	for(int i=0;i<BOYUT;i++)
		printf("*(degerler+%d):%d\n",i,*(degerler+i));	//g�sterici-offset y�ntemi ile de�erleri yazd�r.
	
	for(int i=0;i<BOYUT;i++)
		printf("*(vPtr+%d):%d\n",i,*(vPtr+i));	//g�sterici-offset y�ntemi ile de�erleri yazd�r.
		
		for(int i=0;i<BOYUT;i++)
		printf("vPt[+%d]:%d\n",i,vPtr[i]);	//g�sterici-belirtec y�ntemi ile de�erleri yazd�r.
}
