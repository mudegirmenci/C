/*
3.47 b. matemateiksel e hesapla
*/


#include<stdio.h>

int main()
{
	int sayi;
	float e=1,fak=1;
	
	printf("e icin pozitif bir tamsayi girin:");
	scanf("%d",&sayi);
	
	if(sayi<0)
	 return 0;
	 
	while(sayi>1){
	    fak=sayi*(sayi-1)*fak;    // diyelim 5! alaca��z. fak=5.4.1 olacak ve bizim bir sonraki d�ng�de 3'e ihtiyax�m�z var. �yleyse say�y� 2 azalt�yoruz.
		sayi=sayi-2;
		e+=1/fak;
	}
	printf("Girdiginiz sayinin e si:%f",e);
	return 0;
}
