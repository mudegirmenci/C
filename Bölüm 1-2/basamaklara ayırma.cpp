#include<stdio.h>

int main()
{
	int a;
	
	printf("Bes basamakli bir sayi girin:\n");
	scanf("%d",&a);
	
	printf("%d\n",a%10);        //10'lar basama�� mod. 12345 say�s� 10 a b�l�n�rse 1'ler basama��ndaki say�y� d�nderir.
	printf("%d\n",(a/10)%10);   //C de tam say�lar� b�lme i�lemi 0 verir. yani 12345/10 normalde 1234.5 olmal� fakat tamsay� oldu�u i�in 1234 olarak yuvarl�yor.
	printf("%d\n",(a/100)%10);  //burada da 12345/100=123. 123 mod 10=3
	printf("%d\n",(a/1000)%10);
	printf("%d\n",(a/10000)%10);

	return 0;
}
