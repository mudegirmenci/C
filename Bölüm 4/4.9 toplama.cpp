/*
4.9 kullan�c�dan bir dizi tamsay� al�p bunlar� toplayan program. girilen ilk say� ka� tane say� toplanaca��n� belirler.

*/

#include<stdio.h>

int main(void)
{
	int sayac,toplam=0,sayi;
	printf("Kac sayi toplamak istiyorsunuz?\n");
	scanf("%d",&sayac);
	
	while(sayac-->0){
	   printf("%d. Sayiyi girin:\n",sayac);
	   scanf("%d",&sayi);
	   toplam+=sayi;
	}
	printf("Girdiginiz sayilarin toplami:%d\n",toplam);
	
	return 0;
}
