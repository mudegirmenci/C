#include <stdio.h>
#define BOYUT 10
void kabarcikSiralama(int *,const int);
int main() {
	int a[BOYUT]={5,4,3,6,9,23,7,76,54,0};
	int i;
	
	printf("Veriler orjinal sirada:\n");
	
	for(int i=0;i<BOYUT;i++)
		printf("%4d  ",a[i]);
	
	kabarcikSiralama(a,BOYUT);
	
	printf("Veriler artan sirada:\n");
	
	for(int i=0;i<BOYUT;i++)
		printf("%4d  ",a[i]);
		
}

void kabarcikSiralama(int *dizi,const int boyut){
	void yerDegistir(int *,int *);
	
	for(int tur=0;tur<boyut-1;tur++)
		for(int j=0;j<boyut-1;j++) {
			if(dizi[j]>dizi[j+1])  yerDegistir(&dizi[j],&dizi[j+1]);
		}
}

void yerDegistir(int *eleman1Ptr,int *eleman2Ptr){
	int temp=*eleman1Ptr;
	*eleman1Ptr=*eleman2Ptr;
	*eleman2Ptr=temp;
}
