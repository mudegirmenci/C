/*
4.11 Kullan�c� taraf�ndan girilen birka� tamsay�n�n en k�����n� bulan program.
ilk say� ka� say� girilece�ini belirtecek.
*/

#include<stdio.h>

int main(void)
{
	int sayac,enKucuk=0,sayi;
	printf("Kac sayi girmek istiyorsunuz?\n");
	scanf("%d",&sayac);
	
	printf("%d. Sayiyi girin:\n",sayac);
	scanf("%d",&sayi);
	enKucuk=sayi;
	
	   
	while(--sayac>0){
	   printf("%d. Sayiyi girin:\n",sayac);
	   scanf("%d",&sayi);
	   if(enKucuk>sayi)
	       enKucuk=sayi;
	    
	}
	printf("Girdiginiz sayilarin en kucugu:%d\n",enKucuk);
	
	return 0;
}
