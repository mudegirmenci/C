#include<stdio.h>

int main()
{
	int dersNotu,sayac=1,toplam=0,ortalama;
	
	while(sayac<=10)
	{
		printf("%d. Ogrencinin notunu giriniz: \n",sayac);
		scanf("%d",&dersNotu);
		toplam+=dersNotu;
		sayac++;
	}
	
	ortalama=toplam/10;
	
	printf("Ortalama %d dir.\n",ortalama);
	
	
	return 0;
}
