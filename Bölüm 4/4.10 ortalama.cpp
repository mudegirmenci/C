/*
4.10 birka� say�n�n ortalamaas�n� alan program.
klavyeden 999 say�s� girilene kadar ki b�t�n say�lar� al�p ortalamas�n� yazd�r�r.
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
