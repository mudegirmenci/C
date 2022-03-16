#include <stdio.h>
/*
Diziyi recursive olarak tersten yazdirir.
*/

#define BOYUT 15

void diziYazdir(int[],int);
int enKucukElemanRecursive(int dizi[],int boyut);
int min(int a,int b);

int main(){

   int dizi[15]={25,6,12,14,5,6,7,4,85,-65,34,12,7,14,4},x;
   
   printf("Dizideki degerler:\n");
   
   diziYazdir(dizi,BOYUT);
   
   printf("\n");
   x=enKucukElemanRecursive(dizi,BOYUT-1);	
   printf("Bu dizinin en kucuk eleman:%d\n",x);
   printf("\n");
   return 0;

}
void diziYazdir(int dizi[],int boyut){
	if(boyut>0) {
		printf("%d ",dizi[0]);
		diziYazdir(&dizi[1],boyut-1);
	}

}
int enKucukElemanRecursive(int dizi[],int boyut) {
	
	if(boyut==0)
		return dizi[0];
	return min(enKucukElemanRecursive(dizi,boyut-1),dizi[boyut]);
}

int min(int a,int b){
	if(a<b) return a;
	return b;
}

