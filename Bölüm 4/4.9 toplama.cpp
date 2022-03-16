/*
4.9 kullanýcýdan bir dizi tamsayý alýp bunlarý toplayan program. girilen ilk sayý kaç tane sayý toplanacaðýný belirler.

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
