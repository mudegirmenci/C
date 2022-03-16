#include <stdio.h>
/*
Diziyi recursive toplama
*/

int diziTopla(int[], int);

#define BOYUT 15
int main(){

   int dizi[BOYUT]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
   int toplam;
   
   toplam=diziTopla(dizi,BOYUT);
   printf("Dizi elemanlar toplami:%d\n",toplam);
   
   
}
int diziTopla(int dizi[],int boyut){
	if(boyut==1) return dizi[0];
	
	return dizi[boyut-1]+diziTopla[dizi,boyut-1];
}
