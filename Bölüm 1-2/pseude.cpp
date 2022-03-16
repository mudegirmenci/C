#include<stdio.h>

int main()
{
	int hesapNo=0;
	float hesapBakiyesi=0,aylikHarcama=0,kredi=0,krediLimiti=0,yeniBakiye=0;
	
	printf("Hesap no giriniz:");
	scanf("%d",&hesapNo);
	printf("Hesap Bakiyesini Giriniz:");
	scanf("%f",&hesapBakiyesi);
	printf("Kullanilan Kredi bilgisini girin:");
	scanf("%f",&kredi);
	printf("Kredi limitini girin:");
	scanf("%f",&krediLimiti);
	
	yeniBakiye=hesapBakiyesi-kredi-aylikHarcama;
	
	if(yeniBakiye>aylikHarcama)
		printf("Kredi Limiti aþýldý");
	
	printf("Hesapno: %f\nKredi Limiti: %f\n,Kalan Bakiye: %f\n",hesapNo,krediLimiti,yeniBakiye);
	
	return 0;
}
