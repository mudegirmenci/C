#include <stdio.h>

/*
her biri birbirinden farklý, 10-100 arasý kullanýcýdan 20 sayý alan program
*/

#define BOYUT 21

int arama(int,const int[],int);
int main(){
	
	int a[BOYUT]={0};
	int sayac=0,i;
	printf("10-100 arasi bir sayi girin:\n");
	
	while(sayac<20){
	  scanf("%d",&i);
		if(arama(i,a,BOYUT)!=0 || i<10 || i>100)  
		    printf("Girdiginiz degeri daha once girdiniz veya istenen aralik disinda bir sayi girdiniz. Lutfen farkli bir deger giriniz: \n");
		else {
			a[sayac]=i;	
			sayac++;
			printf("Yeni dizi elemani:%d\n",i);
		}
	
		
	}
	
}
int arama(int deger,const int a[],int boyut){
	for(int i=0;i<boyut-1;i++)
		if(a[i]==deger) return 1;
		
	return 0;
}
