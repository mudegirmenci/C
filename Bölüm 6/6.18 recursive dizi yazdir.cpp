#include <stdio.h>
/*
Diziyi recursive olarak tersten yazdirir.
*/

#define BOYUT 15

void diziYazdir(int[],int);

int main(){

   int dizi[15]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
   
   printf("Dizideki degerler:\n");
   
   diziYazdir(dizi,BOYUT);
   printf("\n");
   return 0;

}
void diziYazdir(int dizi[],int boyut){
	if(boyut>0) {
		printf("%d ",dizi[0]);
		diziYazdir(&dizi[1],boyut-1);
	}

}

