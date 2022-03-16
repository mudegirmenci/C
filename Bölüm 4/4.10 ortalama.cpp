/*
4.10 birkaç sayýnýn ortalamaasýný alan program.
klavyeden 999 sayýsý girilene kadar ki bütün sayýlarý alýp ortalamasýný yazdýrýr.
*/

#include<stdio.h>

int main(){
	int sayac=0,toplam,deger=0;
	
	do 
	{
		printf("Bir deger girin:\n");
		scanf("%d",&deger);
		toplam+=deger;
		sayac++;
	}
	while(deger!=999);
	
	printf("Girilen sayilarin ortalamasi:%d\n",(toplam-999)/(sayac-1));
	
}
