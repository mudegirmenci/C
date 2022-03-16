/*
3.47 faktoriyel hesapla (pozitif sayýlar için)
1. kullanýcýdan bir tamsayý al
2. sayi>=0 oldugu surece
3.   Eðer sayi==0 ise
   		 fak+=1;
   	 deðilse
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
	    fak=sayi*(sayi-1)*fak;    // diyelim 5! alacaðýz. fak=5.4.1 olacak ve bizim bir sonraki döngüde 3'e ihtiyaxýmýz var. öyleyse sayýyý 2 azaltýyoruz.
		sayi=sayi-2;
	}
	printf("Girdiginiz sayinin faktoriyeli:%d",fak);
	return 0;
}
