/*
3.47 faktoriyel hesapla (pozitif say�lar i�in)
1. kullan�c�dan bir tamsay� al
2. sayi>=0 oldugu surece
3.   E�er sayi==0 ise
   		 fak+=1;
   	 de�ilse
   	     fak+=sayi.(sayi-1)
*/

#include<stdio.h>

int main()
{
	int sayi,fak=1;
	
	printf("Pozitif bir tamsayi girin:");
	scanf("%d",&sayi);
	
	if(sayi<0)
	 return 0;
	 
	while(sayi>1){
	    fak=sayi*(sayi-1)*fak;    // diyelim 5! alaca��z. fak=5.4.1 olacak ve bizim bir sonraki d�ng�de 3'e ihtiyax�m�z var. �yleyse say�y� 2 azalt�yoruz.
		sayi=sayi-2;
	}
	printf("Girdiginiz sayinin faktoriyeli:%d",fak);
	return 0;
}
