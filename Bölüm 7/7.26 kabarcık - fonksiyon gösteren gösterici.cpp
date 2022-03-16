#include <stdio.h>
#define BOYUT 10
void kabarcik(int[],const int,int(*)(int,int));
int artan(int,int);
int azalan(int,int);

int main() {
	int a[BOYUT]={5,4,3,6,9,23,7,76,54,0};
	int secim,sayici;
	

	
	printf("artan siralama icin 1 girin:\n");
	scanf("%d",&secim);
	printf("Veriler orjinal sirada:\n");
	
	for(int i=0;i<BOYUT;i++)
		printf("%4d  ",a[i]);
		
	if(secim==1){
		kabarcik(a,BOYUT,artan);
		printf("Verilen artan sirada \n");
	} else {
		kabarcik(a,BOYUT,azalan);
		printf("Verilen azalan sirada \n");
	}
	
	
	for(int i=0;i<BOYUT;i++)
		printf("%4d  ",a[i]);
		
}

void kabarcik(int dizi[],const int boyut,int(*karsilastir)(int,int)){

	void yerDegistir(int *,int *);
	
	for(int tur=0;tur<boyut-1;tur++)
		for(int j=0;j<boyut-1;j++) {
			if((*karsilastir)(dizi[j],dizi[j+1]))  yerDegistir(&dizi[j],&dizi[j+1]);
		}
}

void yerDegistir(int *eleman1Ptr,int *eleman2Ptr){
	int temp=*eleman1Ptr;
	*eleman1Ptr=*eleman2Ptr;
	*eleman2Ptr=temp;
}
int artan(int a,int b) {
	return b<a;
}

int azalan(int a,int b){
	return b>a;
}
